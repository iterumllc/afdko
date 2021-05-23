
#pragma once

#include "antlr4-runtime.h"
#include "assert.h"
#include "BaseErrorListener.h"
#include <functional>
#include <iostream>
#include <map>

#include "FeatLexer.h"
#include "FeatParserBaseVisitor.h"
#include "FeatCtx.h"
#include "feat.h"

/* Include handling:
 *
 * There is one FeatVisitor object per top-level or included file, with the
 * lexer, parser, and tree of that file. The top_ep variable stores the 
 * FeatParser method pointer to the parsing function for the appropriate
 * context, which is passed in at construction time.
 */

typedef antlr4::ParserRuleContext *(FeatParser::*FeatParsingEntry)();

class FeatVisitor : public FeatParserBaseVisitor {
    friend class FeatCtx;
    public:
        typedef std::function<antlr4::ParserRuleContext *(FeatParser&)> EntryPoint;

        FeatVisitor() = delete;
        FeatVisitor(FeatCtx *fc, const char *pathname,
                    FeatVisitor *parent = nullptr,
                    FeatParser::IncludeContext *parent_ctx = nullptr,
                    EntryPoint ep = &FeatParser::file,
                    int depth = 0)
                    : fc(fc), pathname(pathname), parent(parent),
                      parent_ctx(parent_ctx), top_ep(ep), depth(depth) { }
        virtual ~FeatVisitor();

        void Parse(bool do_includes = true);
        void Translate();

        void newFileMsg(char **msg);
        void tokenPositionMsg(char **msg, bool full=false);
        const char *currentTokStr();

        inline antlr4::Token *TOK(antlr4::Token *t) { current_msg_token = t; return t; }
        template <class T, typename std::enable_if<std::is_base_of<antlr4::tree::TerminalNode,T>::value>::type* = nullptr>
            inline T* TOK(T* t) { if (t) current_msg_token = t->getSymbol(); return t; }
        template <class T, typename std::enable_if<std::is_base_of<antlr4::ParserRuleContext,T>::value>::type* = nullptr>
            inline T* TOK(T* t) { if (t) current_msg_token = t->getStart(); return t; }

    private:
        enum Stage { vInclude = 1, vExtract } stage;

        struct FeatErrorListener : public antlr4::BaseErrorListener {
            FeatErrorListener() = delete;
            FeatErrorListener(FeatVisitor &v) : v(v) {};
            virtual void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *symbol,
                                     size_t line, size_t charPositionInLine,
                                     const std::string &msg, std::exception_ptr e) override;
            FeatVisitor &v;
        };

        antlrcpp::Any visitInclude(FeatParser::IncludeContext *ctx) override;

        antlrcpp::Any visitLangsysAssign(FeatParser::LangsysAssignContext *ctx) override;

        antlrcpp::Any visitValueRecordDef(FeatParser::ValueRecordDefContext *ctx) override;

        antlrcpp::Any visitAnchorDef(FeatParser::AnchorDefContext *ctx) override;

        antlrcpp::Any visitAnonBlock(FeatParser::AnonBlockContext *ctx) override;

        antlrcpp::Any visitTable_BASE(FeatParser::Table_BASEContext *ctx) override;
        antlrcpp::Any visitAxisTags(FeatParser::AxisTagsContext *ctx) override;
        antlrcpp::Any visitAxisScripts(FeatParser::AxisScriptsContext *ctx) override;

        antlrcpp::Any visitTable_GDEF(FeatParser::Table_GDEFContext *ctx) override;
        antlrcpp::Any visitGdefGlyphClass(FeatParser::GdefGlyphClassContext *ctx) override;
        antlrcpp::Any visitGdefAttach(FeatParser::GdefAttachContext *ctx) override;
        antlrcpp::Any visitGdefLigCaretPos(FeatParser::GdefLigCaretPosContext *ctx) override;
        antlrcpp::Any visitGdefLigCaretIndex(FeatParser::GdefLigCaretIndexContext *ctx) override;

        antlrcpp::Any visitTable_head(FeatParser::Table_headContext *ctx) override;

        antlrcpp::Any visitTable_hhea(FeatParser::Table_hheaContext *ctx) override;
        antlrcpp::Any visitHhea(FeatParser::HheaContext *ctx) override;

        antlrcpp::Any visitTable_vhea(FeatParser::Table_vheaContext *ctx) override;
        antlrcpp::Any visitVhea(FeatParser::VheaContext *ctx) override;

        antlrcpp::Any visitTable_name(FeatParser::Table_nameContext *ctx) override;
        antlrcpp::Any visitNameID(FeatParser::NameIDContext *ctx) override;

        antlrcpp::Any visitTable_vmtx(FeatParser::Table_vmtxContext *ctx) override;
        antlrcpp::Any visitVmtx(FeatParser::VmtxContext *ctx) override;

        antlrcpp::Any visitTable_STAT(FeatParser::Table_STATContext *ctx) override;
        antlrcpp::Any visitDesignAxis(FeatParser::DesignAxisContext *ctx) override;
        antlrcpp::Any visitNameEntry(FeatParser::NameEntryContext *ctx);
        antlrcpp::Any visitAxisValue(FeatParser::AxisValueContext *ctx) override;
        antlrcpp::Any visitAxisValueFlags(FeatParser::AxisValueFlagsContext *ctx);
        antlrcpp::Any visitAxisValueLocation(FeatParser::AxisValueLocationContext *ctx);
        antlrcpp::Any visitElidedFallbackName(FeatParser::ElidedFallbackNameContext *ctx) override;
        antlrcpp::Any visitElidedFallbackNameID(FeatParser::ElidedFallbackNameIDContext *ctx) override;

        antlrcpp::Any visitTable_OS_2(FeatParser::Table_OS_2Context *ctx) override;
        antlrcpp::Any visitOs_2(FeatParser::Os_2Context *ctx) override;

        antlrcpp::Any visitLookupBlockTopLevel(FeatParser::LookupBlockTopLevelContext *ctx) override;
        antlrcpp::Any visitLookupBlockOrUse(FeatParser::LookupBlockOrUseContext *ctx) override;

        antlrcpp::Any visitFeatureBlock(FeatParser::FeatureBlockContext *ctx) override;
        antlrcpp::Any visitSubtable(FeatParser::SubtableContext *ctx) override;
        antlrcpp::Any visitParameters(FeatParser::ParametersContext *ctx) override;
        antlrcpp::Any visitIgnoreSubOrPos(FeatParser::IgnoreSubOrPosContext *ctx) override;
        antlrcpp::Any visitSubstitute(FeatParser::SubstituteContext *ctx) override;
        antlrcpp::Any visitMark_statement(FeatParser::Mark_statementContext *ctx) override;
        antlrcpp::Any visitPosition(FeatParser::PositionContext *ctx) override;
        antlrcpp::Any visitFeatureUse(FeatParser::FeatureUseContext *ctx) override;
        antlrcpp::Any visitFeatureNames(FeatParser::FeatureNamesContext *ctx) override;
        antlrcpp::Any visitLookupflagAssign(FeatParser::LookupflagAssignContext *ctx) override;
        antlrcpp::Any visitSizemenuname(FeatParser::SizemenunameContext *ctx);
        antlrcpp::Any visitCvParameterBlock(FeatParser::CvParameterBlockContext *ctx) override;
        antlrcpp::Any visitCvParameter(FeatParser::CvParameterContext *ctx) override;

        antlrcpp::Any visitScriptAssign(FeatParser::ScriptAssignContext *ctx) override;

        antlrcpp::Any visitLangAssign(FeatParser::LangAssignContext *ctx) override;

        antlrcpp::Any visitGlyphClassAssign(FeatParser::GlyphClassAssignContext *ctx) override;

        // Translating visitors
        void translateBaseScript(FeatParser::BaseScriptContext *ctx, bool vert, size_t cnt);
        void translateGdefLigCaret(FeatParser::LookupPatternContext *pctx,
                                   std::vector<antlr4::tree::TerminalNode *> nv,
                                   unsigned short format);
        bool translateAnchor(FeatParser::AnchorContext *ctx, int componentIndex);

        // Retrieval visitors
        void getValueRecord(FeatParser::ValueRecordContext *ctx, MetricsInfo &mi);
        void getValueLiteral(FeatParser::ValueLiteralContext *ctx, MetricsInfo &mi);
        GNode *getLookupPattern(FeatParser::LookupPatternContext *ctx, bool markedOK);
        GNode *getLookupPatternElement(FeatParser::LookupPatternElementContext *ctx, bool markedOK);
        GNode *concatenatePattern(GNode **loc, FeatParser::PatternContext *ctx, int flags=0);
        GNode *concatenatePatternElement(GNode **loc, FeatParser::PatternElementContext *ctx);
        GNode *getPatternElement(FeatParser::PatternElementContext *ctx, bool markedOK);
        GNode *getGlyphClass(FeatParser::GlyphClassContext *ctx, bool dontcopy);
        GID getGlyph(FeatParser::GlyphContext *ctx, bool allowNotDef);

        // Utility
        void addGcLiteralToCurrentGC(FeatParser::GcLiteralContext *ctx);
        void getGlyphClassAsCurrentGC(FeatParser::GlyphClassContext *ctx,
                                      antlr4::tree::TerminalNode *target_gc,
                                      bool dontcopy);
        Tag checkTag(FeatParser::TagContext *start, FeatParser::TagContext *end);
        void checkLabel(FeatParser::LabelContext *start, FeatParser::LabelContext *end);

        template <typename T> T getNum(const std::string &str, int base = 0);
        template <typename T> T getFixed(FeatParser::FixedNumContext *ctx, bool param = false);

        // "Remove" default visitors
#ifndef NDEBUG
        antlrcpp::Any visitCursiveElement(FeatParser::CursiveElementContext *ctx) override { assert(false); }
        antlrcpp::Any visitBaseToMarkElement(FeatParser::BaseToMarkElementContext *ctx) override { assert(false); }
        antlrcpp::Any visitLigatureMarkElement(FeatParser::LigatureMarkElementContext *ctx) override { assert(false); }
        antlrcpp::Any visitValuePattern(FeatParser::ValuePatternContext *ctx) override { assert(false); }
        antlrcpp::Any visitLookupflagElement(FeatParser::LookupflagElementContext *ctx) override { assert(false); }
        antlrcpp::Any visitValueRecord(FeatParser::ValueRecordContext *ctx) override { assert(false); }
        antlrcpp::Any visitValueLiteral(FeatParser::ValueLiteralContext *ctx) override { assert(false); }
        antlrcpp::Any visitAnchor(FeatParser::AnchorContext *ctx) override { assert(false); }
        antlrcpp::Any visitLookupPattern(FeatParser::LookupPatternContext *ctx) override { assert(false); }
        antlrcpp::Any visitLookupPatternElement(FeatParser::LookupPatternElementContext *ctx) override { assert(false); }
        antlrcpp::Any visitPattern(FeatParser::PatternContext *ctx) override { assert(false); }
        antlrcpp::Any visitPatternElement(FeatParser::PatternElementContext *ctx) override { assert(false); }
        antlrcpp::Any visitGlyphClassOptional(FeatParser::GlyphClassOptionalContext *ctx) override { assert(false); }
        antlrcpp::Any visitGlyphClass(FeatParser::GlyphClassContext *ctx) override { assert(false); }
        antlrcpp::Any visitGcLiteral(FeatParser::GcLiteralContext *ctx) override { assert(false); }
        antlrcpp::Any visitGcLiteralElement(FeatParser::GcLiteralElementContext *ctx) override { assert(false); }
        antlrcpp::Any visitGlyph(FeatParser::GlyphContext *ctx) override { assert(false); }
        antlrcpp::Any visitGlyphName(FeatParser::GlyphNameContext *ctx) override { assert(false); }
        antlrcpp::Any visitLabel(FeatParser::LabelContext *ctx) override { assert(false); }
        antlrcpp::Any visitTag(FeatParser::TagContext *ctx) override { assert(false); }
        antlrcpp::Any visitFixedNum(FeatParser::FixedNumContext *ctx) override { assert(false); }
        antlrcpp::Any visitGenNum(FeatParser::GenNumContext *ctx) override { assert(false); }
        antlrcpp::Any visitSubtok(FeatParser::SubtokContext *ctx) override { assert(false); }
        antlrcpp::Any visitRevtok(FeatParser::RevtokContext *ctx) override { assert(false); }
        antlrcpp::Any visitAnontok(FeatParser::AnontokContext *ctx) override { assert(false); }
        antlrcpp::Any visitEnumtok(FeatParser::EnumtokContext *ctx) override { assert(false); }
        antlrcpp::Any visitPostok(FeatParser::PostokContext *ctx) override { assert(false); }
        antlrcpp::Any visitMarkligtok(FeatParser::MarkligtokContext *ctx) override { assert(false); }
#endif

        // State
        FeatCtx *fc;
        std::string pathname, dirname;
        FeatVisitor *parent;
        FeatParser::IncludeContext *parent_ctx;

        antlr4::Token *current_msg_token {nullptr};

        std::vector<FeatVisitor *> includes;
        size_t current_include {0};
        EntryPoint top_ep, include_ep;
        int depth;
        bool need_file_msg {true};

        bool all_includes_parse {true};

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
