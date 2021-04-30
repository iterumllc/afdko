
#include "antlr4-runtime.h"
#include "assert.h"
#include "string.h"
#include "FeatCtx.h"
#include "FeatVisitor.h"
#include "FeatParser.h"

void FeatCtx::fill(void) {
    char *featpathname = g->cb.featTopLevelFile(g->cb.ctx);
    if ( featpathname == NULL )
        return;

    FeatVisitor *fv = new FeatVisitor(this, strdup(featpathname));
    if ( fv->ParseAndRegister(true) )
        fv->Translate();
    hotMsg(g, hotFATAL, "Translation of %s finished \n", featpathname);
    return;
}

FeatCtx::~FeatCtx() {
    // XXX destruct visitors
}

inline FeatCtx *hctofc(hotCtx g) {
    assert( g->ctx.feat != NULL );
    return (FeatCtx *) g->ctx.feat;
}

extern "C" {

void featNew(hotCtx g) {
    assert( g->ctx.feat == NULL );
    FeatCtx *hfp = new FeatCtx(g);
    g->ctx.feat = (void *) hfp;
}

void featFree(hotCtx g) {
    delete hctofc(g);
    g->ctx.feat = NULL;
}

void featFill(hotCtx g) { hctofc(g)->fill(); }
void featReuse(hotCtx g) { hctofc(g)->reuse(); }

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
