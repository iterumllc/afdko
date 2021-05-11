
// Generated from FeatParser.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "FeatParserVisitor.h"


/**
 * This class provides an empty implementation of FeatParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  FeatParserBaseVisitor : public FeatParserVisitor {
public:

  virtual antlrcpp::Any visitFeatureFile(FeatParser::FeatureFileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatementFile(FeatParser::StatementFileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTopLevelStatement(FeatParser::TopLevelStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInclude(FeatParser::IncludeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLangsysAssign(FeatParser::LangsysAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAnonBlock(FeatParser::AnonBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFeatureBlock(FeatParser::FeatureBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(FeatParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFeatureUse(FeatParser::FeatureUseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubstitute(FeatParser::SubstituteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPattern(FeatParser::PatternContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPatternElement(FeatParser::PatternElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGlyphClass(FeatParser::GlyphClassContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGcLiteral(FeatParser::GcLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGcLiteralElement(FeatParser::GcLiteralElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGlyph(FeatParser::GlyphContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGlyphName(FeatParser::GlyphNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTag(FeatParser::TagContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubtok(FeatParser::SubtokContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRevtok(FeatParser::RevtokContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAnontok(FeatParser::AnontokContext *ctx) override {
    return visitChildren(ctx);
  }


};

