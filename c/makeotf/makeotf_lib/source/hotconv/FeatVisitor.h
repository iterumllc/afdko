
#pragma once

#include "antlr4-runtime.h"
#include "assert.h"
#include "BaseErrorListener.h"
#include <iostream>
#include <map>

#include "FeatLexer.h"
#include "FeatParserBaseVisitor.h"
#include "FeatCtx.h"
#include "feat.h"

typedef antlr4::ParserRuleContext *(FeatParser::*FeatParsingEntry)();

class FeatVisitor : public FeatParserBaseVisitor {
    public:
        enum Stages { Include, Extract };
        enum EntryPoint { Top };
        FeatVisitor() = delete;
        FeatVisitor(FeatCtx *fc, FeatVisitor *parent,
                    FeatParser::IncludeContext *parent_ctx,
                    const char *pathname) : fc(fc), parent(parent),
                                            parent_ctx(parent_ctx),
                                            pathname(pathname) {
            fc->current_visitor = this;
        }
        virtual ~FeatVisitor();

        bool Parse(enum EntryPoint ep = Top);
        bool Translate();
        void newFileMsg(char **msg);
        void tokenPositionMsg(char **msg);
        const char *currentTokStr();

        inline antlr4::Token *TOK(antlr4::Token *t) { current_msg_token = t; return t; }
        template <class T, typename std::enable_if<std::is_base_of<antlr4::tree::TerminalNode,T>::value>::type* = nullptr>
            inline T* TOK(T* t) { current_msg_token = t->getSymbol(); return t; }
        template <class T, typename std::enable_if<std::is_base_of<antlr4::ParserRuleContext,T>::value>::type* = nullptr>
            inline T* TOK(T* t) { current_msg_token = t->getStart(); return t; }

    private:

        struct FeatErrorListener : public antlr4::BaseErrorListener {
            FeatErrorListener() = delete;
            FeatErrorListener(FeatVisitor &v) : v(v) {};
            virtual void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *symbol,
                                     size_t line, size_t charPositionInLine,
                                     const std::string &msg, std::exception_ptr e) override;
            FeatVisitor &v;
        };

        antlrcpp::Any visitInclude(FeatParser::IncludeContext *ctx);
        antlrcpp::Any visitLangsysAssign(FeatParser::LangsysAssignContext *ctx);
        antlrcpp::Any visitFeatureBlock(FeatParser::FeatureBlockContext *ctx);
        antlrcpp::Any visitSubstitute(FeatParser::SubstituteContext *ctx);
        antlrcpp::Any visitFeatureUse(FeatParser::FeatureUseContext *ctx);

        // Translating visitors
        GNode *translatePattern(FeatParser::PatternContext *ctx, bool markedOK);
        GNode *translateGlyphClass(FeatParser::GlyphClassContext *ctx);
        GID getGlyph(FeatParser::GlyphContext *ctx, bool allowNotDef);

        // Utility
        void addGcLiteralToCurrentGC(FeatParser::GcLiteralContext *ctx);
        void translateGlyphClassAsCurrentGC(FeatParser::GlyphClassContext *ctx,
                                            const std::string *gcname, bool dontcopy);
        Tag checkTag(FeatParser::TagContext *start, FeatParser::TagContext *end);

        // "Remove" default visitors
        antlrcpp::Any visitPattern(FeatParser::PatternContext *ctx) override { assert(false); }
        antlrcpp::Any visitPatternElement(FeatParser::PatternElementContext *ctx) override { assert(false); }
        antlrcpp::Any visitGlyphClass(FeatParser::GlyphClassContext *ctx) override { assert(false); }
        antlrcpp::Any visitGcLiteral(FeatParser::GcLiteralContext *ctx) override { assert(false); }
        antlrcpp::Any visitGcLiteralElement(FeatParser::GcLiteralElementContext *ctx) override { assert(false); }
        antlrcpp::Any visitGlyph(FeatParser::GlyphContext *ctx) override { assert(false); }
        antlrcpp::Any visitGlyphName(FeatParser::GlyphNameContext *ctx) override { assert(false); }
        antlrcpp::Any visitTag(FeatParser::TagContext *ctx) override { assert(false); }
        antlrcpp::Any visitSubtok(FeatParser::SubtokContext *ctx) override { assert(false); }
        antlrcpp::Any visitRevtok(FeatParser::RevtokContext *ctx) override { assert(false); }
        
        // State
        FeatCtx *fc;
        FeatVisitor *parent;
        FeatParser::IncludeContext *parent_ctx;
        std::string pathname, dirname;

        antlr4::Token *current_msg_token {nullptr};

        std::vector<FeatVisitor *> includes;
        int current_include {0};
        bool need_file_msg {true};

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
