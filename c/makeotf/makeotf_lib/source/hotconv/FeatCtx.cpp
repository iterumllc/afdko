
#include "antlr4-runtime.h"
#include <algorithm>
#include "assert.h"
#include <iostream>
#include <memory>
#include "string.h"

#include "FeatCtx.h"
#include "FeatVisitor.h"
#include "FeatParser.h"
#include "otl.h"
#include "GPOS.h"
#include "GSUB.h"
#include "GDEF.h"
#include "OS_2.h"
#include "BASE.h"
#include "STAT.h"
#include "name.h"

#define kDEFAULT_BASECLASS_NAME "FDK_BASE_CLASS"
#define kDEFAULT_LIGATURECLASS_NAME "FDK_LIGATURE_CLASS"
#define kDEFAULT_MARKCLASS_NAME "FDK_DEFAULT_MARK_CLASS"
#define kDEFAULT_COMPONENTCLASS_NAME "FDK_DEFAULT_COMPONENT_CLASS"

const int MAX_NUM_LEN {3};        // For glyph ranges
const int kMaxCodePageValue {32};
const int kCodePageUnSet {-1};
const int AALT_INDEX {-1};        // used as feature index for sorting alt glyphs in rule for aalt feature

#define USE_LANGSYS_MSG                                                   \
    "use \"languagesystem\" statement(s) at beginning of file instead to" \
    " specify the language system(s) this feature should be registered under"

FeatCtx::FeatCtx(hotCtx gc) : g{gc} {
    memset(&cvParameters, 0, sizeof(cvParameters));
    dnaINIT(g->DnaCTX, cvParameters.charValues, 10, 10);
}

FeatCtx::~FeatCtx() {
    // delete all the file vistors including the root visitor
    for (auto &vit: visitors)
        delete vit.second;
    dnaFREE(cvParameters.charValues);
}

void FeatCtx::fill(void) {
    char *featpathname = g->cb.featTopLevelFile(g->cb.ctx);
    if ( featpathname == nullptr )
        return;

    FeatVisitor *fv = new FeatVisitor(this, strdup(featpathname));
    if ( fv->ParseAndRegister(true) )
        fv->Translate();
    // hotMsg(g, hotFATAL, "Translation of %s finished \n", featpathname);
    return;
}

Tag FeatCtx::str2tag(const std::string &tagName) {
    if ( tagName == "dflt" ) {
        return dflt_;
    } else {
        int i;
        char buf[4];
        strncpy(buf, tagName.c_str(), 4);
        for (i = 3; buf[i] == '\0'; i--)
            buf[i] = ' ';
        return TAG(buf[0], buf[1], buf[2], buf[3]);
    }
}

void FeatCtx::closeFeatScriptLang(State &st) {
    if ( st.tbl == TAG_UNDEF )
        return;

    if ( st.tbl == GSUB_) {
        if ( st.lkpType != 0 )
            GSUBLookupEnd(g, st.feature);
        GSUBFeatureEnd(g);
    } else if ( st.tbl == GPOS_) {
        if ( st.lkpType != 0 )
            GPOSLookupEnd(g, st.feature);
        GPOSFeatureEnd(g);
    }
}

/* Add Unicode and CodePage ranges to  OS/2 table. */
/* ------------------------------------------------------------------- */
/* ------------------------------------------------------------------- */
#define SET_BIT_ARR(a, b) (a[(b) / 32] |= 1UL << (b) % 32)

const short kValidCodePageNumbers[kLenCodePageList] = {
    1252,           /*  bit 0  Latin 1 */
    1250,           /*  bit 1  Latin 2: Eastern Europe */
    1251,           /*  bit 2  Cyrillic */
    1253,           /*  bit 3  Greek */
    1254,           /*  bit 4  Turkish */
    1255,           /*  bit 5  Hebrew */
    1256,           /*  bit 6  Arabic */
    1257,           /*  bit 7  Windows Baltic */
    1258,           /*  bit 8  Vietnamese */
    kCodePageUnSet, /*  bit 9  Reserved for Alternate ANSI */
    kCodePageUnSet, /*  bit 10  Reserved for Alternate ANSI */
    kCodePageUnSet, /*  bit 11  Reserved for Alternate ANSI */
    kCodePageUnSet, /*  bit 12  Reserved for Alternate ANSI */
    kCodePageUnSet, /*  bit 13  Reserved for Alternate ANSI */
    kCodePageUnSet, /*  bit 14 Reserved for Alternate ANSI */
    kCodePageUnSet, /*  bit 15  Reserved for Alternate ANSI */
    874,            /*  bit 16  Thai */
    932,            /*  bit 17  JIS/Japan */
    936,            /*  bit 18  Chinese: Simplified chars--PRC and Singapore */
    949,            /*  bit 19  Korean Wansung */
    950,            /*  bit 20  Chinese: Traditional chars--Taiwan and Hong Kong */
    1361,           /*  bit 21  Korean Johab */
    kCodePageUnSet, /*  bit 22-28  Reserved for Alternate ANSI & OEM */
    kCodePageUnSet, /*  bit 23  Reserved for Alternate ANSI & OEM */
    kCodePageUnSet, /*  bit 24  Reserved for Alternate ANSI & OEM */
    kCodePageUnSet, /*  bit 25  Reserved for Alternate ANSI & OEM */
    kCodePageUnSet, /*  bit 26  Reserved for Alternate ANSI & OEM */
    kCodePageUnSet, /*  bit 27  Reserved for Alternate ANSI & OEM */
    kCodePageUnSet, /*  bit 28  Reserved for Alternate ANSI & OEM */
    kCodePageUnSet, /*  bit 29  Macintosh Character Set (US Roman) */
    kCodePageUnSet, /*  bit 30  OEM Character Set */
    kCodePageUnSet, /*  bit 31  Symbol Character Set */
    kCodePageUnSet, /*  bit 32  Reserved for OEM */
    kCodePageUnSet, /*  bit 33  Reserved for OEM */
    kCodePageUnSet, /*  bit 34  Reserved for OEM */
    kCodePageUnSet, /*  bit 35  Reserved for OEM */
    kCodePageUnSet, /*  bit 36  Reserved for OEM */
    kCodePageUnSet, /*  bit 37  Reserved for OEM */
    kCodePageUnSet, /*  bit 38  Reserved for OEM */
    kCodePageUnSet, /*  bit 39  Reserved for OEM */
    kCodePageUnSet, /*  bit 40  Reserved for OEM */
    kCodePageUnSet, /*  bit 41  Reserved for OEM */
    kCodePageUnSet, /*  bit 42  Reserved for OEM */
    kCodePageUnSet, /*  bit 43  Reserved for OEM */
    kCodePageUnSet, /*  bit 44  Reserved for OEM */
    kCodePageUnSet, /*  bit 45  Reserved for OEM */
    kCodePageUnSet, /*  bit 46  Reserved for OEM */
    kCodePageUnSet, /*  bit 47  Reserved for OEM */
    869,            /*  bit 48  IBM Greek */
    866,            /*  bit 49  MS-DOS Russian */
    865,            /*  bit 50  MS-DOS Nordic */
    864,            /*  bit 51  Arabic */
    863,            /*  bit 52  MS-DOS Canadian French */
    862,            /*  bit 53  Hebrew */
    861,            /*  bit 54  MS-DOS Icelandic */
    860,            /*  bit 55  MS-DOS Portuguese */
    857,            /*  bit 56  IBM Turkish */
    855,            /*  bit 57  IBM Cyrillic; primarily Russian */
    852,            /*  bit 58  Latin 2 */
    775,            /*  bit 59  MS-DOS Baltic */
    737,            /*  bit 60  Greek; former 437 G */
    708,            /*  bit 61  Arabic; ASMO 708 */
    850,            /*  bit 62  WE/Latin 1 */
    437,            /*  bit 63  US */
};

static int validateCodePage(short pageNum) {
    int validPageBitIndex = kCodePageUnSet;

    for (int i = 0; i < kLenCodePageList; i++) {
        if (pageNum == kValidCodePageNumbers[i]) {
            validPageBitIndex = i;
            break;
        }
    }

    return validPageBitIndex;
}

void FeatCtx::setUnicodeRange(short unicodeList[kLenUnicodeList]) {
    unsigned long unicodeRange[4] { 0, 0, 0, 0 };
    short i = 0;

    while (i < kLenUnicodeList) {
        short bitnum = unicodeList[i];

        if (bitnum != kCodePageUnSet) {
            if ((bitnum >= 0) && (bitnum < kLenUnicodeList)) {
                SET_BIT_ARR(unicodeRange, bitnum);
            } else {
                ; // XXX featMsg(hotERROR, "OS/2 Bad Unicode block value <%d>. All values must be in [0 ...127] inclusive.", bitnum);
            }
        } else {
            break;
        }
        i++;
    }

    OS_2SetUnicodeRanges(g, unicodeRange[0], unicodeRange[1],
                         unicodeRange[2], unicodeRange[3]);
}

void FeatCtx::setCodePageRange(short codePageList[kLenCodePageList]) {
    unsigned long codePageRange[2] { 0, 0 };
    short validPageBitIndex;
    int i = 0;

    while (i < kLenCodePageList) {
        short pageNumber = codePageList[i];

        if (pageNumber != kCodePageUnSet) {
            validPageBitIndex = validateCodePage(pageNumber);
            if (validPageBitIndex != kCodePageUnSet) {
                SET_BIT_ARR(codePageRange, validPageBitIndex);
            } else {
                ; // XXX featMsg(hotERROR, "OS/2 Code page value <%d> is not permitted according to the OpenType spec v1.4.", pageNumber);
            }
        } else {
            break;
        }

        i++;
    }

    OS_2SetCodePageRanges(g, codePageRange[0], codePageRange[1]);
}

void FeatCtx::addBlock() {
    auto &bl = blockList;
    if (bl.first == nullptr) {
        /* Initial allocation */
        bl.first = bl.curr = (BlockNode *) MEM_NEW(g, sizeof(BlockNode));
        bl.curr->data = (GNode *) MEM_NEW(g, sizeof(GNode) * bl.intl);
    } else {
        /* Incremental allocation */
        bl.curr->next = (BlockNode *) MEM_NEW(g, sizeof(BlockNode));
        bl.curr = bl.curr->next;
        bl.curr->data = (GNode *) MEM_NEW(g, sizeof(GNode) * bl.incr);
    }
    bl.curr->next = nullptr;
    bl.cnt = 0;
}

void FeatCtx::freeBlocks() {
    BlockNode *p, *pNext;

    for (p = blockList.first; p != nullptr; p = pNext) {
        pNext = p->next;
        MEM_FREE(g, p->data);
        MEM_FREE(g, p);
    }
}

GNode *FeatCtx::newNodeFromBlock() {
    auto &bl = blockList;
    if ( bl.first == nullptr || bl.cnt == (bl.curr==bl.first ? bl.intl : bl.incr) )
        addBlock();
    return bl.curr->data + bl.cnt++;
}

bool FeatCtx::LangSys::operator<(const FeatCtx::LangSys &b) const {
    return std::tie(script, lang) < std::tie(b.script, b.lang);
}

bool FeatCtx::LangSys::operator==(const FeatCtx::LangSys &b) const {
    return std::tie(script, lang) == std::tie(b.script, b.lang);
}

bool FeatCtx::State::operator==(const FeatCtx::State &b) const {
    return memcmp(this, &b, sizeof(State))==0;
}

bool FeatCtx::AnchorDef::operator<(const FeatCtx::AnchorDef &b) const {
    return name < b.name;
}

bool FeatCtx::ValueDef::operator<(const FeatCtx::ValueDef &b) const {
    return name < b.name;
}

bool FeatCtx::AALT::FeatureRecord::operator==(const FeatCtx::AALT::FeatureRecord &b) const {
    return feature == b.feature;
}

bool FeatCtx::AALT::FeatureRecord::operator==(const Tag &b) const {
    return feature == b;
}

/* Register current feature under remaining language systems */

void FeatCtx::registerFeatureLangSys() {
    for (auto &ls : langSysSet) {
        bool seenGSUB = false, seenGPOS = false;

        /* If we have seen an explicit language statement for this script, */
        /* then the default lookups have already been included ( or        */
        /* excluded) by the includeDDflt function.                         */
        if (ls.excludeDflt) {
            // XXX ls.excludeDflt = false; /* Clear this so it won't affect the next feature */
            continue;
        }

        for (const auto &lkp : lookup) {
            if (lkp.tbl == GSUB_) {
                if (!seenGSUB) {
                    GSUBFeatureBegin(g, ls.script, ls.lang, curr.feature);
                    seenGSUB = 1;
                }
                GSUBLookupBegin(g, lkp.lkpType, lkp.lkpFlag,
                                (Label)(lkp.label | REF_LAB),
                                lkp.useExtension, lkp.markSetIndex);
                GSUBLookupEnd(g, curr.feature);
            } else {
                /* lkp->tbl == GPOS_ */
                if (!seenGPOS) {
                    GPOSFeatureBegin(g, ls.script, ls.lang, curr.feature);
                    seenGPOS = true;
                }
                GPOSLookupBegin(g, lkp.lkpType, lkp.lkpFlag,
                                (Label)(lkp.label | REF_LAB),
                                lkp.useExtension, lkp.markSetIndex);
                GPOSLookupEnd(g, curr.feature);
            }
        }
        if (seenGSUB) {
            GSUBFeatureEnd(g);
        }
        if (seenGPOS) {
            GPOSFeatureEnd(g);
        }
    }
}

void FeatCtx::startFeature(Tag tag) {
    /* Allow interleaving features */
    if (! tagAssign(tag, featureTag, true)) {
        if (tag != TAG_STAND_ALONE) {
            /* This is normal for standalone lookup blocks- we use the same feature tag for each. */
            ; // XXX featMsg(hotWARNING, "feature already defined: %s", zzlextext);
        }
    }

    fFlags = 0;
    gFlags |= seenFeature;

    lookup.clear();
    script.clear();
    if (langSysSet.size() == 0) {
        addLangSys(DFLT_, dflt_, false);
        ; /* XXX featMsg(hotWARNING,
                "[internal] Feature block seen before any language system statement. You should place languagesystem statements before any feature definition", zzlextext); */
    }
    tagAssign(langSysSet.begin()->script, scriptTag, false);

    language.clear();
    tagAssign(langSysSet.begin()->lang, languageTag, false);

    include_dflt = true;
    DFLTLkps.clear();

    curr.lkpFlag = 0;
    curr.markSetIndex = 0;
}

void FeatCtx::endFeature() {
    if ( curr.feature != aalt_ ) {
        closeFeatScriptLang(curr);
        registerFeatureLangSys();
        prev.tbl = TAG_UNDEF;
    }
}

int FeatCtx::startScriptOrLang(TagType type, Tag tag) {
    if (curr.feature == aalt_ || curr.feature == size_) {
        ; /* XXX featMsg(hotERROR,
                "\"script\" and \"language\" statements "
                "are not allowed in 'aalt' or 'size' features; " USE_LANGSYS_MSG); */
        return -1;
    } else if ((tag != TAG_STAND_ALONE) && (curr.feature == TAG_STAND_ALONE)) {
        ; /* XXX featMsg(hotERROR,
                "\"script\" and \"language\" statements "
                "are not allowed within standalone lookup blocks; "); */
    }
    /*
    if (h->fFlags & FF_LANGSYS_MODE) {
        featMsg(hotWARNING,
                "If you don't want feature '%c%c%c%c' registered under all"
                " the language systems you specified earlier on in the feature"
                " file by the \"languagesystem\" keyword, you must start this"
                " feature with an explicit \"script\" statement",
                TAG_ARG(h->curr.feature));
        return -1;
    }
    */
    fFlags |= seenScriptLang;

    if (type == scriptTag) {
        if (tag == curr.script && curr.language == dflt_)
            return 0;

        /* Once we have seen a script or a language statement other  */
        /* than 'dflt' any further rules in the feature should not   */
        /* be added to the default list.                             */
        fFlags &= ~langSysMode;

        if (tag != curr.script) {
            if (!tagAssign(tag, scriptTag, true))
                ; // zzerr("script behavior already specified");

            language.clear();
            DFLTLkps.clear(); /* reset the script-specific default list to 0 */
        }
        if (curr.language != dflt_)
            tagAssign(dflt_, languageTag, false);

        include_dflt = true;
        curr.lkpFlag = 0;
        curr.markSetIndex = 0;
    } else {
        assert( type == languageTag );
        if (tag == DFLT_) {
            tag = dflt_;
            ; // XXX featMsg(hotWARNING, "'DFLT' is not a valid tag for a language statement; using 'dflt'.");
        }

        /* Once we have seen a script or a language statement other */
        /* than 'dflt' any further rules in the feature should not  */
        /* be added to the default list.                            */
        if ((fFlags & langSysMode) && (tag != dflt_))
            fFlags &= ~langSysMode;

        if (tag == curr.language)
            return 0; /* Statement has no effect */

        if (tag == dflt_)
            ; // XXX zzerr("dflt must precede language-specific behavior");

        if ( !tagAssign(tag, languageTag, true) )
            ; // XXX zzerr("language-specific behavior already specified");
    }
    return 1;
}

void FeatCtx::startTable(Tag tag) {
    if ( !tagAssign(tag, tableTag, true) )
        ; // XXX zzerr("table already specified");
}

void FeatCtx::dumpGlyph(GID gid, int ch, bool print) {
    char msg[512];
    int len;
    if (IS_CID(g)) {
        sprintf(msg, "\\%hd", mapGID2CID(gid));
    } else {
        mapGID2Name(g, gid, msg);
    }
    len = strlen(msg);
    if (ch >= 0) {
        msg[len++] = ch;
    }

    if (print) {
        msg[len++] = '\0';
        fprintf(stderr, "%s", msg);
    } else {
        strncpy(dnaEXTEND(g->note, len), msg, len);
    }
}

#define DUMP_CH(ch, print)             \
    do {                               \
        if (print)                     \
            fprintf(stderr, "%c", ch); \
        else                           \
            *dnaNEXT(g->note) = (ch);  \
    } while (0)

/* If !print, add to g->notes */

void FeatCtx::dumpGlyphClass(GNode *gc, int ch, bool print) {
    GNode *p = gc;

    DUMP_CH('[', print);
    for (; p != NULL; p = p->nextCl) {
        dumpGlyph(p->gid, (char)(p->nextCl != NULL ? ' ' : -1), print);
    }
    DUMP_CH(']', print);
    if (ch >= 0) {
        DUMP_CH(ch, print);
    }
}

/* If !print, add to g->notes */

void FeatCtx::dumpPattern(GNode *pat, int ch, bool print) {
    DUMP_CH('{', print);
    for (; pat != NULL; pat = pat->nextSeq) {
        if (pat->nextCl == NULL) {
            dumpGlyph(pat->gid, -1, print);
        } else {
            dumpGlyphClass(pat, -1, print);
        }
        if (pat->flags & FEAT_MARKED) {
            DUMP_CH('\'', print);
        }
        if (pat->nextSeq != NULL) {
            DUMP_CH(' ', print);
        }
    }
    DUMP_CH('}', print);
    if (ch >= 0) {
        DUMP_CH(ch, print);
    }
}

/* ------------------------------ aalt creation ---------------------------- */

void FeatCtx::aaltAddFeatureTag(Tag tag) {
    if (curr.feature != aalt_) {
        ; // XXX featMsg(hotERROR, "\"feature\" statement allowed only in 'aalt' feature");
    } else if ( tag != aalt_ ) {
        AALT::FeatureRecord t { curr.feature, true };
        auto it = std::find(aalt.features.begin(), aalt.features.end(), t);
        if ( it == aalt.features.end() )
            aalt.features.push_back(t);
    }
}

void FeatCtx::reportUnusedaaltTags() {
    for (auto &f : aalt.features) {
        if ( !f.used ) {
            hotMsg(g, hotWARNING, // XXX
                   "feature '%c%c%c%c', referenced in aalt feature, either is not defined or had no rules which could be included in the aalt feature.",
                   TAG_ARG(f.feature));
        }
    }
}

/* For the alternate glyphs in a  GSUBAlternate rule, sort them */
/* in the order of the GNode aaltIndex field, aka the order that */
/* the features were named in the aalt definition. Alts that are */
/* explicitly defined in the aalt feature have an index of -1. */
/* See aaltAddAlternates. */
void FeatCtx::aaltRuleSort(GNode **list) {
    unsigned int i;
    GNode *p = *list;
    short flags = (*list)->flags;

    /* Copy over pointers */
    std::vector<GNode *> sortTmp;

    for (; p != NULL; p = p->nextCl)
        sortTmp.push_back(p);

    struct {
        bool operator()(GNode *a, GNode *b) const { return a->aaltIndex < b->aaltIndex; }
    } cmpNode;
    std::sort(sortTmp.begin(), sortTmp.end(), cmpNode);

    /* Move pointers around */
    for (i = 0; i < sortTmp.size() - 1; i++)
        sortTmp[i]->nextCl = sortTmp[i + 1];
    sortTmp[i]->nextCl = NULL;

    *list = sortTmp[0];

    (*list)->flags = flags;
}

/* If gid not in cl, return address of end insertion point, else NULL */

static int glyphInClass(GID gid, GNode **cl, GNode ***lastClass) {
    GNode **p = cl;

    for (p = cl; *p != NULL; p = &((*p)->nextCl)) {
        if ((*p)->gid == gid) {
            *lastClass = p;
            return 1;
        }
    }

    *lastClass = p;
    return 0;
}

/* Input GNodes will be copied. Ranges of 1-1, single 1-1, or 1 from n. (Only
   first glyph position in targ will be looked at)  */
/* The aaltIndex is set to non-zero here in order to facilitate later sorting */
/* of the target glyph alternates, by the order that the current feature file is */
/* named in the aalt feature. If the alt glyph is defined explicitly in the */
/* aalt feature, via a 'sub' directive, it gets an index of AALT_INDEX, aka, -1, */
/* so that it will sort before all the alts from included features. */

void FeatCtx::aaltAddAlternates(GNode *targ, GNode *repl) {
    bool range = targ->nextCl != nullptr;

    /* Duplicate repl if a single glyph: */
    if ( targ->nextCl != nullptr && repl->nextCl == nullptr )
        extendNodeToClass(repl, getGlyphClassCount(targ) - 1);

    for (; targ != nullptr; targ = targ->nextCl, repl = repl->nextCl) {
        GNode *replace;

        /* Start new accumulator for targ->gid, if it doesn't already exist */
        auto ru = aalt.rules.find(targ->gid);
        if ( ru == aalt.rules.end() ) {
            GNode *t = setNewNode(targ->gid);
            aalt.rules.insert(std::make_pair(targ->gid, AALT::RuleInfo{ t, nullptr }));
            ru = aalt.rules.find(targ->gid);
        }

        auto ri = ru->second;
        /* Add alternates to alt set,                 */
        /* checking for uniqueness & preserving order */
        replace = repl;
        for (; replace != nullptr; replace = range ? nullptr : replace->nextCl) {
            GNode **lastClass;
            GNode *p;

            auto it = std::find(aalt.features.begin(), aalt.features.end(), curr.feature);
            assert( it != aalt.features.end() );

            if (glyphInClass(replace->gid, &ri.repl, &lastClass)) {
                short aaltTagIndex;

                aaltTagIndex = it - aalt.features.begin();
                p = *lastClass;

                if ( aaltTagIndex < p->aaltIndex ) {
                    p->aaltIndex = aaltTagIndex;
                }
            } else {
                *lastClass = setNewNode(replace->gid);
                p = *lastClass;

                if (curr.feature == aalt_) {
                    p->aaltIndex = AALT_INDEX;
                } else {
                    p->aaltIndex = it - aalt.features.begin();
                }
            }
        }
    }
}

/* Create aalt at end of feature file processing */

void FeatCtx::aaltCreate() {
#if HOT_DEBUG
    long nInterSingleRules = 0;       /* Rules that interact with the alt rules; i.e. */
                                      /* its repl GID == an alt rule's targ GID       */
#endif
    Label labelSingle = LAB_UNDEF;    /* Init to suppress compiler warning */
    Label labelAlternate = LAB_UNDEF; /* Init to Suppress compiler warning */

    if (aalt.rules.size() == 0) {
        return;
    }

    // Create and sort a vector of RuleInfo pointers into the aalt.rules map
    // (the latter must not be altered during this function)
    std::vector<AALT::RuleInfo *> sortTmp;
    sortTmp.reserve(aalt.rules.size());
    for (auto ru : aalt.rules)
        sortTmp.push_back(&ru.second);

    /* Sort single subs before alt subs, sort alt subs by targ GID */
    struct {
        bool operator()(AALT::RuleInfo *aa, AALT::RuleInfo *bb) const {
            GNode *a = aa->repl, *b = bb->repl;

            /* Sort single sub rules before alt sub rules */
            if (is_glyph(a) && is_mult_class(b)) {
                return true;
            } else if (is_mult_class(a) && is_glyph(b)) {
                return false;
            } else if (is_mult_class(a) && is_mult_class(b)) {
                /* Sort alt sub rules by targ GID XXX not sure this is required now */
                return aa->targ->gid < bb->targ->gid;
            } else {
                return a->gid < b->gid; // Just for sake of determinism
            }
        }
    } cmpNode;
    std::sort(sortTmp.begin(), sortTmp.end(), cmpNode);

    auto single_end = sortTmp.begin();
    while ( single_end != sortTmp.end() && is_glyph((*single_end)->repl) )
        single_end++;

    if ( single_end != sortTmp.begin() && single_end != sortTmp.end()) {
        /* If the repl GID of a SingleSub rule is the same as an AltSub    */
        /* rule's targ GID, then the SingleSub rule sinks to the bottom of */
        /* the SingleSub rules, and becomes part of the AltSub rules       */
        /* section:                                                        */
        for (auto si = sortTmp.begin(); si != single_end; si++) {
            auto search = aalt.rules.find((*si)->repl->gid);
            if ( search != aalt.rules.end() && is_mult_class(search->second.repl) ) {
                single_end--;
                if ( si != single_end ) {
                    AALT::RuleInfo *tmp = *single_end;
                    *single_end = *si;
                    *si = tmp;
                }
#if HOT_DEBUG
                nInterSingleRules++;
#endif
            }
        }
#if HOT_DEBUG
        if (nInterSingleRules) {
            DF(1, (stderr,
                   "# aalt: %ld SingleSub rule%s moved to AltSub "
                   "lookup to prevent lookup interaction\n",
                   nInterSingleRules,
                   nInterSingleRules == 1 ? "" : "s"));
        }
#endif
    }

    /* Add default lang sys if none specified */
    if (langSysSet.size() == 0) {
        addLangSys(DFLT_, dflt_, false);
        if (fFlags & langSysMode) {
            hotMsg(g, hotWARNING, "[internal] aalt language system unspecified");
        }
    }

    GSUBFeatureBegin(g, langSysSet.begin()->script, langSysSet.begin()->lang, aalt_);

    /* --- Feed in single subs --- */
    if (sortTmp.begin() != single_end) {
        labelSingle = getNextAnonLabel();
        GSUBLookupBegin(g, GSUBSingle, 0, labelSingle, aalt.useExtension, 0);
        for (auto i = sortTmp.begin(); i != single_end; i++) {
            GSUBRuleAdd(g, (*i)->targ, (*i)->repl);
        }
        GSUBLookupEnd(g, aalt_);
    }

    /* --- Feed in alt subs --- */
    if (single_end != sortTmp.end()) {
        labelAlternate = getNextAnonLabel();
        GSUBLookupBegin(g, GSUBAlternate, 0, labelAlternate, aalt.useExtension, 0);
        for (auto i = single_end; i != sortTmp.end(); i++) {
            aaltRuleSort(&(*i)->repl); // sort alts in order of feature def
                                       // in aalt feature
            GSUBRuleAdd(g, (*i)->targ, (*i)->repl);
        }
        GSUBLookupEnd(g, aalt_);
    }

    GSUBFeatureEnd(g);

    /* Also register these lookups under any other lang systems, if needed: */
    for (auto ls = langSysSet.begin(); ls != langSysSet.end(); ls++) {
        if ( ls == langSysSet.begin() )
            continue;

        GSUBFeatureBegin(g, ls->script, ls->lang, aalt_);

        if (sortTmp.begin() != single_end) {
            GSUBLookupBegin(g, GSUBSingle, 0, (Label)(labelSingle | REF_LAB),
                            aalt.useExtension, 0);
            GSUBLookupEnd(g, aalt_);
        }
        if (single_end != sortTmp.end()) {
            GSUBLookupBegin(g, GSUBAlternate, 0,
                            (Label)(labelAlternate | REF_LAB),
                            aalt.useExtension, 0);
            GSUBLookupEnd(g, aalt_);
        }

        GSUBFeatureEnd(g);
    }
}

void FeatCtx::storeRuleInfo(GNode *targ, GNode *repl) {
    if (curr.tbl == GPOS_ || repl == NULL) {
        return; /* No GPOS or except clauses */
    }
    AALT::FeatureRecord t { curr.feature, false };
    auto f = std::find(aalt.features.begin(), aalt.features.end(), t);
    if ( curr.feature == aalt_ || f != aalt.features.end() ) {
        /* Now check if lkpType is appropriate */

        switch (curr.lkpType) {
            case GSUBSingle:
            case GSUBAlternate:
                break;

            case GSUBChain:
                /* Go to first marked glyph (guaranteed to be present) */
                for (; !(targ->flags & FEAT_MARKED); targ = targ->nextSeq) {
                }
                if (targ->nextSeq != NULL && targ->nextSeq->flags & FEAT_MARKED) {
                    return; /* Ligature sub-substitution */
                }
                break;

            default:
                return;
        }

        if (curr.feature != aalt_) {
            assert( f != aalt.features.end() );
            f->used = true;
        }
        aaltAddAlternates(targ, repl);
    }
}

#if HOT_DEBUG

void FeatCtx::nodeStats() {
    BlockNode *p;
    auto &bl = blockList;

    fprintf(stderr,
            "### GNode Stats\n"
            "nAdded2FreeList: %ld, "
            "nNewFromBlockList: %ld, "
            "nNewFromFreeList: %ld.\n",
            nAdded2FreeList, nNewFromBlockList, nNewFromFreeList);
    fprintf(stderr, "%ld not freed\n",
            nNewFromBlockList + nNewFromFreeList - nAdded2FreeList);

    fprintf(stderr, "### BlockList:");

    for (p = bl.first; p != NULL; p = p->next) {
        long blSize = p == bl.first ? bl.intl : bl.incr;
        if (p->next != NULL) {
            fprintf(stderr, " %ld ->", blSize);
        } else {
            fprintf(stderr, " %ld/%ld\n", bl.cnt, blSize);
        }
    }
}

void FeatCtx::tagDump(Tag tag) {
    if (tag == TAG_UNDEF) {
        fprintf(stderr, "****");
    } else {
        fprintf(stderr, "%c%c%c%c", TAG_ARG(tag));
    }
}

void FeatCtx::stateDump(State &st) {
    fprintf(stderr, "scr='");
    tagDump(st.script);
    fprintf(stderr, "' lan='");
    tagDump(st.language);
    fprintf(stderr, "' fea='");
    tagDump(st.feature);
    fprintf(stderr, "' tbl='");
    tagDump(st.tbl);
    fprintf(stderr, "' lkpTyp=%d lkpFlg=%d label=%X\n",
            st.lkpType, st.lkpFlag, st.label);
}

#endif /* HOT_DEBUG */

/* Returns a glyph node, uninitialized except for flags */
void FeatCtx::initAnchor(AnchorMarkInfo *anchor) {
    anchor->x = 0;
    anchor->y = 0;
    anchor->contourpoint = 0;
    anchor->format = 0;
    anchor->markClass = NULL;
    anchor->markClassIndex = 0;
    anchor->componentIndex = 0;
    return;
}

// Returns a glyph node, uninitialized except for flags
GNode *FeatCtx::newNode() {
    GNode *ret;
    if (freelist != NULL) {
#if HOT_DEBUG
        h->nNewFromFreeList++;
#endif
        /* Return first item from freelist */
        ret = freelist;
        freelist = freelist->nextSeq;
    } else {
        /* Return new item from da */
#if HOT_DEBUG
        nNewFromBlockList++;
#endif
        ret = newNodeFromBlock();
    }

    ret->flags = 0;
    ret->nextSeq = NULL;
    ret->nextCl = NULL;
    ret->lookupLabelCount = 0;
    ret->metricsInfo = NULL;
    ret->aaltIndex = 0;
    ret->markClassName = NULL;
    initAnchor(&ret->markClassAnchorInfo);
    return ret;
}

GNode *FeatCtx::setNewNode(GID gid) {
    GNode *n = newNode();
    n->gid = gid;
    return n;
}

/* Gets length of pattern sequence (ignores any classes) */
unsigned int FeatCtx::getPatternLen(GNode *pat) {
    unsigned int len = 0;
    for (; pat != NULL; pat = pat->nextSeq) {
        len++;
    }
    return len;
}

/* Duplicates node (copies GID) num times to create a class */
void FeatCtx::extendNodeToClass(GNode *node, int num) {
    if (node->nextCl != NULL) {
        hotMsg(g, hotFATAL, "[internal] can't extend glyph class"); // XXX
    }

    if (!(node->flags & FEAT_GCLASS)) {
        node->flags |= FEAT_GCLASS;
    }

    for (int i = 0; i < num; i++) {
        node->nextCl = setNewNode(node->gid);
        node = node->nextCl;
    }
}

/* Return address of last nextCl. Preserves everything */
/* but sets nextSeq of each copied GNode to NULL       */
GNode **FeatCtx::copyGlyphClass(GNode **dst, GNode *src) {
    GNode **newDst = dst;
    for (; src != NULL; src = src->nextCl) {
        *newDst = newNode();
        **newDst = *src;
        (*newDst)->nextSeq = NULL;
        newDst = &(*newDst)->nextCl;
    }
    return newDst;
}

/* Make a copy of src pattern. If num != -1, copy up to num nodes only       */
/* (assumes they exist); set the last nextSeq to NULL. Preserves all flags. */
/* Return address of last nextSeq (so that client may add on to the end).   */

GNode **FeatCtx::copyPattern(GNode **dst, GNode *src, int num) {
    int i = 0;

    for (; (num == -1) ? src != NULL : i < num; i++, src = src->nextSeq) {
        copyGlyphClass(dst, src);
        dst = &(*dst)->nextSeq;
    }
    return dst;
}

#if HOT_DEBUG

void FeatCtx::checkFreeNode(GNode *node) {
    GNode *testNode = freelist;
    long cnt = 0;
    while ( testNode != NULL ) {
        if ( testNode == node )
            printf("Node duplication in free list %lu. gid: %d!\n", (unsigned long)node, node->gid);
        testNode = testNode->nextSeq;
        cnt++;
        if ( cnt > nAdded2FreeList ) {
            printf("Endless loop in checkFreeList.\n");
            break;
        }
    }
}

#endif

/* Add node to freelist (Insert at beginning) */

void FeatCtx::recycleNode(GNode *node) {
#if HOT_DEBUG
    nAdded2FreeList++;
#endif
#if HOT_DEBUG
    checkFreeNode(node);
#endif
    node->nextSeq = freelist;
    freelist = node;
}

#define ITERATIONLIMIT 100000

/* Add nodes to freelist */

void FeatCtx::recycleNodes(GNode *node) {
    GNode *nextSeq;
    long iterations = 0;

    for (; node != NULL; node = nextSeq) {
        nextSeq = node->nextSeq;
        GNode *nextCl;

        /* Recycle class */
        for (GNode *cl = node; cl != NULL; cl = nextCl) {
            nextCl = cl->nextCl;
            recycleNode(cl);
            if (iterations++ > ITERATIONLIMIT) {
                fprintf(stderr, "Makeotf [WARNING]: Many cycles in featRecycleNode. Possible error.\n");
                return;
            }
        }
    }
}

/* --- Glyph --- */

/* Map feature file glyph name to gid; emit error message and return notdef if
   not found (in order to continue until hotQuitOnError() called) */
GID FeatCtx::mapGName2GID(const char *gname, bool allowNotdef) {
    GID gid;
    char *realname;

    // if (IS_CID(g)) {
    //     zzerr("glyph name specified for a CID font");
    // }

    gid = mapName2GID(g, gname, &realname);

    /* Return the glyph if found in the font. When allowNotdef is set, we
     * always return and callers should check for GID_UNDEF as we can't return
     * GID_NOTDEF in this case. */
    if (gid != GID_UNDEF || allowNotdef == 1) {
        return gid;
    }

    /*  XXX
    if (realname != NULL && strcmp(gname, realname) != 0) {
        featMsg(hotERROR, "Glyph \"%s\" (alias \"%s\") not in font",
                realname, gname);
    } else {
        featMsg(hotERROR, "Glyph \"%s\" not in font.", gname);
    } */
    return GID_NOTDEF;
}

GID FeatCtx::cid2gid(const std::string &cidstr) {
    GID gid = 0; /* Suppress optimizer warning */
    if (!IS_CID(g)) {
     ; // XXX   zzerr("CID specified for a non-CID font");
    } else {
        int t = strtoll(cidstr.c_str() + 1, NULL, 10); /* Skip initial '\' */
        if (t < 0 || t > 65535)
            ; // XXX zzerr("not in range 0 .. 65535");
        else if ((gid = mapCID2GID(g, t)) == GID_UNDEF)
        ; // XXX zzerr("CID not found in font");
    }
    return gid; /* Suppress compiler warning */
}

/* --- Glyph class --- */

void FeatCtx::resetCurrentGC() {
    assert( curGCHead == nullptr && curGCTailAddr == NULL && curGCName.empty());
    curGCTailAddr = &curGCHead;
}

void FeatCtx::defineCurrentGC(const std::string &gcname) {
    resetCurrentGC();
    assert( namedGlyphClasses.find(gcname) == namedGlyphClasses.end() );
    curGCName = gcname;
}

void FeatCtx::openAsCurrentGC(const std::string &gcname) {
    resetCurrentGC();
    auto search = namedGlyphClasses.find(gcname);
    if ( search != namedGlyphClasses.end() ) {
        GNode *nextClass = curGCHead = search->second;
        while ( nextClass->nextCl != NULL )
            nextClass = nextClass->nextCl;
        curGCTailAddr = &nextClass;
        // If the class is found don't set curGCName as it doesn't need to
        // be stored on Close.
    } else {
        curGCName = gcname;
    }
}

/* Add glyph to end of current glyph class */

void FeatCtx::addGlyphToCurrentGC(GID gid) {
    *curGCTailAddr = setNewNode(gid);
    curGCTailAddr = &(*curGCTailAddr)->nextCl;
}

static long getNum(const char *str, int length) {
    char buf[MAX_NUM_LEN + 1];
    strncpy(buf, str, length);
    buf[length] = '\0';
    return strtol(buf, NULL, 10);
}

/* Glyph names in range differ by a single letter */

void FeatCtx::addAlphaRangeToCurrentGC(GID first, GID last,
                                       const char *firstName, const char *p,
                                       char q) {
    int l = strlen(firstName)+1;
    char *gname = (char *) MEM_NEW(g, l); // Extra shouldn't be needed
    char *ptr;

    strcpy(gname, firstName);
    ptr = &gname[p - firstName];

    for (; *ptr <= q; (*ptr)++) {
        GID gid = (*ptr == *p) ? first : (*ptr == q) ? last : mapGName2GID(gname, false);
        addGlyphToCurrentGC(gid);
    }
    MEM_FREE(g, gname);
}

/* Glyph names in range differ by a decimal number */

void FeatCtx::addNumRangeToCurrentGC(GID first, GID last, const char *firstName,
                                     const char *p1, const char *p2,
                                     const char *q1, int numLen) {
    /* --- Range is valid number range --- */
    long i, l = strlen(firstName)+1;
    long firstNum = getNum(p1, numLen);
    long lastNum = getNum(q1, numLen);
    char *gname = (char *) MEM_NEW(g, l+3); // Extra shouldn't be needed
    char *preNum = (char *) MEM_NEW(g, l);
    char fmt[128];

    for (i = firstNum; i <= lastNum; i++) {
        GID gid;
        fmt[0] = '\0';
        if (i == firstNum) {
            gid = first;
        } else if (i == lastNum) {
            gid = last;
        } else {
            if (i == firstNum + 1) {
                sprintf(fmt, "%%s%%0%dd%%s", numLen);
                /* Part of glyph name before number; */
                /* p2 marks post-number              */
                strncpy(preNum, firstName, p1 - firstName);
                preNum[p1 - firstName] = '\0';
            }
            snprintf(gname, l+4, fmt, preNum, i, p2);
            gid = mapGName2GID(gname, false);
        }
        addGlyphToCurrentGC(gid);
    }
    MEM_FREE(g, gname);
    MEM_FREE(g, preNum);
}

/* Add glyph range to end of current glyph class */

void FeatCtx::addRangeToCurrentGC(GID first, GID last, const std::string &firstName,
                                  const std::string &lastName) {
#define INVALID_RANGE featMsg(hotFATAL, "Invalid glyph range [%s-%s]", \
                              firstName, lastName)
    if (IS_CID(g)) {
        if (first <= last) {
            for (GID i = first; i <= last; i++) {
                addGlyphToCurrentGC(i);
            }
        } else {
            ; // XXX featMsg(hotFATAL, "Bad GID range: %u thru %u", first, last);
        }
    } else {
        if (firstName.length() != lastName.length()) {
            ; // XXX INVALID_RANGE;
        }

        /* Enforce glyph range rules */
        const char *fn = firstName.c_str(), *p1, *p2;
        const char *ln = lastName.c_str(), *q1, *q2;

        for (p1 = fn, q1 = ln; *p1 != '\0' && *p1 == *q1; p1++, q1++)
            ;

        if (*p1 == '\0') {
            ; // XXX INVALID_RANGE; /* names are same */
        }
        for (p2 = p1, q2 = q1;
             *p2 != '\0' && *p2 != *q2;
             p2++, q2++) {
        }
        /* Both ends of the first difference are now marked. */
        /* The remainder should be the same: */
        if (strcmp(p2, q2) != 0) {
            ; // XXX INVALID_RANGE;
        }

        /* A difference of up to 3 digits is allowed; 1 for letters */
        switch (p2 - p1) {
            int i;

            case 1:
                if (isalpha(*p1) && isalpha(*q1) && *q1 > *p1 && *q1 - *p1 < 26) {
                    addAlphaRangeToCurrentGC(first, last, fn, p1, *q1);
                    return;
                }

            case 2:
            case 3:
                /* All differences should be digits */
                for (i = 0; i < p2 - p1; i++) {
                    if (!isdigit(p1[i]) || !isdigit(q1[i])) {
                        ; // XXX INVALID_RANGE;
                    }
                }
                /* Search for largest enclosing number */
                for (; p1 > firstName && isdigit(*(p1 - 1)); p1--, q1--) {
                }
                for (; isdigit(*p2); p2++, q2++) {
                }
                if (p2 - p1 > MAX_NUM_LEN) {
                    ; // XXX INVALID_RANGE;
                } else {
                    addNumRangeToCurrentGC(first, last, fn, p1, p2, q1, p2 - p1);
                    return;
                }
                break;

            default:
                ; // XXX INVALID_RANGE;
        }
    }
}

GNode *FeatCtx::lookupGlyphClass(const std::string &gcname) {
    auto search = namedGlyphClasses.find(gcname);
    if ( search == namedGlyphClasses.end() ) {
        ; // XXX zzerr("glyph class not defined");
        return nullptr;
    }
    return search->second;
}

void FeatCtx::addGlyphClassToCurrentGC(GNode *src) {
    curGCTailAddr = copyGlyphClass(curGCTailAddr, src);
}

void FeatCtx::addGlyphClassToCurrentGC(const std::string &subGCName) {
    // XXX consider checking curGCName against subGCName and reporting that
    // error specifically
    auto search = namedGlyphClasses.find(subGCName);

    if ( search == namedGlyphClasses.end() ) {
        ; // XXX zzerr("glyph class not defined");
        return;
    }

    curGCTailAddr = copyGlyphClass(curGCTailAddr, search->second);
}

/* If named, return ptr to beginning of gc */

GNode *FeatCtx::finishCurrentGC() {
    if ( !curGCName.empty() )
        namedGlyphClasses.insert({curGCName, curGCHead});

    GNode *ret = curGCHead;
    curGCName.clear();
    curGCHead = nullptr;
    curGCTailAddr = nullptr;
    return ret;
}

/* Add a language system that all features (that do not contain language or
   script statements) would be registered under */

void FeatCtx::addLangSys(Tag script, Tag language, bool checkBeforeFeature) {
    if (checkBeforeFeature && gFlags & seenFeature) {
        ; /* XXX featMsg(hotERROR,
                "languagesystem must be specified before all"
                " feature blocks"); */
        return;
    }
    if (!(gFlags & seenLangSys)) {
        gFlags |= seenLangSys;
    } else if (script == DFLT_) {
        if (gFlags & seenNonDFLTScriptLang)
            ; // XXX featMsg(hotERROR, "All references to the script tag DFLT must precede all other script references.");
    } else {
        gFlags |= seenNonDFLTScriptLang;
    }

    if (script == dflt_) {
        ; // XXX featMsg(hotWARNING, "'dflt' is not a valid script tag for a languagesystem statement; using 'DFLT'.");
        script = DFLT_;
    }

    if (language == DFLT_) {
        ; // XXX featMsg(hotWARNING, "'DFLT' is not a valid language tag for a languagesystem statement; using 'dflt'.");
        language = dflt_;
    }

    /* First check if already exists */
    if ( langSysSet.find({script, language}) != langSysSet.end() ) {
        ; // XXX featMsg(hotWARNING, "Duplicate specification of language system");
        return;
    }

    langSysSet.emplace(script, language);

#if HOT_DEBUG
    if (!checkBeforeFeature) {
        DF(2, (stderr, "languagesystem '%c%c%c%c' '%c%c%c%c' ;\n",
               TAG_ARG(script), TAG_ARG(language)));
    }
#endif
}

bool FeatCtx::tagAssign(Tag tag, enum TagType type, bool checkIfDef) {
    TagArray *ta = NULL;
    Tag *t = NULL;

    if (type == featureTag) {
        ta = &feature;
        t = &curr.feature;
    } else if (type == scriptTag) {
        ta = &script;
        if (tag == dflt_) {
            tag = DFLT_;
            ; // XXX featMsg(hotWARNING, "'dflt' is not a valid tag for a script statement; using 'DFLT'.");
        }
        t = &curr.script;
    } else if (type == languageTag) {
        ta = &language;
        if (tag == DFLT_) {
            tag = dflt_;
            ; // XXX featMsg(hotWARNING, "'DFLT' is not a valid tag for a language statement; using 'dflt'.");
        }
        t = &curr.language;
    } else if (type == tableTag) {
        ta = &table;
    } else if (type != featureTag) {
        ; // XXX featMsg(hotFATAL, "[internal] unrecognized tag type");
        return false;
    }

    if (checkIfDef && ta->find(tag) != ta->end() ) {
        if ((type == featureTag)) {
            assert( t != NULL );
            *t = tag;
        }
        return false;
    }

    ta->emplace(tag);
    if (t != NULL)
        *t = tag;

    return true;
}

void FeatCtx::prepRule(Tag newTbl, int newlkpType, GNode *targ, GNode *repl) {
    int accumDFLTLkps = 1;

    curr.tbl = newTbl;
    curr.lkpType = newlkpType;

    /* Proceed in language system mode for this feature if (1) languagesystem */
    /* specified at global scope and (2) this feature did not start with an  */
    /* explicit script or language statement                                 */
    if (    !(fFlags & langSysMode)
         && gFlags & seenLangSys
         && !(fFlags & seenScriptLang) ) {
        fFlags |= langSysMode;

        /* We're now poised at the start of the first rule of this feature.  */
        /* Start registering rules under the first language system (register */
        /* under the rest of the language systems at end of feature).        */
        auto fls = langSysSet.cbegin();
        assert ( fls !=langSysSet.cend() );
        tagAssign(fls->script, scriptTag, false);
        tagAssign(fls->lang, languageTag, false);
    }

    /* Set the label */
    if (currNamedLkp != LAB_UNDEF) {
        /* This is a named lkp or a reference (to an anon/named) lkp */
        if (curr.label != currNamedLkp) {
            curr.label = currNamedLkp;
        } else if (curr.script == prev.script &&
                   curr.feature == prev.feature) {
            /* Store lkp state only once per lookup. If the script/feature  */
            /* has changed but the named label hasn't, accumDFLTLkps should */
            /* be 1.                                                        */
            accumDFLTLkps = 0;
        }
    } else {
        /* This is an anonymous rule */
        if (prev.script == curr.script &&
            prev.language == curr.language &&
            prev.feature == curr.feature &&
            prev.tbl == curr.tbl &&
            prev.lkpType == curr.lkpType) {
            /* I don't test against lookupFlag and markSetIndex, as I do     */
            /* not want to silently start a new lookup because these changed */
            if ( endOfNamedLkpOrRef ) {
                curr.label = getNextAnonLabel();
            } else {
                curr.label = prev.label;
                accumDFLTLkps = 0; /* Store lkp state only once per lookup */
            }
        } else {
            curr.label = getNextAnonLabel();
        }
    }

    /* --- Everything is now in current state for the new rule --- */

    /* Check that rules in a named lkp block */
    /* are of the same tbl, lkpType, lkpFlag */
    if (currNamedLkp != LAB_UNDEF && IS_NAMED_LAB(curr.label) &&
        !IS_REF_LAB(curr.label) && prev.label == curr.label) {
        if (curr.tbl != prev.tbl || curr.lkpType != prev.lkpType) {
            ; /*XXX  featMsg(hotFATAL,
                    "Lookup type different from previous "
                    "rules in this lookup block"); */
        } else if (curr.lkpFlag != prev.lkpFlag) {
            ; /* xXXX featMsg(hotFATAL,
                    "Lookup flags different from previous "
                    "rules in this block"); */
        } else if (curr.markSetIndex != prev.markSetIndex) {
            ; /* XXX featMsg(hotFATAL,
                    "Lookup flag UseMarkSetIndex different from previous "
                    "rules in this block"); */
        }
    }

    /* Reset DFLTLkp accumulator at feature change or start of DFLT run */
    if ((curr.feature != prev.feature) || (curr.script != prev.script))
        DFLTLkps.clear();

    /* stop accumulating script specific defaults once a language other than 'dflt' is seen */
    if (accumDFLTLkps && curr.language != dflt_)
        accumDFLTLkps = 0;

    if (accumDFLTLkps)
        /* Save for possible inclusion later in lang-specific stuff */
        DFLTLkps.push_back(curr);

    /* Store, if applicable, for GPOSContext and aalt creation */
    if ((!IS_REF_LAB(curr.label)) && (repl != NULL))
        ; // XXX storeRuleInfo(targ, repl);

    /* If h->prev != h->curr (ignoring markSet) */
    if (prev.script != curr.script ||
        prev.language != curr.language ||
        prev.feature != curr.feature ||
        prev.tbl != curr.tbl ||
        prev.lkpType != curr.lkpType ||
        prev.label != curr.label) {
        bool useExtension = false;

        closeFeatScriptLang(prev);

        /* Determine whether extension lookups are to be used */
        if (currNamedLkp != LAB_UNDEF && IS_NAMED_LAB(curr.label)) {
            NamedLkp *lkp = lab2NamedLkp(currNamedLkp);
            if (lkp == NULL) {
                ; // XXX hotMsg(g, hotFATAL, "[internal] label not found\n");
            }
            useExtension = lkp->useExtension;
        }

        /* Initiate calls to GSUB/GPOS */
        if (curr.tbl == GSUB_) {
            GSUBFeatureBegin(g, curr.script, curr.language, curr.feature);
            GSUBLookupBegin(g, curr.lkpType, curr.lkpFlag,
                            curr.label, useExtension, curr.markSetIndex);
        } else if (curr.tbl == GPOS_) {
            GPOSFeatureBegin(g, curr.script, curr.language, curr.feature);
            GPOSLookupBegin(g, curr.lkpType, curr.lkpFlag,
                            curr.label, useExtension, curr.markSetIndex);
        }

        /* If LANGSYS mode, snapshot lookup info for registration under */
        /* other language systems at end of feature                     */
        if (fFlags & langSysMode)
            lookup.emplace_back((LookupInfo) { curr.tbl, curr.lkpType, curr.lkpFlag,
                                curr.markSetIndex, curr.label, useExtension } );
        setIDText();

        /* --- COPY CURRENT TO PREVIOUS STATE: */
        prev = curr;
    } else {
        /* current state sate is the same for everything except maybe lkpFlag and markSetIndex */
        if (curr.lkpFlag != prev.lkpFlag) {
            ; /* XXX featMsg(hotFATAL,
                    "Lookup flags different from previous "
                    "rules in this block"); */
        } else if (curr.markSetIndex != prev.markSetIndex) {
            ; /* XXX featMsg(hotFATAL,
                    "Lookup flag UseMarkSetIndex different from previous "
                    "rules in this block"); */
        }
    }
}

/* --- Rule additions --- */

/* Current fea, scr, lan, lkpFlag already set. Need to set label. */

void FeatCtx::setIDText() // XXX
{
    if (curr.feature == TAG_STAND_ALONE)
        sprintf(g->error_id_text, "standalone");
    else
        sprintf(g->error_id_text, "feature '%c%c%c%c'", TAG_ARG(curr.feature));
    if (IS_NAMED_LAB(curr.label))
    {
        char* p = g->error_id_text + strlen(g->error_id_text);
        NamedLkp *curr = lab2NamedLkp(currNamedLkp);
        sprintf(p, " lookup '%s'", curr->name.c_str());
    }
}

/* Get count of number of nodes in glyph class */

int FeatCtx::getGlyphClassCount(GNode *gc) {
    int cnt = 0;
    for (; gc != NULL; gc = gc->nextCl) {
        cnt++;
    }
    return cnt;
}

/* Return 1 if targ and repl have same number of glyphs in class, else
   emit error message and return 0 */

bool FeatCtx::compareGlyphClassCount(GNode *targ, GNode *repl, bool isSubrule) {
    int nTarg = getGlyphClassCount(targ);
    int nRepl = getGlyphClassCount(repl);

    if (nTarg == nRepl) {
        return true;
    }
    ; /* XXX featMsg(hotERROR,
            "Target glyph class in %srule doesn't have the same"
            " number of elements as the replacement class; the target has %d,"
            " the replacement, %d",
            isSubrule ? "sub-" : "", nTarg, nRepl); */
    return false;
}

void FeatCtx::wrapUpRule() {
    prev = curr;
    endOfNamedLkpOrRef = false;
}


void FeatCtx::addGSUB(int lkpType, GNode *targ, GNode *repl) {
    std::cout << "addGSUB " << lkpType << std::endl;
    if (aaltCheckRule(lkpType, targ, repl))
        return;

    prepRule(GSUB_, lkpType, targ, repl);

    GSUBRuleAdd(g, targ, repl);

    wrapUpRule();
}

/* Return 1 if this rule is to be treated specially */

bool FeatCtx::aaltCheckRule(int type, GNode *targ, GNode *repl) {
    if (curr.feature == aalt_) {
        if (type == GSUBSingle || type == GSUBAlternate) {
            aaltAddAlternates(targ, repl);
            recycleNodes(targ);
            recycleNodes(repl);
        } else {
            ; /* XXX featMsg(hotWARNING,
                    "Only single and alternate "
                    "substitutions are allowed within an 'aalt' feature"); */
        }
        return true;
    }
    return false;
}

/* Validate targ and repl for GSUBSingle. targ and repl come in with nextSeq
   NULL and repl not marked. If valid return 1, else emit error message(s) and
   return 0 */

bool FeatCtx::validateGSUBSingle(GNode *targ, GNode *repl, bool isSubrule) {
    if (!isSubrule && targ->flags & FEAT_MARKED) {
        ; // XXX featMsg(hotERROR, "Target must not be marked in this rule");
        return false;
    }

    if (is_glyph(targ)) {
        if (!is_glyph(repl)) {
            ; // XXX featMsg(hotERROR, "Replacement in %srule must be a single glyph", isSubrule ? "sub-" : "");
            return false;
        }
    } else if (repl->nextCl != NULL &&
               !compareGlyphClassCount(targ, repl, isSubrule)) {
        return false;
    }

    return true;
}

/* Return 1 if node is an unmarked pattern of 2 or more glyphs; glyph classes
   may be present */
static bool isUnmarkedSeq(GNode *node) {
    if (node == nullptr || node->flags & FEAT_HAS_MARKED || node->nextSeq == nullptr) {
        return false;
    }
    return true;
}

/* Return 1 if node is an unmarked pattern of 2 or more glyphs, and no glyph
   classes are present */
static bool isUnmarkedGlyphSeq(GNode *node) {
    if (!isUnmarkedSeq(node)) {
        return false;
    }

    for (; node != nullptr; node = node->nextSeq) {
        if (node->nextCl != nullptr) {
            return true; /* A glyph class is present */
        }
    }
    return true;
}

/* Validate targ and repl for GSUBMultiple. targ comes in with nextSeq NULL and
   repl NULL or with nextSeq non-NULL (and unmarked). If valid return 1, else
   emit error message(s) and return 0 */

bool FeatCtx::validateGSUBMultiple(GNode *targ, GNode *repl, bool isSubrule) {
    if (!isSubrule && targ->flags & FEAT_MARKED) {
        ; // XXX featMsg(hotERROR, "Target must not be marked in this rule");
        return false;
    }

    if (!((isSubrule || is_glyph(targ)) && isUnmarkedGlyphSeq(repl)) && (repl != NULL || targ->flags & FEAT_LOOKUP_NODE)) {
        ; // XXX featMsg(hotERROR, "Invalid multiple substitution rule");
        return false;
    }
    return true;
}

/* Validate targ and repl for GSUBAlternate. repl is not marked. If valid
   return 1, else emit error message(s) and return 0 */

bool FeatCtx::validateGSUBAlternate(GNode *targ, GNode *repl, bool isSubrule) {
    if (!isSubrule && targ->flags & FEAT_MARKED) {
        ; // XXX featMsg(hotERROR, "Target must not be marked in this rule");
        return false;
    }

    if (!is_unmarked_glyph(targ)) {
        ; /* XXX featMsg(hotERROR,
                "Target of alternate substitution %srule must be a"
                " single unmarked glyph",
                isSubrule ? "sub-" : ""); */
        return false;
    }
    if (!is_class(repl)) {
        ; /* XXX featMsg(hotERROR,
                "Replacement of alternate substitution %srule must "
                "be a glyph class",
                isSubrule ? "sub-" : ""); */
        return false;
    }
    return true;
}

/* Validate targ and repl for GSUBLigature. targ comes in with nextSeq
   non-NULL and repl is unmarked. If valid return 1, else emit error message(s)
   and return 0 */

bool FeatCtx::validateGSUBLigature(GNode *targ, GNode *repl, bool isSubrule) {
    if (!isSubrule && targ->flags & FEAT_HAS_MARKED) {
        ; // XXX featMsg(hotERROR, "Target must not be marked in this rule");
        return false;
    }

    if (!(is_glyph(repl))) {
        ; // XXX featMsg(hotERROR, "Invalid ligature %srule replacement", isSubrule ? "sub-" : "");
        return false;
    }
    return true;
}

/* Analyze GSUBChain targ and repl. Return 1 if valid, else 0 */

bool FeatCtx::validateGSUBReverseChain(GNode *targ, GNode *repl) {
    int state;
    GNode *p;
    GNode *input = NULL; /* first node  of input sequence */
    GNode *m = NULL;
    int nMarked = 0;

    if (repl == NULL) {
        /* Except clause */
        if (targ->flags & FEAT_HAS_MARKED) {
            /* Mark backtrack */
            for (p = targ; p != NULL && !(p->flags & FEAT_MARKED);
                 p = p->nextSeq) {
                p->flags |= FEAT_BACKTRACK;
            }
            for (; p != NULL && p->flags & FEAT_MARKED; p = p->nextSeq) {
                p->flags |= FEAT_INPUT;
            }
        } else {
            /* If clause is unmarked: first char is INPUT, rest LOOKAHEAD */
            targ->flags |= FEAT_INPUT;
            p = targ->nextSeq;
        }
        /* Mark rest of glyphs as lookahead */
        for (; p != NULL; p = p->nextSeq) {
            if (p->flags & FEAT_MARKED) {
                ; /* XXX featMsg(hotERROR,
                        "ignore clause may have at most one run "
                        "of marked glyphs"); */
                return false;
            } else {
                p->flags |= FEAT_LOOKAHEAD;
            }
        }
        return true;
    }

    /* At most one run of marked positions supported, for now */
    for (p = targ; p != NULL; p = p->nextSeq) {
        if (p->flags & FEAT_MARKED) {
            if (++nMarked == 1) {
                m = p;
            }
        } else if (p->nextSeq != NULL && p->nextSeq->flags & FEAT_MARKED && nMarked > 0) {
            ; // XXX featMsg(hotERROR, "Reverse contextual GSUB rule may must have one and only one glyph or class marked for replacement");
            return false;
        }
    }

    /* If nothing is marked, mark everything [xxx?] */
    if (nMarked == 0) {
        m = targ;
        for (p = targ; p != NULL; p = p->nextSeq) {
            p->flags |= FEAT_MARKED;
            nMarked++;
        }
    }
    /* m now points to beginning of marked run */

#if 0
    targ->flags |= (nMarked == 1) ? FEAT_HAS_SINGLE_MARK
                                  : FEAT_HAS_LIGATURE_MARK;
#endif

    if (repl->nextSeq != NULL) {
        ; // XXX featMsg(hotERROR, "Reverse contextual GSUB replacement sequence may have only one glyph or class");
        return false;
    }

    if (nMarked != 1) {
        ; // XXX featMsg(hotERROR, "Reverse contextual GSUB rule may must have one and only one glyph or class marked for replacement");
        return false;
    }

    /* Divide into backtrack, input, and lookahead (xxx ff interface?). */
    /* For now, input is marked glyphs                                  */
    state = FEAT_BACKTRACK;
    for (p = targ; p != NULL; p = p->nextSeq) {
        if (p->flags & FEAT_MARKED) {
            if (input == NULL) {
                input = p;
            }
            state = FEAT_INPUT;
        } else if (state != FEAT_BACKTRACK) {
            state = FEAT_LOOKAHEAD;
        }
        p->flags |= state;
    }

    if (!compareGlyphClassCount(input, repl, false)) {
        return false;
    }

    return true;
}

void FeatCtx::subtableBreak() {
    bool retval = false;

    if (curr.feature == aalt_ || curr.feature == size_) {
        ; // XXX featMsg(hotERROR, "\"subtable\" use not allowed in 'aalt' or 'size' feature");
        return;
    }

    if (curr.tbl == GSUB_) {
        retval = GSUBSubtableBreak(g);
    } else if (curr.tbl == GPOS_) {
        retval = GPOSSubtableBreak(g);
    } else {
        ; // XXX featMsg(hotWARNING, "Statement not expected here");
        return;
    }

    if (retval)
        ; // XXX featMsg(hotWARNING, "subtable break is supported only in class kerning lookups");
}

/* Indicate current feature or labeled lookup block to be created with
   extension lookupTypes. */

void FeatCtx::flagExtension(bool isLookup) {
    if ( isLookup ) {
        /* lookup block scope */
        NamedLkp *curr = lab2NamedLkp(currNamedLkp);
        if ( curr == nullptr ) {
            ; // XXX hotMsg(g, hotFATAL, "[internal] label not found\n");
        }
        curr->useExtension = true;
    } else {
        /* feature block scope */
        if (curr.feature == aalt_) {
            aalt.useExtension = true;
        } else {
            ; /* XXX featMsg(hotERROR,
                    "\"useExtension\" allowed in feature-scope only"
                    " for 'aalt'"); */
        }
    }
}


/* Analyze GSUBChain targ and repl. Return 1 if valid, else 0 */

bool FeatCtx::validateGSUBChain(GNode *targ, GNode *repl) {
    int state;
    GNode *p;
    int nMarked = 0;
    GNode *m = NULL; /* Suppress optimizer warning */
    int hasDirectLookups = (targ->flags & FEAT_LOOKUP_NODE);

    if (targ->flags & FEAT_IGNORE_CLAUSE) {
        /* Except clause */
        if (targ->flags & FEAT_HAS_MARKED) {
            /* Mark backtrack */
            for (p = targ; p != NULL && !(p->flags & FEAT_MARKED);
                 p = p->nextSeq) {
                p->flags |= FEAT_BACKTRACK;
            }
            for (; p != NULL && p->flags & FEAT_MARKED; p = p->nextSeq) {
                p->flags |= FEAT_INPUT;
            }
        } else {
            /* If clause is unmarked: first char is INPUT, rest LOOKAHEAD */
            targ->flags |= FEAT_INPUT;
            p = targ->nextSeq;
        }
        /* Mark rest of glyphs as lookahead */
        for (; p != NULL; p = p->nextSeq) {
            if (p->flags & FEAT_MARKED) {
                ; /* XXX featMsg(hotERROR,
                        "ignore clause may have at most one run "
                        "of marked glyphs"); */
                return false;
            } else {
                p->flags |= FEAT_LOOKAHEAD;
            }
        }
        return 1;
    } else if ((repl == NULL) && (!hasDirectLookups)) {
        ; // XXX featMsg(hotERROR, "contextual substitution clause must have a replacement rule or direct lookup reference.");
        return false;
    }

    if (hasDirectLookups) {
        if (repl != NULL) {
            ; // XXX featMsg(hotERROR, "contextual substitution clause cannot both have a replacement rule and a direct lookup reference.");
            return false;
        }
        if (!(targ->flags & FEAT_HAS_MARKED)) {
            ; // XXX featMsg(hotERROR, "The  direct lookup reference in a contextual substitution clause must be marked as part of a contextual input sequence.");
            return false;
        }
    }

    /* At most one run of marked positions supported, for now */
    for (p = targ; p != NULL; p = p->nextSeq) {
        if (p->flags & FEAT_MARKED) {
            if (++nMarked == 1) {
                m = p;
            }
        } else if (p->lookupLabelCount > 0) {
            ; // XXX featMsg(hotERROR, "The  direct lookup reference in a contextual substitution clause must be marked as part of a contextual input sequence.");
            return false;
        } else if (p->nextSeq != NULL && p->nextSeq->flags & FEAT_MARKED && nMarked > 0) {
            ; // XXX featMsg(hotERROR, "Unsupported contextual GSUB target sequence");
            return false;
        }
    }

    /* If nothing is marked, mark everything [xxx?] */
    if (nMarked == 0) {
        m = targ;
        for (p = targ; p != NULL; p = p->nextSeq) {
            p->flags |= FEAT_MARKED;
            nMarked++;
        }
    }
    /* m now points to beginning of marked run */

    if (repl) {
        if (nMarked == 1) {
            if (is_glyph(m) && is_class(repl)) {
                ; // XXX featMsg(hotERROR, "Contextual alternate rule not yet supported");
                return false;
            }

            if (repl->nextSeq != NULL) {
                if (!validateGSUBMultiple(m, repl, 1)) {
                    return false;
                }
            } else if (!validateGSUBSingle(m, repl, 1)) {
                return false;
            }
        } else if (nMarked > 1) {
            if (repl->nextSeq != NULL) {
                ; // XXX featMsg(hotERROR, "Unsupported contextual GSUB replacement sequence");
                return false;
            }

            /* Ligature run may contain classes, but only with a single repl */
            if (!validateGSUBLigature(m, repl, 1)) {
                return false;
            }
        }
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

    return true;
}

void FeatCtx::addSub(GNode *targ, GNode *repl, int lkpType) {
    GNode *nextNode = targ;

    for (nextNode = targ; nextNode != NULL; nextNode = nextNode->nextSeq) {
        if (nextNode->flags & FEAT_MARKED) {
            targ->flags |= FEAT_HAS_MARKED;
            if ((lkpType != GSUBReverse) && (lkpType != GSUBChain)) {
                lkpType = GSUBChain;
            }
            break;
        }
    }

    if (lkpType == GSUBChain || (targ->flags & FEAT_IGNORE_CLAUSE)) {
        std::cout << "chain" << std::endl;
        /* Chain sub exceptions (further analyzed below).                */
        /* "sub f i by fi;" will be here if there was an "except" clause */

        if (!g->hadError) {
            if (validateGSUBChain(targ, repl)) {
                lkpType = GSUBChain;
                addGSUB(GSUBChain, targ, repl);
            }
        }
    } else if (lkpType == GSUBReverse) {
        std::cout << "rev" << std::endl;
        if (validateGSUBReverseChain(targ, repl)) {
            addGSUB(GSUBReverse, targ, repl);
        }
    } else if (lkpType == GSUBAlternate) {
        std::cout << "alt" << std::endl;
        if (validateGSUBAlternate(targ, repl, 0)) {
            addGSUB(GSUBAlternate, targ, repl);
        }
    } else if (targ->nextSeq == NULL && (repl == NULL || repl->nextSeq != NULL)) {
        std::cout << "mult" << std::endl;
        if (validateGSUBMultiple(targ, repl, 0)) {
            addGSUB(GSUBMultiple, targ, repl);
        }
    } else if (targ->nextSeq == NULL && repl->nextSeq == NULL) {
        std::cout << "sing" << std::endl;
        if (validateGSUBSingle(targ, repl, 0)) {
            addGSUB(GSUBSingle, targ, repl);
        }
    } else {
        std::cout << "other" << std::endl;
        GNode *next;

        if (validateGSUBLigature(targ, repl, 0)) {
            /* add glyphs to lig and component classes, in case we need to
            make a default GDEF table. Note that we may make a lot of
            duplicated. These get weeded out later. The components are
            linked by the next->nextSeq fields. For each component*/
            openAsCurrentGC(kDEFAULT_COMPONENTCLASS_NAME); /* looks up class, making if needed. Sets h->gcInsert to address of nextCl of last node, and returns it.*/
            next = targ;
            while (next != NULL) {
                if (next->nextCl != NULL) {
                    /* the current target node is a glyph class. Need to add all members of the class to the kDEFAULT_COMPONENTCLASS_NAME. */
                    addGlyphClassToCurrentGC(next);
                } else {
                    addGlyphToCurrentGC(next->gid); /* adds new node at h->gcInsert, sets h->gcInsert to address of new node's nextCl */
                }
                next = next->nextSeq;
            }
            finishCurrentGC();
            openAsCurrentGC(kDEFAULT_LIGATURECLASS_NAME);
            next = repl;
            while (next != NULL) {
                if (next->nextCl != NULL) {
                    addGlyphClassToCurrentGC(next);
                } else {
                    addGlyphToCurrentGC(next->gid);
                }
                next = next->nextSeq;
            }
            finishCurrentGC();
            addGSUB(GSUBLigature, targ, repl);
        }
    }
}

Label FeatCtx::getNextNamedLkpLabel() {
    if (namedLkpLabelCnt > FEAT_NAMED_LKP_END) {
        ; /* XXX featMsg(hotFATAL,
                "[internal] maximum number of named lookups reached:"
                " %d",
                FEAT_NAMED_LKP_END - FEAT_NAMED_LKP_BEG + 1); */
    }
    return namedLkpLabelCnt++;
}

Label FeatCtx::getNextAnonLabel() {
    if (anonLabelCnt > FEAT_ANON_LKP_END) {
        ; /* XXX hotMsg(g, hotFATAL,
               "[internal] maximum number of lookups reached:"
               " %d",
               FEAT_ANON_LKP_END - FEAT_ANON_LKP_BEG + 1); */
    }
    return anonLabelCnt++;
}

/* Validate and set a particular flag/subcomponent of the lookupflag. markType
   only used if attr is otlMarkAttachmentType */

void FeatCtx::setLkpFlagAttribute(unsigned short *val, unsigned int attr,
                                  unsigned short markAttachClassIndex) {
    if (attr > 1) {
        /* 1 is the RTL flag - does not need to set this */
        gFlags |= seenIgnoreClassFlag;
    }

    if (attr == otlMarkAttachmentType) {
        if (markAttachClassIndex == 0) {
            ; // XXX featMsg(hotERROR, "must specify non-zero MarkAttachmentType value");
        } else if (*val & attr) {
            ; /* XXX featMsg(hotERROR,
                    "MarkAttachmentType already specified in this statement"); */
        } else {
            *val |= (markAttachClassIndex & 0xFF) << 8;
        }
    } else if (attr == otlUseMarkFilteringSet) {
        if (*val & attr) {
            ; /* XXX featMsg(hotERROR,
                    "UseMarkSetType already specified in this statement"); */
        }
        curr.markSetIndex = markAttachClassIndex;
        *val |= attr;
    } else {
        if (*val & attr) {
            ; /* XXX featMsg(hotWARNING,
                    "\"%s\" repeated in this statement; ignoring", zzlextext); */
        } else {
            *val |= attr;
        }
    }
}

void FeatCtx::setLkpFlag(unsigned short flagVal) {
    unsigned short flag = flagVal;
    if (curr.feature == aalt_ || curr.feature == size_) {
        ; /* XXX featMsg(hotERROR,
                "\"lookupflag\" use not allowed in 'aalt' or 'size' feature"); */
    } else if (flag == curr.lkpFlag) {
        ; /* Statement has no effect */
    } else {
        curr.lkpFlag = flag;
    }
    /* if UseMarkSet, then the markSetIndex is set in setLkpFlagAttribute() */
}

/* Named or anon */

void FeatCtx::callLkp(State &st) {
    Label lab = st.label;

#if HOT_DEBUG
    if (g->font.debug & HOT_DB_FEAT_2) {
        if (curr.tbl == GSUB_) {
            fprintf(stderr, "\n");
        }
        fprintf(stderr, "# call lkp ");
        if (IS_REF_LAB(lab)) {
            fprintf(stderr, "REF->");
        }
        if (IS_NAMED_LAB(lab)) {
            fprintf(stderr, "<%s>", lab2NamedLkp(lab)->name);
        } else if (IS_ANON_LAB(lab)) {
            fprintf(stderr, "<ANON>");
        } else {
            hotMsg(g, hotFATAL, "undefined label");
        }
        fprintf(stderr, "[label=%x]", lab);
        /* fprintf(stderr, " : %s:%d:%d", st->tbl == GPOS_ ? "GPOS" : "GSUB", st->lkpType, st->lkpFlag); */
        fprintf(stderr, "(but with s'%c%c%c%c' l'%c%c%c%c' f'%c%c%c%c') :\n",
                TAG_ARG(h->curr.script), TAG_ARG(h->curr.language),
                TAG_ARG(h->curr.feature));
    }
#endif

    /* Use the scr, lan, fea that's *currently* set.                   */
    /* Use the *original* lkpFlag and, of course, tbl and lkpType.     */
    /* Copy the lookup label, set its reference bit.                   */
    /* Simulate the first rule in the original block simply by calling */
    /* prepRule() !                                                    */

    currNamedLkp = (Label)(lab | REF_LAB); /* As in:  lookup <name> {  */
    curr.lkpFlag = st.lkpFlag;
    curr.markSetIndex = st.markSetIndex;
    prepRule(st.tbl, st.lkpType, NULL, NULL);
    /* No actual rules will be fed into GPOS/GSUB */
    wrapUpRule();
    currNamedLkp = LAB_UNDEF; /* As in:  } <name>;        */
    endOfNamedLkpOrRef = true;
}

FeatCtx::NamedLkp *FeatCtx::name2NamedLkp(const std::string lkpName) {
    for (auto &it : namedLkp) {
        if ( it.name == lkpName )
            return &it;
    }
    return nullptr;
}

FeatCtx::NamedLkp *FeatCtx::lab2NamedLkp(Label lab) {
    Label baselab = (Label)(lab & ~REF_LAB);

    if ( !IS_NAMED_LAB(baselab) || baselab >= (Label) namedLkp.size() )
        return nullptr;
    else
        return &namedLkp[baselab];
}

void FeatCtx::useLkp(const std::string name) {
    NamedLkp *lkp = name2NamedLkp(name);

    if (curr.feature == aalt_) {
        ; // XXX featMsg(hotERROR, "\"lookup\" use not allowed in 'aalt' feature");
        return;
    } else {
        AALT::FeatureRecord t { curr.feature, false };
        auto it = std::find(aalt.features.begin(), aalt.features.end(), t);
        if ( it != aalt.features.end() )
            it->used = true;
    }

    if (curr.feature == size_) {
        ; /* XXX featMsg(hotERROR,
                "\"lookup\" use not allowed anymore in 'size'"
                " feature; " USE_LANGSYS_MSG); */
        return;
    }

    if (lkp == NULL) {
        ; // XXX featMsg(hotERROR, "lookup name \"%s\" not defined", name);
    } else {
        callLkp(lkp->state);
    }
}

Label FeatCtx::getLabelIndex(const std::string name) {
    NamedLkp *curr = name2NamedLkp(name);
    if (curr == NULL) {
        ; // XXX featMsg(hotFATAL, "lookup name \"%s\" not defined", name);
    }
    return curr->state.label;
}

/* Sort a glyph class; head node retains flags of original head node */
/* nextSeq, flags, markClassName, and markCnt of head now are zeroed. */

void FeatCtx::sortGlyphClass(GNode **list, int unique, int reportDups) {
    unsigned long i;
    GNode *p = *list;
    /* Preserve values that are kept with the head node only, and then zero them in the head node. */
    GNode *nextTarg = p->nextSeq;
    short flags = (*list)->flags;
    MetricsInfo *metricsInfo = p->metricsInfo;
    char *markClassName = p->markClassName;
    p->markClassName = NULL;
    p->metricsInfo = NULL;
    p->nextSeq = NULL;
    p->flags = 0;

    /* Copy over pointers */
    std::vector<GNode *> sortTmp;

    for (; p != NULL; p = p->nextCl)
        sortTmp.push_back(p);

    struct {
        bool operator()(GNode *a, GNode *b) const { return a->gid < b->gid; }
    } cmpNode;
    std::sort(sortTmp.begin(), sortTmp.end(), cmpNode);

    /* Move pointers around */
    for (i = 0; i < sortTmp.size() - 1; i++)
        sortTmp[i]->nextCl = sortTmp[i + 1];
    sortTmp[i]->nextCl = NULL;

    *list = sortTmp[0];

    /* Check for duplicates */
    if (unique && !g->hadError) {
        for (p = *list; p->nextCl != NULL;) {
            if (p->gid == p->nextCl->gid) {
                GNode *tmp = p->nextCl;

                p->nextCl = tmp->nextCl;
                tmp->nextCl = NULL;
                tmp->nextSeq = NULL;

                /* if INCL_CNT is zero, we are being called after the   */
                /* feature files have been closed. In this case, we are */
                /* sorting GDEF classes, and duplicates don't need a    */
                /* warning.                                             */
                /* XXX
                if ((INCL_CNT > 0) && reportDups) {
                    dumpGlyph(tmp->gid, '\0', 0);
                    ; featMsg(hotNOTE, "Removing duplicate glyph <%s>",
                            g->note.array);
                } */
                recycleNodes(tmp);
            } else {
                p = p->nextCl;
            }
        }
    }

    /*restore head node values to the new head node.*/
    p = *list;
    p->flags = flags;
    p->nextSeq = nextTarg;
    p->metricsInfo = metricsInfo;
    p->markClassName = markClassName;
}

inline FeatCtx *hctofc(hotCtx g) {
    assert( g->ctx.feat != nullptr );
    return (FeatCtx *) g->ctx.feat;
}

extern "C" {

void featNew(hotCtx g) {
    assert( g->ctx.feat == nullptr );
    FeatCtx *hfp = new FeatCtx(g);
    g->ctx.feat = (void *) hfp;
}

void featFree(hotCtx g) {
    delete hctofc(g);
    g->ctx.feat = nullptr;
}

// Prior to Antlr 4 the old code reset the context here but with an object
// that's an invitation for bugs so just reallocate.
void featReuse(hotCtx g) { 
    featFree(g);
    featNew(g);
}

void featFill(hotCtx g) { hctofc(g)->fill(); }

GNode *featSetNewNode(hotCtx g, GID gid) {
    return hctofc(g)->setNewNode(gid);
}

void featRecycleNodes(hotCtx g, GNode *node) {
    hctofc(g)->recycleNodes(node);
}

GNode **featGlyphClassCopy(hotCtx g, GNode **dst, GNode *src) {
    return hctofc(g)->copyGlyphClass(dst, src);
}

void featGlyphDump(hotCtx g, GID gid, int ch, int print) {
    hctofc(g)->dumpGlyph(gid, ch, print);
}

void featGlyphClassDump(hotCtx g, GNode *gc, int ch, int print) {
    hctofc(g)->dumpGlyphClass(gc, ch, print);
}

void featPatternDump(hotCtx g, GNode *pat, int ch, int print) {
    hctofc(g)->dumpPattern(pat, ch, print);
}

GNode **featPatternCopy(hotCtx g, GNode **dst, GNode *src, int num) {
    return hctofc(g)->copyPattern(dst, src, num);
}

void featExtendNodeToClass(hotCtx g, GNode *node, int num) {
    hctofc(g)->extendNodeToClass(node, num);
}

int featGetGlyphClassCount(hotCtx g, GNode *gc) {
    return hctofc(g)->getGlyphClassCount(gc);
}

unsigned int featGetPatternLen(hotCtx g, GNode *pat) {
    return hctofc(g)->getPatternLen(pat);
}

void featGlyphClassSort(hotCtx g, GNode **list, int unique, int reportDups) {
    hctofc(g)->sortGlyphClass(list, unique, reportDups);
}

GNode ***featMakeCrossProduct(hotCtx g, GNode *pat, unsigned *n) {
    return hctofc(g)->makeCrossProduct(pat, n);
}

Label featGetNextAnonLabel(hotCtx g) {
    return hctofc(g)->getNextAnonLabel();
}

int featValidateGPOSChain(hotCtx g, GNode *targ, int lookupType) {
    return hctofc(g)->validateGPOSChain(targ, lookupType);
}

} // extern "C"
