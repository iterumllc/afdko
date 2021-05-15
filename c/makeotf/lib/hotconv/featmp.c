/* This file is a temporary record of the functions from feat.c that still need
 * to be ported to FeatCtx
 */

/* ------------------------ Supplementary Functions ------------------------ */

void featSetIncludeReturnMode(int mode) {
    h->returnMode.include = mode;
}

int featGetIncludeReturnMode(void) {
    return h->returnMode.include;
}

void featSetTagReturnMode(int mode) {
    h->returnMode.tag = mode;
}

int featGetTagReturnMode(void) {
    return h->returnMode.tag;
}

/* --- Device handling --- */

static void deviceBeg(void) {
    /* xxx Todo */
}

static void deviceAddEntry(unsigned short ppem, short delta) {
    /* xxx Todo */
}

static Offset deviceEnd(void) {
    /* xxx Todo */
    return 0;
}

/* --- GDEF interface --- */

static void setGDEFGlyphClassDef(GNode *simple, GNode *ligature, GNode *mark,
                                 GNode *component) {
    h->gFlags |= GF_SEEN_GDEF_GLYPHCLASS;
    setGlyphClassGDef(g, simple, ligature, mark, component);
}

static void addGDEFAttach(GNode *pat, unsigned short contour) {
    int seenContourIndex = 0;
    GNode *next = pat;
    if (pat->nextSeq != NULL) {
        featMsg(hotERROR,
                "Only one glyph|glyphClass may be present per"
                " AttachTable statement");
    }

    while (next != NULL) {
        seenContourIndex = 0;
        seenContourIndex = addAttachEntryGDEF(g, next, contour);
        if (seenContourIndex) {
            featMsg(hotWARNING, "Skipping duplicate contour index %d", contour);
        }
        next = next->nextCl;
    }
}

static void initGDEFLigatureCaretValue()
{
    h->ligCaretValues.cnt = 0;
}

static void addGDEFLigatureCaretValue(int value)
{
    *dnaNEXT(h->ligCaretValues) = value;
}


static void setGDEFLigatureCaret(GNode *pat, unsigned short format) {
    GNode *next = pat;

    if (pat->nextSeq != NULL) {
        featMsg(hotERROR,
                "Only one glyph|glyphClass may be present per"
                " LigatureCaret statement");
    }

    while (next != NULL) {
        addLigCaretEntryGDEF(g, next, h->ligCaretValues.array, h->ligCaretValues.cnt, format);
        next = next->nextCl;
    }
}

static void creatDefaultGDEFClasses() {
    if (!(h->gFlags & GF_SEEN_GDEF_GLYPHCLASS)) {
        /* Add the GlyphClass def */
        GNode **gcInsert;

        GNode *base = NULL;
        GNode *ligature = NULL;
        GNode *marks = NULL;
        GNode *component = NULL;
        GNode *tempSrc;

        /* I need to call gcOpen first, as these classes may have never */
        /* been instantiated, in which case gcLookup would post a fatal */
        /* error on the lookup.                                         */

        /* The source glyph classes are all named classes. Named class      */
        /* glyphs get recycled when hashFree() is called, so we need to     */
        /* make a copy of these classes here, and recycle the copy after in */
        /* GDEF.c::createGlyphClassDef(). This is because                   */
        /* createGlyphClassDef deletes glyphs from within the class lists   */
        /* to eliminate duplicates. If we operate on a named class list,    */
        /* then any deleted duplicated glyphs gets deleted again when       */
        /* hashFree() is called.Also, the hash element head points to the   */
        /* original first glyph, which may be sorted further down the list. */

        gcInsert = gcOpen(kDEFAULT_BASECLASS_NAME);
        base = gcLookup(kDEFAULT_BASECLASS_NAME);
        if (base != NULL) {
            featGlyphClassCopy(h->g, &tempSrc, base);
            base = tempSrc;
            featGlyphClassSort(h->g, &base, 1, 0);
        }

        gcInsert = gcOpen(kDEFAULT_LIGATURECLASS_NAME);
        ligature = gcLookup(kDEFAULT_LIGATURECLASS_NAME);
        if (ligature != NULL) {
            featGlyphClassCopy(h->g, &tempSrc, ligature);
            ligature = tempSrc;
            featGlyphClassSort(h->g, &ligature, 1, 0);
        }

        gcInsert = gcOpen(kDEFAULT_MARKCLASS_NAME);
        marks = gcLookup(kDEFAULT_MARKCLASS_NAME);
        if (marks != NULL) {
            featGlyphClassCopy(h->g, &tempSrc, marks);
            marks = tempSrc;
            featGlyphClassSort(h->g, &marks, 1, 0);
        }

        gcInsert = gcOpen(kDEFAULT_COMPONENTCLASS_NAME);
        component = gcLookup(kDEFAULT_COMPONENTCLASS_NAME);
        if (component != NULL) {
            featGlyphClassCopy(h->g, &tempSrc, component);
            component = tempSrc;
            featGlyphClassSort(h->g, &component, 1, 0);
        }

        setGlyphClassGDef(g, base, ligature, marks, component);
    }
}

/* -------------------------- misc table functions ------------------------------- */

/* Add name string to name table. */

static void addNameString(long platformId, long platspecId,
                          long languageId, long nameId) {
    int nameError = 0;
    if ((nameId == 2) || (nameId == 6) || ((nameId >= 26) && (nameId <= 255)))
        nameError = 1;
    else if ((nameId > 0) && ((nameId < 7) && (!(g->convertFlags & HOT_OVERRIDE_MENUNAMES)))) {
        nameError = 1;
    }
    if (nameError) {
        hotMsg(g, hotWARNING,
               "name id %ld cannot be set from the feature file. "
               "ignoring record [%s %d]",
               nameId,
               INCL.file, h->linenum);
        return;
    }

    /* Add defaults */
    if (platformId == -1) {
        platformId = HOT_NAME_MS_PLATFORM;
    }
    if (platformId == HOT_NAME_MS_PLATFORM) {
        if (platspecId == -1) {
            platspecId = HOT_NAME_MS_UGL;
        }
        if (languageId == -1) {
            languageId = HOT_NAME_MS_ENGLISH;
        }
    } else if (platformId == HOT_NAME_MAC_PLATFORM) {
        if (platspecId == -1) {
            platspecId = HOT_NAME_MAC_ROMAN;
        }
        if (languageId == -1) {
            languageId = HOT_NAME_MAC_ENGLISH;
        }
    }

    /* Terminate name and add to name table */
    *dnaNEXT(h->nameString) = '\0';
    if (hotAddName(g,
                   (unsigned short)platformId, (unsigned short)platspecId,
                   (unsigned short)languageId, (unsigned short)nameId,
                   h->nameString.array)) {
        featMsg(hotERROR, "Bad string");
    }
}

/* Add 'size' feature submenuname name string to name table. */

static void addSizeNameString(long platformId, long platspecId,
                              long languageId) {
    unsigned short nameID;

    /* We only need to reserve a name ID *once*; after the first time, */
    /* all subsequent sizemenunames will share the same nameID.        */
    if (h->featNameID == 0) {
        nameID = nameReserveUserID(g);
        GPOSSetSizeMenuNameID(g, nameID);
        h->featNameID = nameID;
    } else {
        nameID = h->featNameID;
    }

    addNameString(platformId, platspecId, languageId, nameID);
}

/* Add 'name for feature string to name table. */

static void addFeatureNameString(long platformId, long platspecId,
                                 long languageId) {
    unsigned short nameID;

    /* We only need to reserve a name ID *once*; after the first time, */
    /* all subsequent sizemenunames will share the same nameID.        */
    if (h->featNameID == 0) {
        nameID = nameReserveUserID(g);
        GSUBSetFeatureNameID(g, h->curr.feature, nameID);
        h->featNameID = nameID;
    } else {
        nameID = h->featNameID;
    }

    addNameString(platformId, platspecId, languageId, nameID);
}

static void addUserNameString(long platformId, long platspecId,
                              long languageId) {
    unsigned short nameID;

    /* We only need to reserve a name ID *once*. */
    if (h->featNameID == 0) {
        nameID = nameReserveUserID(g);
        h->featNameID = nameID;
    } else {
        nameID = h->featNameID;
    }

    addNameString(platformId, platspecId, languageId, nameID);
}

/* Add vendor name to OS/2 table. */
/* ------------------------------------------------------------------- */
/* ------------------------------------------------------------------- */
static void addVendorString(hotCtx g) {
    int tooshort = 0;

    while (h->nameString.cnt < 4) {
        *dnaNEXT(h->nameString) = ' ';
        tooshort = 1;
    }
    if (tooshort) {
        featMsg(hotWARNING, "Vendor name too short. Padded automatically to 4 characters.");
    }

    if (h->nameString.cnt > 4) {
        featMsg(hotERROR, "Vendor name too long. Max is 4 characters.");
    }

    *dnaNEXT(h->nameString) = '\0';
    setVendId_str(g, h->nameString.array);
}

/* Creates the cross product of pattern pat, and returns a pointer to the array
   of *n resulting sequences. pat is left intact; the client is responsible for
   recycling the result. */

GNode ***featMakeCrossProduct(hotCtx g, GNode *pat, unsigned *n) {
    GNode *cl;
    featCtx h = g->ctx.feat;

    h->prod.cnt = 0;

    /* Add each glyph class in pat to the cross product */
    for (cl = pat; cl != NULL; cl = cl->nextSeq) {
        long i;
        long nProd;

        if (cl == pat) {
            *dnaNEXT(h->prod) = NULL;
        }
        nProd = h->prod.cnt;

        for (i = 0; i < nProd; i++) {
            GNode *p;
            int cntCl = 0;
            int lenSrc = 0;

            /* h->prod.array[i] is the source. Don't store its address as a */
            /* pointer in a local variable since dnaINDEX below may         */
            /* obsolete it!                                                 */
            for (p = cl; p != NULL; p = p->nextCl) {
                GNode **r;

                if (p == cl) {
                    for (r = &h->prod.array[i]; *r != NULL; r = &(*r)->nextSeq) {
                        lenSrc++;
                    }
                } else {
                    int inxTarg = nProd * cntCl + i;
                    GNode **targ = dnaINDEX(h->prod, inxTarg);

                    if (inxTarg >= h->prod.cnt) {
                        /* can't use da_INDEXS */
                        h->prod.cnt = inxTarg + 1;
                    }
                    r = featPatternCopy(g, targ, h->prod.array[i], lenSrc);
                }
                *r = featSetNewNode(g, p->gid);
                cntCl++;
            }
        }
    }

    *n = (unsigned)h->prod.cnt;
    return &h->prod.array;
}

static int CDECL matchValueDef(const void *key, const void *value) {
    return strcmp((char *)key, ((ValueDef *)value)->valueName);
}

static int CDECL cmpValueDefs(const void *first, const void *second, void *ctx) {
    const ValueDef *a = first;
    const ValueDef *b = second;
    return strcmp(a->valueName, b->valueName);
}

void featAddValRecDef(short *metrics, char *valueName) {
    ValueDef *vd;
    vd = (ValueDef *)bsearch(valueName, h->valueDefs.array, h->valueDefs.cnt,
                             sizeof(ValueDef), matchValueDef);

    if (vd != NULL) {
        featMsg(hotFATAL, "Named value record definition '%s' is a a duplicate of an earlier named value record definition.", valueName);
    }

    vd = (ValueDef *)dnaNEXT(h->valueDefs);
    vd->metrics[0] = metrics[0];
    vd->metrics[1] = metrics[1];
    vd->metrics[2] = metrics[2];
    vd->metrics[3] = metrics[3];

    strcpy(vd->valueName, valueName);
    ctuQSort(h->valueDefs.array, h->valueDefs.cnt, sizeof(ValueDef), cmpValueDefs, &h);
}

static void fillMetricsFromValueDef(char *valueName, short *metrics) {
    ValueDef *vd;
    vd = (ValueDef *)bsearch(valueName, h->valueDefs.array, h->valueDefs.cnt,
                             sizeof(ValueDef), matchValueDef);

    if (vd == NULL) {
        featMsg(hotERROR, "Named value reference '%s' is not in list of named value records.", valueName);
        metrics[0] = 0;
        metrics[1] = 0;
        metrics[2] = 0;
        metrics[3] = 0;
        return;
    }
    metrics[0] = vd->metrics[0];
    metrics[1] = vd->metrics[1];
    metrics[2] = vd->metrics[2];
    metrics[3] = vd->metrics[3];
}

static int CDECL matchAnchorDef(const void *key, const void *value) {
    return strcmp((char *)key, ((AnchorDef *)value)->anchorName);
}

static int CDECL cmpAnchorDefs(const void *first, const void *second, void *ctx) {
    const AnchorDef *a = first;
    const AnchorDef *b = second;
    return strcmp(a->anchorName, b->anchorName);
}

void featAddAnchorDef(short x, short y, unsigned short contourIndex, int hasContour, char *anchorName) {
    AnchorDef *ad;
    ad = (AnchorDef *)bsearch(anchorName, h->anchorDefs.array, h->anchorDefs.cnt,
                              sizeof(AnchorDef), matchAnchorDef);

    if (ad != NULL) {
        featMsg(hotFATAL, "Named anchor definition '%s' is a a duplicate of an earlier named anchor definition.", anchorName);
    }

    ad = (AnchorDef *)dnaNEXT(h->anchorDefs);
    ad->x = x;
    ad->y = y;
    if (hasContour) {
        ad->contourpoint = contourIndex;
        ad->hasContour = 1;
    } else {
        ad->hasContour = 0;
    }

    strcpy(ad->anchorName, anchorName);
    ctuQSort(h->anchorDefs.array, h->anchorDefs.cnt, sizeof(AnchorDef), cmpAnchorDefs, &h);
}

static void featAddAnchor(short xVal, short yVal, unsigned short contourIndex, int isNULL, int hasContour, char *anchorName, int componentIndex) {
    AnchorMarkInfo *anchorMarkInfo = dnaNEXT(h->anchorMarkInfo);
    anchorMarkInfo->markClass = NULL;
    initAnchor(anchorMarkInfo);
    if (anchorName != NULL) {
        AnchorDef *ad;
        ad = (AnchorDef *)bsearch(anchorName, h->anchorDefs.array, h->anchorDefs.cnt,
                                  sizeof(AnchorDef), matchAnchorDef);

        if (ad == NULL) {
            featMsg(hotFATAL, "Named anchor reference '%s' is not in list of named anchors.", anchorName);
        }
        anchorMarkInfo->x = ad->x;
        anchorMarkInfo->y = ad->y;

        if (ad->hasContour) {
            anchorMarkInfo->format = 2;
            anchorMarkInfo->contourpoint = contourIndex;
        } else {
            anchorMarkInfo->format = 1;
        }
    } else {
        anchorMarkInfo->x = xVal;
        anchorMarkInfo->y = yVal;
        if (isNULL) {
            anchorMarkInfo->format = 0;
        } else if (hasContour) {
            anchorMarkInfo->format = 2;
            anchorMarkInfo->contourpoint = contourIndex;
        } else {
            anchorMarkInfo->format = 1;
        }
    }
    anchorMarkInfo->componentIndex = componentIndex;
}

/* Add new mark class definition */
static void featAddMark(GNode *targ, char *markClassName) {
    GNode *markNode;
    GNode *curNode;
    GNode **gcInsert;
    AnchorMarkInfo *anchorMarkInfo = dnaINDEX(h->anchorMarkInfo, h->anchorMarkInfo.cnt - 1);

    /* save this anchor info in all glyphs of this mark class */
    curNode = targ;
    while (curNode != NULL) {
        curNode->markClassAnchorInfo = *anchorMarkInfo;
        curNode = curNode->nextCl;
    }

    gcInsert = gcOpen(markClassName); /* Get or creates a new class node with this node in the hash of class names, and sets to be the target of class additions, */

    /* If it is a new class, sets the head class gnode into h->he, and sets h->gcInsert to &h->he->value.head. */
    /* else gcInsert holds the  the address of the last gnode->nextCl                                          */
    featGlyphClassCopy(g, gcInsert, targ);
    markNode = gcLookup(markClassName); /* gcInsert points to the address of the nextCl field in the last node in the class chain; we need the address of the head node */
    if (markNode->flags & FEAT_USED_MARK_CLASS) {
        featMsg(hotERROR, "You cannot add glyphs to a mark class after the mark class has been used in a position statement. %s.", markClassName);
    }

    if (*gcInsert == markNode) {
        /* this is the first time this mark class name has been referenced; save the class name in the head node. */
        copyStr(g, &markNode->markClassName, markClassName);
        *dnaNEXT(h->markClasses) = markNode; /* This is an array that captures all the named mark classes referenced in the feature file.                 */
                                             /* This is not the same as the list in the GPOS.c file, which is a list only of mark classes used the lookup. */
    }

    /* add mark glyphs to default base class */
    gcInsert = gcOpen(kDEFAULT_MARKCLASS_NAME);
    featGlyphClassCopy(g, gcInsert, targ);

    featRecycleNodes(g, targ);

    h->gFlags |= GF_SEEN_MARK_CLASS_FLAG;
}

/* Add mark class reference to current anchorMarkInfo for the rule. */
static void addMarkClass(char *markClassName) {
    GNode *headNode;
    AnchorMarkInfo *anchorMarkInfo = dnaINDEX(h->anchorMarkInfo, h->anchorMarkInfo.cnt - 1);
    headNode = gcLookup(markClassName);
    if (headNode == NULL) {
        featMsg(hotERROR, "MarkToBase or MarkToMark rule references a mark class (%s) that has not yet been defined", markClassName);
        return;
    }
    headNode->flags |= FEAT_USED_MARK_CLASS;
    anchorMarkInfo->markClass = headNode;
}

static void getMarkSetIndex(GNode *markClass, unsigned short *markSetIndex) {
    *markSetIndex = addMarkSetClassGDEF(g, markClass);
}

static void getGDEFMarkClassIndex(GNode *markClass, unsigned short *markAttachClassIndex) {
    *markAttachClassIndex = addGlyphMarkClassGDEF(g, markClass);
    if (*markAttachClassIndex > kMaxMarkAttachClasses) {
        featMsg(hotERROR, "No more than 15 different class names can be used with the \"lookupflag MarkAttachmentType\". This would be a 16th.");
    }
}

    *dnaNEXT(*ta) = tag;
    if (curr != NULL) {
        *curr = tag;
    }

    return 1;
}

#if 0 /* xxx */
/* Returns 1 if all sequence nodes in pattern are marked */
static int isAllMarkedPattern(GNode *node) {
    for (; node != NULL; node = node->nextSeq) {
        if (!(node->flags & FEAT_MARKED)) {
            return 0; /* This node is unmarked */
        }
    }
    return 1;
}

#endif

static void addFeatureNameParam(hotCtx g, unsigned short nameID) {
    prepRule(GSUB_, GSUBFeatureNameParam, NULL, NULL);

    GSUBAddFeatureMenuParam(g, &nameID);

    wrapUpRule();
}

static void addCVNameID(unsigned int nameID, int labelID) {
    switch (labelID) {
        case cvUILabelEnum: {
            if (h->cvParameters.FeatUILabelNameID != 0) {
                featMsg(hotERROR, "A Character Variant parameter table can have only one FeatUILabelNameID entry.");
            }
            h->cvParameters.FeatUILabelNameID = h->featNameID;
            break;
        }

        case cvToolTipEnum: {
            if (h->cvParameters.FeatUITooltipTextNameID != 0) {
                featMsg(hotERROR, "A Character Variant parameter table can have only one SampleTextNameID entry.");
            }
            h->cvParameters.FeatUITooltipTextNameID = h->featNameID;
            break;
        }

        case cvSampletextEnum: {
            if (h->cvParameters.SampleTextNameID != 0) {
                featMsg(hotERROR, "A Character Variant parameter table can have only one SampleTextNameID entry.");
            }
            h->cvParameters.SampleTextNameID = h->featNameID;
            break;
        }

        case kCVParameterLabelEnum: {
            h->cvParameters.NumNamedParameters++;
            if (h->cvParameters.FirstParamUILabelNameID == 0) {
                h->cvParameters.FirstParamUILabelNameID = h->featNameID;
            }
            break;
        }
    }

    h->featNameID = 0;
}

static void addCVParametersCharValue(unsigned long uv) {
    unsigned long *uvp = dnaNEXT(h->cvParameters.charValues);
    *uvp = uv;
}

static void addCVParam(hotCtx g) {
    prepRule(GSUB_, GSUBCVParam, NULL, NULL);

    GSUBAddCVParam(g, &h->cvParameters);

    wrapUpRule();
}

static void addGPOS(int lkpType, GNode *targ, char *fileName, long lineNum, int anchorCount, AnchorMarkInfo *anchorMarkInfo) {
    prepRule(GPOS_, (targ->flags & FEAT_HAS_MARKED) ? GPOSChain : lkpType, targ, NULL);

    GPOSRuleAdd(g, lkpType, targ, fileName, lineNum, anchorCount, anchorMarkInfo);

    wrapUpRule();
}

/* Analyze featValidateGPOSChain targ metrics. Return 1 if valid, else 0 */
/* Also sets flags in backtrack and look-ahead sequences */

int featValidateGPOSChain(hotCtx g, GNode *targ, int lkpType) {
    int state;
    GNode *p;
    int nMarked = 0;
    int nNodesWithMetrics = 0;
    int seenTerminalMetrics = 0; /* special case for kern -like syntax in a contextual sub statement. */
    int nBaseGlyphs = 0;
    int nLookupRefs = 0;
    GNode *m = NULL;        /* Suppress optimizer warning */
    GNode *lastNode = NULL; /* Suppress optimizer warning */

    /* At most one run of marked positions supported, for now */
    for (p = targ; p != NULL; p = p->nextSeq) {
        lastNode = p;

        if (p->flags & FEAT_MARKED) {
            if (++nMarked == 1) {
                m = p;
            }
            if (p->metricsInfo != NULL) {
                nNodesWithMetrics++;
            }
            if (p->lookupLabelCount > 0) {
                nLookupRefs++;
            }
        } else {
            if (p->lookupLabelCount > 0) {
                featMsg(hotERROR, "Lookup references are allowed only in the input sequence: this is the sequence of marked glyphs.");
            }

            if (p->flags & FEAT_IS_MARK_NODE) {
                featMsg(hotERROR, "The final mark class must be marked as part of the input sequence: this is the sequence of marked glyphs.");
            }

            if ((p->nextSeq != NULL) && (p->nextSeq->flags & FEAT_MARKED) && (nMarked > 0)) {
                featMsg(hotERROR, "Unsupported contextual GPOS target sequence: only one run of marked glyphs  is supported.");
                return 0;
            }

            /* We actually do allow  a value records after the last glyph node, if there is only one marked glyph */
            if (p->metricsInfo != NULL) {
                if (nMarked == 0) {
                    featMsg(hotERROR, "Positioning cannot be applied in the backtrack glyph sequence, before the marked glyph sequence.");
                    return 0;
                }
                if ((p->nextSeq != NULL) || (nMarked > 1)) {
                    featMsg(hotERROR, "Positioning values are allowed only in the marked glyph sequence, or after the final glyph node when only one glyph node is marked.");
                    return 0;
                }

                if ((p->nextSeq == NULL) && (nMarked == 1)) {
                    seenTerminalMetrics = 1;
                }

                nNodesWithMetrics++;
            }
        }

        if (p->flags & FEAT_IS_BASE_NODE) {
            nBaseGlyphs++;
            if ((lkpType == GPOSCursive) && (!(p->flags & FEAT_MARKED))) {
                featMsg(hotERROR, "The base glyph or glyph class must be marked as part of the input sequence in a contextual pos cursive statement.");
            }
        }
    }

    /* m now points to beginning of marked run */

    /* Check for special case of a single marked node, with one or more lookahead nodes, and a single value record attached to the last node */
    if (seenTerminalMetrics) {
        m->metricsInfo = lastNode->metricsInfo;
        lastNode->metricsInfo = NULL;
    }

    if (targ->flags & FEAT_IGNORE_CLAUSE) {
        /* An ignore clause is always contextual. If not marked, then mark the first glyph in the sequence */
        if (nMarked == 0) {
            targ->flags |= FEAT_MARKED;
            nMarked = 1;
        }
    } else if ((nNodesWithMetrics == 0) && (nBaseGlyphs == 0) && (nLookupRefs == 0)) {
        featMsg(hotERROR, "Contextual positioning rule must specify a positioning value or a mark attachment rule or a direct lookup reference.");
        return 0;
    }

    /* Divide into backtrack, input, and lookahead (xxx ff interface?). */
    /* For now, input is marked glyphs                                  */
    state = FEAT_BACKTRACK;
    for (p = targ; p != NULL; p = p->nextSeq) {
        if (p->flags & FEAT_MARKED) {
            state = FEAT_INPUT;
        } else if (state != FEAT_BACKTRACK) {
            state = FEAT_LOOKAHEAD;
        }
        p->flags |= state;
    }

    return 1;
}

/* Add feature parameters */

static void addFeatureParam(hotCtx g, short *params, unsigned short numParams) {
    switch (h->curr.feature) {
        case size_:
            prepRule(GPOS_, GPOSFeatureParam, NULL, NULL);

            GPOSAddSize(g, params, numParams);

            wrapUpRule();

            break;

        default:
            featMsg(hotERROR,
                    "A feature parameter is supported only for the 'size' feature.");
    }
}

/* ----------- ----------- -------------------------
   Targ        Metrics     Lookup type
   ----------- ----------- -------------------------
   g           m m m m     Single                   g: single glyph
   c           m m m m     Single (range)           c: glyph class (2 or more)
                                                    x: g or c
   g g         m           Pair (specific)
   g c         m           Pair (class)
   c g         m           Pair (class)
   c c         m           Pair (class)

   x x' x x'   m m         Chain ctx (not supported)
   ----------- ----------- -------------------------

   Add a pos rule from the feature file.
    Can assume targ is at least one node. If h->metrics.cnt == 0
   then targ is an "ignore position" pattern. */

static MetricsInfo *getNextMetricsInfoRec(void) {
    return dnaNEXT(h->metricsInfo);
}

static void addBaseClass(GNode *targ, char *defaultClassName) {
    /* Find base node in a possibly contextual sequence, */
    /* and add it to the default base glyph class        */
    GNode *nextNode = targ;

    /* If it is contextual, first find the base glyph */
    if (targ->flags & FEAT_HAS_MARKED) {
        while (nextNode != NULL) {
            if (nextNode->flags & FEAT_IS_BASE_NODE) {
                break;
            }
            nextNode = nextNode->nextSeq;
        }
    }

    if (nextNode->flags & FEAT_IS_BASE_NODE) {
        GNode **gcInsert = gcOpen(defaultClassName);
        if (nextNode->nextCl != NULL) {
            gcInsert = featGlyphClassCopy(g, gcInsert, nextNode);
        } else {
            gcAddGlyph(nextNode->gid);
            gcInsert = h->gcInsert;
        }
    }
}

static void addPos(GNode *targ, int type, int enumerate) {
    int glyphCount = 0;
    int markedCount = 0;
    int lookupLabelCnt = 0;
    GNode *next_targ = NULL;
    GNode *copyHeadNode;

    if (enumerate) {
        targ->flags |= FEAT_ENUMERATE;
    }

    /* count glyphs, figure out if is single, pair, or context. */
    next_targ = targ;
    while (next_targ != NULL) {
        glyphCount++;
        if (next_targ->flags & FEAT_MARKED) {
            markedCount++;
        }
        if (next_targ->lookupLabelCount > 0) {
            lookupLabelCnt++;
            if (!(next_targ->flags & FEAT_MARKED)) {
                featMsg(hotERROR, "the glyph which precedes the 'lookup' keyword must be marked as part of the contextual input sequence");
            }
        }
        next_targ = next_targ->nextSeq;
    }

    /* The ignore statement can only be used with contextual lookups. */
    /* If no glyph is marked, then mark the first.                    */
    if (targ->flags & FEAT_IGNORE_CLAUSE) {
        type = GPOSChain;
        if (markedCount == 0) {
            markedCount = 1;
            targ->flags |= FEAT_MARKED;
        }
    }

    if (markedCount > 0) {
        targ->flags |= FEAT_HAS_MARKED; /* used later to decide if stuff is contextual */
    }
    if ((glyphCount == 2) && (markedCount == 0) && (type == GPOSSingle)) {
        type = GPOSPair;
    } else if (enumerate) {
        featMsg(hotERROR, "\"enumerate\" only allowed with pair positioning,");
    }

    if (type == GPOSSingle) {
        addGPOS(GPOSSingle, targ, INCL.file, zzline, h->anchorMarkInfo.cnt, &h->anchorMarkInfo.array[0]);
        /* These nodes are recycled in GPOS.c */
    } else if (type == GPOSPair) {
        next_targ = targ->nextSeq;
        if (targ->nextCl != NULL) {
            /* In order to sort and remove duplicates, I need to copy the   */
            /* original class definition. This is because class definitions */
            /* may be used for sequences as well as real classes, and       */
            /* sorting and removing duplicates from the original class is a */
            /* bad idea.                                                    */
            featGlyphClassCopy(h->g, &copyHeadNode, targ);
            targ = copyHeadNode;
            featGlyphClassSort(g, &targ, 1, 1);
            targ->nextSeq = next_targ; /* featGlyphClassCopy zeros the  nextSeq field in all nodes.*/
        }
        if (next_targ->nextCl != NULL) {
            /* In order to sort and remove duplicates, I need to copy the    */
            /* original class definition. This is because class definitions  */
            /* may be used for sequences as well as real classes, and        */
            /* sorting and removing duplicates from the original class is a  */
            /* bad idea. */
            featGlyphClassCopy(h->g, &copyHeadNode, next_targ);
            next_targ = copyHeadNode;
            featGlyphClassSort(g, &next_targ, 1, 1);
            targ->nextSeq = next_targ; /* featGlyphClassSort may change which node in the next_targ class is the head node.  */
        }
        /* addGPOSPair(targ, second, enumerate); */
        addGPOS(GPOSPair, targ, INCL.file, zzline, h->anchorMarkInfo.cnt, &h->anchorMarkInfo.array[0]);
        /* These nodes are recycled in GPOS.c due to some complicated copying of nodes. */
    } else if (type == GPOSCursive) {
        if (h->anchorMarkInfo.cnt != 2) {
            featMsg(hotERROR, "The 'cursive' statement requires two anchors. This has %ld. Skipping rule.", h->anchorMarkInfo.cnt);
        } else if ((!(targ->flags & FEAT_HAS_MARKED)) && ((!(targ->flags & FEAT_IS_BASE_NODE)) || (targ->nextSeq != NULL))) {
            featMsg(hotERROR, "This statement has contextual glyphs around the cursive statement, but no glyphs are marked as part of the input sequence. Skipping rule.", h->anchorMarkInfo.cnt);
        } else {
            addGPOS(GPOSCursive, targ, INCL.file, zzline, h->anchorMarkInfo.cnt, &h->anchorMarkInfo.array[0]);
        }
        /* These nodes are recycled in GPOS.c */
    } else if (type == GPOSMarkToBase) {
        addBaseClass(targ, kDEFAULT_BASECLASS_NAME);
        if ((!(targ->flags & FEAT_HAS_MARKED)) && ((!(targ->flags & FEAT_IS_BASE_NODE)) || ((targ->nextSeq != NULL) && (targ->nextSeq->nextSeq != NULL)))) {
            featMsg(hotERROR, "This statement has contextual glyphs around the base-to-mark statement, but no glyphs are marked as part of the input sequence. Skipping rule.", h->anchorMarkInfo.cnt);
        }
        addGPOS(GPOSMarkToBase, targ, INCL.file, zzline, h->anchorMarkInfo.cnt, &h->anchorMarkInfo.array[0]);
        /* These nodes are recycled in GPOS.c */
    } else if (type == GPOSMarkToLigature) {
        addBaseClass(targ, kDEFAULT_LIGATURECLASS_NAME);
        if ((!(targ->flags & FEAT_HAS_MARKED)) && ((!(targ->flags & FEAT_IS_BASE_NODE)) || ((targ->nextSeq != NULL) && (targ->nextSeq->nextSeq != NULL)))) {
            featMsg(hotERROR, "This statement has contextual glyphs around the ligature statement, but no glyphs are marked as part of the input sequence. Skipping rule.", h->anchorMarkInfo.cnt);
        }

        /* With mark to ligatures, we may see the same mark class on         */
        /* different components, which leads to duplicate GID's in the       */
        /* contextual mark node. As a result, we need to sort and get rid of */
        /* duplicates.                                                       */

        if (targ->flags & FEAT_HAS_MARKED) {
            /* find the mark node */
            GNode *markClassNode = targ;
            GNode *prevNode = NULL;

            while (markClassNode != NULL) {
                if (markClassNode->flags & FEAT_IS_MARK_NODE) {
                    break;
                }
                prevNode = markClassNode;
                markClassNode = markClassNode->nextSeq;
            }
            if ((markClassNode != NULL) && (markClassNode->flags & FEAT_IS_MARK_NODE)) {
                featGlyphClassCopy(h->g, &copyHeadNode, markClassNode);
                markClassNode = copyHeadNode;
                featGlyphClassSort(g, &markClassNode, 1, 0); /* changes value of markClassNode. I specify to NOT warn of duplicates, because they can happen with correct syntax. */
                prevNode->nextSeq = markClassNode;
            }
        }

        addGPOS(GPOSMarkToLigature, targ, INCL.file, zzline, h->anchorMarkInfo.cnt, &h->anchorMarkInfo.array[0]);
        /* These nodes are recycled in GPOS.c */
    } else if (type == GPOSMarkToMark) {
        addBaseClass(targ, kDEFAULT_MARKCLASS_NAME);
        if ((!(targ->flags & FEAT_HAS_MARKED)) && ((!(targ->flags & FEAT_IS_BASE_NODE)) || ((targ->nextSeq != NULL) && (targ->nextSeq->nextSeq != NULL)))) {
            featMsg(hotERROR, "This statement has contextual glyphs around the mark-to-mark statement, but no glyphs are marked as part of the input sequence. Skipping rule.", h->anchorMarkInfo.cnt);
        }
        addGPOS(GPOSMarkToMark, targ, INCL.file, zzline, h->anchorMarkInfo.cnt, &h->anchorMarkInfo.array[0]);
        /* These nodes are recycled in GPOS.c */
    } else if (type == GPOSChain) {
        /* is contextual */
        if (markedCount == 0) {
            featMsg(hotERROR, "The 'lookup' keyword can be used only in a contextual statement. At least one glyph in the sequence must be marked. Skipping rule.");
        } else {
            featValidateGPOSChain(g, targ, type);
            addGPOS(GPOSChain, targ, INCL.file, zzline, h->anchorMarkInfo.cnt, &h->anchorMarkInfo.array[0]);
        }
        /* These nodes are recycled in GPOS.c, as they are used in the fill phase, some time after this function returns. */
    } else {
        featMsg(hotERROR, "This rule type is not recognized..");
    }
}

static void setFontRev(char *rev) {
    char *fraction = 0;
    double minor = 0;

    long major = strtol(rev, &fraction, 10);

    if ((fraction != 0) && (strlen(fraction) > 0)) {
        short strLen = strlen(fraction);
        minor = strtod(fraction, NULL);

        if (strLen != 4) {
            double version = major + minor;
            featMsg(hotWARNING, "head FontRevision entry <%s> should have 3 fractional decimal places. Stored as <%.3f>", rev, version);
        }
    } else {
        featMsg(hotWARNING, "head FontRevision entry <%ld> should have 3 fractional decimal places; it now has none.", major);
    }

    /* limit of 32767 as anything higher sets the sign bit to negative */
    major = MIN(major, 32767);

    /* Convert to Fixed */
    g->font.version.otf = (Fixed)((major + minor) * 65536.0);
}

static void checkLkpName(char *name, int linenum, int atStart, int isStandAlone) {
    if (isStandAlone) {
        /* This is a standalone lookup, used outside of a feature block. */
        /* Add it to the dummy feature 'A\0\0A'                           */
        if (atStart) {
            checkTag(TAG_STAND_ALONE, featureTag, atStart);
            checkTag(TAG_STAND_ALONE, scriptTag, atStart);
        } else {
            checkTag(TAG_STAND_ALONE, featureTag, atStart);
        }
    } else {
        if (h->curr.feature == aalt_) {
            if (atStart) {
                featMsg(hotERROR, "\"lookup\" use not allowed in 'aalt' feature");
            }
            return;
        }
        if (h->curr.feature == size_) {
            if (atStart) {
                featMsg(hotERROR,
                        "\"lookup\" use not allowed anymore in 'size'"
                        " feature; " USE_LANGSYS_MSG);
            }
            return;
        }
    }
    if (atStart) {
        NamedLkp *new;

        DF(2, (stderr, "# at start of named lookup %s\n", name));
        if (name2NamedLkp(name) != NULL) {
            featMsg(hotFATAL, "lookup name \"%s\" already defined", name);
        }

        h->currNamedLkp = getNextNamedLkpLabel();

        /* Store in named lookup array */
        new = dnaNEXT(h->namedLkp);
        new->useExtension = 0;
        copyStr(g, &new->name, name);
        /* State will be recorded at end of block section, below */
    } else {
        NamedLkp *curr = lab2NamedLkp(h->currNamedLkp);

        DF(2, (stderr, "# at end of named lookup %s\n", name));
        if (curr == NULL) {
            hotMsg(g, hotFATAL, "[internal] label not found\n");
        }
        if (strcmp(curr->name, name) != 0) {
            zzerr("doesn't match starting label of block");
        }

        /* Store state for future lookup references to it */
        curr->state = h->curr;

        h->currNamedLkp = LAB_UNDEF;
        h->endOfNamedLkpOrRef = 1;
    }
}

/* Include dflt rules in lang-specific behavior if includeDFLT != 0 */

static void includeDFLT(int includeDFLT, int langChange, int seenOldDFLT) {
    if (seenOldDFLT && (!h->seenOldDFLT)) {
        h->seenOldDFLT = 1;
        featMsg(hotWARNING, "Use of includeDFLT and excludeDFLT tags has been deprecated. It will work, but please use 'include_dflt' and 'exclude_dflt' tags instead.");
    }
    /* Set value */
    if (langChange) {
        h->include_dflt = includeDFLT;
    } else if (includeDFLT != h->include_dflt) {
        zzerr(
            "can't change whether a language should include dflt rules once "
            "this has already been indicated");
    }

    if (includeDFLT) {
        /* Include dflt rules for current script and explicit language    */
        /* statement. Languages which don't exclude_dflt get the feature- */
        /* level defaults at the end of the feature.                      */
        long i;

        for (i = 0; i < h->DFLTLkps.cnt; i++) {
            State *st = &h->DFLTLkps.array[i];
            callLkp(st);
        }
    } else {
        /* Defaults have been explicitly excluded from the this language.  */
        /* Find the matching  script-lang lang-sys, and set the flag so it */
        /* won't add the feature level defaults at the end of the feature. */
        int i;

        for (i = 0; i < h->langSys.cnt; i++) {
            LangSys *curLangSys = &h->langSys.array[i];
            if (curLangSys->script == h->curr.script && curLangSys->lang == h->curr.language) {
                curLangSys->excludeDflt = 1;
                break;
            }
        } /* end for all lang sys */
    }
}
