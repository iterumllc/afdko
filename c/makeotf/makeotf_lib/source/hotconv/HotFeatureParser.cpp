
#include "assert.h"
#include "antlr4-runtime.h"
#include "FeaParserBaseVisitor.h"

#include "feat.h"

class HotFeatureParser : public FeaParserBaseVisitor {
    private:
        hotCtx g;
    public:
        HotFeatureParser() = delete;
        HotFeatureParser(hotCtx gc) : g(gc) {}

        int featFill(void) { assert(false); }
        void featReuse(void) { assert(false); }
	GNode *featSetNewNode(GID gid) { assert(false); }
        void featRecycleNodes(GNode *node) { assert(false); }
        GNode **featGlyphClassCopy(GNode **dst, GNode *src) { assert(false); }
        void featGlyphDump(GID gid, int ch, int print) { assert(false); }
        void featGlyphClassDump(GNode *gc, int ch, int print) { assert(false); }
        void featPatternDump(GNode *pat, int ch, int print) { assert(false); }
        GNode **featPatternCopy(GNode **dst, GNode *src, int num) { assert(false); }
        void featExtendNodeToClass(GNode *node, int num) { assert(false); }
        int featGetGlyphClassCount(GNode *gc) { assert(false); }
        unsigned int featGetPatternLen(GNode *pat) { assert(false); }
        void featGlyphClassSort(GNode **list, int unique, int reportDups) { assert(false); }
        GNode ***featMakeCrossProduct(GNode *pat, unsigned *n) { assert(false); }
        Label featGetNextAnonLabel(void) { assert(false); }
        int featValidateGPOSChain(GNode *targ, int lookupType) { assert(false); }
};

inline HotFeatureParser *hCtoHFPP(hotCtx g) {
    assert( g->ctx.feat != NULL );
    return (HotFeatureParser *) g->ctx.feat;
}

extern "C" {

void featNew(hotCtx g) {
    assert( g->ctx.feat == NULL );
    HotFeatureParser *hfp = new HotFeatureParser(g);
    g->ctx.feat = (void *) hfp;
}

void featFree(hotCtx g) {
    delete hCtoHFPP(g);
    g->ctx.feat = NULL;
}

int featFill(hotCtx g) { return hCtoHFPP(g)->featFill(); }
void featReuse(hotCtx g) { hCtoHFPP(g)->featReuse(); }

GNode *featSetNewNode(hotCtx g, GID gid) {
    return hCtoHFPP(g)->featSetNewNode(gid);
}

void featRecycleNodes(hotCtx g, GNode *node) {
    hCtoHFPP(g)->featRecycleNodes(node);
}

GNode **featGlyphClassCopy(hotCtx g, GNode **dst, GNode *src) {
    return hCtoHFPP(g)->featGlyphClassCopy(dst, src);
}

void featGlyphDump(hotCtx g, GID gid, int ch, int print) {
    hCtoHFPP(g)->featGlyphDump(gid, ch, print);
}

void featGlyphClassDump(hotCtx g, GNode *gc, int ch, int print) {
    hCtoHFPP(g)->featGlyphClassDump(gc, ch, print);
}

void featPatternDump(hotCtx g, GNode *pat, int ch, int print) {
    hCtoHFPP(g)->featPatternDump(pat, ch, print);
}

GNode **featPatternCopy(hotCtx g, GNode **dst, GNode *src, int num) {
    return hCtoHFPP(g)->featPatternCopy(dst, src, num);
}

void featExtendNodeToClass(hotCtx g, GNode *node, int num) {
    hCtoHFPP(g)->featExtendNodeToClass(node, num);
}

int featGetGlyphClassCount(hotCtx g, GNode *gc) {
    return hCtoHFPP(g)->featGetGlyphClassCount(gc);
}

unsigned int featGetPatternLen(hotCtx g, GNode *pat) {
    return hCtoHFPP(g)->featGetPatternLen(pat);
}

void featGlyphClassSort(hotCtx g, GNode **list, int unique, int reportDups) {
    hCtoHFPP(g)->featGlyphClassSort(list, unique, reportDups);
}

GNode ***featMakeCrossProduct(hotCtx g, GNode *pat, unsigned *n) {
    return hCtoHFPP(g)->featMakeCrossProduct(pat, n);
}

Label featGetNextAnonLabel(hotCtx g) {
    return hCtoHFPP(g)->featGetNextAnonLabel();
}

int featValidateGPOSChain(hotCtx g, GNode *targ, int lookupType) {
    return hCtoHFPP(g)->featValidateGPOSChain(targ, lookupType);
}

} // extern "C"
