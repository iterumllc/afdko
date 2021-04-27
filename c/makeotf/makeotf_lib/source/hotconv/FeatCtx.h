
#include "assert.h"
#include "feat.h"

class FeatCtx {
    private:
        hotCtx g;
    public:
        FeatCtx() = delete;
        FeatCtx(hotCtx gc) : g(gc) {}

	// Implementations of external calls in feat.h
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
