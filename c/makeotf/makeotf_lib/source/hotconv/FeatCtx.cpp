
#include "antlr4-runtime.h"
#include "assert.h"
#include <iostream>
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
    hotMsg(g, hotFATAL, "Translation of %s finished \n", featpathname);
    return;
}

Tag FeatCtx::str2tag(std::string &tagName) {
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

Tag FeatCtx::checkTag(TagCtx *start, TagCtx *end, TagType type) {
    assert ( start != nullptr && end != nullptr );
    std::string st_str = start->getText();
    std::string et_str = end->getText();
    Tag stag = str2tag(st_str), etag = str2tag(et_str);

    if ( stag != etag )
        hotMsg(g, hotWARNING, "Start tag %s does not match end tag %s.", st_str.c_str(), et_str.c_str());

    return stag;
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

GNode *FeatCtx::newGNode() {
    auto &bl = blockList;
    if ( bl.first == nullptr || bl.cnt == (bl.curr==bl.first ? bl.intl : bl.incr) )
        addBlock();
    return bl.curr->data + bl.cnt++;
}

bool FeatCtx::LangSys::operator<(const FeatCtx::LangSys &b) {
    return std::tie(script, lang) < std::tie(b.script, b.lang);
}

bool FeatCtx::LangSys::operator==(const FeatCtx::LangSys &b) {
    return std::tie(script, lang) == std::tie(b.script, b.lang);
}

bool FeatCtx::State::operator==(const FeatCtx::State &b) {
    return memcmp(this, &b, sizeof(State))==0;
}

bool FeatCtx::AnchorDef::operator<(const FeatCtx::AnchorDef &b) {
    return name < b.name;
}

bool FeatCtx::ValueDef::operator<(const FeatCtx::ValueDef &b) {
    return name < b.name;
}

bool FeatCtx::AALT::FeatureRecord::operator==(const FeatCtx::AALT::FeatureRecord &b) {
    return feature == b.feature;
}

/*
void FeatCtx::startFeature(void) {
}

void FeatCtx::endFeature(void) {
    if ( curr.feature != aalt_ ) {
        closeFeatScriptLang(curr.feature);
        registerFeatureLangSys();
        prev.tbl = TAG_UNDEF;
    }
}
*/

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
    return hctofc(g)->glyphClassCopy(dst, src);
}

void featGlyphDump(hotCtx g, GID gid, int ch, int print) {
    hctofc(g)->glyphDump(gid, ch, print);
}

void featGlyphClassDump(hotCtx g, GNode *gc, int ch, int print) {
    hctofc(g)->glyphClassDump(gc, ch, print);
}

void featPatternDump(hotCtx g, GNode *pat, int ch, int print) {
    hctofc(g)->patternDump(pat, ch, print);
}

GNode **featPatternCopy(hotCtx g, GNode **dst, GNode *src, int num) {
    return hctofc(g)->patternCopy(dst, src, num);
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
    hctofc(g)->glyphClassSort(list, unique, reportDups);
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
