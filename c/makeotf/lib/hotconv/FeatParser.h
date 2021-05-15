
// Generated from FeatParser.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  FeatParser : public antlr4::Parser {
public:
  enum {
    ANON = 1, ANONV = 2, COMMENT = 3, WHITESPACE = 4, BY = 5, FROM = 6, 
    FEATURE = 7, SUB = 8, SUBV = 9, REV = 10, REVV = 11, LANGSYS = 12, KNULL = 13, 
    INCLUDE = 14, LCBRACE = 15, RCBRACE = 16, LBRACKET = 17, RBRACKET = 18, 
    HYPHEN = 19, SEMI = 20, MARKER = 21, QUOTE = 22, GCLASS = 23, CID = 24, 
    ESCGNAME = 25, NAMELABEL = 26, EXTNAME = 27, CATCHTAG = 28, A_WHITESPACE = 29, 
    A_LABEL = 30, A_LBRACE = 31, A_CLOSE = 32, A_LINE = 33, I_WHITESPACE = 34, 
    I_RPAREN = 35, IFILE = 36, I_LPAREN = 37, STRVAL = 38, EQUOTE = 39
  };

  enum {
    RuleFeatureFile = 0, RuleStatementFile = 1, RuleTopLevelStatement = 2, 
    RuleInclude = 3, RuleLangsysAssign = 4, RuleAnonBlock = 5, RuleFeatureBlock = 6, 
    RuleStatement = 7, RuleFeatureUse = 8, RuleSubstitute = 9, RulePattern = 10, 
    RulePatternElement = 11, RuleGlyphClass = 12, RuleGcLiteral = 13, RuleGcLiteralElement = 14, 
    RuleGlyph = 15, RuleGlyphName = 16, RuleTag = 17, RuleSubtok = 18, RuleRevtok = 19, 
    RuleAnontok = 20
  };

  explicit FeatParser(antlr4::TokenStream *input);
  ~FeatParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class FeatureFileContext;
  class StatementFileContext;
  class TopLevelStatementContext;
  class IncludeContext;
  class LangsysAssignContext;
  class AnonBlockContext;
  class FeatureBlockContext;
  class StatementContext;
  class FeatureUseContext;
  class SubstituteContext;
  class PatternContext;
  class PatternElementContext;
  class GlyphClassContext;
  class GcLiteralContext;
  class GcLiteralElementContext;
  class GlyphContext;
  class GlyphNameContext;
  class TagContext;
  class SubtokContext;
  class RevtokContext;
  class AnontokContext; 

  class  FeatureFileContext : public antlr4::ParserRuleContext {
  public:
    FeatureFileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<TopLevelStatementContext *> topLevelStatement();
    TopLevelStatementContext* topLevelStatement(size_t i);
    std::vector<AnonBlockContext *> anonBlock();
    AnonBlockContext* anonBlock(size_t i);
    std::vector<FeatureBlockContext *> featureBlock();
    FeatureBlockContext* featureBlock(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FeatureFileContext* featureFile();

  class  StatementFileContext : public antlr4::ParserRuleContext {
  public:
    StatementFileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementFileContext* statementFile();

  class  TopLevelStatementContext : public antlr4::ParserRuleContext {
  public:
    TopLevelStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMI();
    IncludeContext *include();
    LangsysAssignContext *langsysAssign();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TopLevelStatementContext* topLevelStatement();

  class  IncludeContext : public antlr4::ParserRuleContext {
  public:
    IncludeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INCLUDE();
    antlr4::tree::TerminalNode *I_RPAREN();
    antlr4::tree::TerminalNode *IFILE();
    antlr4::tree::TerminalNode *I_LPAREN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IncludeContext* include();

  class  LangsysAssignContext : public antlr4::ParserRuleContext {
  public:
    FeatParser::TagContext *script = nullptr;
    FeatParser::TagContext *lang = nullptr;
    LangsysAssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LANGSYS();
    std::vector<TagContext *> tag();
    TagContext* tag(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LangsysAssignContext* langsysAssign();

  class  AnonBlockContext : public antlr4::ParserRuleContext {
  public:
    AnonBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AnontokContext *anontok();
    antlr4::tree::TerminalNode *A_LABEL();
    antlr4::tree::TerminalNode *A_LBRACE();
    antlr4::tree::TerminalNode *A_CLOSE();
    std::vector<antlr4::tree::TerminalNode *> A_LINE();
    antlr4::tree::TerminalNode* A_LINE(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnonBlockContext* anonBlock();

  class  FeatureBlockContext : public antlr4::ParserRuleContext {
  public:
    FeatParser::TagContext *starttag = nullptr;
    FeatParser::TagContext *endtag = nullptr;
    FeatureBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FEATURE();
    antlr4::tree::TerminalNode *LCBRACE();
    antlr4::tree::TerminalNode *RCBRACE();
    antlr4::tree::TerminalNode *SEMI();
    std::vector<TagContext *> tag();
    TagContext* tag(size_t i);
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FeatureBlockContext* featureBlock();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMI();
    FeatureUseContext *featureUse();
    SubstituteContext *substitute();
    IncludeContext *include();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  FeatureUseContext : public antlr4::ParserRuleContext {
  public:
    FeatureUseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FEATURE();
    TagContext *tag();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FeatureUseContext* featureUse();

  class  SubstituteContext : public antlr4::ParserRuleContext {
  public:
    FeatParser::PatternContext *startpat = nullptr;
    FeatParser::PatternContext *endpat = nullptr;
    SubstituteContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RevtokContext *revtok();
    antlr4::tree::TerminalNode *BY();
    std::vector<PatternContext *> pattern();
    PatternContext* pattern(size_t i);
    antlr4::tree::TerminalNode *KNULL();
    SubtokContext *subtok();
    antlr4::tree::TerminalNode *FROM();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SubstituteContext* substitute();

  class  PatternContext : public antlr4::ParserRuleContext {
  public:
    PatternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<PatternElementContext *> patternElement();
    PatternElementContext* patternElement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PatternContext* pattern();

  class  PatternElementContext : public antlr4::ParserRuleContext {
  public:
    PatternElementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    GlyphClassContext *glyphClass();
    GlyphContext *glyph();
    antlr4::tree::TerminalNode *MARKER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PatternElementContext* patternElement();

  class  GlyphClassContext : public antlr4::ParserRuleContext {
  public:
    GlyphClassContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GCLASS();
    GcLiteralContext *gcLiteral();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GlyphClassContext* glyphClass();

  class  GcLiteralContext : public antlr4::ParserRuleContext {
  public:
    GcLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACKET();
    antlr4::tree::TerminalNode *RBRACKET();
    std::vector<GcLiteralElementContext *> gcLiteralElement();
    GcLiteralElementContext* gcLiteralElement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GcLiteralContext* gcLiteral();

  class  GcLiteralElementContext : public antlr4::ParserRuleContext {
  public:
    FeatParser::GlyphContext *startg = nullptr;
    FeatParser::GlyphContext *endg = nullptr;
    GcLiteralElementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<GlyphContext *> glyph();
    GlyphContext* glyph(size_t i);
    antlr4::tree::TerminalNode *HYPHEN();
    antlr4::tree::TerminalNode *GCLASS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GcLiteralElementContext* gcLiteralElement();

  class  GlyphContext : public antlr4::ParserRuleContext {
  public:
    GlyphContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    GlyphNameContext *glyphName();
    antlr4::tree::TerminalNode *CID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GlyphContext* glyph();

  class  GlyphNameContext : public antlr4::ParserRuleContext {
  public:
    GlyphNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ESCGNAME();
    antlr4::tree::TerminalNode *NAMELABEL();
    antlr4::tree::TerminalNode *EXTNAME();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GlyphNameContext* glyphName();

  class  TagContext : public antlr4::ParserRuleContext {
  public:
    TagContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAMELABEL();
    antlr4::tree::TerminalNode *EXTNAME();
    antlr4::tree::TerminalNode *CATCHTAG();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TagContext* tag();

  class  SubtokContext : public antlr4::ParserRuleContext {
  public:
    SubtokContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SUB();
    antlr4::tree::TerminalNode *SUBV();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SubtokContext* subtok();

  class  RevtokContext : public antlr4::ParserRuleContext {
  public:
    RevtokContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REV();
    antlr4::tree::TerminalNode *REVV();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RevtokContext* revtok();

  class  AnontokContext : public antlr4::ParserRuleContext {
  public:
    AnontokContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ANON();
    antlr4::tree::TerminalNode *ANONV();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnontokContext* anontok();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

