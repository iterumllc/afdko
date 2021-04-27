
#include "assert.h"
#include "antlr4-runtime.h"
#include "FeatParserBaseVisitor.h"

#include "feat.h"

class FeatVisitor : public FeatParserBaseVisitor {
    public:
        FeatVisitor() = delete;
        FeatVisitor(featCtx featc) : fc(featc) {}

    private:
        featCtx fc;
};
