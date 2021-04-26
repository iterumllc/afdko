
#include "assert.h"
#include "antlr4-runtime.h"
#include "FeaParserBaseVisitor.h"

#include "feat.h"

class HotFeatureVisitor : public FeaParserBaseVisitor {
    private:
        hotCtx g;
    public:
        HotFeatureVisitor() = delete;
        HotFeatureVisitor(hotCtx gc) : g(gc) {}

	// Hooks for external calls
        int fill(void) { assert(false); }
        void reuse(void) { assert(false); }
	GNode *setNewNode(GID gid) { assert(false); }
        void recycleNodes(GNode *node) { assert(false); }
        GNode **glyphClassCopy(GNode **dst, GNode *src) { assert(false); }
        void glyphDump(GID gid, int ch, int print) { assert(false); }
        void glyphClassDump(GNode *gc, int ch, int print) { assert(false); }
        void patternDump(GNode *pat, int ch, int print) { assert(false); }
        GNode **patternCopy(GNode **dst, GNode *src, int num) { assert(false); }
        void extendNodeToClass(GNode *node, int num) { assert(false); }
        int getGlyphClassCount(GNode *gc) { assert(false); }
        unsigned int getPatternLen(GNode *pat) { assert(false); }
        void glyphClassSort(GNode **list, int unique, int reportDups) { assert(false); }
        GNode ***makeCrossProduct(GNode *pat, unsigned *n) { assert(false); }
        Label getNextAnonLabel(void) { assert(false); }
        int validateGPOSChain(GNode *targ, int lookupType) { assert(false); }
};

inline HotFeatureVisitor *hCtoHFPP(hotCtx g) {
    assert( g->ctx.feat != NULL );
    return (HotFeatureVisitor *) g->ctx.feat;
}

extern "C" {

void featNew(hotCtx g) {
    assert( g->ctx.feat == NULL );
    HotFeatureVisitor *hfp = new HotFeatureVisitor(g);
    g->ctx.feat = (void *) hfp;
}

void featFree(hotCtx g) {
    delete hCtoHFPP(g);
    g->ctx.feat = NULL;
}

int featFill(hotCtx g) { return hCtoHFPP(g)->fill(); }
void featReuse(hotCtx g) { hCtoHFPP(g)->reuse(); }

GNode *featSetNewNode(hotCtx g, GID gid) {
    return hCtoHFPP(g)->setNewNode(gid);
}

void featRecycleNodes(hotCtx g, GNode *node) {
    hCtoHFPP(g)->recycleNodes(node);
}

GNode **featGlyphClassCopy(hotCtx g, GNode **dst, GNode *src) {
    return hCtoHFPP(g)->glyphClassCopy(dst, src);
}

void featGlyphDump(hotCtx g, GID gid, int ch, int print) {
    hCtoHFPP(g)->glyphDump(gid, ch, print);
}

void featGlyphClassDump(hotCtx g, GNode *gc, int ch, int print) {
    hCtoHFPP(g)->glyphClassDump(gc, ch, print);
}

void featPatternDump(hotCtx g, GNode *pat, int ch, int print) {
    hCtoHFPP(g)->patternDump(pat, ch, print);
}

GNode **featPatternCopy(hotCtx g, GNode **dst, GNode *src, int num) {
    return hCtoHFPP(g)->patternCopy(dst, src, num);
}

void featExtendNodeToClass(hotCtx g, GNode *node, int num) {
    hCtoHFPP(g)->extendNodeToClass(node, num);
}

int featGetGlyphClassCount(hotCtx g, GNode *gc) {
    return hCtoHFPP(g)->getGlyphClassCount(gc);
}

unsigned int featGetPatternLen(hotCtx g, GNode *pat) {
    return hCtoHFPP(g)->getPatternLen(pat);
}

void featGlyphClassSort(hotCtx g, GNode **list, int unique, int reportDups) {
    hCtoHFPP(g)->glyphClassSort(list, unique, reportDups);
}

GNode ***featMakeCrossProduct(hotCtx g, GNode *pat, unsigned *n) {
    return hCtoHFPP(g)->makeCrossProduct(pat, n);
}

Label featGetNextAnonLabel(hotCtx g) {
    return hCtoHFPP(g)->getNextAnonLabel();
}

int featValidateGPOSChain(hotCtx g, GNode *targ, int lookupType) {
    return hCtoHFPP(g)->validateGPOSChain(targ, lookupType);
}

} // extern "C"
