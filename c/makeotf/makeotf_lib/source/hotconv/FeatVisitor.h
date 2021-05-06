
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
        antlrcpp::Any visitFeatureBlock(FeatParser::FeatureBlockContext *ctx);
        antlrcpp::Any visitSubstitute(FeatParser::SubstituteContext *ctx);
        antlrcpp::Any visitInclude(FeatParser::IncludeContext *ctx);

        // "Remove" default visitors
        antlrcpp::Any visitPattern(FeatParser::PatternContext *ctx) override { assert(false); }
        antlrcpp::Any visitPatternElement(FeatParser::PatternElementContext *ctx) override { assert(false); }
        antlrcpp::Any visitGlyphClass(FeatParser::GlyphClassContext *ctx) override { assert(false); }
        antlrcpp::Any visitGcLiteralElement(FeatParser::GcLiteralElementContext *ctx) override { assert(false); }
        antlrcpp::Any visitGcLiteral(FeatParser::GcLiteralContext *ctx) override { assert(false); }
        antlrcpp::Any visitGlyph(FeatParser::GlyphContext *ctx) override { assert(false); }
        antlrcpp::Any visitGlyphName(FeatParser::GlyphNameContext *ctx) override { assert(false); }
        antlrcpp::Any visitTag(FeatParser::TagContext *ctx) override { assert(false); }
        
        // Translating visitors
        GNode *translatePattern(FeatParser::PatternContext *ctx, bool markedOK);
        GNode *translateGlyphClass(FeatParser::GlyphClassContext *ctx);
        GID getGlyph(FeatParser::GlyphContext *ctx, bool allowNotDef);

        // Utility
        void addGcLiteralToCurrentGC(FeatParser::GcLiteralContext *ctx);
        void translateGlyphClassAsCurrentGC(FeatParser::GlyphClassContext *ctx,
                                            const std::string *gcname, bool dontcopy);
        Tag checkTag(TagCtx *start, TagCtx *end);


        // State
        FeatCtx *fc;
        char *pathname, *dirname {nullptr};
        enum EntryPoints ep {Top};

        /* It appears that the parse tree is only valid for the lifetime of
         * the parser and the parser is only valid for the lifetime of just
         * about everything else. Therefore we keep all of it around until the
         * object is destroyed.
         */
        antlr4::ANTLRInputStream *input {nullptr};
        FeatLexer *lexer {nullptr};
        antlr4::CommonTokenStream *tokens {nullptr};
        FeatParser *parser {nullptr};
        antlr4::tree::ParseTree *tree {nullptr};
};
