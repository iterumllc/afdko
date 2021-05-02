
#pragma once

#include "assert.h"
#include <iostream>
#include "antlr4-runtime.h"
#include "FeatLexer.h"
#include "FeatParserBaseVisitor.h"
#include "FeatCtx.h"

#include "feat.h"

typedef antlr4::ParserRuleContext *(FeatParser::*FeatParsingEntry)();

class FeatVisitor : public FeatParserBaseVisitor {
    public:
        enum Stages { Include, Extract };
        enum EntryPoints { Top };
        FeatVisitor() = delete;
        FeatVisitor(FeatCtx *featc, char *name)
            : fc(featc), pathname(name) {}
        virtual ~FeatVisitor();

        bool ParseAndRegister(bool toplevel);
        bool Translate();

    private:
        virtual antlrcpp::Any visitTag(FeatParser::TagContext *ctx);
        virtual antlrcpp::Any visitGlyph(FeatParser::GlyphContext *ctx);
        virtual antlrcpp::Any visitGlyphclass(FeatParser::GlyphclassContext *ctx);
        virtual antlrcpp::Any visitPattern(FeatParser::PatternContext *ctx);
        virtual antlrcpp::Any visitSubstitute(FeatParser::SubstituteContext *ctx);
        virtual antlrcpp::Any visitInclude(FeatParser::IncludeContext *ctx);
        virtual antlrcpp::Any visitFeatureBlock(FeatParser::FeatureBlockContext *ctx);

        FeatCtx *fc;
        char *pathname, *dirname = NULL;
        enum EntryPoints ep = Top;

        /* It appears that the parse tree is only valid for the lifetime of
         * the parser and the parser is only valid for the lifetime of just
         * about everything else, so we keep all that stuff around until the
         * object is destroyed.
         */
        antlr4::ANTLRInputStream *input = NULL;
        FeatLexer *lexer = NULL;
        antlr4::CommonTokenStream *tokens = NULL;
        FeatParser *parser = NULL;
        antlr4::tree::ParseTree *tree = NULL;
};
