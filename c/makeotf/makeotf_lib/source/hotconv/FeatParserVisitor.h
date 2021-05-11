
// Generated from FeatParser.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "FeatParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by FeatParser.
 */
class  FeatParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by FeatParser.
   */
    virtual antlrcpp::Any visitFeatureFile(FeatParser::FeatureFileContext *context) = 0;

    virtual antlrcpp::Any visitStatementFile(FeatParser::StatementFileContext *context) = 0;

    virtual antlrcpp::Any visitTopLevelStatement(FeatParser::TopLevelStatementContext *context) = 0;

    virtual antlrcpp::Any visitInclude(FeatParser::IncludeContext *context) = 0;

    virtual antlrcpp::Any visitLangsysAssign(FeatParser::LangsysAssignContext *context) = 0;

    virtual antlrcpp::Any visitAnonBlock(FeatParser::AnonBlockContext *context) = 0;

    virtual antlrcpp::Any visitFeatureBlock(FeatParser::FeatureBlockContext *context) = 0;

    virtual antlrcpp::Any visitStatement(FeatParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitFeatureUse(FeatParser::FeatureUseContext *context) = 0;

    virtual antlrcpp::Any visitSubstitute(FeatParser::SubstituteContext *context) = 0;

    virtual antlrcpp::Any visitPattern(FeatParser::PatternContext *context) = 0;

    virtual antlrcpp::Any visitPatternElement(FeatParser::PatternElementContext *context) = 0;

    virtual antlrcpp::Any visitGlyphClass(FeatParser::GlyphClassContext *context) = 0;

    virtual antlrcpp::Any visitGcLiteral(FeatParser::GcLiteralContext *context) = 0;

    virtual antlrcpp::Any visitGcLiteralElement(FeatParser::GcLiteralElementContext *context) = 0;

    virtual antlrcpp::Any visitGlyph(FeatParser::GlyphContext *context) = 0;

    virtual antlrcpp::Any visitGlyphName(FeatParser::GlyphNameContext *context) = 0;

    virtual antlrcpp::Any visitTag(FeatParser::TagContext *context) = 0;

    virtual antlrcpp::Any visitSubtok(FeatParser::SubtokContext *context) = 0;

    virtual antlrcpp::Any visitRevtok(FeatParser::RevtokContext *context) = 0;

    virtual antlrcpp::Any visitAnontok(FeatParser::AnontokContext *context) = 0;


};

