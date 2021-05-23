
// Generated from FeatParser.g4 by ANTLR 4.9.2


#include "FeatParserVisitor.h"

#include "FeatParser.h"


using namespace antlrcpp;
using namespace antlr4;

FeatParser::FeatParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

FeatParser::~FeatParser() {
  delete _interpreter;
}

std::string FeatParser::getGrammarFileName() const {
  return "FeatParser.g4";
}

const std::vector<std::string>& FeatParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& FeatParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- FileContext ------------------------------------------------------------------

FeatParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::FileContext::EOF() {
  return getToken(FeatParser::EOF, 0);
}

std::vector<FeatParser::TopLevelStatementContext *> FeatParser::FileContext::topLevelStatement() {
  return getRuleContexts<FeatParser::TopLevelStatementContext>();
}

FeatParser::TopLevelStatementContext* FeatParser::FileContext::topLevelStatement(size_t i) {
  return getRuleContext<FeatParser::TopLevelStatementContext>(i);
}

std::vector<FeatParser::FeatureBlockContext *> FeatParser::FileContext::featureBlock() {
  return getRuleContexts<FeatParser::FeatureBlockContext>();
}

FeatParser::FeatureBlockContext* FeatParser::FileContext::featureBlock(size_t i) {
  return getRuleContext<FeatParser::FeatureBlockContext>(i);
}

std::vector<FeatParser::TableBlockContext *> FeatParser::FileContext::tableBlock() {
  return getRuleContexts<FeatParser::TableBlockContext>();
}

FeatParser::TableBlockContext* FeatParser::FileContext::tableBlock(size_t i) {
  return getRuleContext<FeatParser::TableBlockContext>(i);
}

std::vector<FeatParser::AnonBlockContext *> FeatParser::FileContext::anonBlock() {
  return getRuleContexts<FeatParser::AnonBlockContext>();
}

FeatParser::AnonBlockContext* FeatParser::FileContext::anonBlock(size_t i) {
  return getRuleContext<FeatParser::AnonBlockContext>(i);
}

std::vector<FeatParser::LookupBlockTopLevelContext *> FeatParser::FileContext::lookupBlockTopLevel() {
  return getRuleContexts<FeatParser::LookupBlockTopLevelContext>();
}

FeatParser::LookupBlockTopLevelContext* FeatParser::FileContext::lookupBlockTopLevel(size_t i) {
  return getRuleContext<FeatParser::LookupBlockTopLevelContext>(i);
}


size_t FeatParser::FileContext::getRuleIndex() const {
  return FeatParser::RuleFile;
}


antlrcpp::Any FeatParser::FileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitFile(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::FileContext* FeatParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, FeatParser::RuleFile);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(223);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FeatParser::ANON)
      | (1ULL << FeatParser::ANON_v)
      | (1ULL << FeatParser::INCLUDE)
      | (1ULL << FeatParser::FEATURE)
      | (1ULL << FeatParser::TABLE)
      | (1ULL << FeatParser::LANGSYS)
      | (1ULL << FeatParser::LOOKUP)
      | (1ULL << FeatParser::ANCHOR_DEF)
      | (1ULL << FeatParser::VALUE_RECORD_DEF)
      | (1ULL << FeatParser::MARK_CLASS))) != 0) || _la == FeatParser::GCLASS) {
      setState(221);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case FeatParser::INCLUDE:
        case FeatParser::LANGSYS:
        case FeatParser::ANCHOR_DEF:
        case FeatParser::VALUE_RECORD_DEF:
        case FeatParser::MARK_CLASS:
        case FeatParser::GCLASS: {
          setState(216);
          topLevelStatement();
          break;
        }

        case FeatParser::FEATURE: {
          setState(217);
          featureBlock();
          break;
        }

        case FeatParser::TABLE: {
          setState(218);
          tableBlock();
          break;
        }

        case FeatParser::ANON:
        case FeatParser::ANON_v: {
          setState(219);
          anonBlock();
          break;
        }

        case FeatParser::LOOKUP: {
          setState(220);
          lookupBlockTopLevel();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(225);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(226);
    match(FeatParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TopLevelStatementContext ------------------------------------------------------------------

FeatParser::TopLevelStatementContext::TopLevelStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::TopLevelStatementContext::SEMI() {
  return getToken(FeatParser::SEMI, 0);
}

FeatParser::IncludeContext* FeatParser::TopLevelStatementContext::include() {
  return getRuleContext<FeatParser::IncludeContext>(0);
}

FeatParser::GlyphClassAssignContext* FeatParser::TopLevelStatementContext::glyphClassAssign() {
  return getRuleContext<FeatParser::GlyphClassAssignContext>(0);
}

FeatParser::LangsysAssignContext* FeatParser::TopLevelStatementContext::langsysAssign() {
  return getRuleContext<FeatParser::LangsysAssignContext>(0);
}

FeatParser::Mark_statementContext* FeatParser::TopLevelStatementContext::mark_statement() {
  return getRuleContext<FeatParser::Mark_statementContext>(0);
}

FeatParser::AnchorDefContext* FeatParser::TopLevelStatementContext::anchorDef() {
  return getRuleContext<FeatParser::AnchorDefContext>(0);
}

FeatParser::ValueRecordDefContext* FeatParser::TopLevelStatementContext::valueRecordDef() {
  return getRuleContext<FeatParser::ValueRecordDefContext>(0);
}


size_t FeatParser::TopLevelStatementContext::getRuleIndex() const {
  return FeatParser::RuleTopLevelStatement;
}


antlrcpp::Any FeatParser::TopLevelStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitTopLevelStatement(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::TopLevelStatementContext* FeatParser::topLevelStatement() {
  TopLevelStatementContext *_localctx = _tracker.createInstance<TopLevelStatementContext>(_ctx, getState());
  enterRule(_localctx, 2, FeatParser::RuleTopLevelStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(234);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::INCLUDE: {
        setState(228);
        include();
        break;
      }

      case FeatParser::GCLASS: {
        setState(229);
        glyphClassAssign();
        break;
      }

      case FeatParser::LANGSYS: {
        setState(230);
        langsysAssign();
        break;
      }

      case FeatParser::MARK_CLASS: {
        setState(231);
        mark_statement();
        break;
      }

      case FeatParser::ANCHOR_DEF: {
        setState(232);
        anchorDef();
        break;
      }

      case FeatParser::VALUE_RECORD_DEF: {
        setState(233);
        valueRecordDef();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(236);
    match(FeatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IncludeContext ------------------------------------------------------------------

FeatParser::IncludeContext::IncludeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::IncludeContext::INCLUDE() {
  return getToken(FeatParser::INCLUDE, 0);
}

tree::TerminalNode* FeatParser::IncludeContext::I_RPAREN() {
  return getToken(FeatParser::I_RPAREN, 0);
}

tree::TerminalNode* FeatParser::IncludeContext::IFILE() {
  return getToken(FeatParser::IFILE, 0);
}

tree::TerminalNode* FeatParser::IncludeContext::I_LPAREN() {
  return getToken(FeatParser::I_LPAREN, 0);
}


size_t FeatParser::IncludeContext::getRuleIndex() const {
  return FeatParser::RuleInclude;
}


antlrcpp::Any FeatParser::IncludeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitInclude(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::IncludeContext* FeatParser::include() {
  IncludeContext *_localctx = _tracker.createInstance<IncludeContext>(_ctx, getState());
  enterRule(_localctx, 4, FeatParser::RuleInclude);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(238);
    match(FeatParser::INCLUDE);
    setState(239);
    match(FeatParser::I_RPAREN);
    setState(240);
    match(FeatParser::IFILE);
    setState(241);
    match(FeatParser::I_LPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GlyphClassAssignContext ------------------------------------------------------------------

FeatParser::GlyphClassAssignContext::GlyphClassAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::GlyphClassAssignContext::GCLASS() {
  return getToken(FeatParser::GCLASS, 0);
}

tree::TerminalNode* FeatParser::GlyphClassAssignContext::EQUALS() {
  return getToken(FeatParser::EQUALS, 0);
}

FeatParser::GlyphClassContext* FeatParser::GlyphClassAssignContext::glyphClass() {
  return getRuleContext<FeatParser::GlyphClassContext>(0);
}


size_t FeatParser::GlyphClassAssignContext::getRuleIndex() const {
  return FeatParser::RuleGlyphClassAssign;
}


antlrcpp::Any FeatParser::GlyphClassAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitGlyphClassAssign(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::GlyphClassAssignContext* FeatParser::glyphClassAssign() {
  GlyphClassAssignContext *_localctx = _tracker.createInstance<GlyphClassAssignContext>(_ctx, getState());
  enterRule(_localctx, 6, FeatParser::RuleGlyphClassAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(243);
    match(FeatParser::GCLASS);
    setState(244);
    match(FeatParser::EQUALS);
    setState(245);
    glyphClass();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LangsysAssignContext ------------------------------------------------------------------

FeatParser::LangsysAssignContext::LangsysAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::LangsysAssignContext::LANGSYS() {
  return getToken(FeatParser::LANGSYS, 0);
}

std::vector<FeatParser::TagContext *> FeatParser::LangsysAssignContext::tag() {
  return getRuleContexts<FeatParser::TagContext>();
}

FeatParser::TagContext* FeatParser::LangsysAssignContext::tag(size_t i) {
  return getRuleContext<FeatParser::TagContext>(i);
}


size_t FeatParser::LangsysAssignContext::getRuleIndex() const {
  return FeatParser::RuleLangsysAssign;
}


antlrcpp::Any FeatParser::LangsysAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitLangsysAssign(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::LangsysAssignContext* FeatParser::langsysAssign() {
  LangsysAssignContext *_localctx = _tracker.createInstance<LangsysAssignContext>(_ctx, getState());
  enterRule(_localctx, 8, FeatParser::RuleLangsysAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(247);
    match(FeatParser::LANGSYS);
    setState(248);
    dynamic_cast<LangsysAssignContext *>(_localctx)->script = tag();
    setState(249);
    dynamic_cast<LangsysAssignContext *>(_localctx)->lang = tag();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Mark_statementContext ------------------------------------------------------------------

FeatParser::Mark_statementContext::Mark_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::Mark_statementContext::MARK_CLASS() {
  return getToken(FeatParser::MARK_CLASS, 0);
}

FeatParser::AnchorContext* FeatParser::Mark_statementContext::anchor() {
  return getRuleContext<FeatParser::AnchorContext>(0);
}

tree::TerminalNode* FeatParser::Mark_statementContext::GCLASS() {
  return getToken(FeatParser::GCLASS, 0);
}

FeatParser::GlyphContext* FeatParser::Mark_statementContext::glyph() {
  return getRuleContext<FeatParser::GlyphContext>(0);
}

FeatParser::GlyphClassContext* FeatParser::Mark_statementContext::glyphClass() {
  return getRuleContext<FeatParser::GlyphClassContext>(0);
}


size_t FeatParser::Mark_statementContext::getRuleIndex() const {
  return FeatParser::RuleMark_statement;
}


antlrcpp::Any FeatParser::Mark_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitMark_statement(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::Mark_statementContext* FeatParser::mark_statement() {
  Mark_statementContext *_localctx = _tracker.createInstance<Mark_statementContext>(_ctx, getState());
  enterRule(_localctx, 10, FeatParser::RuleMark_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(251);
    match(FeatParser::MARK_CLASS);
    setState(254);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::CID:
      case FeatParser::ESCGNAME:
      case FeatParser::NAMELABEL:
      case FeatParser::EXTNAME: {
        setState(252);
        glyph();
        break;
      }

      case FeatParser::LBRACKET:
      case FeatParser::GCLASS: {
        setState(253);
        glyphClass();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(256);
    anchor();
    setState(257);
    match(FeatParser::GCLASS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnchorDefContext ------------------------------------------------------------------

FeatParser::AnchorDefContext::AnchorDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::AnchorDefContext::ANCHOR_DEF() {
  return getToken(FeatParser::ANCHOR_DEF, 0);
}

std::vector<tree::TerminalNode *> FeatParser::AnchorDefContext::NUM() {
  return getTokens(FeatParser::NUM);
}

tree::TerminalNode* FeatParser::AnchorDefContext::NUM(size_t i) {
  return getToken(FeatParser::NUM, i);
}

FeatParser::LabelContext* FeatParser::AnchorDefContext::label() {
  return getRuleContext<FeatParser::LabelContext>(0);
}

tree::TerminalNode* FeatParser::AnchorDefContext::CONTOURPOINT() {
  return getToken(FeatParser::CONTOURPOINT, 0);
}


size_t FeatParser::AnchorDefContext::getRuleIndex() const {
  return FeatParser::RuleAnchorDef;
}


antlrcpp::Any FeatParser::AnchorDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitAnchorDef(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::AnchorDefContext* FeatParser::anchorDef() {
  AnchorDefContext *_localctx = _tracker.createInstance<AnchorDefContext>(_ctx, getState());
  enterRule(_localctx, 12, FeatParser::RuleAnchorDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(259);
    match(FeatParser::ANCHOR_DEF);
    setState(260);
    dynamic_cast<AnchorDefContext *>(_localctx)->xval = match(FeatParser::NUM);
    setState(261);
    dynamic_cast<AnchorDefContext *>(_localctx)->yval = match(FeatParser::NUM);
    setState(264);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FeatParser::CONTOURPOINT) {
      setState(262);
      match(FeatParser::CONTOURPOINT);
      setState(263);
      dynamic_cast<AnchorDefContext *>(_localctx)->cp = match(FeatParser::NUM);
    }
    setState(266);
    dynamic_cast<AnchorDefContext *>(_localctx)->name = label();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueRecordDefContext ------------------------------------------------------------------

FeatParser::ValueRecordDefContext::ValueRecordDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::ValueRecordDefContext::VALUE_RECORD_DEF() {
  return getToken(FeatParser::VALUE_RECORD_DEF, 0);
}

FeatParser::ValueLiteralContext* FeatParser::ValueRecordDefContext::valueLiteral() {
  return getRuleContext<FeatParser::ValueLiteralContext>(0);
}

FeatParser::LabelContext* FeatParser::ValueRecordDefContext::label() {
  return getRuleContext<FeatParser::LabelContext>(0);
}


size_t FeatParser::ValueRecordDefContext::getRuleIndex() const {
  return FeatParser::RuleValueRecordDef;
}


antlrcpp::Any FeatParser::ValueRecordDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitValueRecordDef(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::ValueRecordDefContext* FeatParser::valueRecordDef() {
  ValueRecordDefContext *_localctx = _tracker.createInstance<ValueRecordDefContext>(_ctx, getState());
  enterRule(_localctx, 14, FeatParser::RuleValueRecordDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(268);
    match(FeatParser::VALUE_RECORD_DEF);
    setState(269);
    valueLiteral();
    setState(270);
    label();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FeatureBlockContext ------------------------------------------------------------------

FeatParser::FeatureBlockContext::FeatureBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::FeatureBlockContext::FEATURE() {
  return getToken(FeatParser::FEATURE, 0);
}

tree::TerminalNode* FeatParser::FeatureBlockContext::LCBRACE() {
  return getToken(FeatParser::LCBRACE, 0);
}

tree::TerminalNode* FeatParser::FeatureBlockContext::RCBRACE() {
  return getToken(FeatParser::RCBRACE, 0);
}

tree::TerminalNode* FeatParser::FeatureBlockContext::SEMI() {
  return getToken(FeatParser::SEMI, 0);
}

std::vector<FeatParser::TagContext *> FeatParser::FeatureBlockContext::tag() {
  return getRuleContexts<FeatParser::TagContext>();
}

FeatParser::TagContext* FeatParser::FeatureBlockContext::tag(size_t i) {
  return getRuleContext<FeatParser::TagContext>(i);
}

tree::TerminalNode* FeatParser::FeatureBlockContext::USE_EXTENSION() {
  return getToken(FeatParser::USE_EXTENSION, 0);
}

std::vector<FeatParser::FeatureStatementContext *> FeatParser::FeatureBlockContext::featureStatement() {
  return getRuleContexts<FeatParser::FeatureStatementContext>();
}

FeatParser::FeatureStatementContext* FeatParser::FeatureBlockContext::featureStatement(size_t i) {
  return getRuleContext<FeatParser::FeatureStatementContext>(i);
}


size_t FeatParser::FeatureBlockContext::getRuleIndex() const {
  return FeatParser::RuleFeatureBlock;
}


antlrcpp::Any FeatParser::FeatureBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitFeatureBlock(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::FeatureBlockContext* FeatParser::featureBlock() {
  FeatureBlockContext *_localctx = _tracker.createInstance<FeatureBlockContext>(_ctx, getState());
  enterRule(_localctx, 16, FeatParser::RuleFeatureBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(272);
    match(FeatParser::FEATURE);
    setState(273);
    dynamic_cast<FeatureBlockContext *>(_localctx)->starttag = tag();
    setState(275);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FeatParser::USE_EXTENSION) {
      setState(274);
      match(FeatParser::USE_EXTENSION);
    }
    setState(277);
    match(FeatParser::LCBRACE);
    setState(279); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(278);
      featureStatement();
      setState(281); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FeatParser::INCLUDE)
      | (1ULL << FeatParser::FEATURE)
      | (1ULL << FeatParser::SCRIPT)
      | (1ULL << FeatParser::LANGUAGE)
      | (1ULL << FeatParser::SUBTABLE)
      | (1ULL << FeatParser::LOOKUP)
      | (1ULL << FeatParser::LOOKUPFLAG)
      | (1ULL << FeatParser::ENUMERATE)
      | (1ULL << FeatParser::ENUMERATE_v)
      | (1ULL << FeatParser::EXCEPT)
      | (1ULL << FeatParser::IGNORE)
      | (1ULL << FeatParser::SUBSTITUTE)
      | (1ULL << FeatParser::SUBSTITUTE_v)
      | (1ULL << FeatParser::REVERSE)
      | (1ULL << FeatParser::REVERSE_v)
      | (1ULL << FeatParser::POSITION)
      | (1ULL << FeatParser::POSITION_v)
      | (1ULL << FeatParser::PARAMETERS)
      | (1ULL << FeatParser::FEATURE_NAMES)
      | (1ULL << FeatParser::CV_PARAMETERS)
      | (1ULL << FeatParser::SIZEMENUNAME)
      | (1ULL << FeatParser::MARK_CLASS))) != 0) || _la == FeatParser::GCLASS);
    setState(283);
    match(FeatParser::RCBRACE);
    setState(284);
    dynamic_cast<FeatureBlockContext *>(_localctx)->endtag = tag();
    setState(285);
    match(FeatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TableBlockContext ------------------------------------------------------------------

FeatParser::TableBlockContext::TableBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::TableBlockContext::TABLE() {
  return getToken(FeatParser::TABLE, 0);
}

FeatParser::Table_BASEContext* FeatParser::TableBlockContext::table_BASE() {
  return getRuleContext<FeatParser::Table_BASEContext>(0);
}

FeatParser::Table_GDEFContext* FeatParser::TableBlockContext::table_GDEF() {
  return getRuleContext<FeatParser::Table_GDEFContext>(0);
}

FeatParser::Table_headContext* FeatParser::TableBlockContext::table_head() {
  return getRuleContext<FeatParser::Table_headContext>(0);
}

FeatParser::Table_hheaContext* FeatParser::TableBlockContext::table_hhea() {
  return getRuleContext<FeatParser::Table_hheaContext>(0);
}

FeatParser::Table_vheaContext* FeatParser::TableBlockContext::table_vhea() {
  return getRuleContext<FeatParser::Table_vheaContext>(0);
}

FeatParser::Table_nameContext* FeatParser::TableBlockContext::table_name() {
  return getRuleContext<FeatParser::Table_nameContext>(0);
}

FeatParser::Table_OS_2Context* FeatParser::TableBlockContext::table_OS_2() {
  return getRuleContext<FeatParser::Table_OS_2Context>(0);
}

FeatParser::Table_STATContext* FeatParser::TableBlockContext::table_STAT() {
  return getRuleContext<FeatParser::Table_STATContext>(0);
}

FeatParser::Table_vmtxContext* FeatParser::TableBlockContext::table_vmtx() {
  return getRuleContext<FeatParser::Table_vmtxContext>(0);
}


size_t FeatParser::TableBlockContext::getRuleIndex() const {
  return FeatParser::RuleTableBlock;
}


antlrcpp::Any FeatParser::TableBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitTableBlock(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::TableBlockContext* FeatParser::tableBlock() {
  TableBlockContext *_localctx = _tracker.createInstance<TableBlockContext>(_ctx, getState());
  enterRule(_localctx, 18, FeatParser::RuleTableBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(287);
    match(FeatParser::TABLE);
    setState(297);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::BASE: {
        setState(288);
        table_BASE();
        break;
      }

      case FeatParser::GDEF: {
        setState(289);
        table_GDEF();
        break;
      }

      case FeatParser::HEAD: {
        setState(290);
        table_head();
        break;
      }

      case FeatParser::HHEA: {
        setState(291);
        table_hhea();
        break;
      }

      case FeatParser::VHEA: {
        setState(292);
        table_vhea();
        break;
      }

      case FeatParser::NAME: {
        setState(293);
        table_name();
        break;
      }

      case FeatParser::OS_2: {
        setState(294);
        table_OS_2();
        break;
      }

      case FeatParser::STAT: {
        setState(295);
        table_STAT();
        break;
      }

      case FeatParser::VMTX: {
        setState(296);
        table_vmtx();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnonBlockContext ------------------------------------------------------------------

FeatParser::AnonBlockContext::AnonBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FeatParser::AnontokContext* FeatParser::AnonBlockContext::anontok() {
  return getRuleContext<FeatParser::AnontokContext>(0);
}

tree::TerminalNode* FeatParser::AnonBlockContext::A_LABEL() {
  return getToken(FeatParser::A_LABEL, 0);
}

tree::TerminalNode* FeatParser::AnonBlockContext::A_LBRACE() {
  return getToken(FeatParser::A_LBRACE, 0);
}

tree::TerminalNode* FeatParser::AnonBlockContext::A_CLOSE() {
  return getToken(FeatParser::A_CLOSE, 0);
}

std::vector<tree::TerminalNode *> FeatParser::AnonBlockContext::A_LINE() {
  return getTokens(FeatParser::A_LINE);
}

tree::TerminalNode* FeatParser::AnonBlockContext::A_LINE(size_t i) {
  return getToken(FeatParser::A_LINE, i);
}


size_t FeatParser::AnonBlockContext::getRuleIndex() const {
  return FeatParser::RuleAnonBlock;
}


antlrcpp::Any FeatParser::AnonBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitAnonBlock(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::AnonBlockContext* FeatParser::anonBlock() {
  AnonBlockContext *_localctx = _tracker.createInstance<AnonBlockContext>(_ctx, getState());
  enterRule(_localctx, 20, FeatParser::RuleAnonBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(299);
    anontok();
    setState(300);
    match(FeatParser::A_LABEL);
    setState(301);
    match(FeatParser::A_LBRACE);
    setState(305);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FeatParser::A_LINE) {
      setState(302);
      match(FeatParser::A_LINE);
      setState(307);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(308);
    match(FeatParser::A_CLOSE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LookupBlockTopLevelContext ------------------------------------------------------------------

FeatParser::LookupBlockTopLevelContext::LookupBlockTopLevelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::LookupBlockTopLevelContext::LOOKUP() {
  return getToken(FeatParser::LOOKUP, 0);
}

tree::TerminalNode* FeatParser::LookupBlockTopLevelContext::LCBRACE() {
  return getToken(FeatParser::LCBRACE, 0);
}

tree::TerminalNode* FeatParser::LookupBlockTopLevelContext::RCBRACE() {
  return getToken(FeatParser::RCBRACE, 0);
}

tree::TerminalNode* FeatParser::LookupBlockTopLevelContext::SEMI() {
  return getToken(FeatParser::SEMI, 0);
}

std::vector<FeatParser::LabelContext *> FeatParser::LookupBlockTopLevelContext::label() {
  return getRuleContexts<FeatParser::LabelContext>();
}

FeatParser::LabelContext* FeatParser::LookupBlockTopLevelContext::label(size_t i) {
  return getRuleContext<FeatParser::LabelContext>(i);
}

tree::TerminalNode* FeatParser::LookupBlockTopLevelContext::USE_EXTENSION() {
  return getToken(FeatParser::USE_EXTENSION, 0);
}

std::vector<FeatParser::StatementContext *> FeatParser::LookupBlockTopLevelContext::statement() {
  return getRuleContexts<FeatParser::StatementContext>();
}

FeatParser::StatementContext* FeatParser::LookupBlockTopLevelContext::statement(size_t i) {
  return getRuleContext<FeatParser::StatementContext>(i);
}


size_t FeatParser::LookupBlockTopLevelContext::getRuleIndex() const {
  return FeatParser::RuleLookupBlockTopLevel;
}


antlrcpp::Any FeatParser::LookupBlockTopLevelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitLookupBlockTopLevel(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::LookupBlockTopLevelContext* FeatParser::lookupBlockTopLevel() {
  LookupBlockTopLevelContext *_localctx = _tracker.createInstance<LookupBlockTopLevelContext>(_ctx, getState());
  enterRule(_localctx, 22, FeatParser::RuleLookupBlockTopLevel);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(310);
    match(FeatParser::LOOKUP);
    setState(311);
    dynamic_cast<LookupBlockTopLevelContext *>(_localctx)->startlabel = label();
    setState(313);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FeatParser::USE_EXTENSION) {
      setState(312);
      match(FeatParser::USE_EXTENSION);
    }
    setState(315);
    match(FeatParser::LCBRACE);
    setState(317); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(316);
      statement();
      setState(319); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FeatParser::INCLUDE)
      | (1ULL << FeatParser::FEATURE)
      | (1ULL << FeatParser::SCRIPT)
      | (1ULL << FeatParser::LANGUAGE)
      | (1ULL << FeatParser::SUBTABLE)
      | (1ULL << FeatParser::LOOKUPFLAG)
      | (1ULL << FeatParser::ENUMERATE)
      | (1ULL << FeatParser::ENUMERATE_v)
      | (1ULL << FeatParser::EXCEPT)
      | (1ULL << FeatParser::IGNORE)
      | (1ULL << FeatParser::SUBSTITUTE)
      | (1ULL << FeatParser::SUBSTITUTE_v)
      | (1ULL << FeatParser::REVERSE)
      | (1ULL << FeatParser::REVERSE_v)
      | (1ULL << FeatParser::POSITION)
      | (1ULL << FeatParser::POSITION_v)
      | (1ULL << FeatParser::PARAMETERS)
      | (1ULL << FeatParser::FEATURE_NAMES)
      | (1ULL << FeatParser::SIZEMENUNAME)
      | (1ULL << FeatParser::MARK_CLASS))) != 0) || _la == FeatParser::GCLASS);
    setState(321);
    match(FeatParser::RCBRACE);
    setState(322);
    dynamic_cast<LookupBlockTopLevelContext *>(_localctx)->endlabel = label();
    setState(323);
    match(FeatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FeatureStatementContext ------------------------------------------------------------------

FeatParser::FeatureStatementContext::FeatureStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FeatParser::StatementContext* FeatParser::FeatureStatementContext::statement() {
  return getRuleContext<FeatParser::StatementContext>(0);
}

FeatParser::LookupBlockOrUseContext* FeatParser::FeatureStatementContext::lookupBlockOrUse() {
  return getRuleContext<FeatParser::LookupBlockOrUseContext>(0);
}

FeatParser::CvParameterBlockContext* FeatParser::FeatureStatementContext::cvParameterBlock() {
  return getRuleContext<FeatParser::CvParameterBlockContext>(0);
}


size_t FeatParser::FeatureStatementContext::getRuleIndex() const {
  return FeatParser::RuleFeatureStatement;
}


antlrcpp::Any FeatParser::FeatureStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitFeatureStatement(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::FeatureStatementContext* FeatParser::featureStatement() {
  FeatureStatementContext *_localctx = _tracker.createInstance<FeatureStatementContext>(_ctx, getState());
  enterRule(_localctx, 24, FeatParser::RuleFeatureStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(328);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::INCLUDE:
      case FeatParser::FEATURE:
      case FeatParser::SCRIPT:
      case FeatParser::LANGUAGE:
      case FeatParser::SUBTABLE:
      case FeatParser::LOOKUPFLAG:
      case FeatParser::ENUMERATE:
      case FeatParser::ENUMERATE_v:
      case FeatParser::EXCEPT:
      case FeatParser::IGNORE:
      case FeatParser::SUBSTITUTE:
      case FeatParser::SUBSTITUTE_v:
      case FeatParser::REVERSE:
      case FeatParser::REVERSE_v:
      case FeatParser::POSITION:
      case FeatParser::POSITION_v:
      case FeatParser::PARAMETERS:
      case FeatParser::FEATURE_NAMES:
      case FeatParser::SIZEMENUNAME:
      case FeatParser::MARK_CLASS:
      case FeatParser::GCLASS: {
        enterOuterAlt(_localctx, 1);
        setState(325);
        statement();
        break;
      }

      case FeatParser::LOOKUP: {
        enterOuterAlt(_localctx, 2);
        setState(326);
        lookupBlockOrUse();
        break;
      }

      case FeatParser::CV_PARAMETERS: {
        enterOuterAlt(_localctx, 3);
        setState(327);
        cvParameterBlock();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LookupBlockOrUseContext ------------------------------------------------------------------

FeatParser::LookupBlockOrUseContext::LookupBlockOrUseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::LookupBlockOrUseContext::LOOKUP() {
  return getToken(FeatParser::LOOKUP, 0);
}

tree::TerminalNode* FeatParser::LookupBlockOrUseContext::SEMI() {
  return getToken(FeatParser::SEMI, 0);
}

std::vector<FeatParser::LabelContext *> FeatParser::LookupBlockOrUseContext::label() {
  return getRuleContexts<FeatParser::LabelContext>();
}

FeatParser::LabelContext* FeatParser::LookupBlockOrUseContext::label(size_t i) {
  return getRuleContext<FeatParser::LabelContext>(i);
}

tree::TerminalNode* FeatParser::LookupBlockOrUseContext::LCBRACE() {
  return getToken(FeatParser::LCBRACE, 0);
}

tree::TerminalNode* FeatParser::LookupBlockOrUseContext::RCBRACE() {
  return getToken(FeatParser::RCBRACE, 0);
}

tree::TerminalNode* FeatParser::LookupBlockOrUseContext::USE_EXTENSION() {
  return getToken(FeatParser::USE_EXTENSION, 0);
}

std::vector<FeatParser::StatementContext *> FeatParser::LookupBlockOrUseContext::statement() {
  return getRuleContexts<FeatParser::StatementContext>();
}

FeatParser::StatementContext* FeatParser::LookupBlockOrUseContext::statement(size_t i) {
  return getRuleContext<FeatParser::StatementContext>(i);
}


size_t FeatParser::LookupBlockOrUseContext::getRuleIndex() const {
  return FeatParser::RuleLookupBlockOrUse;
}


antlrcpp::Any FeatParser::LookupBlockOrUseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitLookupBlockOrUse(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::LookupBlockOrUseContext* FeatParser::lookupBlockOrUse() {
  LookupBlockOrUseContext *_localctx = _tracker.createInstance<LookupBlockOrUseContext>(_ctx, getState());
  enterRule(_localctx, 26, FeatParser::RuleLookupBlockOrUse);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(330);
    match(FeatParser::LOOKUP);
    setState(331);
    dynamic_cast<LookupBlockOrUseContext *>(_localctx)->startlabel = label();
    setState(344);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FeatParser::USE_EXTENSION || _la == FeatParser::LCBRACE) {
      setState(333);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == FeatParser::USE_EXTENSION) {
        setState(332);
        match(FeatParser::USE_EXTENSION);
      }
      setState(335);
      match(FeatParser::LCBRACE);
      setState(337); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(336);
        statement();
        setState(339); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << FeatParser::INCLUDE)
        | (1ULL << FeatParser::FEATURE)
        | (1ULL << FeatParser::SCRIPT)
        | (1ULL << FeatParser::LANGUAGE)
        | (1ULL << FeatParser::SUBTABLE)
        | (1ULL << FeatParser::LOOKUPFLAG)
        | (1ULL << FeatParser::ENUMERATE)
        | (1ULL << FeatParser::ENUMERATE_v)
        | (1ULL << FeatParser::EXCEPT)
        | (1ULL << FeatParser::IGNORE)
        | (1ULL << FeatParser::SUBSTITUTE)
        | (1ULL << FeatParser::SUBSTITUTE_v)
        | (1ULL << FeatParser::REVERSE)
        | (1ULL << FeatParser::REVERSE_v)
        | (1ULL << FeatParser::POSITION)
        | (1ULL << FeatParser::POSITION_v)
        | (1ULL << FeatParser::PARAMETERS)
        | (1ULL << FeatParser::FEATURE_NAMES)
        | (1ULL << FeatParser::SIZEMENUNAME)
        | (1ULL << FeatParser::MARK_CLASS))) != 0) || _la == FeatParser::GCLASS);
      setState(341);
      match(FeatParser::RCBRACE);
      setState(342);
      dynamic_cast<LookupBlockOrUseContext *>(_localctx)->endlabel = label();
    }
    setState(346);
    match(FeatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CvParameterBlockContext ------------------------------------------------------------------

FeatParser::CvParameterBlockContext::CvParameterBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::CvParameterBlockContext::CV_PARAMETERS() {
  return getToken(FeatParser::CV_PARAMETERS, 0);
}

tree::TerminalNode* FeatParser::CvParameterBlockContext::LCBRACE() {
  return getToken(FeatParser::LCBRACE, 0);
}

tree::TerminalNode* FeatParser::CvParameterBlockContext::RCBRACE() {
  return getToken(FeatParser::RCBRACE, 0);
}

tree::TerminalNode* FeatParser::CvParameterBlockContext::SEMI() {
  return getToken(FeatParser::SEMI, 0);
}

std::vector<FeatParser::CvParameterStatementContext *> FeatParser::CvParameterBlockContext::cvParameterStatement() {
  return getRuleContexts<FeatParser::CvParameterStatementContext>();
}

FeatParser::CvParameterStatementContext* FeatParser::CvParameterBlockContext::cvParameterStatement(size_t i) {
  return getRuleContext<FeatParser::CvParameterStatementContext>(i);
}


size_t FeatParser::CvParameterBlockContext::getRuleIndex() const {
  return FeatParser::RuleCvParameterBlock;
}


antlrcpp::Any FeatParser::CvParameterBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitCvParameterBlock(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::CvParameterBlockContext* FeatParser::cvParameterBlock() {
  CvParameterBlockContext *_localctx = _tracker.createInstance<CvParameterBlockContext>(_ctx, getState());
  enterRule(_localctx, 28, FeatParser::RuleCvParameterBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(348);
    match(FeatParser::CV_PARAMETERS);
    setState(349);
    match(FeatParser::LCBRACE);
    setState(353);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FeatParser::INCLUDE)
      | (1ULL << FeatParser::CV_UI_LABEL)
      | (1ULL << FeatParser::CV_TOOLTIP)
      | (1ULL << FeatParser::CV_SAMPLE_TEXT)
      | (1ULL << FeatParser::CV_PARAM_LABEL)
      | (1ULL << FeatParser::CV_CHARACTER))) != 0)) {
      setState(350);
      cvParameterStatement();
      setState(355);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(356);
    match(FeatParser::RCBRACE);
    setState(357);
    match(FeatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CvParameterStatementContext ------------------------------------------------------------------

FeatParser::CvParameterStatementContext::CvParameterStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::CvParameterStatementContext::SEMI() {
  return getToken(FeatParser::SEMI, 0);
}

FeatParser::CvParameterContext* FeatParser::CvParameterStatementContext::cvParameter() {
  return getRuleContext<FeatParser::CvParameterContext>(0);
}

FeatParser::IncludeContext* FeatParser::CvParameterStatementContext::include() {
  return getRuleContext<FeatParser::IncludeContext>(0);
}


size_t FeatParser::CvParameterStatementContext::getRuleIndex() const {
  return FeatParser::RuleCvParameterStatement;
}


antlrcpp::Any FeatParser::CvParameterStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitCvParameterStatement(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::CvParameterStatementContext* FeatParser::cvParameterStatement() {
  CvParameterStatementContext *_localctx = _tracker.createInstance<CvParameterStatementContext>(_ctx, getState());
  enterRule(_localctx, 30, FeatParser::RuleCvParameterStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(361);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::CV_UI_LABEL:
      case FeatParser::CV_TOOLTIP:
      case FeatParser::CV_SAMPLE_TEXT:
      case FeatParser::CV_PARAM_LABEL:
      case FeatParser::CV_CHARACTER: {
        setState(359);
        cvParameter();
        break;
      }

      case FeatParser::INCLUDE: {
        setState(360);
        include();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(363);
    match(FeatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CvParameterContext ------------------------------------------------------------------

FeatParser::CvParameterContext::CvParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::CvParameterContext::LCBRACE() {
  return getToken(FeatParser::LCBRACE, 0);
}

tree::TerminalNode* FeatParser::CvParameterContext::RCBRACE() {
  return getToken(FeatParser::RCBRACE, 0);
}

tree::TerminalNode* FeatParser::CvParameterContext::CV_UI_LABEL() {
  return getToken(FeatParser::CV_UI_LABEL, 0);
}

tree::TerminalNode* FeatParser::CvParameterContext::CV_TOOLTIP() {
  return getToken(FeatParser::CV_TOOLTIP, 0);
}

tree::TerminalNode* FeatParser::CvParameterContext::CV_SAMPLE_TEXT() {
  return getToken(FeatParser::CV_SAMPLE_TEXT, 0);
}

tree::TerminalNode* FeatParser::CvParameterContext::CV_PARAM_LABEL() {
  return getToken(FeatParser::CV_PARAM_LABEL, 0);
}

std::vector<FeatParser::NameEntryStatementContext *> FeatParser::CvParameterContext::nameEntryStatement() {
  return getRuleContexts<FeatParser::NameEntryStatementContext>();
}

FeatParser::NameEntryStatementContext* FeatParser::CvParameterContext::nameEntryStatement(size_t i) {
  return getRuleContext<FeatParser::NameEntryStatementContext>(i);
}

tree::TerminalNode* FeatParser::CvParameterContext::CV_CHARACTER() {
  return getToken(FeatParser::CV_CHARACTER, 0);
}

FeatParser::GenNumContext* FeatParser::CvParameterContext::genNum() {
  return getRuleContext<FeatParser::GenNumContext>(0);
}


size_t FeatParser::CvParameterContext::getRuleIndex() const {
  return FeatParser::RuleCvParameter;
}


antlrcpp::Any FeatParser::CvParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitCvParameter(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::CvParameterContext* FeatParser::cvParameter() {
  CvParameterContext *_localctx = _tracker.createInstance<CvParameterContext>(_ctx, getState());
  enterRule(_localctx, 32, FeatParser::RuleCvParameter);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(376);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::CV_UI_LABEL:
      case FeatParser::CV_TOOLTIP:
      case FeatParser::CV_SAMPLE_TEXT:
      case FeatParser::CV_PARAM_LABEL: {
        enterOuterAlt(_localctx, 1);
        setState(365);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << FeatParser::CV_UI_LABEL)
          | (1ULL << FeatParser::CV_TOOLTIP)
          | (1ULL << FeatParser::CV_SAMPLE_TEXT)
          | (1ULL << FeatParser::CV_PARAM_LABEL))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(366);
        match(FeatParser::LCBRACE);
        setState(368); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(367);
          nameEntryStatement();
          setState(370); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == FeatParser::INCLUDE || _la == FeatParser::NAME);
        setState(372);
        match(FeatParser::RCBRACE);
        break;
      }

      case FeatParser::CV_CHARACTER: {
        enterOuterAlt(_localctx, 2);
        setState(374);
        match(FeatParser::CV_CHARACTER);
        setState(375);
        genNum();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

FeatParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::StatementContext::SEMI() {
  return getToken(FeatParser::SEMI, 0);
}

FeatParser::FeatureUseContext* FeatParser::StatementContext::featureUse() {
  return getRuleContext<FeatParser::FeatureUseContext>(0);
}

FeatParser::ScriptAssignContext* FeatParser::StatementContext::scriptAssign() {
  return getRuleContext<FeatParser::ScriptAssignContext>(0);
}

FeatParser::LangAssignContext* FeatParser::StatementContext::langAssign() {
  return getRuleContext<FeatParser::LangAssignContext>(0);
}

FeatParser::LookupflagAssignContext* FeatParser::StatementContext::lookupflagAssign() {
  return getRuleContext<FeatParser::LookupflagAssignContext>(0);
}

FeatParser::GlyphClassAssignContext* FeatParser::StatementContext::glyphClassAssign() {
  return getRuleContext<FeatParser::GlyphClassAssignContext>(0);
}

FeatParser::IgnoreSubOrPosContext* FeatParser::StatementContext::ignoreSubOrPos() {
  return getRuleContext<FeatParser::IgnoreSubOrPosContext>(0);
}

FeatParser::SubstituteContext* FeatParser::StatementContext::substitute() {
  return getRuleContext<FeatParser::SubstituteContext>(0);
}

FeatParser::Mark_statementContext* FeatParser::StatementContext::mark_statement() {
  return getRuleContext<FeatParser::Mark_statementContext>(0);
}

FeatParser::PositionContext* FeatParser::StatementContext::position() {
  return getRuleContext<FeatParser::PositionContext>(0);
}

FeatParser::ParametersContext* FeatParser::StatementContext::parameters() {
  return getRuleContext<FeatParser::ParametersContext>(0);
}

FeatParser::SizemenunameContext* FeatParser::StatementContext::sizemenuname() {
  return getRuleContext<FeatParser::SizemenunameContext>(0);
}

FeatParser::FeatureNamesContext* FeatParser::StatementContext::featureNames() {
  return getRuleContext<FeatParser::FeatureNamesContext>(0);
}

FeatParser::SubtableContext* FeatParser::StatementContext::subtable() {
  return getRuleContext<FeatParser::SubtableContext>(0);
}

FeatParser::IncludeContext* FeatParser::StatementContext::include() {
  return getRuleContext<FeatParser::IncludeContext>(0);
}


size_t FeatParser::StatementContext::getRuleIndex() const {
  return FeatParser::RuleStatement;
}


antlrcpp::Any FeatParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::StatementContext* FeatParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 34, FeatParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(392);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::FEATURE: {
        setState(378);
        featureUse();
        break;
      }

      case FeatParser::SCRIPT: {
        setState(379);
        scriptAssign();
        break;
      }

      case FeatParser::LANGUAGE: {
        setState(380);
        langAssign();
        break;
      }

      case FeatParser::LOOKUPFLAG: {
        setState(381);
        lookupflagAssign();
        break;
      }

      case FeatParser::GCLASS: {
        setState(382);
        glyphClassAssign();
        break;
      }

      case FeatParser::IGNORE: {
        setState(383);
        ignoreSubOrPos();
        break;
      }

      case FeatParser::EXCEPT:
      case FeatParser::SUBSTITUTE:
      case FeatParser::SUBSTITUTE_v:
      case FeatParser::REVERSE:
      case FeatParser::REVERSE_v: {
        setState(384);
        substitute();
        break;
      }

      case FeatParser::MARK_CLASS: {
        setState(385);
        mark_statement();
        break;
      }

      case FeatParser::ENUMERATE:
      case FeatParser::ENUMERATE_v:
      case FeatParser::POSITION:
      case FeatParser::POSITION_v: {
        setState(386);
        position();
        break;
      }

      case FeatParser::PARAMETERS: {
        setState(387);
        parameters();
        break;
      }

      case FeatParser::SIZEMENUNAME: {
        setState(388);
        sizemenuname();
        break;
      }

      case FeatParser::FEATURE_NAMES: {
        setState(389);
        featureNames();
        break;
      }

      case FeatParser::SUBTABLE: {
        setState(390);
        subtable();
        break;
      }

      case FeatParser::INCLUDE: {
        setState(391);
        include();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(394);
    match(FeatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FeatureUseContext ------------------------------------------------------------------

FeatParser::FeatureUseContext::FeatureUseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::FeatureUseContext::FEATURE() {
  return getToken(FeatParser::FEATURE, 0);
}

FeatParser::TagContext* FeatParser::FeatureUseContext::tag() {
  return getRuleContext<FeatParser::TagContext>(0);
}


size_t FeatParser::FeatureUseContext::getRuleIndex() const {
  return FeatParser::RuleFeatureUse;
}


antlrcpp::Any FeatParser::FeatureUseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitFeatureUse(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::FeatureUseContext* FeatParser::featureUse() {
  FeatureUseContext *_localctx = _tracker.createInstance<FeatureUseContext>(_ctx, getState());
  enterRule(_localctx, 36, FeatParser::RuleFeatureUse);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(396);
    match(FeatParser::FEATURE);
    setState(397);
    tag();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScriptAssignContext ------------------------------------------------------------------

FeatParser::ScriptAssignContext::ScriptAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::ScriptAssignContext::SCRIPT() {
  return getToken(FeatParser::SCRIPT, 0);
}

FeatParser::TagContext* FeatParser::ScriptAssignContext::tag() {
  return getRuleContext<FeatParser::TagContext>(0);
}


size_t FeatParser::ScriptAssignContext::getRuleIndex() const {
  return FeatParser::RuleScriptAssign;
}


antlrcpp::Any FeatParser::ScriptAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitScriptAssign(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::ScriptAssignContext* FeatParser::scriptAssign() {
  ScriptAssignContext *_localctx = _tracker.createInstance<ScriptAssignContext>(_ctx, getState());
  enterRule(_localctx, 38, FeatParser::RuleScriptAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(399);
    match(FeatParser::SCRIPT);
    setState(400);
    tag();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LangAssignContext ------------------------------------------------------------------

FeatParser::LangAssignContext::LangAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::LangAssignContext::LANGUAGE() {
  return getToken(FeatParser::LANGUAGE, 0);
}

FeatParser::TagContext* FeatParser::LangAssignContext::tag() {
  return getRuleContext<FeatParser::TagContext>(0);
}

tree::TerminalNode* FeatParser::LangAssignContext::EXCLUDE_DFLT() {
  return getToken(FeatParser::EXCLUDE_DFLT, 0);
}

tree::TerminalNode* FeatParser::LangAssignContext::INCLUDE_DFLT() {
  return getToken(FeatParser::INCLUDE_DFLT, 0);
}

tree::TerminalNode* FeatParser::LangAssignContext::EXCLUDE_dflt() {
  return getToken(FeatParser::EXCLUDE_dflt, 0);
}

tree::TerminalNode* FeatParser::LangAssignContext::INCLUDE_dflt() {
  return getToken(FeatParser::INCLUDE_dflt, 0);
}


size_t FeatParser::LangAssignContext::getRuleIndex() const {
  return FeatParser::RuleLangAssign;
}


antlrcpp::Any FeatParser::LangAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitLangAssign(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::LangAssignContext* FeatParser::langAssign() {
  LangAssignContext *_localctx = _tracker.createInstance<LangAssignContext>(_ctx, getState());
  enterRule(_localctx, 40, FeatParser::RuleLangAssign);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(402);
    match(FeatParser::LANGUAGE);
    setState(403);
    tag();
    setState(405);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FeatParser::EXCLUDE_DFLT)
      | (1ULL << FeatParser::INCLUDE_DFLT)
      | (1ULL << FeatParser::EXCLUDE_dflt)
      | (1ULL << FeatParser::INCLUDE_dflt))) != 0)) {
      setState(404);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << FeatParser::EXCLUDE_DFLT)
        | (1ULL << FeatParser::INCLUDE_DFLT)
        | (1ULL << FeatParser::EXCLUDE_dflt)
        | (1ULL << FeatParser::INCLUDE_dflt))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LookupflagAssignContext ------------------------------------------------------------------

FeatParser::LookupflagAssignContext::LookupflagAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::LookupflagAssignContext::LOOKUPFLAG() {
  return getToken(FeatParser::LOOKUPFLAG, 0);
}

tree::TerminalNode* FeatParser::LookupflagAssignContext::NUM() {
  return getToken(FeatParser::NUM, 0);
}

std::vector<FeatParser::LookupflagElementContext *> FeatParser::LookupflagAssignContext::lookupflagElement() {
  return getRuleContexts<FeatParser::LookupflagElementContext>();
}

FeatParser::LookupflagElementContext* FeatParser::LookupflagAssignContext::lookupflagElement(size_t i) {
  return getRuleContext<FeatParser::LookupflagElementContext>(i);
}


size_t FeatParser::LookupflagAssignContext::getRuleIndex() const {
  return FeatParser::RuleLookupflagAssign;
}


antlrcpp::Any FeatParser::LookupflagAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitLookupflagAssign(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::LookupflagAssignContext* FeatParser::lookupflagAssign() {
  LookupflagAssignContext *_localctx = _tracker.createInstance<LookupflagAssignContext>(_ctx, getState());
  enterRule(_localctx, 42, FeatParser::RuleLookupflagAssign);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(407);
    match(FeatParser::LOOKUPFLAG);
    setState(414);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::NUM: {
        setState(408);
        match(FeatParser::NUM);
        break;
      }

      case FeatParser::RIGHT_TO_LEFT:
      case FeatParser::IGNORE_BASE_GLYPHS:
      case FeatParser::IGNORE_LIGATURES:
      case FeatParser::IGNORE_MARKS:
      case FeatParser::USE_MARK_FILTERING_SET:
      case FeatParser::MARK_ATTACHMENT_TYPE: {
        setState(410); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(409);
          lookupflagElement();
          setState(412); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << FeatParser::RIGHT_TO_LEFT)
          | (1ULL << FeatParser::IGNORE_BASE_GLYPHS)
          | (1ULL << FeatParser::IGNORE_LIGATURES)
          | (1ULL << FeatParser::IGNORE_MARKS)
          | (1ULL << FeatParser::USE_MARK_FILTERING_SET)
          | (1ULL << FeatParser::MARK_ATTACHMENT_TYPE))) != 0));
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LookupflagElementContext ------------------------------------------------------------------

FeatParser::LookupflagElementContext::LookupflagElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::LookupflagElementContext::RIGHT_TO_LEFT() {
  return getToken(FeatParser::RIGHT_TO_LEFT, 0);
}

tree::TerminalNode* FeatParser::LookupflagElementContext::IGNORE_BASE_GLYPHS() {
  return getToken(FeatParser::IGNORE_BASE_GLYPHS, 0);
}

tree::TerminalNode* FeatParser::LookupflagElementContext::IGNORE_LIGATURES() {
  return getToken(FeatParser::IGNORE_LIGATURES, 0);
}

tree::TerminalNode* FeatParser::LookupflagElementContext::IGNORE_MARKS() {
  return getToken(FeatParser::IGNORE_MARKS, 0);
}

tree::TerminalNode* FeatParser::LookupflagElementContext::MARK_ATTACHMENT_TYPE() {
  return getToken(FeatParser::MARK_ATTACHMENT_TYPE, 0);
}

FeatParser::GlyphClassContext* FeatParser::LookupflagElementContext::glyphClass() {
  return getRuleContext<FeatParser::GlyphClassContext>(0);
}

tree::TerminalNode* FeatParser::LookupflagElementContext::USE_MARK_FILTERING_SET() {
  return getToken(FeatParser::USE_MARK_FILTERING_SET, 0);
}


size_t FeatParser::LookupflagElementContext::getRuleIndex() const {
  return FeatParser::RuleLookupflagElement;
}


antlrcpp::Any FeatParser::LookupflagElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitLookupflagElement(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::LookupflagElementContext* FeatParser::lookupflagElement() {
  LookupflagElementContext *_localctx = _tracker.createInstance<LookupflagElementContext>(_ctx, getState());
  enterRule(_localctx, 44, FeatParser::RuleLookupflagElement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(424);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::RIGHT_TO_LEFT: {
        enterOuterAlt(_localctx, 1);
        setState(416);
        match(FeatParser::RIGHT_TO_LEFT);
        break;
      }

      case FeatParser::IGNORE_BASE_GLYPHS: {
        enterOuterAlt(_localctx, 2);
        setState(417);
        match(FeatParser::IGNORE_BASE_GLYPHS);
        break;
      }

      case FeatParser::IGNORE_LIGATURES: {
        enterOuterAlt(_localctx, 3);
        setState(418);
        match(FeatParser::IGNORE_LIGATURES);
        break;
      }

      case FeatParser::IGNORE_MARKS: {
        enterOuterAlt(_localctx, 4);
        setState(419);
        match(FeatParser::IGNORE_MARKS);
        break;
      }

      case FeatParser::MARK_ATTACHMENT_TYPE: {
        enterOuterAlt(_localctx, 5);
        setState(420);
        match(FeatParser::MARK_ATTACHMENT_TYPE);
        setState(421);
        glyphClass();
        break;
      }

      case FeatParser::USE_MARK_FILTERING_SET: {
        enterOuterAlt(_localctx, 6);
        setState(422);
        match(FeatParser::USE_MARK_FILTERING_SET);
        setState(423);
        glyphClass();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IgnoreSubOrPosContext ------------------------------------------------------------------

FeatParser::IgnoreSubOrPosContext::IgnoreSubOrPosContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::IgnoreSubOrPosContext::IGNORE() {
  return getToken(FeatParser::IGNORE, 0);
}

std::vector<FeatParser::LookupPatternContext *> FeatParser::IgnoreSubOrPosContext::lookupPattern() {
  return getRuleContexts<FeatParser::LookupPatternContext>();
}

FeatParser::LookupPatternContext* FeatParser::IgnoreSubOrPosContext::lookupPattern(size_t i) {
  return getRuleContext<FeatParser::LookupPatternContext>(i);
}

FeatParser::SubtokContext* FeatParser::IgnoreSubOrPosContext::subtok() {
  return getRuleContext<FeatParser::SubtokContext>(0);
}

FeatParser::RevtokContext* FeatParser::IgnoreSubOrPosContext::revtok() {
  return getRuleContext<FeatParser::RevtokContext>(0);
}

FeatParser::PostokContext* FeatParser::IgnoreSubOrPosContext::postok() {
  return getRuleContext<FeatParser::PostokContext>(0);
}

std::vector<tree::TerminalNode *> FeatParser::IgnoreSubOrPosContext::COMMA() {
  return getTokens(FeatParser::COMMA);
}

tree::TerminalNode* FeatParser::IgnoreSubOrPosContext::COMMA(size_t i) {
  return getToken(FeatParser::COMMA, i);
}


size_t FeatParser::IgnoreSubOrPosContext::getRuleIndex() const {
  return FeatParser::RuleIgnoreSubOrPos;
}


antlrcpp::Any FeatParser::IgnoreSubOrPosContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitIgnoreSubOrPos(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::IgnoreSubOrPosContext* FeatParser::ignoreSubOrPos() {
  IgnoreSubOrPosContext *_localctx = _tracker.createInstance<IgnoreSubOrPosContext>(_ctx, getState());
  enterRule(_localctx, 46, FeatParser::RuleIgnoreSubOrPos);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(426);
    match(FeatParser::IGNORE);
    setState(430);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::SUBSTITUTE:
      case FeatParser::SUBSTITUTE_v: {
        setState(427);
        subtok();
        break;
      }

      case FeatParser::REVERSE:
      case FeatParser::REVERSE_v: {
        setState(428);
        revtok();
        break;
      }

      case FeatParser::POSITION:
      case FeatParser::POSITION_v: {
        setState(429);
        postok();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(432);
    lookupPattern();
    setState(437);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FeatParser::COMMA) {
      setState(433);
      match(FeatParser::COMMA);
      setState(434);
      lookupPattern();
      setState(439);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubstituteContext ------------------------------------------------------------------

FeatParser::SubstituteContext::SubstituteContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FeatParser::RevtokContext* FeatParser::SubstituteContext::revtok() {
  return getRuleContext<FeatParser::RevtokContext>(0);
}

FeatParser::SubtokContext* FeatParser::SubstituteContext::subtok() {
  return getRuleContext<FeatParser::SubtokContext>(0);
}

tree::TerminalNode* FeatParser::SubstituteContext::EXCEPT() {
  return getToken(FeatParser::EXCEPT, 0);
}

std::vector<FeatParser::LookupPatternContext *> FeatParser::SubstituteContext::lookupPattern() {
  return getRuleContexts<FeatParser::LookupPatternContext>();
}

FeatParser::LookupPatternContext* FeatParser::SubstituteContext::lookupPattern(size_t i) {
  return getRuleContext<FeatParser::LookupPatternContext>(i);
}

tree::TerminalNode* FeatParser::SubstituteContext::BY() {
  return getToken(FeatParser::BY, 0);
}

std::vector<tree::TerminalNode *> FeatParser::SubstituteContext::COMMA() {
  return getTokens(FeatParser::COMMA);
}

tree::TerminalNode* FeatParser::SubstituteContext::COMMA(size_t i) {
  return getToken(FeatParser::COMMA, i);
}

tree::TerminalNode* FeatParser::SubstituteContext::FROM() {
  return getToken(FeatParser::FROM, 0);
}

tree::TerminalNode* FeatParser::SubstituteContext::KNULL() {
  return getToken(FeatParser::KNULL, 0);
}


size_t FeatParser::SubstituteContext::getRuleIndex() const {
  return FeatParser::RuleSubstitute;
}


antlrcpp::Any FeatParser::SubstituteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitSubstitute(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::SubstituteContext* FeatParser::substitute() {
  SubstituteContext *_localctx = _tracker.createInstance<SubstituteContext>(_ctx, getState());
  enterRule(_localctx, 48, FeatParser::RuleSubstitute);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(449);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FeatParser::EXCEPT) {
      setState(440);
      match(FeatParser::EXCEPT);
      setState(441);
      lookupPattern();
      setState(446);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FeatParser::COMMA) {
        setState(442);
        match(FeatParser::COMMA);
        setState(443);
        lookupPattern();
        setState(448);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(469);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::REVERSE:
      case FeatParser::REVERSE_v: {
        setState(451);
        revtok();
        setState(452);
        dynamic_cast<SubstituteContext *>(_localctx)->startpat = lookupPattern();
        setState(458);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == FeatParser::BY) {
          setState(453);
          match(FeatParser::BY);
          setState(456);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case FeatParser::KNULL: {
              setState(454);
              match(FeatParser::KNULL);
              break;
            }

            case FeatParser::LBRACKET:
            case FeatParser::GCLASS:
            case FeatParser::CID:
            case FeatParser::ESCGNAME:
            case FeatParser::NAMELABEL:
            case FeatParser::EXTNAME: {
              setState(455);
              dynamic_cast<SubstituteContext *>(_localctx)->endpat = lookupPattern();
              break;
            }

          default:
            throw NoViableAltException(this);
          }
        }
        break;
      }

      case FeatParser::SUBSTITUTE:
      case FeatParser::SUBSTITUTE_v: {
        setState(460);
        subtok();
        setState(461);
        dynamic_cast<SubstituteContext *>(_localctx)->startpat = lookupPattern();
        setState(467);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == FeatParser::BY

        || _la == FeatParser::FROM) {
          setState(462);
          _la = _input->LA(1);
          if (!(_la == FeatParser::BY

          || _la == FeatParser::FROM)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(465);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case FeatParser::KNULL: {
              setState(463);
              match(FeatParser::KNULL);
              break;
            }

            case FeatParser::LBRACKET:
            case FeatParser::GCLASS:
            case FeatParser::CID:
            case FeatParser::ESCGNAME:
            case FeatParser::NAMELABEL:
            case FeatParser::EXTNAME: {
              setState(464);
              dynamic_cast<SubstituteContext *>(_localctx)->endpat = lookupPattern();
              break;
            }

          default:
            throw NoViableAltException(this);
          }
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PositionContext ------------------------------------------------------------------

FeatParser::PositionContext::PositionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FeatParser::PostokContext* FeatParser::PositionContext::postok() {
  return getRuleContext<FeatParser::PostokContext>(0);
}

FeatParser::EnumtokContext* FeatParser::PositionContext::enumtok() {
  return getRuleContext<FeatParser::EnumtokContext>(0);
}

std::vector<FeatParser::PatternContext *> FeatParser::PositionContext::pattern() {
  return getRuleContexts<FeatParser::PatternContext>();
}

FeatParser::PatternContext* FeatParser::PositionContext::pattern(size_t i) {
  return getRuleContext<FeatParser::PatternContext>(i);
}

FeatParser::ValueRecordContext* FeatParser::PositionContext::valueRecord() {
  return getRuleContext<FeatParser::ValueRecordContext>(0);
}

tree::TerminalNode* FeatParser::PositionContext::CURSIVE() {
  return getToken(FeatParser::CURSIVE, 0);
}

FeatParser::CursiveElementContext* FeatParser::PositionContext::cursiveElement() {
  return getRuleContext<FeatParser::CursiveElementContext>(0);
}

tree::TerminalNode* FeatParser::PositionContext::MARKBASE() {
  return getToken(FeatParser::MARKBASE, 0);
}

FeatParser::MarkligtokContext* FeatParser::PositionContext::markligtok() {
  return getRuleContext<FeatParser::MarkligtokContext>(0);
}

tree::TerminalNode* FeatParser::PositionContext::MARK() {
  return getToken(FeatParser::MARK, 0);
}

std::vector<FeatParser::ValuePatternContext *> FeatParser::PositionContext::valuePattern() {
  return getRuleContexts<FeatParser::ValuePatternContext>();
}

FeatParser::ValuePatternContext* FeatParser::PositionContext::valuePattern(size_t i) {
  return getRuleContext<FeatParser::ValuePatternContext>(i);
}

std::vector<tree::TerminalNode *> FeatParser::PositionContext::LOOKUP() {
  return getTokens(FeatParser::LOOKUP);
}

tree::TerminalNode* FeatParser::PositionContext::LOOKUP(size_t i) {
  return getToken(FeatParser::LOOKUP, i);
}

std::vector<FeatParser::LabelContext *> FeatParser::PositionContext::label() {
  return getRuleContexts<FeatParser::LabelContext>();
}

FeatParser::LabelContext* FeatParser::PositionContext::label(size_t i) {
  return getRuleContext<FeatParser::LabelContext>(i);
}

std::vector<FeatParser::LookupPatternElementContext *> FeatParser::PositionContext::lookupPatternElement() {
  return getRuleContexts<FeatParser::LookupPatternElementContext>();
}

FeatParser::LookupPatternElementContext* FeatParser::PositionContext::lookupPatternElement(size_t i) {
  return getRuleContext<FeatParser::LookupPatternElementContext>(i);
}

std::vector<FeatParser::BaseToMarkElementContext *> FeatParser::PositionContext::baseToMarkElement() {
  return getRuleContexts<FeatParser::BaseToMarkElementContext>();
}

FeatParser::BaseToMarkElementContext* FeatParser::PositionContext::baseToMarkElement(size_t i) {
  return getRuleContext<FeatParser::BaseToMarkElementContext>(i);
}

std::vector<FeatParser::LigatureMarkElementContext *> FeatParser::PositionContext::ligatureMarkElement() {
  return getRuleContexts<FeatParser::LigatureMarkElementContext>();
}

FeatParser::LigatureMarkElementContext* FeatParser::PositionContext::ligatureMarkElement(size_t i) {
  return getRuleContext<FeatParser::LigatureMarkElementContext>(i);
}


size_t FeatParser::PositionContext::getRuleIndex() const {
  return FeatParser::RulePosition;
}


antlrcpp::Any FeatParser::PositionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitPosition(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::PositionContext* FeatParser::position() {
  PositionContext *_localctx = _tracker.createInstance<PositionContext>(_ctx, getState());
  enterRule(_localctx, 50, FeatParser::RulePosition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(472);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FeatParser::ENUMERATE

    || _la == FeatParser::ENUMERATE_v) {
      setState(471);
      enumtok();
    }
    setState(474);
    postok();
    setState(476);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 116) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 116)) & ((1ULL << (FeatParser::LBRACKET - 116))
      | (1ULL << (FeatParser::GCLASS - 116))
      | (1ULL << (FeatParser::CID - 116))
      | (1ULL << (FeatParser::ESCGNAME - 116))
      | (1ULL << (FeatParser::NAMELABEL - 116))
      | (1ULL << (FeatParser::EXTNAME - 116)))) != 0)) {
      setState(475);
      dynamic_cast<PositionContext *>(_localctx)->startpat = pattern();
    }
    setState(532);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::BEGINVALUE:
      case FeatParser::NUM: {
        setState(478);
        valueRecord();
        setState(482);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (((((_la - 116) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 116)) & ((1ULL << (FeatParser::LBRACKET - 116))
          | (1ULL << (FeatParser::GCLASS - 116))
          | (1ULL << (FeatParser::CID - 116))
          | (1ULL << (FeatParser::ESCGNAME - 116))
          | (1ULL << (FeatParser::NAMELABEL - 116))
          | (1ULL << (FeatParser::EXTNAME - 116)))) != 0)) {
          setState(479);
          valuePattern();
          setState(484);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case FeatParser::LOOKUP: {
        setState(487); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(485);
          match(FeatParser::LOOKUP);
          setState(486);
          label();
          setState(489); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == FeatParser::LOOKUP);
        setState(494);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (((((_la - 116) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 116)) & ((1ULL << (FeatParser::LBRACKET - 116))
          | (1ULL << (FeatParser::GCLASS - 116))
          | (1ULL << (FeatParser::CID - 116))
          | (1ULL << (FeatParser::ESCGNAME - 116))
          | (1ULL << (FeatParser::NAMELABEL - 116))
          | (1ULL << (FeatParser::EXTNAME - 116)))) != 0)) {
          setState(491);
          lookupPatternElement();
          setState(496);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case FeatParser::CURSIVE: {
        setState(497);
        match(FeatParser::CURSIVE);
        setState(498);
        cursiveElement();
        setState(500);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (((((_la - 116) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 116)) & ((1ULL << (FeatParser::LBRACKET - 116))
          | (1ULL << (FeatParser::GCLASS - 116))
          | (1ULL << (FeatParser::CID - 116))
          | (1ULL << (FeatParser::ESCGNAME - 116))
          | (1ULL << (FeatParser::NAMELABEL - 116))
          | (1ULL << (FeatParser::EXTNAME - 116)))) != 0)) {
          setState(499);
          dynamic_cast<PositionContext *>(_localctx)->endpat = pattern();
        }
        break;
      }

      case FeatParser::MARKBASE: {
        setState(502);
        match(FeatParser::MARKBASE);
        setState(503);
        dynamic_cast<PositionContext *>(_localctx)->midpat = pattern();
        setState(505); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(504);
          baseToMarkElement();
          setState(507); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == FeatParser::BEGINVALUE);
        setState(510);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (((((_la - 116) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 116)) & ((1ULL << (FeatParser::LBRACKET - 116))
          | (1ULL << (FeatParser::GCLASS - 116))
          | (1ULL << (FeatParser::CID - 116))
          | (1ULL << (FeatParser::ESCGNAME - 116))
          | (1ULL << (FeatParser::NAMELABEL - 116))
          | (1ULL << (FeatParser::EXTNAME - 116)))) != 0)) {
          setState(509);
          dynamic_cast<PositionContext *>(_localctx)->endpat = pattern();
        }
        break;
      }

      case FeatParser::MARKLIG:
      case FeatParser::MARKLIG_v: {
        setState(512);
        markligtok();
        setState(513);
        dynamic_cast<PositionContext *>(_localctx)->midpat = pattern();
        setState(515); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(514);
          ligatureMarkElement();
          setState(517); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == FeatParser::BEGINVALUE);
        setState(520);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (((((_la - 116) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 116)) & ((1ULL << (FeatParser::LBRACKET - 116))
          | (1ULL << (FeatParser::GCLASS - 116))
          | (1ULL << (FeatParser::CID - 116))
          | (1ULL << (FeatParser::ESCGNAME - 116))
          | (1ULL << (FeatParser::NAMELABEL - 116))
          | (1ULL << (FeatParser::EXTNAME - 116)))) != 0)) {
          setState(519);
          dynamic_cast<PositionContext *>(_localctx)->endpat = pattern();
        }
        break;
      }

      case FeatParser::MARK: {
        setState(522);
        match(FeatParser::MARK);
        setState(523);
        dynamic_cast<PositionContext *>(_localctx)->midpat = pattern();
        setState(525); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(524);
          baseToMarkElement();
          setState(527); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == FeatParser::BEGINVALUE);
        setState(530);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (((((_la - 116) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 116)) & ((1ULL << (FeatParser::LBRACKET - 116))
          | (1ULL << (FeatParser::GCLASS - 116))
          | (1ULL << (FeatParser::CID - 116))
          | (1ULL << (FeatParser::ESCGNAME - 116))
          | (1ULL << (FeatParser::NAMELABEL - 116))
          | (1ULL << (FeatParser::EXTNAME - 116)))) != 0)) {
          setState(529);
          dynamic_cast<PositionContext *>(_localctx)->endpat = pattern();
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValuePatternContext ------------------------------------------------------------------

FeatParser::ValuePatternContext::ValuePatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FeatParser::PatternElementContext* FeatParser::ValuePatternContext::patternElement() {
  return getRuleContext<FeatParser::PatternElementContext>(0);
}

FeatParser::ValueRecordContext* FeatParser::ValuePatternContext::valueRecord() {
  return getRuleContext<FeatParser::ValueRecordContext>(0);
}


size_t FeatParser::ValuePatternContext::getRuleIndex() const {
  return FeatParser::RuleValuePattern;
}


antlrcpp::Any FeatParser::ValuePatternContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitValuePattern(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::ValuePatternContext* FeatParser::valuePattern() {
  ValuePatternContext *_localctx = _tracker.createInstance<ValuePatternContext>(_ctx, getState());
  enterRule(_localctx, 52, FeatParser::RuleValuePattern);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(534);
    patternElement();
    setState(536);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FeatParser::BEGINVALUE || _la == FeatParser::NUM) {
      setState(535);
      valueRecord();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueRecordContext ------------------------------------------------------------------

FeatParser::ValueRecordContext::ValueRecordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::ValueRecordContext::BEGINVALUE() {
  return getToken(FeatParser::BEGINVALUE, 0);
}

tree::TerminalNode* FeatParser::ValueRecordContext::ENDVALUE() {
  return getToken(FeatParser::ENDVALUE, 0);
}

FeatParser::LabelContext* FeatParser::ValueRecordContext::label() {
  return getRuleContext<FeatParser::LabelContext>(0);
}

FeatParser::ValueLiteralContext* FeatParser::ValueRecordContext::valueLiteral() {
  return getRuleContext<FeatParser::ValueLiteralContext>(0);
}


size_t FeatParser::ValueRecordContext::getRuleIndex() const {
  return FeatParser::RuleValueRecord;
}


antlrcpp::Any FeatParser::ValueRecordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitValueRecord(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::ValueRecordContext* FeatParser::valueRecord() {
  ValueRecordContext *_localctx = _tracker.createInstance<ValueRecordContext>(_ctx, getState());
  enterRule(_localctx, 54, FeatParser::RuleValueRecord);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(543);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(538);
      match(FeatParser::BEGINVALUE);
      setState(539);
      dynamic_cast<ValueRecordContext *>(_localctx)->valuename = label();
      setState(540);
      match(FeatParser::ENDVALUE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(542);
      valueLiteral();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueLiteralContext ------------------------------------------------------------------

FeatParser::ValueLiteralContext::ValueLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::ValueLiteralContext::BEGINVALUE() {
  return getToken(FeatParser::BEGINVALUE, 0);
}

std::vector<tree::TerminalNode *> FeatParser::ValueLiteralContext::NUM() {
  return getTokens(FeatParser::NUM);
}

tree::TerminalNode* FeatParser::ValueLiteralContext::NUM(size_t i) {
  return getToken(FeatParser::NUM, i);
}

tree::TerminalNode* FeatParser::ValueLiteralContext::ENDVALUE() {
  return getToken(FeatParser::ENDVALUE, 0);
}


size_t FeatParser::ValueLiteralContext::getRuleIndex() const {
  return FeatParser::RuleValueLiteral;
}


antlrcpp::Any FeatParser::ValueLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitValueLiteral(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::ValueLiteralContext* FeatParser::valueLiteral() {
  ValueLiteralContext *_localctx = _tracker.createInstance<ValueLiteralContext>(_ctx, getState());
  enterRule(_localctx, 56, FeatParser::RuleValueLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(552);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::BEGINVALUE: {
        enterOuterAlt(_localctx, 1);
        setState(545);
        match(FeatParser::BEGINVALUE);
        setState(546);
        match(FeatParser::NUM);
        setState(547);
        match(FeatParser::NUM);
        setState(548);
        match(FeatParser::NUM);
        setState(549);
        match(FeatParser::NUM);
        setState(550);
        match(FeatParser::ENDVALUE);
        break;
      }

      case FeatParser::NUM: {
        enterOuterAlt(_localctx, 2);
        setState(551);
        match(FeatParser::NUM);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CursiveElementContext ------------------------------------------------------------------

FeatParser::CursiveElementContext::CursiveElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FeatParser::PatternElementContext* FeatParser::CursiveElementContext::patternElement() {
  return getRuleContext<FeatParser::PatternElementContext>(0);
}

std::vector<FeatParser::AnchorContext *> FeatParser::CursiveElementContext::anchor() {
  return getRuleContexts<FeatParser::AnchorContext>();
}

FeatParser::AnchorContext* FeatParser::CursiveElementContext::anchor(size_t i) {
  return getRuleContext<FeatParser::AnchorContext>(i);
}


size_t FeatParser::CursiveElementContext::getRuleIndex() const {
  return FeatParser::RuleCursiveElement;
}


antlrcpp::Any FeatParser::CursiveElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitCursiveElement(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::CursiveElementContext* FeatParser::cursiveElement() {
  CursiveElementContext *_localctx = _tracker.createInstance<CursiveElementContext>(_ctx, getState());
  enterRule(_localctx, 58, FeatParser::RuleCursiveElement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(554);
    patternElement();
    setState(555);
    anchor();
    setState(556);
    anchor();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BaseToMarkElementContext ------------------------------------------------------------------

FeatParser::BaseToMarkElementContext::BaseToMarkElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FeatParser::AnchorContext* FeatParser::BaseToMarkElementContext::anchor() {
  return getRuleContext<FeatParser::AnchorContext>(0);
}

tree::TerminalNode* FeatParser::BaseToMarkElementContext::MARK() {
  return getToken(FeatParser::MARK, 0);
}

tree::TerminalNode* FeatParser::BaseToMarkElementContext::GCLASS() {
  return getToken(FeatParser::GCLASS, 0);
}

tree::TerminalNode* FeatParser::BaseToMarkElementContext::MARKER() {
  return getToken(FeatParser::MARKER, 0);
}


size_t FeatParser::BaseToMarkElementContext::getRuleIndex() const {
  return FeatParser::RuleBaseToMarkElement;
}


antlrcpp::Any FeatParser::BaseToMarkElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitBaseToMarkElement(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::BaseToMarkElementContext* FeatParser::baseToMarkElement() {
  BaseToMarkElementContext *_localctx = _tracker.createInstance<BaseToMarkElementContext>(_ctx, getState());
  enterRule(_localctx, 60, FeatParser::RuleBaseToMarkElement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(558);
    anchor();
    setState(559);
    match(FeatParser::MARK);
    setState(560);
    match(FeatParser::GCLASS);
    setState(562);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FeatParser::MARKER) {
      setState(561);
      match(FeatParser::MARKER);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LigatureMarkElementContext ------------------------------------------------------------------

FeatParser::LigatureMarkElementContext::LigatureMarkElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FeatParser::AnchorContext* FeatParser::LigatureMarkElementContext::anchor() {
  return getRuleContext<FeatParser::AnchorContext>(0);
}

tree::TerminalNode* FeatParser::LigatureMarkElementContext::MARK() {
  return getToken(FeatParser::MARK, 0);
}

tree::TerminalNode* FeatParser::LigatureMarkElementContext::GCLASS() {
  return getToken(FeatParser::GCLASS, 0);
}

tree::TerminalNode* FeatParser::LigatureMarkElementContext::LIG_COMPONENT() {
  return getToken(FeatParser::LIG_COMPONENT, 0);
}

tree::TerminalNode* FeatParser::LigatureMarkElementContext::MARKER() {
  return getToken(FeatParser::MARKER, 0);
}


size_t FeatParser::LigatureMarkElementContext::getRuleIndex() const {
  return FeatParser::RuleLigatureMarkElement;
}


antlrcpp::Any FeatParser::LigatureMarkElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitLigatureMarkElement(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::LigatureMarkElementContext* FeatParser::ligatureMarkElement() {
  LigatureMarkElementContext *_localctx = _tracker.createInstance<LigatureMarkElementContext>(_ctx, getState());
  enterRule(_localctx, 62, FeatParser::RuleLigatureMarkElement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(564);
    anchor();
    setState(567);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FeatParser::MARK) {
      setState(565);
      match(FeatParser::MARK);
      setState(566);
      match(FeatParser::GCLASS);
    }
    setState(570);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FeatParser::LIG_COMPONENT) {
      setState(569);
      match(FeatParser::LIG_COMPONENT);
    }
    setState(573);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FeatParser::MARKER) {
      setState(572);
      match(FeatParser::MARKER);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

FeatParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::ParametersContext::PARAMETERS() {
  return getToken(FeatParser::PARAMETERS, 0);
}

std::vector<FeatParser::FixedNumContext *> FeatParser::ParametersContext::fixedNum() {
  return getRuleContexts<FeatParser::FixedNumContext>();
}

FeatParser::FixedNumContext* FeatParser::ParametersContext::fixedNum(size_t i) {
  return getRuleContext<FeatParser::FixedNumContext>(i);
}


size_t FeatParser::ParametersContext::getRuleIndex() const {
  return FeatParser::RuleParameters;
}


antlrcpp::Any FeatParser::ParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitParameters(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::ParametersContext* FeatParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 64, FeatParser::RuleParameters);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(575);
    match(FeatParser::PARAMETERS);
    setState(577); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(576);
      fixedNum();
      setState(579); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == FeatParser::POINTNUM

    || _la == FeatParser::NUM);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SizemenunameContext ------------------------------------------------------------------

FeatParser::SizemenunameContext::SizemenunameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::SizemenunameContext::SIZEMENUNAME() {
  return getToken(FeatParser::SIZEMENUNAME, 0);
}

tree::TerminalNode* FeatParser::SizemenunameContext::QUOTE() {
  return getToken(FeatParser::QUOTE, 0);
}

tree::TerminalNode* FeatParser::SizemenunameContext::STRVAL() {
  return getToken(FeatParser::STRVAL, 0);
}

tree::TerminalNode* FeatParser::SizemenunameContext::EQUOTE() {
  return getToken(FeatParser::EQUOTE, 0);
}

std::vector<FeatParser::GenNumContext *> FeatParser::SizemenunameContext::genNum() {
  return getRuleContexts<FeatParser::GenNumContext>();
}

FeatParser::GenNumContext* FeatParser::SizemenunameContext::genNum(size_t i) {
  return getRuleContext<FeatParser::GenNumContext>(i);
}


size_t FeatParser::SizemenunameContext::getRuleIndex() const {
  return FeatParser::RuleSizemenuname;
}


antlrcpp::Any FeatParser::SizemenunameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitSizemenuname(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::SizemenunameContext* FeatParser::sizemenuname() {
  SizemenunameContext *_localctx = _tracker.createInstance<SizemenunameContext>(_ctx, getState());
  enterRule(_localctx, 66, FeatParser::RuleSizemenuname);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(581);
    match(FeatParser::SIZEMENUNAME);
    setState(588);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 130) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 130)) & ((1ULL << (FeatParser::NUMEXT - 130))
      | (1ULL << (FeatParser::NUMOCT - 130))
      | (1ULL << (FeatParser::NUM - 130)))) != 0)) {
      setState(582);
      genNum();
      setState(586);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 130) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 130)) & ((1ULL << (FeatParser::NUMEXT - 130))
        | (1ULL << (FeatParser::NUMOCT - 130))
        | (1ULL << (FeatParser::NUM - 130)))) != 0)) {
        setState(583);
        genNum();
        setState(584);
        genNum();
      }
    }
    setState(590);
    match(FeatParser::QUOTE);
    setState(591);
    match(FeatParser::STRVAL);
    setState(592);
    match(FeatParser::EQUOTE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FeatureNamesContext ------------------------------------------------------------------

FeatParser::FeatureNamesContext::FeatureNamesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::FeatureNamesContext::FEATURE_NAMES() {
  return getToken(FeatParser::FEATURE_NAMES, 0);
}

tree::TerminalNode* FeatParser::FeatureNamesContext::LCBRACE() {
  return getToken(FeatParser::LCBRACE, 0);
}

tree::TerminalNode* FeatParser::FeatureNamesContext::RCBRACE() {
  return getToken(FeatParser::RCBRACE, 0);
}

std::vector<FeatParser::NameEntryStatementContext *> FeatParser::FeatureNamesContext::nameEntryStatement() {
  return getRuleContexts<FeatParser::NameEntryStatementContext>();
}

FeatParser::NameEntryStatementContext* FeatParser::FeatureNamesContext::nameEntryStatement(size_t i) {
  return getRuleContext<FeatParser::NameEntryStatementContext>(i);
}


size_t FeatParser::FeatureNamesContext::getRuleIndex() const {
  return FeatParser::RuleFeatureNames;
}


antlrcpp::Any FeatParser::FeatureNamesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitFeatureNames(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::FeatureNamesContext* FeatParser::featureNames() {
  FeatureNamesContext *_localctx = _tracker.createInstance<FeatureNamesContext>(_ctx, getState());
  enterRule(_localctx, 68, FeatParser::RuleFeatureNames);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(594);
    match(FeatParser::FEATURE_NAMES);
    setState(595);
    match(FeatParser::LCBRACE);
    setState(597); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(596);
      nameEntryStatement();
      setState(599); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == FeatParser::INCLUDE || _la == FeatParser::NAME);
    setState(601);
    match(FeatParser::RCBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubtableContext ------------------------------------------------------------------

FeatParser::SubtableContext::SubtableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::SubtableContext::SUBTABLE() {
  return getToken(FeatParser::SUBTABLE, 0);
}


size_t FeatParser::SubtableContext::getRuleIndex() const {
  return FeatParser::RuleSubtable;
}


antlrcpp::Any FeatParser::SubtableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitSubtable(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::SubtableContext* FeatParser::subtable() {
  SubtableContext *_localctx = _tracker.createInstance<SubtableContext>(_ctx, getState());
  enterRule(_localctx, 70, FeatParser::RuleSubtable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(603);
    match(FeatParser::SUBTABLE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_BASEContext ------------------------------------------------------------------

FeatParser::Table_BASEContext::Table_BASEContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FeatParser::Table_BASEContext::BASE() {
  return getTokens(FeatParser::BASE);
}

tree::TerminalNode* FeatParser::Table_BASEContext::BASE(size_t i) {
  return getToken(FeatParser::BASE, i);
}

tree::TerminalNode* FeatParser::Table_BASEContext::LCBRACE() {
  return getToken(FeatParser::LCBRACE, 0);
}

tree::TerminalNode* FeatParser::Table_BASEContext::RCBRACE() {
  return getToken(FeatParser::RCBRACE, 0);
}

tree::TerminalNode* FeatParser::Table_BASEContext::SEMI() {
  return getToken(FeatParser::SEMI, 0);
}

std::vector<FeatParser::BaseStatementContext *> FeatParser::Table_BASEContext::baseStatement() {
  return getRuleContexts<FeatParser::BaseStatementContext>();
}

FeatParser::BaseStatementContext* FeatParser::Table_BASEContext::baseStatement(size_t i) {
  return getRuleContext<FeatParser::BaseStatementContext>(i);
}


size_t FeatParser::Table_BASEContext::getRuleIndex() const {
  return FeatParser::RuleTable_BASE;
}


antlrcpp::Any FeatParser::Table_BASEContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitTable_BASE(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::Table_BASEContext* FeatParser::table_BASE() {
  Table_BASEContext *_localctx = _tracker.createInstance<Table_BASEContext>(_ctx, getState());
  enterRule(_localctx, 72, FeatParser::RuleTable_BASE);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(605);
    match(FeatParser::BASE);
    setState(606);
    match(FeatParser::LCBRACE);
    setState(608); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(607);
      baseStatement();
      setState(610); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (((((_la - 5) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 5)) & ((1ULL << (FeatParser::INCLUDE - 5))
      | (1ULL << (FeatParser::HA_BTL - 5))
      | (1ULL << (FeatParser::VA_BTL - 5))
      | (1ULL << (FeatParser::HA_BSL - 5))
      | (1ULL << (FeatParser::VA_BSL - 5)))) != 0));
    setState(612);
    match(FeatParser::RCBRACE);
    setState(613);
    match(FeatParser::BASE);
    setState(614);
    match(FeatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BaseStatementContext ------------------------------------------------------------------

FeatParser::BaseStatementContext::BaseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::BaseStatementContext::SEMI() {
  return getToken(FeatParser::SEMI, 0);
}

FeatParser::AxisTagsContext* FeatParser::BaseStatementContext::axisTags() {
  return getRuleContext<FeatParser::AxisTagsContext>(0);
}

FeatParser::AxisScriptsContext* FeatParser::BaseStatementContext::axisScripts() {
  return getRuleContext<FeatParser::AxisScriptsContext>(0);
}

FeatParser::IncludeContext* FeatParser::BaseStatementContext::include() {
  return getRuleContext<FeatParser::IncludeContext>(0);
}


size_t FeatParser::BaseStatementContext::getRuleIndex() const {
  return FeatParser::RuleBaseStatement;
}


antlrcpp::Any FeatParser::BaseStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitBaseStatement(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::BaseStatementContext* FeatParser::baseStatement() {
  BaseStatementContext *_localctx = _tracker.createInstance<BaseStatementContext>(_ctx, getState());
  enterRule(_localctx, 74, FeatParser::RuleBaseStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(619);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::HA_BTL:
      case FeatParser::VA_BTL: {
        setState(616);
        axisTags();
        break;
      }

      case FeatParser::HA_BSL:
      case FeatParser::VA_BSL: {
        setState(617);
        axisScripts();
        break;
      }

      case FeatParser::INCLUDE: {
        setState(618);
        include();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(621);
    match(FeatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AxisTagsContext ------------------------------------------------------------------

FeatParser::AxisTagsContext::AxisTagsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::AxisTagsContext::HA_BTL() {
  return getToken(FeatParser::HA_BTL, 0);
}

tree::TerminalNode* FeatParser::AxisTagsContext::VA_BTL() {
  return getToken(FeatParser::VA_BTL, 0);
}

std::vector<FeatParser::TagContext *> FeatParser::AxisTagsContext::tag() {
  return getRuleContexts<FeatParser::TagContext>();
}

FeatParser::TagContext* FeatParser::AxisTagsContext::tag(size_t i) {
  return getRuleContext<FeatParser::TagContext>(i);
}


size_t FeatParser::AxisTagsContext::getRuleIndex() const {
  return FeatParser::RuleAxisTags;
}


antlrcpp::Any FeatParser::AxisTagsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitAxisTags(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::AxisTagsContext* FeatParser::axisTags() {
  AxisTagsContext *_localctx = _tracker.createInstance<AxisTagsContext>(_ctx, getState());
  enterRule(_localctx, 76, FeatParser::RuleAxisTags);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(623);
    _la = _input->LA(1);
    if (!(_la == FeatParser::HA_BTL

    || _la == FeatParser::VA_BTL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(625); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(624);
      tag();
      setState(627); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == FeatParser::MARK || ((((_la - 127) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 127)) & ((1ULL << (FeatParser::NAMELABEL - 127))
      | (1ULL << (FeatParser::EXTNAME - 127))
      | (1ULL << (FeatParser::CATCHTAG - 127)))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AxisScriptsContext ------------------------------------------------------------------

FeatParser::AxisScriptsContext::AxisScriptsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FeatParser::BaseScriptContext *> FeatParser::AxisScriptsContext::baseScript() {
  return getRuleContexts<FeatParser::BaseScriptContext>();
}

FeatParser::BaseScriptContext* FeatParser::AxisScriptsContext::baseScript(size_t i) {
  return getRuleContext<FeatParser::BaseScriptContext>(i);
}

tree::TerminalNode* FeatParser::AxisScriptsContext::HA_BSL() {
  return getToken(FeatParser::HA_BSL, 0);
}

tree::TerminalNode* FeatParser::AxisScriptsContext::VA_BSL() {
  return getToken(FeatParser::VA_BSL, 0);
}

std::vector<tree::TerminalNode *> FeatParser::AxisScriptsContext::COMMA() {
  return getTokens(FeatParser::COMMA);
}

tree::TerminalNode* FeatParser::AxisScriptsContext::COMMA(size_t i) {
  return getToken(FeatParser::COMMA, i);
}


size_t FeatParser::AxisScriptsContext::getRuleIndex() const {
  return FeatParser::RuleAxisScripts;
}


antlrcpp::Any FeatParser::AxisScriptsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitAxisScripts(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::AxisScriptsContext* FeatParser::axisScripts() {
  AxisScriptsContext *_localctx = _tracker.createInstance<AxisScriptsContext>(_ctx, getState());
  enterRule(_localctx, 78, FeatParser::RuleAxisScripts);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(629);
    _la = _input->LA(1);
    if (!(_la == FeatParser::HA_BSL

    || _la == FeatParser::VA_BSL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(630);
    baseScript();
    setState(635);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FeatParser::COMMA) {
      setState(631);
      match(FeatParser::COMMA);
      setState(632);
      baseScript();
      setState(637);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BaseScriptContext ------------------------------------------------------------------

FeatParser::BaseScriptContext::BaseScriptContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FeatParser::TagContext *> FeatParser::BaseScriptContext::tag() {
  return getRuleContexts<FeatParser::TagContext>();
}

FeatParser::TagContext* FeatParser::BaseScriptContext::tag(size_t i) {
  return getRuleContext<FeatParser::TagContext>(i);
}

std::vector<tree::TerminalNode *> FeatParser::BaseScriptContext::NUM() {
  return getTokens(FeatParser::NUM);
}

tree::TerminalNode* FeatParser::BaseScriptContext::NUM(size_t i) {
  return getToken(FeatParser::NUM, i);
}


size_t FeatParser::BaseScriptContext::getRuleIndex() const {
  return FeatParser::RuleBaseScript;
}


antlrcpp::Any FeatParser::BaseScriptContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitBaseScript(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::BaseScriptContext* FeatParser::baseScript() {
  BaseScriptContext *_localctx = _tracker.createInstance<BaseScriptContext>(_ctx, getState());
  enterRule(_localctx, 80, FeatParser::RuleBaseScript);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(638);
    dynamic_cast<BaseScriptContext *>(_localctx)->script = tag();
    setState(639);
    dynamic_cast<BaseScriptContext *>(_localctx)->db = tag();
    setState(641); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(640);
      match(FeatParser::NUM);
      setState(643); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == FeatParser::NUM);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_GDEFContext ------------------------------------------------------------------

FeatParser::Table_GDEFContext::Table_GDEFContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FeatParser::Table_GDEFContext::GDEF() {
  return getTokens(FeatParser::GDEF);
}

tree::TerminalNode* FeatParser::Table_GDEFContext::GDEF(size_t i) {
  return getToken(FeatParser::GDEF, i);
}

tree::TerminalNode* FeatParser::Table_GDEFContext::LCBRACE() {
  return getToken(FeatParser::LCBRACE, 0);
}

tree::TerminalNode* FeatParser::Table_GDEFContext::RCBRACE() {
  return getToken(FeatParser::RCBRACE, 0);
}

tree::TerminalNode* FeatParser::Table_GDEFContext::SEMI() {
  return getToken(FeatParser::SEMI, 0);
}

std::vector<FeatParser::GdefStatementContext *> FeatParser::Table_GDEFContext::gdefStatement() {
  return getRuleContexts<FeatParser::GdefStatementContext>();
}

FeatParser::GdefStatementContext* FeatParser::Table_GDEFContext::gdefStatement(size_t i) {
  return getRuleContext<FeatParser::GdefStatementContext>(i);
}


size_t FeatParser::Table_GDEFContext::getRuleIndex() const {
  return FeatParser::RuleTable_GDEF;
}


antlrcpp::Any FeatParser::Table_GDEFContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitTable_GDEF(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::Table_GDEFContext* FeatParser::table_GDEF() {
  Table_GDEFContext *_localctx = _tracker.createInstance<Table_GDEFContext>(_ctx, getState());
  enterRule(_localctx, 82, FeatParser::RuleTable_GDEF);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(645);
    match(FeatParser::GDEF);
    setState(646);
    match(FeatParser::LCBRACE);
    setState(648); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(647);
      gdefStatement();
      setState(650); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == FeatParser::INCLUDE || ((((_la - 66) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 66)) & ((1ULL << (FeatParser::GLYPH_CLASS_DEF - 66))
      | (1ULL << (FeatParser::ATTACH - 66))
      | (1ULL << (FeatParser::LIG_CARET_BY_POS - 66))
      | (1ULL << (FeatParser::LIG_CARET_BY_IDX - 66)))) != 0));
    setState(652);
    match(FeatParser::RCBRACE);
    setState(653);
    match(FeatParser::GDEF);
    setState(654);
    match(FeatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GdefStatementContext ------------------------------------------------------------------

FeatParser::GdefStatementContext::GdefStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::GdefStatementContext::SEMI() {
  return getToken(FeatParser::SEMI, 0);
}

FeatParser::GdefGlyphClassContext* FeatParser::GdefStatementContext::gdefGlyphClass() {
  return getRuleContext<FeatParser::GdefGlyphClassContext>(0);
}

FeatParser::GdefAttachContext* FeatParser::GdefStatementContext::gdefAttach() {
  return getRuleContext<FeatParser::GdefAttachContext>(0);
}

FeatParser::GdefLigCaretPosContext* FeatParser::GdefStatementContext::gdefLigCaretPos() {
  return getRuleContext<FeatParser::GdefLigCaretPosContext>(0);
}

FeatParser::GdefLigCaretIndexContext* FeatParser::GdefStatementContext::gdefLigCaretIndex() {
  return getRuleContext<FeatParser::GdefLigCaretIndexContext>(0);
}

FeatParser::IncludeContext* FeatParser::GdefStatementContext::include() {
  return getRuleContext<FeatParser::IncludeContext>(0);
}


size_t FeatParser::GdefStatementContext::getRuleIndex() const {
  return FeatParser::RuleGdefStatement;
}


antlrcpp::Any FeatParser::GdefStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitGdefStatement(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::GdefStatementContext* FeatParser::gdefStatement() {
  GdefStatementContext *_localctx = _tracker.createInstance<GdefStatementContext>(_ctx, getState());
  enterRule(_localctx, 84, FeatParser::RuleGdefStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(661);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::GLYPH_CLASS_DEF: {
        setState(656);
        gdefGlyphClass();
        break;
      }

      case FeatParser::ATTACH: {
        setState(657);
        gdefAttach();
        break;
      }

      case FeatParser::LIG_CARET_BY_POS: {
        setState(658);
        gdefLigCaretPos();
        break;
      }

      case FeatParser::LIG_CARET_BY_IDX: {
        setState(659);
        gdefLigCaretIndex();
        break;
      }

      case FeatParser::INCLUDE: {
        setState(660);
        include();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(663);
    match(FeatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GdefGlyphClassContext ------------------------------------------------------------------

FeatParser::GdefGlyphClassContext::GdefGlyphClassContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::GdefGlyphClassContext::GLYPH_CLASS_DEF() {
  return getToken(FeatParser::GLYPH_CLASS_DEF, 0);
}

std::vector<FeatParser::GlyphClassOptionalContext *> FeatParser::GdefGlyphClassContext::glyphClassOptional() {
  return getRuleContexts<FeatParser::GlyphClassOptionalContext>();
}

FeatParser::GlyphClassOptionalContext* FeatParser::GdefGlyphClassContext::glyphClassOptional(size_t i) {
  return getRuleContext<FeatParser::GlyphClassOptionalContext>(i);
}

std::vector<tree::TerminalNode *> FeatParser::GdefGlyphClassContext::COMMA() {
  return getTokens(FeatParser::COMMA);
}

tree::TerminalNode* FeatParser::GdefGlyphClassContext::COMMA(size_t i) {
  return getToken(FeatParser::COMMA, i);
}


size_t FeatParser::GdefGlyphClassContext::getRuleIndex() const {
  return FeatParser::RuleGdefGlyphClass;
}


antlrcpp::Any FeatParser::GdefGlyphClassContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitGdefGlyphClass(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::GdefGlyphClassContext* FeatParser::gdefGlyphClass() {
  GdefGlyphClassContext *_localctx = _tracker.createInstance<GdefGlyphClassContext>(_ctx, getState());
  enterRule(_localctx, 86, FeatParser::RuleGdefGlyphClass);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(665);
    match(FeatParser::GLYPH_CLASS_DEF);
    setState(666);
    glyphClassOptional();
    setState(667);
    match(FeatParser::COMMA);
    setState(668);
    glyphClassOptional();
    setState(669);
    match(FeatParser::COMMA);
    setState(670);
    glyphClassOptional();
    setState(671);
    match(FeatParser::COMMA);
    setState(672);
    glyphClassOptional();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GdefAttachContext ------------------------------------------------------------------

FeatParser::GdefAttachContext::GdefAttachContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::GdefAttachContext::ATTACH() {
  return getToken(FeatParser::ATTACH, 0);
}

FeatParser::LookupPatternContext* FeatParser::GdefAttachContext::lookupPattern() {
  return getRuleContext<FeatParser::LookupPatternContext>(0);
}

std::vector<tree::TerminalNode *> FeatParser::GdefAttachContext::NUM() {
  return getTokens(FeatParser::NUM);
}

tree::TerminalNode* FeatParser::GdefAttachContext::NUM(size_t i) {
  return getToken(FeatParser::NUM, i);
}


size_t FeatParser::GdefAttachContext::getRuleIndex() const {
  return FeatParser::RuleGdefAttach;
}


antlrcpp::Any FeatParser::GdefAttachContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitGdefAttach(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::GdefAttachContext* FeatParser::gdefAttach() {
  GdefAttachContext *_localctx = _tracker.createInstance<GdefAttachContext>(_ctx, getState());
  enterRule(_localctx, 88, FeatParser::RuleGdefAttach);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(674);
    match(FeatParser::ATTACH);
    setState(675);
    lookupPattern();
    setState(677); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(676);
      match(FeatParser::NUM);
      setState(679); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == FeatParser::NUM);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GdefLigCaretPosContext ------------------------------------------------------------------

FeatParser::GdefLigCaretPosContext::GdefLigCaretPosContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::GdefLigCaretPosContext::LIG_CARET_BY_POS() {
  return getToken(FeatParser::LIG_CARET_BY_POS, 0);
}

FeatParser::LookupPatternContext* FeatParser::GdefLigCaretPosContext::lookupPattern() {
  return getRuleContext<FeatParser::LookupPatternContext>(0);
}

std::vector<tree::TerminalNode *> FeatParser::GdefLigCaretPosContext::NUM() {
  return getTokens(FeatParser::NUM);
}

tree::TerminalNode* FeatParser::GdefLigCaretPosContext::NUM(size_t i) {
  return getToken(FeatParser::NUM, i);
}


size_t FeatParser::GdefLigCaretPosContext::getRuleIndex() const {
  return FeatParser::RuleGdefLigCaretPos;
}


antlrcpp::Any FeatParser::GdefLigCaretPosContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitGdefLigCaretPos(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::GdefLigCaretPosContext* FeatParser::gdefLigCaretPos() {
  GdefLigCaretPosContext *_localctx = _tracker.createInstance<GdefLigCaretPosContext>(_ctx, getState());
  enterRule(_localctx, 90, FeatParser::RuleGdefLigCaretPos);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(681);
    match(FeatParser::LIG_CARET_BY_POS);
    setState(682);
    lookupPattern();
    setState(684); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(683);
      match(FeatParser::NUM);
      setState(686); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == FeatParser::NUM);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GdefLigCaretIndexContext ------------------------------------------------------------------

FeatParser::GdefLigCaretIndexContext::GdefLigCaretIndexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::GdefLigCaretIndexContext::LIG_CARET_BY_IDX() {
  return getToken(FeatParser::LIG_CARET_BY_IDX, 0);
}

FeatParser::LookupPatternContext* FeatParser::GdefLigCaretIndexContext::lookupPattern() {
  return getRuleContext<FeatParser::LookupPatternContext>(0);
}

std::vector<tree::TerminalNode *> FeatParser::GdefLigCaretIndexContext::NUM() {
  return getTokens(FeatParser::NUM);
}

tree::TerminalNode* FeatParser::GdefLigCaretIndexContext::NUM(size_t i) {
  return getToken(FeatParser::NUM, i);
}


size_t FeatParser::GdefLigCaretIndexContext::getRuleIndex() const {
  return FeatParser::RuleGdefLigCaretIndex;
}


antlrcpp::Any FeatParser::GdefLigCaretIndexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitGdefLigCaretIndex(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::GdefLigCaretIndexContext* FeatParser::gdefLigCaretIndex() {
  GdefLigCaretIndexContext *_localctx = _tracker.createInstance<GdefLigCaretIndexContext>(_ctx, getState());
  enterRule(_localctx, 92, FeatParser::RuleGdefLigCaretIndex);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(688);
    match(FeatParser::LIG_CARET_BY_IDX);
    setState(689);
    lookupPattern();
    setState(691); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(690);
      match(FeatParser::NUM);
      setState(693); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == FeatParser::NUM);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_headContext ------------------------------------------------------------------

FeatParser::Table_headContext::Table_headContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FeatParser::Table_headContext::HEAD() {
  return getTokens(FeatParser::HEAD);
}

tree::TerminalNode* FeatParser::Table_headContext::HEAD(size_t i) {
  return getToken(FeatParser::HEAD, i);
}

tree::TerminalNode* FeatParser::Table_headContext::LCBRACE() {
  return getToken(FeatParser::LCBRACE, 0);
}

std::vector<tree::TerminalNode *> FeatParser::Table_headContext::SEMI() {
  return getTokens(FeatParser::SEMI);
}

tree::TerminalNode* FeatParser::Table_headContext::SEMI(size_t i) {
  return getToken(FeatParser::SEMI, i);
}

tree::TerminalNode* FeatParser::Table_headContext::RCBRACE() {
  return getToken(FeatParser::RCBRACE, 0);
}

tree::TerminalNode* FeatParser::Table_headContext::FONT_REVISION() {
  return getToken(FeatParser::FONT_REVISION, 0);
}

tree::TerminalNode* FeatParser::Table_headContext::POINTNUM() {
  return getToken(FeatParser::POINTNUM, 0);
}


size_t FeatParser::Table_headContext::getRuleIndex() const {
  return FeatParser::RuleTable_head;
}


antlrcpp::Any FeatParser::Table_headContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitTable_head(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::Table_headContext* FeatParser::table_head() {
  Table_headContext *_localctx = _tracker.createInstance<Table_headContext>(_ctx, getState());
  enterRule(_localctx, 94, FeatParser::RuleTable_head);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(695);
    match(FeatParser::HEAD);
    setState(696);
    match(FeatParser::LCBRACE);
    setState(699);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FeatParser::FONT_REVISION) {
      setState(697);
      match(FeatParser::FONT_REVISION);
      setState(698);
      match(FeatParser::POINTNUM);
    }
    setState(701);
    match(FeatParser::SEMI);
    setState(702);
    match(FeatParser::RCBRACE);
    setState(703);
    match(FeatParser::HEAD);
    setState(704);
    match(FeatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_hheaContext ------------------------------------------------------------------

FeatParser::Table_hheaContext::Table_hheaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FeatParser::Table_hheaContext::HHEA() {
  return getTokens(FeatParser::HHEA);
}

tree::TerminalNode* FeatParser::Table_hheaContext::HHEA(size_t i) {
  return getToken(FeatParser::HHEA, i);
}

tree::TerminalNode* FeatParser::Table_hheaContext::LCBRACE() {
  return getToken(FeatParser::LCBRACE, 0);
}

tree::TerminalNode* FeatParser::Table_hheaContext::RCBRACE() {
  return getToken(FeatParser::RCBRACE, 0);
}

tree::TerminalNode* FeatParser::Table_hheaContext::SEMI() {
  return getToken(FeatParser::SEMI, 0);
}

std::vector<FeatParser::HheaStatementContext *> FeatParser::Table_hheaContext::hheaStatement() {
  return getRuleContexts<FeatParser::HheaStatementContext>();
}

FeatParser::HheaStatementContext* FeatParser::Table_hheaContext::hheaStatement(size_t i) {
  return getRuleContext<FeatParser::HheaStatementContext>(i);
}


size_t FeatParser::Table_hheaContext::getRuleIndex() const {
  return FeatParser::RuleTable_hhea;
}


antlrcpp::Any FeatParser::Table_hheaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitTable_hhea(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::Table_hheaContext* FeatParser::table_hhea() {
  Table_hheaContext *_localctx = _tracker.createInstance<Table_hheaContext>(_ctx, getState());
  enterRule(_localctx, 96, FeatParser::RuleTable_hhea);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(706);
    match(FeatParser::HHEA);
    setState(707);
    match(FeatParser::LCBRACE);
    setState(711);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FeatParser::INCLUDE || ((((_la - 73) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 73)) & ((1ULL << (FeatParser::ASCENDER - 73))
      | (1ULL << (FeatParser::DESCENDER - 73))
      | (1ULL << (FeatParser::LINE_GAP - 73))
      | (1ULL << (FeatParser::CARET_OFFSET - 73)))) != 0)) {
      setState(708);
      hheaStatement();
      setState(713);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(714);
    match(FeatParser::RCBRACE);
    setState(715);
    match(FeatParser::HHEA);
    setState(716);
    match(FeatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- HheaStatementContext ------------------------------------------------------------------

FeatParser::HheaStatementContext::HheaStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::HheaStatementContext::SEMI() {
  return getToken(FeatParser::SEMI, 0);
}

FeatParser::HheaContext* FeatParser::HheaStatementContext::hhea() {
  return getRuleContext<FeatParser::HheaContext>(0);
}

FeatParser::IncludeContext* FeatParser::HheaStatementContext::include() {
  return getRuleContext<FeatParser::IncludeContext>(0);
}


size_t FeatParser::HheaStatementContext::getRuleIndex() const {
  return FeatParser::RuleHheaStatement;
}


antlrcpp::Any FeatParser::HheaStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitHheaStatement(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::HheaStatementContext* FeatParser::hheaStatement() {
  HheaStatementContext *_localctx = _tracker.createInstance<HheaStatementContext>(_ctx, getState());
  enterRule(_localctx, 98, FeatParser::RuleHheaStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(720);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::ASCENDER:
      case FeatParser::DESCENDER:
      case FeatParser::LINE_GAP:
      case FeatParser::CARET_OFFSET: {
        setState(718);
        hhea();
        break;
      }

      case FeatParser::INCLUDE: {
        setState(719);
        include();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(722);
    match(FeatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- HheaContext ------------------------------------------------------------------

FeatParser::HheaContext::HheaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::HheaContext::NUM() {
  return getToken(FeatParser::NUM, 0);
}

tree::TerminalNode* FeatParser::HheaContext::CARET_OFFSET() {
  return getToken(FeatParser::CARET_OFFSET, 0);
}

tree::TerminalNode* FeatParser::HheaContext::ASCENDER() {
  return getToken(FeatParser::ASCENDER, 0);
}

tree::TerminalNode* FeatParser::HheaContext::DESCENDER() {
  return getToken(FeatParser::DESCENDER, 0);
}

tree::TerminalNode* FeatParser::HheaContext::LINE_GAP() {
  return getToken(FeatParser::LINE_GAP, 0);
}


size_t FeatParser::HheaContext::getRuleIndex() const {
  return FeatParser::RuleHhea;
}


antlrcpp::Any FeatParser::HheaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitHhea(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::HheaContext* FeatParser::hhea() {
  HheaContext *_localctx = _tracker.createInstance<HheaContext>(_ctx, getState());
  enterRule(_localctx, 100, FeatParser::RuleHhea);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(724);
    _la = _input->LA(1);
    if (!(((((_la - 73) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 73)) & ((1ULL << (FeatParser::ASCENDER - 73))
      | (1ULL << (FeatParser::DESCENDER - 73))
      | (1ULL << (FeatParser::LINE_GAP - 73))
      | (1ULL << (FeatParser::CARET_OFFSET - 73)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(725);
    match(FeatParser::NUM);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_vheaContext ------------------------------------------------------------------

FeatParser::Table_vheaContext::Table_vheaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FeatParser::Table_vheaContext::VHEA() {
  return getTokens(FeatParser::VHEA);
}

tree::TerminalNode* FeatParser::Table_vheaContext::VHEA(size_t i) {
  return getToken(FeatParser::VHEA, i);
}

tree::TerminalNode* FeatParser::Table_vheaContext::LCBRACE() {
  return getToken(FeatParser::LCBRACE, 0);
}

tree::TerminalNode* FeatParser::Table_vheaContext::RCBRACE() {
  return getToken(FeatParser::RCBRACE, 0);
}

tree::TerminalNode* FeatParser::Table_vheaContext::SEMI() {
  return getToken(FeatParser::SEMI, 0);
}

std::vector<FeatParser::VheaStatementContext *> FeatParser::Table_vheaContext::vheaStatement() {
  return getRuleContexts<FeatParser::VheaStatementContext>();
}

FeatParser::VheaStatementContext* FeatParser::Table_vheaContext::vheaStatement(size_t i) {
  return getRuleContext<FeatParser::VheaStatementContext>(i);
}


size_t FeatParser::Table_vheaContext::getRuleIndex() const {
  return FeatParser::RuleTable_vhea;
}


antlrcpp::Any FeatParser::Table_vheaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitTable_vhea(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::Table_vheaContext* FeatParser::table_vhea() {
  Table_vheaContext *_localctx = _tracker.createInstance<Table_vheaContext>(_ctx, getState());
  enterRule(_localctx, 102, FeatParser::RuleTable_vhea);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(727);
    match(FeatParser::VHEA);
    setState(728);
    match(FeatParser::LCBRACE);
    setState(732);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FeatParser::INCLUDE || ((((_la - 108) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 108)) & ((1ULL << (FeatParser::VERT_TYPO_ASCENDER - 108))
      | (1ULL << (FeatParser::VERT_TYPO_DESCENDER - 108))
      | (1ULL << (FeatParser::VERT_TYPO_LINE_GAP - 108)))) != 0)) {
      setState(729);
      vheaStatement();
      setState(734);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(735);
    match(FeatParser::RCBRACE);
    setState(736);
    match(FeatParser::VHEA);
    setState(737);
    match(FeatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VheaStatementContext ------------------------------------------------------------------

FeatParser::VheaStatementContext::VheaStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::VheaStatementContext::SEMI() {
  return getToken(FeatParser::SEMI, 0);
}

FeatParser::VheaContext* FeatParser::VheaStatementContext::vhea() {
  return getRuleContext<FeatParser::VheaContext>(0);
}

FeatParser::IncludeContext* FeatParser::VheaStatementContext::include() {
  return getRuleContext<FeatParser::IncludeContext>(0);
}


size_t FeatParser::VheaStatementContext::getRuleIndex() const {
  return FeatParser::RuleVheaStatement;
}


antlrcpp::Any FeatParser::VheaStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitVheaStatement(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::VheaStatementContext* FeatParser::vheaStatement() {
  VheaStatementContext *_localctx = _tracker.createInstance<VheaStatementContext>(_ctx, getState());
  enterRule(_localctx, 104, FeatParser::RuleVheaStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(741);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::VERT_TYPO_ASCENDER:
      case FeatParser::VERT_TYPO_DESCENDER:
      case FeatParser::VERT_TYPO_LINE_GAP: {
        setState(739);
        vhea();
        break;
      }

      case FeatParser::INCLUDE: {
        setState(740);
        include();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(743);
    match(FeatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VheaContext ------------------------------------------------------------------

FeatParser::VheaContext::VheaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::VheaContext::NUM() {
  return getToken(FeatParser::NUM, 0);
}

tree::TerminalNode* FeatParser::VheaContext::VERT_TYPO_ASCENDER() {
  return getToken(FeatParser::VERT_TYPO_ASCENDER, 0);
}

tree::TerminalNode* FeatParser::VheaContext::VERT_TYPO_DESCENDER() {
  return getToken(FeatParser::VERT_TYPO_DESCENDER, 0);
}

tree::TerminalNode* FeatParser::VheaContext::VERT_TYPO_LINE_GAP() {
  return getToken(FeatParser::VERT_TYPO_LINE_GAP, 0);
}


size_t FeatParser::VheaContext::getRuleIndex() const {
  return FeatParser::RuleVhea;
}


antlrcpp::Any FeatParser::VheaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitVhea(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::VheaContext* FeatParser::vhea() {
  VheaContext *_localctx = _tracker.createInstance<VheaContext>(_ctx, getState());
  enterRule(_localctx, 106, FeatParser::RuleVhea);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(745);
    _la = _input->LA(1);
    if (!(((((_la - 108) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 108)) & ((1ULL << (FeatParser::VERT_TYPO_ASCENDER - 108))
      | (1ULL << (FeatParser::VERT_TYPO_DESCENDER - 108))
      | (1ULL << (FeatParser::VERT_TYPO_LINE_GAP - 108)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(746);
    match(FeatParser::NUM);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_nameContext ------------------------------------------------------------------

FeatParser::Table_nameContext::Table_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FeatParser::Table_nameContext::NAME() {
  return getTokens(FeatParser::NAME);
}

tree::TerminalNode* FeatParser::Table_nameContext::NAME(size_t i) {
  return getToken(FeatParser::NAME, i);
}

tree::TerminalNode* FeatParser::Table_nameContext::LCBRACE() {
  return getToken(FeatParser::LCBRACE, 0);
}

tree::TerminalNode* FeatParser::Table_nameContext::RCBRACE() {
  return getToken(FeatParser::RCBRACE, 0);
}

tree::TerminalNode* FeatParser::Table_nameContext::SEMI() {
  return getToken(FeatParser::SEMI, 0);
}

std::vector<FeatParser::NameStatementContext *> FeatParser::Table_nameContext::nameStatement() {
  return getRuleContexts<FeatParser::NameStatementContext>();
}

FeatParser::NameStatementContext* FeatParser::Table_nameContext::nameStatement(size_t i) {
  return getRuleContext<FeatParser::NameStatementContext>(i);
}


size_t FeatParser::Table_nameContext::getRuleIndex() const {
  return FeatParser::RuleTable_name;
}


antlrcpp::Any FeatParser::Table_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitTable_name(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::Table_nameContext* FeatParser::table_name() {
  Table_nameContext *_localctx = _tracker.createInstance<Table_nameContext>(_ctx, getState());
  enterRule(_localctx, 108, FeatParser::RuleTable_name);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(748);
    match(FeatParser::NAME);
    setState(749);
    match(FeatParser::LCBRACE);
    setState(751); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(750);
      nameStatement();
      setState(753); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == FeatParser::INCLUDE || _la == FeatParser::NAMEID);
    setState(755);
    match(FeatParser::RCBRACE);
    setState(756);
    match(FeatParser::NAME);
    setState(757);
    match(FeatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameStatementContext ------------------------------------------------------------------

FeatParser::NameStatementContext::NameStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::NameStatementContext::SEMI() {
  return getToken(FeatParser::SEMI, 0);
}

FeatParser::NameIDContext* FeatParser::NameStatementContext::nameID() {
  return getRuleContext<FeatParser::NameIDContext>(0);
}

FeatParser::IncludeContext* FeatParser::NameStatementContext::include() {
  return getRuleContext<FeatParser::IncludeContext>(0);
}


size_t FeatParser::NameStatementContext::getRuleIndex() const {
  return FeatParser::RuleNameStatement;
}


antlrcpp::Any FeatParser::NameStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitNameStatement(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::NameStatementContext* FeatParser::nameStatement() {
  NameStatementContext *_localctx = _tracker.createInstance<NameStatementContext>(_ctx, getState());
  enterRule(_localctx, 110, FeatParser::RuleNameStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(761);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::NAMEID: {
        setState(759);
        nameID();
        break;
      }

      case FeatParser::INCLUDE: {
        setState(760);
        include();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(763);
    match(FeatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameIDContext ------------------------------------------------------------------

FeatParser::NameIDContext::NameIDContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::NameIDContext::NAMEID() {
  return getToken(FeatParser::NAMEID, 0);
}

tree::TerminalNode* FeatParser::NameIDContext::QUOTE() {
  return getToken(FeatParser::QUOTE, 0);
}

tree::TerminalNode* FeatParser::NameIDContext::STRVAL() {
  return getToken(FeatParser::STRVAL, 0);
}

tree::TerminalNode* FeatParser::NameIDContext::EQUOTE() {
  return getToken(FeatParser::EQUOTE, 0);
}

std::vector<FeatParser::GenNumContext *> FeatParser::NameIDContext::genNum() {
  return getRuleContexts<FeatParser::GenNumContext>();
}

FeatParser::GenNumContext* FeatParser::NameIDContext::genNum(size_t i) {
  return getRuleContext<FeatParser::GenNumContext>(i);
}


size_t FeatParser::NameIDContext::getRuleIndex() const {
  return FeatParser::RuleNameID;
}


antlrcpp::Any FeatParser::NameIDContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitNameID(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::NameIDContext* FeatParser::nameID() {
  NameIDContext *_localctx = _tracker.createInstance<NameIDContext>(_ctx, getState());
  enterRule(_localctx, 112, FeatParser::RuleNameID);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(765);
    match(FeatParser::NAMEID);
    setState(766);
    dynamic_cast<NameIDContext *>(_localctx)->id = genNum();
    setState(773);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 130) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 130)) & ((1ULL << (FeatParser::NUMEXT - 130))
      | (1ULL << (FeatParser::NUMOCT - 130))
      | (1ULL << (FeatParser::NUM - 130)))) != 0)) {
      setState(767);
      dynamic_cast<NameIDContext *>(_localctx)->plat = genNum();
      setState(771);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 130) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 130)) & ((1ULL << (FeatParser::NUMEXT - 130))
        | (1ULL << (FeatParser::NUMOCT - 130))
        | (1ULL << (FeatParser::NUM - 130)))) != 0)) {
        setState(768);
        dynamic_cast<NameIDContext *>(_localctx)->spec = genNum();
        setState(769);
        dynamic_cast<NameIDContext *>(_localctx)->lang = genNum();
      }
    }
    setState(775);
    match(FeatParser::QUOTE);
    setState(776);
    match(FeatParser::STRVAL);
    setState(777);
    match(FeatParser::EQUOTE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_OS_2Context ------------------------------------------------------------------

FeatParser::Table_OS_2Context::Table_OS_2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FeatParser::Table_OS_2Context::OS_2() {
  return getTokens(FeatParser::OS_2);
}

tree::TerminalNode* FeatParser::Table_OS_2Context::OS_2(size_t i) {
  return getToken(FeatParser::OS_2, i);
}

tree::TerminalNode* FeatParser::Table_OS_2Context::LCBRACE() {
  return getToken(FeatParser::LCBRACE, 0);
}

tree::TerminalNode* FeatParser::Table_OS_2Context::RCBRACE() {
  return getToken(FeatParser::RCBRACE, 0);
}

tree::TerminalNode* FeatParser::Table_OS_2Context::SEMI() {
  return getToken(FeatParser::SEMI, 0);
}

std::vector<FeatParser::Os_2StatementContext *> FeatParser::Table_OS_2Context::os_2Statement() {
  return getRuleContexts<FeatParser::Os_2StatementContext>();
}

FeatParser::Os_2StatementContext* FeatParser::Table_OS_2Context::os_2Statement(size_t i) {
  return getRuleContext<FeatParser::Os_2StatementContext>(i);
}


size_t FeatParser::Table_OS_2Context::getRuleIndex() const {
  return FeatParser::RuleTable_OS_2;
}


antlrcpp::Any FeatParser::Table_OS_2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitTable_OS_2(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::Table_OS_2Context* FeatParser::table_OS_2() {
  Table_OS_2Context *_localctx = _tracker.createInstance<Table_OS_2Context>(_ctx, getState());
  enterRule(_localctx, 114, FeatParser::RuleTable_OS_2);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(779);
    match(FeatParser::OS_2);
    setState(780);
    match(FeatParser::LCBRACE);
    setState(782); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(781);
      os_2Statement();
      setState(784); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == FeatParser::INCLUDE || ((((_la - 80) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 80)) & ((1ULL << (FeatParser::FS_TYPE - 80))
      | (1ULL << (FeatParser::FS_TYPE_v - 80))
      | (1ULL << (FeatParser::OS2_LOWER_OP_SIZE - 80))
      | (1ULL << (FeatParser::OS2_UPPER_OP_SIZE - 80))
      | (1ULL << (FeatParser::PANOSE - 80))
      | (1ULL << (FeatParser::TYPO_ASCENDER - 80))
      | (1ULL << (FeatParser::TYPO_DESCENDER - 80))
      | (1ULL << (FeatParser::TYPO_LINE_GAP - 80))
      | (1ULL << (FeatParser::WIN_ASCENT - 80))
      | (1ULL << (FeatParser::WIN_DESCENT - 80))
      | (1ULL << (FeatParser::X_HEIGHT - 80))
      | (1ULL << (FeatParser::CAP_HEIGHT - 80))
      | (1ULL << (FeatParser::WEIGHT_CLASS - 80))
      | (1ULL << (FeatParser::WIDTH_CLASS - 80))
      | (1ULL << (FeatParser::VENDOR - 80))
      | (1ULL << (FeatParser::UNICODE_RANGE - 80))
      | (1ULL << (FeatParser::CODE_PAGE_RANGE - 80))
      | (1ULL << (FeatParser::FAMILY_CLASS - 80)))) != 0));
    setState(786);
    match(FeatParser::RCBRACE);
    setState(787);
    match(FeatParser::OS_2);
    setState(788);
    match(FeatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Os_2StatementContext ------------------------------------------------------------------

FeatParser::Os_2StatementContext::Os_2StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::Os_2StatementContext::SEMI() {
  return getToken(FeatParser::SEMI, 0);
}

FeatParser::Os_2Context* FeatParser::Os_2StatementContext::os_2() {
  return getRuleContext<FeatParser::Os_2Context>(0);
}

FeatParser::IncludeContext* FeatParser::Os_2StatementContext::include() {
  return getRuleContext<FeatParser::IncludeContext>(0);
}


size_t FeatParser::Os_2StatementContext::getRuleIndex() const {
  return FeatParser::RuleOs_2Statement;
}


antlrcpp::Any FeatParser::Os_2StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitOs_2Statement(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::Os_2StatementContext* FeatParser::os_2Statement() {
  Os_2StatementContext *_localctx = _tracker.createInstance<Os_2StatementContext>(_ctx, getState());
  enterRule(_localctx, 116, FeatParser::RuleOs_2Statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(792);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::FS_TYPE:
      case FeatParser::FS_TYPE_v:
      case FeatParser::OS2_LOWER_OP_SIZE:
      case FeatParser::OS2_UPPER_OP_SIZE:
      case FeatParser::PANOSE:
      case FeatParser::TYPO_ASCENDER:
      case FeatParser::TYPO_DESCENDER:
      case FeatParser::TYPO_LINE_GAP:
      case FeatParser::WIN_ASCENT:
      case FeatParser::WIN_DESCENT:
      case FeatParser::X_HEIGHT:
      case FeatParser::CAP_HEIGHT:
      case FeatParser::WEIGHT_CLASS:
      case FeatParser::WIDTH_CLASS:
      case FeatParser::VENDOR:
      case FeatParser::UNICODE_RANGE:
      case FeatParser::CODE_PAGE_RANGE:
      case FeatParser::FAMILY_CLASS: {
        setState(790);
        os_2();
        break;
      }

      case FeatParser::INCLUDE: {
        setState(791);
        include();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(794);
    match(FeatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Os_2Context ------------------------------------------------------------------

FeatParser::Os_2Context::Os_2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::Os_2Context::TYPO_ASCENDER() {
  return getToken(FeatParser::TYPO_ASCENDER, 0);
}

tree::TerminalNode* FeatParser::Os_2Context::TYPO_DESCENDER() {
  return getToken(FeatParser::TYPO_DESCENDER, 0);
}

tree::TerminalNode* FeatParser::Os_2Context::TYPO_LINE_GAP() {
  return getToken(FeatParser::TYPO_LINE_GAP, 0);
}

tree::TerminalNode* FeatParser::Os_2Context::WIN_ASCENT() {
  return getToken(FeatParser::WIN_ASCENT, 0);
}

tree::TerminalNode* FeatParser::Os_2Context::WIN_DESCENT() {
  return getToken(FeatParser::WIN_DESCENT, 0);
}

tree::TerminalNode* FeatParser::Os_2Context::X_HEIGHT() {
  return getToken(FeatParser::X_HEIGHT, 0);
}

tree::TerminalNode* FeatParser::Os_2Context::CAP_HEIGHT() {
  return getToken(FeatParser::CAP_HEIGHT, 0);
}

std::vector<tree::TerminalNode *> FeatParser::Os_2Context::NUM() {
  return getTokens(FeatParser::NUM);
}

tree::TerminalNode* FeatParser::Os_2Context::NUM(size_t i) {
  return getToken(FeatParser::NUM, i);
}

tree::TerminalNode* FeatParser::Os_2Context::FS_TYPE() {
  return getToken(FeatParser::FS_TYPE, 0);
}

tree::TerminalNode* FeatParser::Os_2Context::FS_TYPE_v() {
  return getToken(FeatParser::FS_TYPE_v, 0);
}

tree::TerminalNode* FeatParser::Os_2Context::WEIGHT_CLASS() {
  return getToken(FeatParser::WEIGHT_CLASS, 0);
}

tree::TerminalNode* FeatParser::Os_2Context::WIDTH_CLASS() {
  return getToken(FeatParser::WIDTH_CLASS, 0);
}

tree::TerminalNode* FeatParser::Os_2Context::OS2_LOWER_OP_SIZE() {
  return getToken(FeatParser::OS2_LOWER_OP_SIZE, 0);
}

tree::TerminalNode* FeatParser::Os_2Context::OS2_UPPER_OP_SIZE() {
  return getToken(FeatParser::OS2_UPPER_OP_SIZE, 0);
}

tree::TerminalNode* FeatParser::Os_2Context::FAMILY_CLASS() {
  return getToken(FeatParser::FAMILY_CLASS, 0);
}

FeatParser::GenNumContext* FeatParser::Os_2Context::genNum() {
  return getRuleContext<FeatParser::GenNumContext>(0);
}

tree::TerminalNode* FeatParser::Os_2Context::VENDOR() {
  return getToken(FeatParser::VENDOR, 0);
}

tree::TerminalNode* FeatParser::Os_2Context::QUOTE() {
  return getToken(FeatParser::QUOTE, 0);
}

tree::TerminalNode* FeatParser::Os_2Context::STRVAL() {
  return getToken(FeatParser::STRVAL, 0);
}

tree::TerminalNode* FeatParser::Os_2Context::EQUOTE() {
  return getToken(FeatParser::EQUOTE, 0);
}

tree::TerminalNode* FeatParser::Os_2Context::PANOSE() {
  return getToken(FeatParser::PANOSE, 0);
}

tree::TerminalNode* FeatParser::Os_2Context::UNICODE_RANGE() {
  return getToken(FeatParser::UNICODE_RANGE, 0);
}

tree::TerminalNode* FeatParser::Os_2Context::CODE_PAGE_RANGE() {
  return getToken(FeatParser::CODE_PAGE_RANGE, 0);
}


size_t FeatParser::Os_2Context::getRuleIndex() const {
  return FeatParser::RuleOs_2;
}


antlrcpp::Any FeatParser::Os_2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitOs_2(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::Os_2Context* FeatParser::os_2() {
  Os_2Context *_localctx = _tracker.createInstance<Os_2Context>(_ctx, getState());
  enterRule(_localctx, 118, FeatParser::RuleOs_2);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(823);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::TYPO_ASCENDER:
      case FeatParser::TYPO_DESCENDER:
      case FeatParser::TYPO_LINE_GAP:
      case FeatParser::WIN_ASCENT:
      case FeatParser::WIN_DESCENT:
      case FeatParser::X_HEIGHT:
      case FeatParser::CAP_HEIGHT: {
        enterOuterAlt(_localctx, 1);
        setState(796);
        _la = _input->LA(1);
        if (!(((((_la - 85) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 85)) & ((1ULL << (FeatParser::TYPO_ASCENDER - 85))
          | (1ULL << (FeatParser::TYPO_DESCENDER - 85))
          | (1ULL << (FeatParser::TYPO_LINE_GAP - 85))
          | (1ULL << (FeatParser::WIN_ASCENT - 85))
          | (1ULL << (FeatParser::WIN_DESCENT - 85))
          | (1ULL << (FeatParser::X_HEIGHT - 85))
          | (1ULL << (FeatParser::CAP_HEIGHT - 85)))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(797);
        dynamic_cast<Os_2Context *>(_localctx)->num = match(FeatParser::NUM);
        break;
      }

      case FeatParser::FS_TYPE:
      case FeatParser::FS_TYPE_v:
      case FeatParser::OS2_LOWER_OP_SIZE:
      case FeatParser::OS2_UPPER_OP_SIZE:
      case FeatParser::WEIGHT_CLASS:
      case FeatParser::WIDTH_CLASS: {
        enterOuterAlt(_localctx, 2);
        setState(798);
        _la = _input->LA(1);
        if (!(((((_la - 80) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 80)) & ((1ULL << (FeatParser::FS_TYPE - 80))
          | (1ULL << (FeatParser::FS_TYPE_v - 80))
          | (1ULL << (FeatParser::OS2_LOWER_OP_SIZE - 80))
          | (1ULL << (FeatParser::OS2_UPPER_OP_SIZE - 80))
          | (1ULL << (FeatParser::WEIGHT_CLASS - 80))
          | (1ULL << (FeatParser::WIDTH_CLASS - 80)))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(799);
        dynamic_cast<Os_2Context *>(_localctx)->unum = match(FeatParser::NUM);
        break;
      }

      case FeatParser::FAMILY_CLASS: {
        enterOuterAlt(_localctx, 3);
        setState(800);
        match(FeatParser::FAMILY_CLASS);
        setState(801);
        dynamic_cast<Os_2Context *>(_localctx)->gnum = genNum();
        break;
      }

      case FeatParser::VENDOR: {
        enterOuterAlt(_localctx, 4);
        setState(802);
        match(FeatParser::VENDOR);
        setState(803);
        match(FeatParser::QUOTE);
        setState(804);
        match(FeatParser::STRVAL);
        setState(805);
        match(FeatParser::EQUOTE);
        break;
      }

      case FeatParser::PANOSE: {
        enterOuterAlt(_localctx, 5);
        setState(806);
        match(FeatParser::PANOSE);
        setState(807);
        match(FeatParser::NUM);
        setState(808);
        match(FeatParser::NUM);
        setState(809);
        match(FeatParser::NUM);
        setState(810);
        match(FeatParser::NUM);
        setState(811);
        match(FeatParser::NUM);
        setState(812);
        match(FeatParser::NUM);
        setState(813);
        match(FeatParser::NUM);
        setState(814);
        match(FeatParser::NUM);
        setState(815);
        match(FeatParser::NUM);
        setState(816);
        match(FeatParser::NUM);
        break;
      }

      case FeatParser::UNICODE_RANGE:
      case FeatParser::CODE_PAGE_RANGE: {
        enterOuterAlt(_localctx, 6);
        setState(817);
        _la = _input->LA(1);
        if (!(_la == FeatParser::UNICODE_RANGE

        || _la == FeatParser::CODE_PAGE_RANGE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(819); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(818);
          match(FeatParser::NUM);
          setState(821); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == FeatParser::NUM);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_STATContext ------------------------------------------------------------------

FeatParser::Table_STATContext::Table_STATContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FeatParser::Table_STATContext::STAT() {
  return getTokens(FeatParser::STAT);
}

tree::TerminalNode* FeatParser::Table_STATContext::STAT(size_t i) {
  return getToken(FeatParser::STAT, i);
}

tree::TerminalNode* FeatParser::Table_STATContext::LCBRACE() {
  return getToken(FeatParser::LCBRACE, 0);
}

tree::TerminalNode* FeatParser::Table_STATContext::RCBRACE() {
  return getToken(FeatParser::RCBRACE, 0);
}

tree::TerminalNode* FeatParser::Table_STATContext::SEMI() {
  return getToken(FeatParser::SEMI, 0);
}

std::vector<FeatParser::StatStatementContext *> FeatParser::Table_STATContext::statStatement() {
  return getRuleContexts<FeatParser::StatStatementContext>();
}

FeatParser::StatStatementContext* FeatParser::Table_STATContext::statStatement(size_t i) {
  return getRuleContext<FeatParser::StatStatementContext>(i);
}


size_t FeatParser::Table_STATContext::getRuleIndex() const {
  return FeatParser::RuleTable_STAT;
}


antlrcpp::Any FeatParser::Table_STATContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitTable_STAT(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::Table_STATContext* FeatParser::table_STAT() {
  Table_STATContext *_localctx = _tracker.createInstance<Table_STATContext>(_ctx, getState());
  enterRule(_localctx, 120, FeatParser::RuleTable_STAT);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(825);
    match(FeatParser::STAT);
    setState(826);
    match(FeatParser::LCBRACE);
    setState(828); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(827);
      statStatement();
      setState(830); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == FeatParser::INCLUDE || ((((_la - 99) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 99)) & ((1ULL << (FeatParser::ELIDED_FALLBACK_NAME - 99))
      | (1ULL << (FeatParser::ELIDED_FALLBACK_NAME_ID - 99))
      | (1ULL << (FeatParser::DESIGN_AXIS - 99))
      | (1ULL << (FeatParser::AXIS_VALUE - 99)))) != 0));
    setState(832);
    match(FeatParser::RCBRACE);
    setState(833);
    match(FeatParser::STAT);
    setState(834);
    match(FeatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatStatementContext ------------------------------------------------------------------

FeatParser::StatStatementContext::StatStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::StatStatementContext::SEMI() {
  return getToken(FeatParser::SEMI, 0);
}

FeatParser::DesignAxisContext* FeatParser::StatStatementContext::designAxis() {
  return getRuleContext<FeatParser::DesignAxisContext>(0);
}

FeatParser::AxisValueContext* FeatParser::StatStatementContext::axisValue() {
  return getRuleContext<FeatParser::AxisValueContext>(0);
}

FeatParser::ElidedFallbackNameContext* FeatParser::StatStatementContext::elidedFallbackName() {
  return getRuleContext<FeatParser::ElidedFallbackNameContext>(0);
}

FeatParser::ElidedFallbackNameIDContext* FeatParser::StatStatementContext::elidedFallbackNameID() {
  return getRuleContext<FeatParser::ElidedFallbackNameIDContext>(0);
}

FeatParser::IncludeContext* FeatParser::StatStatementContext::include() {
  return getRuleContext<FeatParser::IncludeContext>(0);
}


size_t FeatParser::StatStatementContext::getRuleIndex() const {
  return FeatParser::RuleStatStatement;
}


antlrcpp::Any FeatParser::StatStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitStatStatement(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::StatStatementContext* FeatParser::statStatement() {
  StatStatementContext *_localctx = _tracker.createInstance<StatStatementContext>(_ctx, getState());
  enterRule(_localctx, 122, FeatParser::RuleStatStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(841);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::DESIGN_AXIS: {
        setState(836);
        designAxis();
        break;
      }

      case FeatParser::AXIS_VALUE: {
        setState(837);
        axisValue();
        break;
      }

      case FeatParser::ELIDED_FALLBACK_NAME: {
        setState(838);
        elidedFallbackName();
        break;
      }

      case FeatParser::ELIDED_FALLBACK_NAME_ID: {
        setState(839);
        elidedFallbackNameID();
        break;
      }

      case FeatParser::INCLUDE: {
        setState(840);
        include();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(843);
    match(FeatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DesignAxisContext ------------------------------------------------------------------

FeatParser::DesignAxisContext::DesignAxisContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::DesignAxisContext::DESIGN_AXIS() {
  return getToken(FeatParser::DESIGN_AXIS, 0);
}

FeatParser::TagContext* FeatParser::DesignAxisContext::tag() {
  return getRuleContext<FeatParser::TagContext>(0);
}

tree::TerminalNode* FeatParser::DesignAxisContext::NUM() {
  return getToken(FeatParser::NUM, 0);
}

tree::TerminalNode* FeatParser::DesignAxisContext::LCBRACE() {
  return getToken(FeatParser::LCBRACE, 0);
}

tree::TerminalNode* FeatParser::DesignAxisContext::RCBRACE() {
  return getToken(FeatParser::RCBRACE, 0);
}

std::vector<FeatParser::NameEntryStatementContext *> FeatParser::DesignAxisContext::nameEntryStatement() {
  return getRuleContexts<FeatParser::NameEntryStatementContext>();
}

FeatParser::NameEntryStatementContext* FeatParser::DesignAxisContext::nameEntryStatement(size_t i) {
  return getRuleContext<FeatParser::NameEntryStatementContext>(i);
}


size_t FeatParser::DesignAxisContext::getRuleIndex() const {
  return FeatParser::RuleDesignAxis;
}


antlrcpp::Any FeatParser::DesignAxisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitDesignAxis(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::DesignAxisContext* FeatParser::designAxis() {
  DesignAxisContext *_localctx = _tracker.createInstance<DesignAxisContext>(_ctx, getState());
  enterRule(_localctx, 124, FeatParser::RuleDesignAxis);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(845);
    match(FeatParser::DESIGN_AXIS);
    setState(846);
    tag();
    setState(847);
    match(FeatParser::NUM);
    setState(848);
    match(FeatParser::LCBRACE);
    setState(850); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(849);
      nameEntryStatement();
      setState(852); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == FeatParser::INCLUDE || _la == FeatParser::NAME);
    setState(854);
    match(FeatParser::RCBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AxisValueContext ------------------------------------------------------------------

FeatParser::AxisValueContext::AxisValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::AxisValueContext::AXIS_VALUE() {
  return getToken(FeatParser::AXIS_VALUE, 0);
}

tree::TerminalNode* FeatParser::AxisValueContext::LCBRACE() {
  return getToken(FeatParser::LCBRACE, 0);
}

tree::TerminalNode* FeatParser::AxisValueContext::RCBRACE() {
  return getToken(FeatParser::RCBRACE, 0);
}

std::vector<FeatParser::AxisValueStatementContext *> FeatParser::AxisValueContext::axisValueStatement() {
  return getRuleContexts<FeatParser::AxisValueStatementContext>();
}

FeatParser::AxisValueStatementContext* FeatParser::AxisValueContext::axisValueStatement(size_t i) {
  return getRuleContext<FeatParser::AxisValueStatementContext>(i);
}


size_t FeatParser::AxisValueContext::getRuleIndex() const {
  return FeatParser::RuleAxisValue;
}


antlrcpp::Any FeatParser::AxisValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitAxisValue(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::AxisValueContext* FeatParser::axisValue() {
  AxisValueContext *_localctx = _tracker.createInstance<AxisValueContext>(_ctx, getState());
  enterRule(_localctx, 126, FeatParser::RuleAxisValue);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(856);
    match(FeatParser::AXIS_VALUE);
    setState(857);
    match(FeatParser::LCBRACE);
    setState(859); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(858);
      axisValueStatement();
      setState(861); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == FeatParser::INCLUDE || ((((_la - 77) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 77)) & ((1ULL << (FeatParser::NAME - 77))
      | (1ULL << (FeatParser::FLAG - 77))
      | (1ULL << (FeatParser::LOCATION - 77)))) != 0));
    setState(863);
    match(FeatParser::RCBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AxisValueStatementContext ------------------------------------------------------------------

FeatParser::AxisValueStatementContext::AxisValueStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::AxisValueStatementContext::SEMI() {
  return getToken(FeatParser::SEMI, 0);
}

FeatParser::NameEntryContext* FeatParser::AxisValueStatementContext::nameEntry() {
  return getRuleContext<FeatParser::NameEntryContext>(0);
}

FeatParser::AxisValueLocationContext* FeatParser::AxisValueStatementContext::axisValueLocation() {
  return getRuleContext<FeatParser::AxisValueLocationContext>(0);
}

FeatParser::AxisValueFlagsContext* FeatParser::AxisValueStatementContext::axisValueFlags() {
  return getRuleContext<FeatParser::AxisValueFlagsContext>(0);
}

FeatParser::IncludeContext* FeatParser::AxisValueStatementContext::include() {
  return getRuleContext<FeatParser::IncludeContext>(0);
}


size_t FeatParser::AxisValueStatementContext::getRuleIndex() const {
  return FeatParser::RuleAxisValueStatement;
}


antlrcpp::Any FeatParser::AxisValueStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitAxisValueStatement(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::AxisValueStatementContext* FeatParser::axisValueStatement() {
  AxisValueStatementContext *_localctx = _tracker.createInstance<AxisValueStatementContext>(_ctx, getState());
  enterRule(_localctx, 128, FeatParser::RuleAxisValueStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(869);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::NAME: {
        setState(865);
        nameEntry();
        break;
      }

      case FeatParser::LOCATION: {
        setState(866);
        axisValueLocation();
        break;
      }

      case FeatParser::FLAG: {
        setState(867);
        axisValueFlags();
        break;
      }

      case FeatParser::INCLUDE: {
        setState(868);
        include();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(871);
    match(FeatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AxisValueLocationContext ------------------------------------------------------------------

FeatParser::AxisValueLocationContext::AxisValueLocationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::AxisValueLocationContext::LOCATION() {
  return getToken(FeatParser::LOCATION, 0);
}

FeatParser::TagContext* FeatParser::AxisValueLocationContext::tag() {
  return getRuleContext<FeatParser::TagContext>(0);
}

std::vector<FeatParser::FixedNumContext *> FeatParser::AxisValueLocationContext::fixedNum() {
  return getRuleContexts<FeatParser::FixedNumContext>();
}

FeatParser::FixedNumContext* FeatParser::AxisValueLocationContext::fixedNum(size_t i) {
  return getRuleContext<FeatParser::FixedNumContext>(i);
}


size_t FeatParser::AxisValueLocationContext::getRuleIndex() const {
  return FeatParser::RuleAxisValueLocation;
}


antlrcpp::Any FeatParser::AxisValueLocationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitAxisValueLocation(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::AxisValueLocationContext* FeatParser::axisValueLocation() {
  AxisValueLocationContext *_localctx = _tracker.createInstance<AxisValueLocationContext>(_ctx, getState());
  enterRule(_localctx, 130, FeatParser::RuleAxisValueLocation);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(873);
    match(FeatParser::LOCATION);
    setState(874);
    tag();
    setState(875);
    fixedNum();
    setState(880);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FeatParser::POINTNUM

    || _la == FeatParser::NUM) {
      setState(876);
      fixedNum();
      setState(878);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == FeatParser::POINTNUM

      || _la == FeatParser::NUM) {
        setState(877);
        fixedNum();
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AxisValueFlagsContext ------------------------------------------------------------------

FeatParser::AxisValueFlagsContext::AxisValueFlagsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::AxisValueFlagsContext::FLAG() {
  return getToken(FeatParser::FLAG, 0);
}

std::vector<tree::TerminalNode *> FeatParser::AxisValueFlagsContext::AXIS_OSFA() {
  return getTokens(FeatParser::AXIS_OSFA);
}

tree::TerminalNode* FeatParser::AxisValueFlagsContext::AXIS_OSFA(size_t i) {
  return getToken(FeatParser::AXIS_OSFA, i);
}

std::vector<tree::TerminalNode *> FeatParser::AxisValueFlagsContext::AXIS_EAVN() {
  return getTokens(FeatParser::AXIS_EAVN);
}

tree::TerminalNode* FeatParser::AxisValueFlagsContext::AXIS_EAVN(size_t i) {
  return getToken(FeatParser::AXIS_EAVN, i);
}


size_t FeatParser::AxisValueFlagsContext::getRuleIndex() const {
  return FeatParser::RuleAxisValueFlags;
}


antlrcpp::Any FeatParser::AxisValueFlagsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitAxisValueFlags(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::AxisValueFlagsContext* FeatParser::axisValueFlags() {
  AxisValueFlagsContext *_localctx = _tracker.createInstance<AxisValueFlagsContext>(_ctx, getState());
  enterRule(_localctx, 132, FeatParser::RuleAxisValueFlags);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(882);
    match(FeatParser::FLAG);
    setState(884); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(883);
      _la = _input->LA(1);
      if (!(_la == FeatParser::AXIS_EAVN

      || _la == FeatParser::AXIS_OSFA)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(886); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == FeatParser::AXIS_EAVN

    || _la == FeatParser::AXIS_OSFA);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElidedFallbackNameContext ------------------------------------------------------------------

FeatParser::ElidedFallbackNameContext::ElidedFallbackNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::ElidedFallbackNameContext::ELIDED_FALLBACK_NAME() {
  return getToken(FeatParser::ELIDED_FALLBACK_NAME, 0);
}

tree::TerminalNode* FeatParser::ElidedFallbackNameContext::LCBRACE() {
  return getToken(FeatParser::LCBRACE, 0);
}

tree::TerminalNode* FeatParser::ElidedFallbackNameContext::RCBRACE() {
  return getToken(FeatParser::RCBRACE, 0);
}

std::vector<FeatParser::NameEntryStatementContext *> FeatParser::ElidedFallbackNameContext::nameEntryStatement() {
  return getRuleContexts<FeatParser::NameEntryStatementContext>();
}

FeatParser::NameEntryStatementContext* FeatParser::ElidedFallbackNameContext::nameEntryStatement(size_t i) {
  return getRuleContext<FeatParser::NameEntryStatementContext>(i);
}


size_t FeatParser::ElidedFallbackNameContext::getRuleIndex() const {
  return FeatParser::RuleElidedFallbackName;
}


antlrcpp::Any FeatParser::ElidedFallbackNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitElidedFallbackName(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::ElidedFallbackNameContext* FeatParser::elidedFallbackName() {
  ElidedFallbackNameContext *_localctx = _tracker.createInstance<ElidedFallbackNameContext>(_ctx, getState());
  enterRule(_localctx, 134, FeatParser::RuleElidedFallbackName);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(888);
    match(FeatParser::ELIDED_FALLBACK_NAME);
    setState(889);
    match(FeatParser::LCBRACE);
    setState(891); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(890);
      nameEntryStatement();
      setState(893); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == FeatParser::INCLUDE || _la == FeatParser::NAME);
    setState(895);
    match(FeatParser::RCBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameEntryStatementContext ------------------------------------------------------------------

FeatParser::NameEntryStatementContext::NameEntryStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::NameEntryStatementContext::SEMI() {
  return getToken(FeatParser::SEMI, 0);
}

FeatParser::NameEntryContext* FeatParser::NameEntryStatementContext::nameEntry() {
  return getRuleContext<FeatParser::NameEntryContext>(0);
}

FeatParser::IncludeContext* FeatParser::NameEntryStatementContext::include() {
  return getRuleContext<FeatParser::IncludeContext>(0);
}


size_t FeatParser::NameEntryStatementContext::getRuleIndex() const {
  return FeatParser::RuleNameEntryStatement;
}


antlrcpp::Any FeatParser::NameEntryStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitNameEntryStatement(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::NameEntryStatementContext* FeatParser::nameEntryStatement() {
  NameEntryStatementContext *_localctx = _tracker.createInstance<NameEntryStatementContext>(_ctx, getState());
  enterRule(_localctx, 136, FeatParser::RuleNameEntryStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(899);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::NAME: {
        setState(897);
        nameEntry();
        break;
      }

      case FeatParser::INCLUDE: {
        setState(898);
        include();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(901);
    match(FeatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElidedFallbackNameIDContext ------------------------------------------------------------------

FeatParser::ElidedFallbackNameIDContext::ElidedFallbackNameIDContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::ElidedFallbackNameIDContext::ELIDED_FALLBACK_NAME_ID() {
  return getToken(FeatParser::ELIDED_FALLBACK_NAME_ID, 0);
}

FeatParser::GenNumContext* FeatParser::ElidedFallbackNameIDContext::genNum() {
  return getRuleContext<FeatParser::GenNumContext>(0);
}


size_t FeatParser::ElidedFallbackNameIDContext::getRuleIndex() const {
  return FeatParser::RuleElidedFallbackNameID;
}


antlrcpp::Any FeatParser::ElidedFallbackNameIDContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitElidedFallbackNameID(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::ElidedFallbackNameIDContext* FeatParser::elidedFallbackNameID() {
  ElidedFallbackNameIDContext *_localctx = _tracker.createInstance<ElidedFallbackNameIDContext>(_ctx, getState());
  enterRule(_localctx, 138, FeatParser::RuleElidedFallbackNameID);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(903);
    match(FeatParser::ELIDED_FALLBACK_NAME_ID);
    setState(904);
    genNum();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameEntryContext ------------------------------------------------------------------

FeatParser::NameEntryContext::NameEntryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::NameEntryContext::NAME() {
  return getToken(FeatParser::NAME, 0);
}

tree::TerminalNode* FeatParser::NameEntryContext::QUOTE() {
  return getToken(FeatParser::QUOTE, 0);
}

tree::TerminalNode* FeatParser::NameEntryContext::STRVAL() {
  return getToken(FeatParser::STRVAL, 0);
}

tree::TerminalNode* FeatParser::NameEntryContext::EQUOTE() {
  return getToken(FeatParser::EQUOTE, 0);
}

std::vector<FeatParser::GenNumContext *> FeatParser::NameEntryContext::genNum() {
  return getRuleContexts<FeatParser::GenNumContext>();
}

FeatParser::GenNumContext* FeatParser::NameEntryContext::genNum(size_t i) {
  return getRuleContext<FeatParser::GenNumContext>(i);
}


size_t FeatParser::NameEntryContext::getRuleIndex() const {
  return FeatParser::RuleNameEntry;
}


antlrcpp::Any FeatParser::NameEntryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitNameEntry(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::NameEntryContext* FeatParser::nameEntry() {
  NameEntryContext *_localctx = _tracker.createInstance<NameEntryContext>(_ctx, getState());
  enterRule(_localctx, 140, FeatParser::RuleNameEntry);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(906);
    match(FeatParser::NAME);
    setState(913);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 130) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 130)) & ((1ULL << (FeatParser::NUMEXT - 130))
      | (1ULL << (FeatParser::NUMOCT - 130))
      | (1ULL << (FeatParser::NUM - 130)))) != 0)) {
      setState(907);
      genNum();
      setState(911);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 130) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 130)) & ((1ULL << (FeatParser::NUMEXT - 130))
        | (1ULL << (FeatParser::NUMOCT - 130))
        | (1ULL << (FeatParser::NUM - 130)))) != 0)) {
        setState(908);
        genNum();
        setState(909);
        genNum();
      }
    }
    setState(915);
    match(FeatParser::QUOTE);
    setState(916);
    match(FeatParser::STRVAL);
    setState(917);
    match(FeatParser::EQUOTE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_vmtxContext ------------------------------------------------------------------

FeatParser::Table_vmtxContext::Table_vmtxContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FeatParser::Table_vmtxContext::VMTX() {
  return getTokens(FeatParser::VMTX);
}

tree::TerminalNode* FeatParser::Table_vmtxContext::VMTX(size_t i) {
  return getToken(FeatParser::VMTX, i);
}

tree::TerminalNode* FeatParser::Table_vmtxContext::LCBRACE() {
  return getToken(FeatParser::LCBRACE, 0);
}

tree::TerminalNode* FeatParser::Table_vmtxContext::RCBRACE() {
  return getToken(FeatParser::RCBRACE, 0);
}

tree::TerminalNode* FeatParser::Table_vmtxContext::SEMI() {
  return getToken(FeatParser::SEMI, 0);
}

std::vector<FeatParser::VmtxStatementContext *> FeatParser::Table_vmtxContext::vmtxStatement() {
  return getRuleContexts<FeatParser::VmtxStatementContext>();
}

FeatParser::VmtxStatementContext* FeatParser::Table_vmtxContext::vmtxStatement(size_t i) {
  return getRuleContext<FeatParser::VmtxStatementContext>(i);
}


size_t FeatParser::Table_vmtxContext::getRuleIndex() const {
  return FeatParser::RuleTable_vmtx;
}


antlrcpp::Any FeatParser::Table_vmtxContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitTable_vmtx(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::Table_vmtxContext* FeatParser::table_vmtx() {
  Table_vmtxContext *_localctx = _tracker.createInstance<Table_vmtxContext>(_ctx, getState());
  enterRule(_localctx, 142, FeatParser::RuleTable_vmtx);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(919);
    match(FeatParser::VMTX);
    setState(920);
    match(FeatParser::LCBRACE);
    setState(922); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(921);
      vmtxStatement();
      setState(924); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == FeatParser::INCLUDE || _la == FeatParser::VERT_ORIGIN_Y

    || _la == FeatParser::VERT_ADVANCE_Y);
    setState(926);
    match(FeatParser::RCBRACE);
    setState(927);
    match(FeatParser::VMTX);
    setState(928);
    match(FeatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VmtxStatementContext ------------------------------------------------------------------

FeatParser::VmtxStatementContext::VmtxStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::VmtxStatementContext::SEMI() {
  return getToken(FeatParser::SEMI, 0);
}

FeatParser::VmtxContext* FeatParser::VmtxStatementContext::vmtx() {
  return getRuleContext<FeatParser::VmtxContext>(0);
}

FeatParser::IncludeContext* FeatParser::VmtxStatementContext::include() {
  return getRuleContext<FeatParser::IncludeContext>(0);
}


size_t FeatParser::VmtxStatementContext::getRuleIndex() const {
  return FeatParser::RuleVmtxStatement;
}


antlrcpp::Any FeatParser::VmtxStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitVmtxStatement(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::VmtxStatementContext* FeatParser::vmtxStatement() {
  VmtxStatementContext *_localctx = _tracker.createInstance<VmtxStatementContext>(_ctx, getState());
  enterRule(_localctx, 144, FeatParser::RuleVmtxStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(932);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::VERT_ORIGIN_Y:
      case FeatParser::VERT_ADVANCE_Y: {
        setState(930);
        vmtx();
        break;
      }

      case FeatParser::INCLUDE: {
        setState(931);
        include();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(934);
    match(FeatParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VmtxContext ------------------------------------------------------------------

FeatParser::VmtxContext::VmtxContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FeatParser::GlyphContext* FeatParser::VmtxContext::glyph() {
  return getRuleContext<FeatParser::GlyphContext>(0);
}

tree::TerminalNode* FeatParser::VmtxContext::NUM() {
  return getToken(FeatParser::NUM, 0);
}

tree::TerminalNode* FeatParser::VmtxContext::VERT_ORIGIN_Y() {
  return getToken(FeatParser::VERT_ORIGIN_Y, 0);
}

tree::TerminalNode* FeatParser::VmtxContext::VERT_ADVANCE_Y() {
  return getToken(FeatParser::VERT_ADVANCE_Y, 0);
}


size_t FeatParser::VmtxContext::getRuleIndex() const {
  return FeatParser::RuleVmtx;
}


antlrcpp::Any FeatParser::VmtxContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitVmtx(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::VmtxContext* FeatParser::vmtx() {
  VmtxContext *_localctx = _tracker.createInstance<VmtxContext>(_ctx, getState());
  enterRule(_localctx, 146, FeatParser::RuleVmtx);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(936);
    _la = _input->LA(1);
    if (!(_la == FeatParser::VERT_ORIGIN_Y

    || _la == FeatParser::VERT_ADVANCE_Y)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(937);
    glyph();
    setState(938);
    match(FeatParser::NUM);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnchorContext ------------------------------------------------------------------

FeatParser::AnchorContext::AnchorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::AnchorContext::BEGINVALUE() {
  return getToken(FeatParser::BEGINVALUE, 0);
}

tree::TerminalNode* FeatParser::AnchorContext::ANCHOR() {
  return getToken(FeatParser::ANCHOR, 0);
}

tree::TerminalNode* FeatParser::AnchorContext::ENDVALUE() {
  return getToken(FeatParser::ENDVALUE, 0);
}

tree::TerminalNode* FeatParser::AnchorContext::KNULL() {
  return getToken(FeatParser::KNULL, 0);
}

FeatParser::LabelContext* FeatParser::AnchorContext::label() {
  return getRuleContext<FeatParser::LabelContext>(0);
}

std::vector<tree::TerminalNode *> FeatParser::AnchorContext::NUM() {
  return getTokens(FeatParser::NUM);
}

tree::TerminalNode* FeatParser::AnchorContext::NUM(size_t i) {
  return getToken(FeatParser::NUM, i);
}

tree::TerminalNode* FeatParser::AnchorContext::CONTOURPOINT() {
  return getToken(FeatParser::CONTOURPOINT, 0);
}


size_t FeatParser::AnchorContext::getRuleIndex() const {
  return FeatParser::RuleAnchor;
}


antlrcpp::Any FeatParser::AnchorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitAnchor(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::AnchorContext* FeatParser::anchor() {
  AnchorContext *_localctx = _tracker.createInstance<AnchorContext>(_ctx, getState());
  enterRule(_localctx, 148, FeatParser::RuleAnchor);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(940);
    match(FeatParser::BEGINVALUE);
    setState(941);
    match(FeatParser::ANCHOR);
    setState(950);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::NUM: {
        setState(942);
        dynamic_cast<AnchorContext *>(_localctx)->xval = match(FeatParser::NUM);
        setState(943);
        dynamic_cast<AnchorContext *>(_localctx)->yval = match(FeatParser::NUM);
        setState(946);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == FeatParser::CONTOURPOINT) {
          setState(944);
          match(FeatParser::CONTOURPOINT);
          setState(945);
          dynamic_cast<AnchorContext *>(_localctx)->cp = match(FeatParser::NUM);
        }
        break;
      }

      case FeatParser::KNULL: {
        setState(948);
        match(FeatParser::KNULL);
        break;
      }

      case FeatParser::NAMELABEL: {
        setState(949);
        dynamic_cast<AnchorContext *>(_localctx)->name = label();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(952);
    match(FeatParser::ENDVALUE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LookupPatternContext ------------------------------------------------------------------

FeatParser::LookupPatternContext::LookupPatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FeatParser::LookupPatternElementContext *> FeatParser::LookupPatternContext::lookupPatternElement() {
  return getRuleContexts<FeatParser::LookupPatternElementContext>();
}

FeatParser::LookupPatternElementContext* FeatParser::LookupPatternContext::lookupPatternElement(size_t i) {
  return getRuleContext<FeatParser::LookupPatternElementContext>(i);
}


size_t FeatParser::LookupPatternContext::getRuleIndex() const {
  return FeatParser::RuleLookupPattern;
}


antlrcpp::Any FeatParser::LookupPatternContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitLookupPattern(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::LookupPatternContext* FeatParser::lookupPattern() {
  LookupPatternContext *_localctx = _tracker.createInstance<LookupPatternContext>(_ctx, getState());
  enterRule(_localctx, 150, FeatParser::RuleLookupPattern);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(955); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(954);
      lookupPatternElement();
      setState(957); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (((((_la - 116) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 116)) & ((1ULL << (FeatParser::LBRACKET - 116))
      | (1ULL << (FeatParser::GCLASS - 116))
      | (1ULL << (FeatParser::CID - 116))
      | (1ULL << (FeatParser::ESCGNAME - 116))
      | (1ULL << (FeatParser::NAMELABEL - 116))
      | (1ULL << (FeatParser::EXTNAME - 116)))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LookupPatternElementContext ------------------------------------------------------------------

FeatParser::LookupPatternElementContext::LookupPatternElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FeatParser::PatternElementContext* FeatParser::LookupPatternElementContext::patternElement() {
  return getRuleContext<FeatParser::PatternElementContext>(0);
}

std::vector<tree::TerminalNode *> FeatParser::LookupPatternElementContext::LOOKUP() {
  return getTokens(FeatParser::LOOKUP);
}

tree::TerminalNode* FeatParser::LookupPatternElementContext::LOOKUP(size_t i) {
  return getToken(FeatParser::LOOKUP, i);
}

std::vector<FeatParser::LabelContext *> FeatParser::LookupPatternElementContext::label() {
  return getRuleContexts<FeatParser::LabelContext>();
}

FeatParser::LabelContext* FeatParser::LookupPatternElementContext::label(size_t i) {
  return getRuleContext<FeatParser::LabelContext>(i);
}


size_t FeatParser::LookupPatternElementContext::getRuleIndex() const {
  return FeatParser::RuleLookupPatternElement;
}


antlrcpp::Any FeatParser::LookupPatternElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitLookupPatternElement(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::LookupPatternElementContext* FeatParser::lookupPatternElement() {
  LookupPatternElementContext *_localctx = _tracker.createInstance<LookupPatternElementContext>(_ctx, getState());
  enterRule(_localctx, 152, FeatParser::RuleLookupPatternElement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(959);
    patternElement();
    setState(964);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FeatParser::LOOKUP) {
      setState(960);
      match(FeatParser::LOOKUP);
      setState(961);
      label();
      setState(966);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PatternContext ------------------------------------------------------------------

FeatParser::PatternContext::PatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FeatParser::PatternElementContext *> FeatParser::PatternContext::patternElement() {
  return getRuleContexts<FeatParser::PatternElementContext>();
}

FeatParser::PatternElementContext* FeatParser::PatternContext::patternElement(size_t i) {
  return getRuleContext<FeatParser::PatternElementContext>(i);
}


size_t FeatParser::PatternContext::getRuleIndex() const {
  return FeatParser::RulePattern;
}


antlrcpp::Any FeatParser::PatternContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitPattern(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::PatternContext* FeatParser::pattern() {
  PatternContext *_localctx = _tracker.createInstance<PatternContext>(_ctx, getState());
  enterRule(_localctx, 154, FeatParser::RulePattern);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(968); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(967);
      patternElement();
      setState(970); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (((((_la - 116) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 116)) & ((1ULL << (FeatParser::LBRACKET - 116))
      | (1ULL << (FeatParser::GCLASS - 116))
      | (1ULL << (FeatParser::CID - 116))
      | (1ULL << (FeatParser::ESCGNAME - 116))
      | (1ULL << (FeatParser::NAMELABEL - 116))
      | (1ULL << (FeatParser::EXTNAME - 116)))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PatternElementContext ------------------------------------------------------------------

FeatParser::PatternElementContext::PatternElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FeatParser::GlyphClassContext* FeatParser::PatternElementContext::glyphClass() {
  return getRuleContext<FeatParser::GlyphClassContext>(0);
}

FeatParser::GlyphContext* FeatParser::PatternElementContext::glyph() {
  return getRuleContext<FeatParser::GlyphContext>(0);
}

tree::TerminalNode* FeatParser::PatternElementContext::MARKER() {
  return getToken(FeatParser::MARKER, 0);
}


size_t FeatParser::PatternElementContext::getRuleIndex() const {
  return FeatParser::RulePatternElement;
}


antlrcpp::Any FeatParser::PatternElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitPatternElement(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::PatternElementContext* FeatParser::patternElement() {
  PatternElementContext *_localctx = _tracker.createInstance<PatternElementContext>(_ctx, getState());
  enterRule(_localctx, 156, FeatParser::RulePatternElement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(974);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::LBRACKET:
      case FeatParser::GCLASS: {
        setState(972);
        glyphClass();
        break;
      }

      case FeatParser::CID:
      case FeatParser::ESCGNAME:
      case FeatParser::NAMELABEL:
      case FeatParser::EXTNAME: {
        setState(973);
        glyph();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(977);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FeatParser::MARKER) {
      setState(976);
      match(FeatParser::MARKER);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GlyphClassOptionalContext ------------------------------------------------------------------

FeatParser::GlyphClassOptionalContext::GlyphClassOptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FeatParser::GlyphClassContext* FeatParser::GlyphClassOptionalContext::glyphClass() {
  return getRuleContext<FeatParser::GlyphClassContext>(0);
}


size_t FeatParser::GlyphClassOptionalContext::getRuleIndex() const {
  return FeatParser::RuleGlyphClassOptional;
}


antlrcpp::Any FeatParser::GlyphClassOptionalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitGlyphClassOptional(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::GlyphClassOptionalContext* FeatParser::glyphClassOptional() {
  GlyphClassOptionalContext *_localctx = _tracker.createInstance<GlyphClassOptionalContext>(_ctx, getState());
  enterRule(_localctx, 158, FeatParser::RuleGlyphClassOptional);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(980);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FeatParser::LBRACKET

    || _la == FeatParser::GCLASS) {
      setState(979);
      glyphClass();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GlyphClassContext ------------------------------------------------------------------

FeatParser::GlyphClassContext::GlyphClassContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::GlyphClassContext::GCLASS() {
  return getToken(FeatParser::GCLASS, 0);
}

FeatParser::GcLiteralContext* FeatParser::GlyphClassContext::gcLiteral() {
  return getRuleContext<FeatParser::GcLiteralContext>(0);
}


size_t FeatParser::GlyphClassContext::getRuleIndex() const {
  return FeatParser::RuleGlyphClass;
}


antlrcpp::Any FeatParser::GlyphClassContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitGlyphClass(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::GlyphClassContext* FeatParser::glyphClass() {
  GlyphClassContext *_localctx = _tracker.createInstance<GlyphClassContext>(_ctx, getState());
  enterRule(_localctx, 160, FeatParser::RuleGlyphClass);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(984);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::GCLASS: {
        enterOuterAlt(_localctx, 1);
        setState(982);
        match(FeatParser::GCLASS);
        break;
      }

      case FeatParser::LBRACKET: {
        enterOuterAlt(_localctx, 2);
        setState(983);
        gcLiteral();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GcLiteralContext ------------------------------------------------------------------

FeatParser::GcLiteralContext::GcLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::GcLiteralContext::LBRACKET() {
  return getToken(FeatParser::LBRACKET, 0);
}

tree::TerminalNode* FeatParser::GcLiteralContext::RBRACKET() {
  return getToken(FeatParser::RBRACKET, 0);
}

std::vector<FeatParser::GcLiteralElementContext *> FeatParser::GcLiteralContext::gcLiteralElement() {
  return getRuleContexts<FeatParser::GcLiteralElementContext>();
}

FeatParser::GcLiteralElementContext* FeatParser::GcLiteralContext::gcLiteralElement(size_t i) {
  return getRuleContext<FeatParser::GcLiteralElementContext>(i);
}


size_t FeatParser::GcLiteralContext::getRuleIndex() const {
  return FeatParser::RuleGcLiteral;
}


antlrcpp::Any FeatParser::GcLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitGcLiteral(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::GcLiteralContext* FeatParser::gcLiteral() {
  GcLiteralContext *_localctx = _tracker.createInstance<GcLiteralContext>(_ctx, getState());
  enterRule(_localctx, 162, FeatParser::RuleGcLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(986);
    match(FeatParser::LBRACKET);
    setState(988); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(987);
      gcLiteralElement();
      setState(990); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (((((_la - 124) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 124)) & ((1ULL << (FeatParser::GCLASS - 124))
      | (1ULL << (FeatParser::CID - 124))
      | (1ULL << (FeatParser::ESCGNAME - 124))
      | (1ULL << (FeatParser::NAMELABEL - 124))
      | (1ULL << (FeatParser::EXTNAME - 124)))) != 0));
    setState(992);
    match(FeatParser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GcLiteralElementContext ------------------------------------------------------------------

FeatParser::GcLiteralElementContext::GcLiteralElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FeatParser::GlyphContext *> FeatParser::GcLiteralElementContext::glyph() {
  return getRuleContexts<FeatParser::GlyphContext>();
}

FeatParser::GlyphContext* FeatParser::GcLiteralElementContext::glyph(size_t i) {
  return getRuleContext<FeatParser::GlyphContext>(i);
}

tree::TerminalNode* FeatParser::GcLiteralElementContext::HYPHEN() {
  return getToken(FeatParser::HYPHEN, 0);
}

tree::TerminalNode* FeatParser::GcLiteralElementContext::GCLASS() {
  return getToken(FeatParser::GCLASS, 0);
}


size_t FeatParser::GcLiteralElementContext::getRuleIndex() const {
  return FeatParser::RuleGcLiteralElement;
}


antlrcpp::Any FeatParser::GcLiteralElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitGcLiteralElement(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::GcLiteralElementContext* FeatParser::gcLiteralElement() {
  GcLiteralElementContext *_localctx = _tracker.createInstance<GcLiteralElementContext>(_ctx, getState());
  enterRule(_localctx, 164, FeatParser::RuleGcLiteralElement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1000);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::CID:
      case FeatParser::ESCGNAME:
      case FeatParser::NAMELABEL:
      case FeatParser::EXTNAME: {
        enterOuterAlt(_localctx, 1);
        setState(994);
        dynamic_cast<GcLiteralElementContext *>(_localctx)->startg = glyph();
        setState(997);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == FeatParser::HYPHEN) {
          setState(995);
          match(FeatParser::HYPHEN);
          setState(996);
          dynamic_cast<GcLiteralElementContext *>(_localctx)->endg = glyph();
        }
        break;
      }

      case FeatParser::GCLASS: {
        enterOuterAlt(_localctx, 2);
        setState(999);
        match(FeatParser::GCLASS);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GlyphContext ------------------------------------------------------------------

FeatParser::GlyphContext::GlyphContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FeatParser::GlyphNameContext* FeatParser::GlyphContext::glyphName() {
  return getRuleContext<FeatParser::GlyphNameContext>(0);
}

tree::TerminalNode* FeatParser::GlyphContext::CID() {
  return getToken(FeatParser::CID, 0);
}


size_t FeatParser::GlyphContext::getRuleIndex() const {
  return FeatParser::RuleGlyph;
}


antlrcpp::Any FeatParser::GlyphContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitGlyph(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::GlyphContext* FeatParser::glyph() {
  GlyphContext *_localctx = _tracker.createInstance<GlyphContext>(_ctx, getState());
  enterRule(_localctx, 166, FeatParser::RuleGlyph);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1004);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::ESCGNAME:
      case FeatParser::NAMELABEL:
      case FeatParser::EXTNAME: {
        enterOuterAlt(_localctx, 1);
        setState(1002);
        glyphName();
        break;
      }

      case FeatParser::CID: {
        enterOuterAlt(_localctx, 2);
        setState(1003);
        match(FeatParser::CID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GlyphNameContext ------------------------------------------------------------------

FeatParser::GlyphNameContext::GlyphNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::GlyphNameContext::ESCGNAME() {
  return getToken(FeatParser::ESCGNAME, 0);
}

tree::TerminalNode* FeatParser::GlyphNameContext::NAMELABEL() {
  return getToken(FeatParser::NAMELABEL, 0);
}

tree::TerminalNode* FeatParser::GlyphNameContext::EXTNAME() {
  return getToken(FeatParser::EXTNAME, 0);
}


size_t FeatParser::GlyphNameContext::getRuleIndex() const {
  return FeatParser::RuleGlyphName;
}


antlrcpp::Any FeatParser::GlyphNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitGlyphName(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::GlyphNameContext* FeatParser::glyphName() {
  GlyphNameContext *_localctx = _tracker.createInstance<GlyphNameContext>(_ctx, getState());
  enterRule(_localctx, 168, FeatParser::RuleGlyphName);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1006);
    _la = _input->LA(1);
    if (!(((((_la - 126) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 126)) & ((1ULL << (FeatParser::ESCGNAME - 126))
      | (1ULL << (FeatParser::NAMELABEL - 126))
      | (1ULL << (FeatParser::EXTNAME - 126)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LabelContext ------------------------------------------------------------------

FeatParser::LabelContext::LabelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::LabelContext::NAMELABEL() {
  return getToken(FeatParser::NAMELABEL, 0);
}


size_t FeatParser::LabelContext::getRuleIndex() const {
  return FeatParser::RuleLabel;
}


antlrcpp::Any FeatParser::LabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitLabel(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::LabelContext* FeatParser::label() {
  LabelContext *_localctx = _tracker.createInstance<LabelContext>(_ctx, getState());
  enterRule(_localctx, 170, FeatParser::RuleLabel);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1008);
    match(FeatParser::NAMELABEL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TagContext ------------------------------------------------------------------

FeatParser::TagContext::TagContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::TagContext::NAMELABEL() {
  return getToken(FeatParser::NAMELABEL, 0);
}

tree::TerminalNode* FeatParser::TagContext::EXTNAME() {
  return getToken(FeatParser::EXTNAME, 0);
}

tree::TerminalNode* FeatParser::TagContext::CATCHTAG() {
  return getToken(FeatParser::CATCHTAG, 0);
}

tree::TerminalNode* FeatParser::TagContext::MARK() {
  return getToken(FeatParser::MARK, 0);
}


size_t FeatParser::TagContext::getRuleIndex() const {
  return FeatParser::RuleTag;
}


antlrcpp::Any FeatParser::TagContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitTag(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::TagContext* FeatParser::tag() {
  TagContext *_localctx = _tracker.createInstance<TagContext>(_ctx, getState());
  enterRule(_localctx, 172, FeatParser::RuleTag);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1010);
    _la = _input->LA(1);
    if (!(_la == FeatParser::MARK || ((((_la - 127) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 127)) & ((1ULL << (FeatParser::NAMELABEL - 127))
      | (1ULL << (FeatParser::EXTNAME - 127))
      | (1ULL << (FeatParser::CATCHTAG - 127)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FixedNumContext ------------------------------------------------------------------

FeatParser::FixedNumContext::FixedNumContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::FixedNumContext::POINTNUM() {
  return getToken(FeatParser::POINTNUM, 0);
}

tree::TerminalNode* FeatParser::FixedNumContext::NUM() {
  return getToken(FeatParser::NUM, 0);
}


size_t FeatParser::FixedNumContext::getRuleIndex() const {
  return FeatParser::RuleFixedNum;
}


antlrcpp::Any FeatParser::FixedNumContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitFixedNum(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::FixedNumContext* FeatParser::fixedNum() {
  FixedNumContext *_localctx = _tracker.createInstance<FixedNumContext>(_ctx, getState());
  enterRule(_localctx, 174, FeatParser::RuleFixedNum);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1012);
    _la = _input->LA(1);
    if (!(_la == FeatParser::POINTNUM

    || _la == FeatParser::NUM)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GenNumContext ------------------------------------------------------------------

FeatParser::GenNumContext::GenNumContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::GenNumContext::NUM() {
  return getToken(FeatParser::NUM, 0);
}

tree::TerminalNode* FeatParser::GenNumContext::NUMOCT() {
  return getToken(FeatParser::NUMOCT, 0);
}

tree::TerminalNode* FeatParser::GenNumContext::NUMEXT() {
  return getToken(FeatParser::NUMEXT, 0);
}


size_t FeatParser::GenNumContext::getRuleIndex() const {
  return FeatParser::RuleGenNum;
}


antlrcpp::Any FeatParser::GenNumContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitGenNum(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::GenNumContext* FeatParser::genNum() {
  GenNumContext *_localctx = _tracker.createInstance<GenNumContext>(_ctx, getState());
  enterRule(_localctx, 176, FeatParser::RuleGenNum);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1014);
    _la = _input->LA(1);
    if (!(((((_la - 130) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 130)) & ((1ULL << (FeatParser::NUMEXT - 130))
      | (1ULL << (FeatParser::NUMOCT - 130))
      | (1ULL << (FeatParser::NUM - 130)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FeatureFileContext ------------------------------------------------------------------

FeatParser::FeatureFileContext::FeatureFileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::FeatureFileContext::EOF() {
  return getToken(FeatParser::EOF, 0);
}

std::vector<FeatParser::FeatureStatementContext *> FeatParser::FeatureFileContext::featureStatement() {
  return getRuleContexts<FeatParser::FeatureStatementContext>();
}

FeatParser::FeatureStatementContext* FeatParser::FeatureFileContext::featureStatement(size_t i) {
  return getRuleContext<FeatParser::FeatureStatementContext>(i);
}


size_t FeatParser::FeatureFileContext::getRuleIndex() const {
  return FeatParser::RuleFeatureFile;
}


antlrcpp::Any FeatParser::FeatureFileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitFeatureFile(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::FeatureFileContext* FeatParser::featureFile() {
  FeatureFileContext *_localctx = _tracker.createInstance<FeatureFileContext>(_ctx, getState());
  enterRule(_localctx, 178, FeatParser::RuleFeatureFile);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1019);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FeatParser::INCLUDE)
      | (1ULL << FeatParser::FEATURE)
      | (1ULL << FeatParser::SCRIPT)
      | (1ULL << FeatParser::LANGUAGE)
      | (1ULL << FeatParser::SUBTABLE)
      | (1ULL << FeatParser::LOOKUP)
      | (1ULL << FeatParser::LOOKUPFLAG)
      | (1ULL << FeatParser::ENUMERATE)
      | (1ULL << FeatParser::ENUMERATE_v)
      | (1ULL << FeatParser::EXCEPT)
      | (1ULL << FeatParser::IGNORE)
      | (1ULL << FeatParser::SUBSTITUTE)
      | (1ULL << FeatParser::SUBSTITUTE_v)
      | (1ULL << FeatParser::REVERSE)
      | (1ULL << FeatParser::REVERSE_v)
      | (1ULL << FeatParser::POSITION)
      | (1ULL << FeatParser::POSITION_v)
      | (1ULL << FeatParser::PARAMETERS)
      | (1ULL << FeatParser::FEATURE_NAMES)
      | (1ULL << FeatParser::CV_PARAMETERS)
      | (1ULL << FeatParser::SIZEMENUNAME)
      | (1ULL << FeatParser::MARK_CLASS))) != 0) || _la == FeatParser::GCLASS) {
      setState(1016);
      featureStatement();
      setState(1021);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1022);
    match(FeatParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementFileContext ------------------------------------------------------------------

FeatParser::StatementFileContext::StatementFileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::StatementFileContext::EOF() {
  return getToken(FeatParser::EOF, 0);
}

std::vector<FeatParser::StatementContext *> FeatParser::StatementFileContext::statement() {
  return getRuleContexts<FeatParser::StatementContext>();
}

FeatParser::StatementContext* FeatParser::StatementFileContext::statement(size_t i) {
  return getRuleContext<FeatParser::StatementContext>(i);
}


size_t FeatParser::StatementFileContext::getRuleIndex() const {
  return FeatParser::RuleStatementFile;
}


antlrcpp::Any FeatParser::StatementFileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitStatementFile(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::StatementFileContext* FeatParser::statementFile() {
  StatementFileContext *_localctx = _tracker.createInstance<StatementFileContext>(_ctx, getState());
  enterRule(_localctx, 180, FeatParser::RuleStatementFile);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1027);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FeatParser::INCLUDE)
      | (1ULL << FeatParser::FEATURE)
      | (1ULL << FeatParser::SCRIPT)
      | (1ULL << FeatParser::LANGUAGE)
      | (1ULL << FeatParser::SUBTABLE)
      | (1ULL << FeatParser::LOOKUPFLAG)
      | (1ULL << FeatParser::ENUMERATE)
      | (1ULL << FeatParser::ENUMERATE_v)
      | (1ULL << FeatParser::EXCEPT)
      | (1ULL << FeatParser::IGNORE)
      | (1ULL << FeatParser::SUBSTITUTE)
      | (1ULL << FeatParser::SUBSTITUTE_v)
      | (1ULL << FeatParser::REVERSE)
      | (1ULL << FeatParser::REVERSE_v)
      | (1ULL << FeatParser::POSITION)
      | (1ULL << FeatParser::POSITION_v)
      | (1ULL << FeatParser::PARAMETERS)
      | (1ULL << FeatParser::FEATURE_NAMES)
      | (1ULL << FeatParser::SIZEMENUNAME)
      | (1ULL << FeatParser::MARK_CLASS))) != 0) || _la == FeatParser::GCLASS) {
      setState(1024);
      statement();
      setState(1029);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1030);
    match(FeatParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CvStatementFileContext ------------------------------------------------------------------

FeatParser::CvStatementFileContext::CvStatementFileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::CvStatementFileContext::EOF() {
  return getToken(FeatParser::EOF, 0);
}

std::vector<FeatParser::CvParameterStatementContext *> FeatParser::CvStatementFileContext::cvParameterStatement() {
  return getRuleContexts<FeatParser::CvParameterStatementContext>();
}

FeatParser::CvParameterStatementContext* FeatParser::CvStatementFileContext::cvParameterStatement(size_t i) {
  return getRuleContext<FeatParser::CvParameterStatementContext>(i);
}


size_t FeatParser::CvStatementFileContext::getRuleIndex() const {
  return FeatParser::RuleCvStatementFile;
}


antlrcpp::Any FeatParser::CvStatementFileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitCvStatementFile(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::CvStatementFileContext* FeatParser::cvStatementFile() {
  CvStatementFileContext *_localctx = _tracker.createInstance<CvStatementFileContext>(_ctx, getState());
  enterRule(_localctx, 182, FeatParser::RuleCvStatementFile);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1035);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FeatParser::INCLUDE)
      | (1ULL << FeatParser::CV_UI_LABEL)
      | (1ULL << FeatParser::CV_TOOLTIP)
      | (1ULL << FeatParser::CV_SAMPLE_TEXT)
      | (1ULL << FeatParser::CV_PARAM_LABEL)
      | (1ULL << FeatParser::CV_CHARACTER))) != 0)) {
      setState(1032);
      cvParameterStatement();
      setState(1037);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1038);
    match(FeatParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BaseFileContext ------------------------------------------------------------------

FeatParser::BaseFileContext::BaseFileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::BaseFileContext::EOF() {
  return getToken(FeatParser::EOF, 0);
}

std::vector<FeatParser::BaseStatementContext *> FeatParser::BaseFileContext::baseStatement() {
  return getRuleContexts<FeatParser::BaseStatementContext>();
}

FeatParser::BaseStatementContext* FeatParser::BaseFileContext::baseStatement(size_t i) {
  return getRuleContext<FeatParser::BaseStatementContext>(i);
}


size_t FeatParser::BaseFileContext::getRuleIndex() const {
  return FeatParser::RuleBaseFile;
}


antlrcpp::Any FeatParser::BaseFileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitBaseFile(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::BaseFileContext* FeatParser::baseFile() {
  BaseFileContext *_localctx = _tracker.createInstance<BaseFileContext>(_ctx, getState());
  enterRule(_localctx, 184, FeatParser::RuleBaseFile);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1043);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 5) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 5)) & ((1ULL << (FeatParser::INCLUDE - 5))
      | (1ULL << (FeatParser::HA_BTL - 5))
      | (1ULL << (FeatParser::VA_BTL - 5))
      | (1ULL << (FeatParser::HA_BSL - 5))
      | (1ULL << (FeatParser::VA_BSL - 5)))) != 0)) {
      setState(1040);
      baseStatement();
      setState(1045);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1046);
    match(FeatParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- HheaFileContext ------------------------------------------------------------------

FeatParser::HheaFileContext::HheaFileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::HheaFileContext::EOF() {
  return getToken(FeatParser::EOF, 0);
}

std::vector<FeatParser::HheaStatementContext *> FeatParser::HheaFileContext::hheaStatement() {
  return getRuleContexts<FeatParser::HheaStatementContext>();
}

FeatParser::HheaStatementContext* FeatParser::HheaFileContext::hheaStatement(size_t i) {
  return getRuleContext<FeatParser::HheaStatementContext>(i);
}


size_t FeatParser::HheaFileContext::getRuleIndex() const {
  return FeatParser::RuleHheaFile;
}


antlrcpp::Any FeatParser::HheaFileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitHheaFile(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::HheaFileContext* FeatParser::hheaFile() {
  HheaFileContext *_localctx = _tracker.createInstance<HheaFileContext>(_ctx, getState());
  enterRule(_localctx, 186, FeatParser::RuleHheaFile);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1051);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FeatParser::INCLUDE || ((((_la - 73) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 73)) & ((1ULL << (FeatParser::ASCENDER - 73))
      | (1ULL << (FeatParser::DESCENDER - 73))
      | (1ULL << (FeatParser::LINE_GAP - 73))
      | (1ULL << (FeatParser::CARET_OFFSET - 73)))) != 0)) {
      setState(1048);
      hheaStatement();
      setState(1053);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1054);
    match(FeatParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VheaFileContext ------------------------------------------------------------------

FeatParser::VheaFileContext::VheaFileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::VheaFileContext::EOF() {
  return getToken(FeatParser::EOF, 0);
}

std::vector<FeatParser::VheaStatementContext *> FeatParser::VheaFileContext::vheaStatement() {
  return getRuleContexts<FeatParser::VheaStatementContext>();
}

FeatParser::VheaStatementContext* FeatParser::VheaFileContext::vheaStatement(size_t i) {
  return getRuleContext<FeatParser::VheaStatementContext>(i);
}


size_t FeatParser::VheaFileContext::getRuleIndex() const {
  return FeatParser::RuleVheaFile;
}


antlrcpp::Any FeatParser::VheaFileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitVheaFile(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::VheaFileContext* FeatParser::vheaFile() {
  VheaFileContext *_localctx = _tracker.createInstance<VheaFileContext>(_ctx, getState());
  enterRule(_localctx, 188, FeatParser::RuleVheaFile);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1059);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FeatParser::INCLUDE || ((((_la - 108) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 108)) & ((1ULL << (FeatParser::VERT_TYPO_ASCENDER - 108))
      | (1ULL << (FeatParser::VERT_TYPO_DESCENDER - 108))
      | (1ULL << (FeatParser::VERT_TYPO_LINE_GAP - 108)))) != 0)) {
      setState(1056);
      vheaStatement();
      setState(1061);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1062);
    match(FeatParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GdefFileContext ------------------------------------------------------------------

FeatParser::GdefFileContext::GdefFileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::GdefFileContext::EOF() {
  return getToken(FeatParser::EOF, 0);
}

std::vector<FeatParser::GdefStatementContext *> FeatParser::GdefFileContext::gdefStatement() {
  return getRuleContexts<FeatParser::GdefStatementContext>();
}

FeatParser::GdefStatementContext* FeatParser::GdefFileContext::gdefStatement(size_t i) {
  return getRuleContext<FeatParser::GdefStatementContext>(i);
}


size_t FeatParser::GdefFileContext::getRuleIndex() const {
  return FeatParser::RuleGdefFile;
}


antlrcpp::Any FeatParser::GdefFileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitGdefFile(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::GdefFileContext* FeatParser::gdefFile() {
  GdefFileContext *_localctx = _tracker.createInstance<GdefFileContext>(_ctx, getState());
  enterRule(_localctx, 190, FeatParser::RuleGdefFile);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1067);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FeatParser::INCLUDE || ((((_la - 66) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 66)) & ((1ULL << (FeatParser::GLYPH_CLASS_DEF - 66))
      | (1ULL << (FeatParser::ATTACH - 66))
      | (1ULL << (FeatParser::LIG_CARET_BY_POS - 66))
      | (1ULL << (FeatParser::LIG_CARET_BY_IDX - 66)))) != 0)) {
      setState(1064);
      gdefStatement();
      setState(1069);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1070);
    match(FeatParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameFileContext ------------------------------------------------------------------

FeatParser::NameFileContext::NameFileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::NameFileContext::EOF() {
  return getToken(FeatParser::EOF, 0);
}

std::vector<FeatParser::NameStatementContext *> FeatParser::NameFileContext::nameStatement() {
  return getRuleContexts<FeatParser::NameStatementContext>();
}

FeatParser::NameStatementContext* FeatParser::NameFileContext::nameStatement(size_t i) {
  return getRuleContext<FeatParser::NameStatementContext>(i);
}


size_t FeatParser::NameFileContext::getRuleIndex() const {
  return FeatParser::RuleNameFile;
}


antlrcpp::Any FeatParser::NameFileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitNameFile(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::NameFileContext* FeatParser::nameFile() {
  NameFileContext *_localctx = _tracker.createInstance<NameFileContext>(_ctx, getState());
  enterRule(_localctx, 192, FeatParser::RuleNameFile);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1075);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FeatParser::INCLUDE || _la == FeatParser::NAMEID) {
      setState(1072);
      nameStatement();
      setState(1077);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1078);
    match(FeatParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VmtxFileContext ------------------------------------------------------------------

FeatParser::VmtxFileContext::VmtxFileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::VmtxFileContext::EOF() {
  return getToken(FeatParser::EOF, 0);
}

std::vector<FeatParser::VmtxStatementContext *> FeatParser::VmtxFileContext::vmtxStatement() {
  return getRuleContexts<FeatParser::VmtxStatementContext>();
}

FeatParser::VmtxStatementContext* FeatParser::VmtxFileContext::vmtxStatement(size_t i) {
  return getRuleContext<FeatParser::VmtxStatementContext>(i);
}


size_t FeatParser::VmtxFileContext::getRuleIndex() const {
  return FeatParser::RuleVmtxFile;
}


antlrcpp::Any FeatParser::VmtxFileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitVmtxFile(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::VmtxFileContext* FeatParser::vmtxFile() {
  VmtxFileContext *_localctx = _tracker.createInstance<VmtxFileContext>(_ctx, getState());
  enterRule(_localctx, 194, FeatParser::RuleVmtxFile);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1083);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FeatParser::INCLUDE || _la == FeatParser::VERT_ORIGIN_Y

    || _la == FeatParser::VERT_ADVANCE_Y) {
      setState(1080);
      vmtxStatement();
      setState(1085);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1086);
    match(FeatParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Os_2FileContext ------------------------------------------------------------------

FeatParser::Os_2FileContext::Os_2FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::Os_2FileContext::EOF() {
  return getToken(FeatParser::EOF, 0);
}

std::vector<FeatParser::Os_2StatementContext *> FeatParser::Os_2FileContext::os_2Statement() {
  return getRuleContexts<FeatParser::Os_2StatementContext>();
}

FeatParser::Os_2StatementContext* FeatParser::Os_2FileContext::os_2Statement(size_t i) {
  return getRuleContext<FeatParser::Os_2StatementContext>(i);
}


size_t FeatParser::Os_2FileContext::getRuleIndex() const {
  return FeatParser::RuleOs_2File;
}


antlrcpp::Any FeatParser::Os_2FileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitOs_2File(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::Os_2FileContext* FeatParser::os_2File() {
  Os_2FileContext *_localctx = _tracker.createInstance<Os_2FileContext>(_ctx, getState());
  enterRule(_localctx, 196, FeatParser::RuleOs_2File);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1091);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FeatParser::INCLUDE || ((((_la - 80) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 80)) & ((1ULL << (FeatParser::FS_TYPE - 80))
      | (1ULL << (FeatParser::FS_TYPE_v - 80))
      | (1ULL << (FeatParser::OS2_LOWER_OP_SIZE - 80))
      | (1ULL << (FeatParser::OS2_UPPER_OP_SIZE - 80))
      | (1ULL << (FeatParser::PANOSE - 80))
      | (1ULL << (FeatParser::TYPO_ASCENDER - 80))
      | (1ULL << (FeatParser::TYPO_DESCENDER - 80))
      | (1ULL << (FeatParser::TYPO_LINE_GAP - 80))
      | (1ULL << (FeatParser::WIN_ASCENT - 80))
      | (1ULL << (FeatParser::WIN_DESCENT - 80))
      | (1ULL << (FeatParser::X_HEIGHT - 80))
      | (1ULL << (FeatParser::CAP_HEIGHT - 80))
      | (1ULL << (FeatParser::WEIGHT_CLASS - 80))
      | (1ULL << (FeatParser::WIDTH_CLASS - 80))
      | (1ULL << (FeatParser::VENDOR - 80))
      | (1ULL << (FeatParser::UNICODE_RANGE - 80))
      | (1ULL << (FeatParser::CODE_PAGE_RANGE - 80))
      | (1ULL << (FeatParser::FAMILY_CLASS - 80)))) != 0)) {
      setState(1088);
      os_2Statement();
      setState(1093);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1094);
    match(FeatParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatFileContext ------------------------------------------------------------------

FeatParser::StatFileContext::StatFileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::StatFileContext::EOF() {
  return getToken(FeatParser::EOF, 0);
}

std::vector<FeatParser::StatStatementContext *> FeatParser::StatFileContext::statStatement() {
  return getRuleContexts<FeatParser::StatStatementContext>();
}

FeatParser::StatStatementContext* FeatParser::StatFileContext::statStatement(size_t i) {
  return getRuleContext<FeatParser::StatStatementContext>(i);
}


size_t FeatParser::StatFileContext::getRuleIndex() const {
  return FeatParser::RuleStatFile;
}


antlrcpp::Any FeatParser::StatFileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitStatFile(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::StatFileContext* FeatParser::statFile() {
  StatFileContext *_localctx = _tracker.createInstance<StatFileContext>(_ctx, getState());
  enterRule(_localctx, 198, FeatParser::RuleStatFile);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1099);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FeatParser::INCLUDE || ((((_la - 99) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 99)) & ((1ULL << (FeatParser::ELIDED_FALLBACK_NAME - 99))
      | (1ULL << (FeatParser::ELIDED_FALLBACK_NAME_ID - 99))
      | (1ULL << (FeatParser::DESIGN_AXIS - 99))
      | (1ULL << (FeatParser::AXIS_VALUE - 99)))) != 0)) {
      setState(1096);
      statStatement();
      setState(1101);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1102);
    match(FeatParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AxisValueFileContext ------------------------------------------------------------------

FeatParser::AxisValueFileContext::AxisValueFileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::AxisValueFileContext::EOF() {
  return getToken(FeatParser::EOF, 0);
}

std::vector<FeatParser::AxisValueStatementContext *> FeatParser::AxisValueFileContext::axisValueStatement() {
  return getRuleContexts<FeatParser::AxisValueStatementContext>();
}

FeatParser::AxisValueStatementContext* FeatParser::AxisValueFileContext::axisValueStatement(size_t i) {
  return getRuleContext<FeatParser::AxisValueStatementContext>(i);
}


size_t FeatParser::AxisValueFileContext::getRuleIndex() const {
  return FeatParser::RuleAxisValueFile;
}


antlrcpp::Any FeatParser::AxisValueFileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitAxisValueFile(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::AxisValueFileContext* FeatParser::axisValueFile() {
  AxisValueFileContext *_localctx = _tracker.createInstance<AxisValueFileContext>(_ctx, getState());
  enterRule(_localctx, 200, FeatParser::RuleAxisValueFile);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1107);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FeatParser::INCLUDE || ((((_la - 77) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 77)) & ((1ULL << (FeatParser::NAME - 77))
      | (1ULL << (FeatParser::FLAG - 77))
      | (1ULL << (FeatParser::LOCATION - 77)))) != 0)) {
      setState(1104);
      axisValueStatement();
      setState(1109);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1110);
    match(FeatParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameEntryFileContext ------------------------------------------------------------------

FeatParser::NameEntryFileContext::NameEntryFileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::NameEntryFileContext::EOF() {
  return getToken(FeatParser::EOF, 0);
}

std::vector<FeatParser::NameEntryStatementContext *> FeatParser::NameEntryFileContext::nameEntryStatement() {
  return getRuleContexts<FeatParser::NameEntryStatementContext>();
}

FeatParser::NameEntryStatementContext* FeatParser::NameEntryFileContext::nameEntryStatement(size_t i) {
  return getRuleContext<FeatParser::NameEntryStatementContext>(i);
}


size_t FeatParser::NameEntryFileContext::getRuleIndex() const {
  return FeatParser::RuleNameEntryFile;
}


antlrcpp::Any FeatParser::NameEntryFileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitNameEntryFile(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::NameEntryFileContext* FeatParser::nameEntryFile() {
  NameEntryFileContext *_localctx = _tracker.createInstance<NameEntryFileContext>(_ctx, getState());
  enterRule(_localctx, 202, FeatParser::RuleNameEntryFile);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1115);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FeatParser::INCLUDE || _la == FeatParser::NAME) {
      setState(1112);
      nameEntryStatement();
      setState(1117);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1118);
    match(FeatParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubtokContext ------------------------------------------------------------------

FeatParser::SubtokContext::SubtokContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::SubtokContext::SUBSTITUTE() {
  return getToken(FeatParser::SUBSTITUTE, 0);
}

tree::TerminalNode* FeatParser::SubtokContext::SUBSTITUTE_v() {
  return getToken(FeatParser::SUBSTITUTE_v, 0);
}


size_t FeatParser::SubtokContext::getRuleIndex() const {
  return FeatParser::RuleSubtok;
}


antlrcpp::Any FeatParser::SubtokContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitSubtok(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::SubtokContext* FeatParser::subtok() {
  SubtokContext *_localctx = _tracker.createInstance<SubtokContext>(_ctx, getState());
  enterRule(_localctx, 204, FeatParser::RuleSubtok);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1120);
    _la = _input->LA(1);
    if (!(_la == FeatParser::SUBSTITUTE

    || _la == FeatParser::SUBSTITUTE_v)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RevtokContext ------------------------------------------------------------------

FeatParser::RevtokContext::RevtokContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::RevtokContext::REVERSE() {
  return getToken(FeatParser::REVERSE, 0);
}

tree::TerminalNode* FeatParser::RevtokContext::REVERSE_v() {
  return getToken(FeatParser::REVERSE_v, 0);
}


size_t FeatParser::RevtokContext::getRuleIndex() const {
  return FeatParser::RuleRevtok;
}


antlrcpp::Any FeatParser::RevtokContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitRevtok(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::RevtokContext* FeatParser::revtok() {
  RevtokContext *_localctx = _tracker.createInstance<RevtokContext>(_ctx, getState());
  enterRule(_localctx, 206, FeatParser::RuleRevtok);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1122);
    _la = _input->LA(1);
    if (!(_la == FeatParser::REVERSE

    || _la == FeatParser::REVERSE_v)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnontokContext ------------------------------------------------------------------

FeatParser::AnontokContext::AnontokContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::AnontokContext::ANON() {
  return getToken(FeatParser::ANON, 0);
}

tree::TerminalNode* FeatParser::AnontokContext::ANON_v() {
  return getToken(FeatParser::ANON_v, 0);
}


size_t FeatParser::AnontokContext::getRuleIndex() const {
  return FeatParser::RuleAnontok;
}


antlrcpp::Any FeatParser::AnontokContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitAnontok(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::AnontokContext* FeatParser::anontok() {
  AnontokContext *_localctx = _tracker.createInstance<AnontokContext>(_ctx, getState());
  enterRule(_localctx, 208, FeatParser::RuleAnontok);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1124);
    _la = _input->LA(1);
    if (!(_la == FeatParser::ANON

    || _la == FeatParser::ANON_v)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumtokContext ------------------------------------------------------------------

FeatParser::EnumtokContext::EnumtokContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::EnumtokContext::ENUMERATE() {
  return getToken(FeatParser::ENUMERATE, 0);
}

tree::TerminalNode* FeatParser::EnumtokContext::ENUMERATE_v() {
  return getToken(FeatParser::ENUMERATE_v, 0);
}


size_t FeatParser::EnumtokContext::getRuleIndex() const {
  return FeatParser::RuleEnumtok;
}


antlrcpp::Any FeatParser::EnumtokContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitEnumtok(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::EnumtokContext* FeatParser::enumtok() {
  EnumtokContext *_localctx = _tracker.createInstance<EnumtokContext>(_ctx, getState());
  enterRule(_localctx, 210, FeatParser::RuleEnumtok);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1126);
    _la = _input->LA(1);
    if (!(_la == FeatParser::ENUMERATE

    || _la == FeatParser::ENUMERATE_v)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PostokContext ------------------------------------------------------------------

FeatParser::PostokContext::PostokContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::PostokContext::POSITION() {
  return getToken(FeatParser::POSITION, 0);
}

tree::TerminalNode* FeatParser::PostokContext::POSITION_v() {
  return getToken(FeatParser::POSITION_v, 0);
}


size_t FeatParser::PostokContext::getRuleIndex() const {
  return FeatParser::RulePostok;
}


antlrcpp::Any FeatParser::PostokContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitPostok(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::PostokContext* FeatParser::postok() {
  PostokContext *_localctx = _tracker.createInstance<PostokContext>(_ctx, getState());
  enterRule(_localctx, 212, FeatParser::RulePostok);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1128);
    _la = _input->LA(1);
    if (!(_la == FeatParser::POSITION

    || _la == FeatParser::POSITION_v)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MarkligtokContext ------------------------------------------------------------------

FeatParser::MarkligtokContext::MarkligtokContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::MarkligtokContext::MARKLIG() {
  return getToken(FeatParser::MARKLIG, 0);
}

tree::TerminalNode* FeatParser::MarkligtokContext::MARKLIG_v() {
  return getToken(FeatParser::MARKLIG_v, 0);
}


size_t FeatParser::MarkligtokContext::getRuleIndex() const {
  return FeatParser::RuleMarkligtok;
}


antlrcpp::Any FeatParser::MarkligtokContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FeatParserVisitor*>(visitor))
    return parserVisitor->visitMarkligtok(this);
  else
    return visitor->visitChildren(this);
}

FeatParser::MarkligtokContext* FeatParser::markligtok() {
  MarkligtokContext *_localctx = _tracker.createInstance<MarkligtokContext>(_ctx, getState());
  enterRule(_localctx, 214, FeatParser::RuleMarkligtok);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1130);
    _la = _input->LA(1);
    if (!(_la == FeatParser::MARKLIG

    || _la == FeatParser::MARKLIG_v)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> FeatParser::_decisionToDFA;
atn::PredictionContextCache FeatParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN FeatParser::_atn;
std::vector<uint16_t> FeatParser::_serializedATN;

std::vector<std::string> FeatParser::_ruleNames = {
  "file", "topLevelStatement", "include", "glyphClassAssign", "langsysAssign", 
  "mark_statement", "anchorDef", "valueRecordDef", "featureBlock", "tableBlock", 
  "anonBlock", "lookupBlockTopLevel", "featureStatement", "lookupBlockOrUse", 
  "cvParameterBlock", "cvParameterStatement", "cvParameter", "statement", 
  "featureUse", "scriptAssign", "langAssign", "lookupflagAssign", "lookupflagElement", 
  "ignoreSubOrPos", "substitute", "position", "valuePattern", "valueRecord", 
  "valueLiteral", "cursiveElement", "baseToMarkElement", "ligatureMarkElement", 
  "parameters", "sizemenuname", "featureNames", "subtable", "table_BASE", 
  "baseStatement", "axisTags", "axisScripts", "baseScript", "table_GDEF", 
  "gdefStatement", "gdefGlyphClass", "gdefAttach", "gdefLigCaretPos", "gdefLigCaretIndex", 
  "table_head", "table_hhea", "hheaStatement", "hhea", "table_vhea", "vheaStatement", 
  "vhea", "table_name", "nameStatement", "nameID", "table_OS_2", "os_2Statement", 
  "os_2", "table_STAT", "statStatement", "designAxis", "axisValue", "axisValueStatement", 
  "axisValueLocation", "axisValueFlags", "elidedFallbackName", "nameEntryStatement", 
  "elidedFallbackNameID", "nameEntry", "table_vmtx", "vmtxStatement", "vmtx", 
  "anchor", "lookupPattern", "lookupPatternElement", "pattern", "patternElement", 
  "glyphClassOptional", "glyphClass", "gcLiteral", "gcLiteralElement", "glyph", 
  "glyphName", "label", "tag", "fixedNum", "genNum", "featureFile", "statementFile", 
  "cvStatementFile", "baseFile", "hheaFile", "vheaFile", "gdefFile", "nameFile", 
  "vmtxFile", "os_2File", "statFile", "axisValueFile", "nameEntryFile", 
  "subtok", "revtok", "anontok", "enumtok", "postok", "markligtok"
};

std::vector<std::string> FeatParser::_literalNames = {
  "", "'anon'", "'anonymous'", "", "", "'include'", "'feature'", "'table'", 
  "'script'", "'language'", "'languagesystem'", "'subtable'", "'lookup'", 
  "'lookupflag'", "'RightToLeft'", "'IgnoreBaseGlyphs'", "'IgnoreLigatures'", 
  "'IgnoreMarks'", "'UseMarkFilteringSet'", "'MarkAttachmentType'", "'excludeDFLT'", 
  "'includeDFLT'", "'exclude_dflt'", "'include_dflt'", "'useExtension'", 
  "'<'", "'>'", "'enumerate'", "'enum'", "'except'", "'ignore'", "'substitute'", 
  "'sub'", "'reversesub'", "'rsub'", "'by'", "'from'", "'position'", "'pos'", 
  "'parameters'", "'featureNames'", "'cvParameters'", "'FeatUILabelNameID'", 
  "'FeatUITooltipTextNameID'", "'SampleTextNameID'", "'ParamUILabelNameID'", 
  "'Character'", "'sizemenuname'", "'contourpoint'", "'anchor'", "'anchorDef'", 
  "'valueRecordDef'", "'mark'", "'markClass'", "'cursive'", "'base'", "'ligature'", 
  "'lig'", "'ligComponent'", "'NULL'", "'BASE'", "'HorizAxis.BaseTagList'", 
  "'VertAxis.BaseTagList'", "'HorizAxis.BaseScriptList'", "'VertAxis.BaseScriptList'", 
  "'GDEF'", "'GlyphClassDef'", "'Attach'", "'LigatureCaretByPos'", "'LigatureCaretByIndex'", 
  "'head'", "'FontRevision'", "'hhea'", "'Ascender'", "'Descender'", "'LineGap'", 
  "'CaretOffset'", "'name'", "'nameid'", "'OS/2'", "'FSType'", "'fsType'", 
  "'LowerOpSize'", "'UpperOpSize'", "'Panose'", "'TypoAscender'", "'TypoDescender'", 
  "'TypoLineGap'", "'winAscent'", "'winDescent'", "'XHeight'", "'CapHeight'", 
  "'WeightClass'", "'WidthClass'", "'Vendor'", "'UnicodeRange'", "'CodePageRange'", 
  "'FamilyClass'", "'STAT'", "'ElidedFallbackName'", "'ElidedFallbackNameID'", 
  "'DesignAxis'", "'AxisValue'", "'flag'", "'location'", "'ElidableAxisValueName'", 
  "'OlderSiblingFontAttribute'", "'vhea'", "'VertTypoAscender'", "'VertTypoDescender'", 
  "'VertTypoLineGap'", "'vmtx'", "'VertOriginY'", "'VertAdvanceY'", "", 
  "'}'", "'['", "']'", "'-'", "';'", "'='", "'''", "','", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "'('", "", "')'"
};

std::vector<std::string> FeatParser::_symbolicNames = {
  "", "ANON", "ANON_v", "COMMENT", "WHITESPACE", "INCLUDE", "FEATURE", "TABLE", 
  "SCRIPT", "LANGUAGE", "LANGSYS", "SUBTABLE", "LOOKUP", "LOOKUPFLAG", "RIGHT_TO_LEFT", 
  "IGNORE_BASE_GLYPHS", "IGNORE_LIGATURES", "IGNORE_MARKS", "USE_MARK_FILTERING_SET", 
  "MARK_ATTACHMENT_TYPE", "EXCLUDE_DFLT", "INCLUDE_DFLT", "EXCLUDE_dflt", 
  "INCLUDE_dflt", "USE_EXTENSION", "BEGINVALUE", "ENDVALUE", "ENUMERATE", 
  "ENUMERATE_v", "EXCEPT", "IGNORE", "SUBSTITUTE", "SUBSTITUTE_v", "REVERSE", 
  "REVERSE_v", "BY", "FROM", "POSITION", "POSITION_v", "PARAMETERS", "FEATURE_NAMES", 
  "CV_PARAMETERS", "CV_UI_LABEL", "CV_TOOLTIP", "CV_SAMPLE_TEXT", "CV_PARAM_LABEL", 
  "CV_CHARACTER", "SIZEMENUNAME", "CONTOURPOINT", "ANCHOR", "ANCHOR_DEF", 
  "VALUE_RECORD_DEF", "MARK", "MARK_CLASS", "CURSIVE", "MARKBASE", "MARKLIG", 
  "MARKLIG_v", "LIG_COMPONENT", "KNULL", "BASE", "HA_BTL", "VA_BTL", "HA_BSL", 
  "VA_BSL", "GDEF", "GLYPH_CLASS_DEF", "ATTACH", "LIG_CARET_BY_POS", "LIG_CARET_BY_IDX", 
  "HEAD", "FONT_REVISION", "HHEA", "ASCENDER", "DESCENDER", "LINE_GAP", 
  "CARET_OFFSET", "NAME", "NAMEID", "OS_2", "FS_TYPE", "FS_TYPE_v", "OS2_LOWER_OP_SIZE", 
  "OS2_UPPER_OP_SIZE", "PANOSE", "TYPO_ASCENDER", "TYPO_DESCENDER", "TYPO_LINE_GAP", 
  "WIN_ASCENT", "WIN_DESCENT", "X_HEIGHT", "CAP_HEIGHT", "WEIGHT_CLASS", 
  "WIDTH_CLASS", "VENDOR", "UNICODE_RANGE", "CODE_PAGE_RANGE", "FAMILY_CLASS", 
  "STAT", "ELIDED_FALLBACK_NAME", "ELIDED_FALLBACK_NAME_ID", "DESIGN_AXIS", 
  "AXIS_VALUE", "FLAG", "LOCATION", "AXIS_EAVN", "AXIS_OSFA", "VHEA", "VERT_TYPO_ASCENDER", 
  "VERT_TYPO_DESCENDER", "VERT_TYPO_LINE_GAP", "VMTX", "VERT_ORIGIN_Y", 
  "VERT_ADVANCE_Y", "LCBRACE", "RCBRACE", "LBRACKET", "RBRACKET", "HYPHEN", 
  "SEMI", "EQUALS", "MARKER", "COMMA", "QUOTE", "GCLASS", "CID", "ESCGNAME", 
  "NAMELABEL", "EXTNAME", "POINTNUM", "NUMEXT", "NUMOCT", "NUM", "CATCHTAG", 
  "A_WHITESPACE", "A_LABEL", "A_LBRACE", "A_CLOSE", "A_LINE", "I_WHITESPACE", 
  "I_RPAREN", "IFILE", "I_LPAREN", "STRVAL", "EQUOTE"
};

dfa::Vocabulary FeatParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> FeatParser::_tokenNames;

FeatParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x92, 0x46f, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 
       0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 
       0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 0x9, 0x1f, 0x4, 0x20, 
       0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 0x9, 0x22, 0x4, 0x23, 
       0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 0x25, 0x4, 0x26, 
       0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 0x4, 0x29, 
       0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 0x2c, 
       0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
       0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 
       0x9, 0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 
       0x9, 0x35, 0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 
       0x9, 0x38, 0x4, 0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 
       0x9, 0x3b, 0x4, 0x3c, 0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 
       0x9, 0x3e, 0x4, 0x3f, 0x9, 0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 
       0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 
       0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 0x46, 0x9, 0x46, 0x4, 0x47, 
       0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 0x9, 0x49, 0x4, 0x4a, 
       0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 0x4c, 0x4, 0x4d, 
       0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 0x4, 0x50, 
       0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 0x53, 
       0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
       0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 
       0x9, 0x59, 0x4, 0x5a, 0x9, 0x5a, 0x4, 0x5b, 0x9, 0x5b, 0x4, 0x5c, 
       0x9, 0x5c, 0x4, 0x5d, 0x9, 0x5d, 0x4, 0x5e, 0x9, 0x5e, 0x4, 0x5f, 
       0x9, 0x5f, 0x4, 0x60, 0x9, 0x60, 0x4, 0x61, 0x9, 0x61, 0x4, 0x62, 
       0x9, 0x62, 0x4, 0x63, 0x9, 0x63, 0x4, 0x64, 0x9, 0x64, 0x4, 0x65, 
       0x9, 0x65, 0x4, 0x66, 0x9, 0x66, 0x4, 0x67, 0x9, 0x67, 0x4, 0x68, 
       0x9, 0x68, 0x4, 0x69, 0x9, 0x69, 0x4, 0x6a, 0x9, 0x6a, 0x4, 0x6b, 
       0x9, 0x6b, 0x4, 0x6c, 0x9, 0x6c, 0x4, 0x6d, 0x9, 0x6d, 0x3, 0x2, 
       0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0xe0, 0xa, 0x2, 
       0xc, 0x2, 0xe, 0x2, 0xe3, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0xed, 
       0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 
       0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 
       0x7, 0x101, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 
       0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x10b, 0xa, 0x8, 0x3, 
       0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 
       0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x116, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 
       0x6, 0xa, 0x11a, 0xa, 0xa, 0xd, 0xa, 0xe, 0xa, 0x11b, 0x3, 0xa, 0x3, 
       0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
       0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 
       0xb, 0x12c, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 
       0xc, 0x132, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x135, 0xb, 0xc, 0x3, 0xc, 
       0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x13c, 0xa, 0xd, 
       0x3, 0xd, 0x3, 0xd, 0x6, 0xd, 0x140, 0xa, 0xd, 0xd, 0xd, 0xe, 0xd, 
       0x141, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 
       0x3, 0xe, 0x5, 0xe, 0x14b, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
       0x5, 0xf, 0x150, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x6, 0xf, 0x154, 0xa, 
       0xf, 0xd, 0xf, 0xe, 0xf, 0x155, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 
       0xf, 0x15b, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 
       0x10, 0x7, 0x10, 0x162, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0x165, 0xb, 
       0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x5, 
       0x11, 0x16c, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 
       0x3, 0x12, 0x6, 0x12, 0x173, 0xa, 0x12, 0xd, 0x12, 0xe, 0x12, 0x174, 
       0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x17b, 0xa, 
       0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
       0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
       0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x18b, 0xa, 0x13, 0x3, 0x13, 
       0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 
       0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x198, 0xa, 
       0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x6, 0x17, 0x19d, 0xa, 0x17, 
       0xd, 0x17, 0xe, 0x17, 0x19e, 0x5, 0x17, 0x1a1, 0xa, 0x17, 0x3, 0x18, 
       0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
       0x3, 0x18, 0x5, 0x18, 0x1ab, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 
       0x19, 0x3, 0x19, 0x5, 0x19, 0x1b1, 0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 
       0x3, 0x19, 0x7, 0x19, 0x1b6, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 0x1b9, 
       0xb, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x7, 0x1a, 
       0x1bf, 0xa, 0x1a, 0xc, 0x1a, 0xe, 0x1a, 0x1c2, 0xb, 0x1a, 0x5, 0x1a, 
       0x1c4, 0xa, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
       0x1a, 0x5, 0x1a, 0x1cb, 0xa, 0x1a, 0x5, 0x1a, 0x1cd, 0xa, 0x1a, 0x3, 
       0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x1d4, 
       0xa, 0x1a, 0x5, 0x1a, 0x1d6, 0xa, 0x1a, 0x5, 0x1a, 0x1d8, 0xa, 0x1a, 
       0x3, 0x1b, 0x5, 0x1b, 0x1db, 0xa, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 
       0x1b, 0x1df, 0xa, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 0x1e3, 0xa, 
       0x1b, 0xc, 0x1b, 0xe, 0x1b, 0x1e6, 0xb, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
       0x6, 0x1b, 0x1ea, 0xa, 0x1b, 0xd, 0x1b, 0xe, 0x1b, 0x1eb, 0x3, 0x1b, 
       0x7, 0x1b, 0x1ef, 0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 0x1f2, 0xb, 0x1b, 
       0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x1f7, 0xa, 0x1b, 0x3, 
       0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x6, 0x1b, 0x1fc, 0xa, 0x1b, 0xd, 0x1b, 
       0xe, 0x1b, 0x1fd, 0x3, 0x1b, 0x5, 0x1b, 0x201, 0xa, 0x1b, 0x3, 0x1b, 
       0x3, 0x1b, 0x3, 0x1b, 0x6, 0x1b, 0x206, 0xa, 0x1b, 0xd, 0x1b, 0xe, 
       0x1b, 0x207, 0x3, 0x1b, 0x5, 0x1b, 0x20b, 0xa, 0x1b, 0x3, 0x1b, 0x3, 
       0x1b, 0x3, 0x1b, 0x6, 0x1b, 0x210, 0xa, 0x1b, 0xd, 0x1b, 0xe, 0x1b, 
       0x211, 0x3, 0x1b, 0x5, 0x1b, 0x215, 0xa, 0x1b, 0x5, 0x1b, 0x217, 
       0xa, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x21b, 0xa, 0x1c, 0x3, 
       0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x222, 
       0xa, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
       0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x22b, 0xa, 0x1e, 0x3, 0x1f, 0x3, 
       0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 
       0x20, 0x5, 0x20, 0x235, 0xa, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
       0x5, 0x21, 0x23a, 0xa, 0x21, 0x3, 0x21, 0x5, 0x21, 0x23d, 0xa, 0x21, 
       0x3, 0x21, 0x5, 0x21, 0x240, 0xa, 0x21, 0x3, 0x22, 0x3, 0x22, 0x6, 
       0x22, 0x244, 0xa, 0x22, 0xd, 0x22, 0xe, 0x22, 0x245, 0x3, 0x23, 0x3, 
       0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x24d, 0xa, 0x23, 
       0x5, 0x23, 0x24f, 0xa, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 
       0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x6, 0x24, 0x258, 0xa, 0x24, 
       0xd, 0x24, 0xe, 0x24, 0x259, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x3, 
       0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x6, 0x26, 0x263, 0xa, 0x26, 
       0xd, 0x26, 0xe, 0x26, 0x264, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 
       0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x26e, 0xa, 0x27, 
       0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x6, 0x28, 0x274, 0xa, 
       0x28, 0xd, 0x28, 0xe, 0x28, 0x275, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
       0x3, 0x29, 0x7, 0x29, 0x27c, 0xa, 0x29, 0xc, 0x29, 0xe, 0x29, 0x27f, 
       0xb, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x6, 0x2a, 0x284, 0xa, 
       0x2a, 0xd, 0x2a, 0xe, 0x2a, 0x285, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
       0x6, 0x2b, 0x28b, 0xa, 0x2b, 0xd, 0x2b, 0xe, 0x2b, 0x28c, 0x3, 0x2b, 
       0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 
       0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x298, 0xa, 0x2c, 0x3, 0x2c, 0x3, 
       0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 
       0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
       0x2e, 0x6, 0x2e, 0x2a8, 0xa, 0x2e, 0xd, 0x2e, 0xe, 0x2e, 0x2a9, 0x3, 
       0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x6, 0x2f, 0x2af, 0xa, 0x2f, 0xd, 0x2f, 
       0xe, 0x2f, 0x2b0, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x6, 0x30, 0x2b6, 
       0xa, 0x30, 0xd, 0x30, 0xe, 0x30, 0x2b7, 0x3, 0x31, 0x3, 0x31, 0x3, 
       0x31, 0x3, 0x31, 0x5, 0x31, 0x2be, 0xa, 0x31, 0x3, 0x31, 0x3, 0x31, 
       0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 
       0x7, 0x32, 0x2c8, 0xa, 0x32, 0xc, 0x32, 0xe, 0x32, 0x2cb, 0xb, 0x32, 
       0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x33, 0x3, 0x33, 
       0x5, 0x33, 0x2d3, 0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x34, 0x3, 
       0x34, 0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x7, 0x35, 0x2dd, 
       0xa, 0x35, 0xc, 0x35, 0xe, 0x35, 0x2e0, 0xb, 0x35, 0x3, 0x35, 0x3, 
       0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x36, 0x3, 0x36, 0x5, 0x36, 0x2e8, 
       0xa, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 
       0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x6, 0x38, 0x2f2, 0xa, 0x38, 0xd, 
       0x38, 0xe, 0x38, 0x2f3, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 
       0x3, 0x39, 0x3, 0x39, 0x5, 0x39, 0x2fc, 0xa, 0x39, 0x3, 0x39, 0x3, 
       0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 
       0x3a, 0x5, 0x3a, 0x306, 0xa, 0x3a, 0x5, 0x3a, 0x308, 0xa, 0x3a, 0x3, 
       0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 
       0x3b, 0x6, 0x3b, 0x311, 0xa, 0x3b, 0xd, 0x3b, 0xe, 0x3b, 0x312, 0x3, 
       0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x5, 
       0x3c, 0x31b, 0xa, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 
       0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 
       0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 
       0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 
       0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x6, 0x3d, 0x336, 0xa, 0x3d, 0xd, 
       0x3d, 0xe, 0x3d, 0x337, 0x5, 0x3d, 0x33a, 0xa, 0x3d, 0x3, 0x3e, 0x3, 
       0x3e, 0x3, 0x3e, 0x6, 0x3e, 0x33f, 0xa, 0x3e, 0xd, 0x3e, 0xe, 0x3e, 
       0x340, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3f, 0x3, 
       0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x5, 0x3f, 0x34c, 0xa, 0x3f, 
       0x3, 0x3f, 0x3, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 
       0x3, 0x40, 0x6, 0x40, 0x355, 0xa, 0x40, 0xd, 0x40, 0xe, 0x40, 0x356, 
       0x3, 0x40, 0x3, 0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x6, 0x41, 
       0x35e, 0xa, 0x41, 0xd, 0x41, 0xe, 0x41, 0x35f, 0x3, 0x41, 0x3, 0x41, 
       0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x5, 0x42, 0x368, 0xa, 
       0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 
       0x43, 0x3, 0x43, 0x5, 0x43, 0x371, 0xa, 0x43, 0x5, 0x43, 0x373, 0xa, 
       0x43, 0x3, 0x44, 0x3, 0x44, 0x6, 0x44, 0x377, 0xa, 0x44, 0xd, 0x44, 
       0xe, 0x44, 0x378, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x6, 0x45, 0x37e, 
       0xa, 0x45, 0xd, 0x45, 0xe, 0x45, 0x37f, 0x3, 0x45, 0x3, 0x45, 0x3, 
       0x46, 0x3, 0x46, 0x5, 0x46, 0x386, 0xa, 0x46, 0x3, 0x46, 0x3, 0x46, 
       0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 
       0x3, 0x48, 0x3, 0x48, 0x5, 0x48, 0x392, 0xa, 0x48, 0x5, 0x48, 0x394, 
       0xa, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x49, 
       0x3, 0x49, 0x3, 0x49, 0x6, 0x49, 0x39d, 0xa, 0x49, 0xd, 0x49, 0xe, 
       0x49, 0x39e, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x4a, 
       0x3, 0x4a, 0x5, 0x4a, 0x3a7, 0xa, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 
       0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 0x3, 
       0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x5, 0x4c, 0x3b5, 0xa, 0x4c, 
       0x3, 0x4c, 0x3, 0x4c, 0x5, 0x4c, 0x3b9, 0xa, 0x4c, 0x3, 0x4c, 0x3, 
       0x4c, 0x3, 0x4d, 0x6, 0x4d, 0x3be, 0xa, 0x4d, 0xd, 0x4d, 0xe, 0x4d, 
       0x3bf, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x7, 0x4e, 0x3c5, 0xa, 0x4e, 
       0xc, 0x4e, 0xe, 0x4e, 0x3c8, 0xb, 0x4e, 0x3, 0x4f, 0x6, 0x4f, 0x3cb, 
       0xa, 0x4f, 0xd, 0x4f, 0xe, 0x4f, 0x3cc, 0x3, 0x50, 0x3, 0x50, 0x5, 
       0x50, 0x3d1, 0xa, 0x50, 0x3, 0x50, 0x5, 0x50, 0x3d4, 0xa, 0x50, 0x3, 
       0x51, 0x5, 0x51, 0x3d7, 0xa, 0x51, 0x3, 0x52, 0x3, 0x52, 0x5, 0x52, 
       0x3db, 0xa, 0x52, 0x3, 0x53, 0x3, 0x53, 0x6, 0x53, 0x3df, 0xa, 0x53, 
       0xd, 0x53, 0xe, 0x53, 0x3e0, 0x3, 0x53, 0x3, 0x53, 0x3, 0x54, 0x3, 
       0x54, 0x3, 0x54, 0x5, 0x54, 0x3e8, 0xa, 0x54, 0x3, 0x54, 0x5, 0x54, 
       0x3eb, 0xa, 0x54, 0x3, 0x55, 0x3, 0x55, 0x5, 0x55, 0x3ef, 0xa, 0x55, 
       0x3, 0x56, 0x3, 0x56, 0x3, 0x57, 0x3, 0x57, 0x3, 0x58, 0x3, 0x58, 
       0x3, 0x59, 0x3, 0x59, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5b, 0x7, 0x5b, 
       0x3fc, 0xa, 0x5b, 0xc, 0x5b, 0xe, 0x5b, 0x3ff, 0xb, 0x5b, 0x3, 0x5b, 
       0x3, 0x5b, 0x3, 0x5c, 0x7, 0x5c, 0x404, 0xa, 0x5c, 0xc, 0x5c, 0xe, 
       0x5c, 0x407, 0xb, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5d, 0x7, 0x5d, 
       0x40c, 0xa, 0x5d, 0xc, 0x5d, 0xe, 0x5d, 0x40f, 0xb, 0x5d, 0x3, 0x5d, 
       0x3, 0x5d, 0x3, 0x5e, 0x7, 0x5e, 0x414, 0xa, 0x5e, 0xc, 0x5e, 0xe, 
       0x5e, 0x417, 0xb, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5f, 0x7, 0x5f, 
       0x41c, 0xa, 0x5f, 0xc, 0x5f, 0xe, 0x5f, 0x41f, 0xb, 0x5f, 0x3, 0x5f, 
       0x3, 0x5f, 0x3, 0x60, 0x7, 0x60, 0x424, 0xa, 0x60, 0xc, 0x60, 0xe, 
       0x60, 0x427, 0xb, 0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 0x61, 0x7, 0x61, 
       0x42c, 0xa, 0x61, 0xc, 0x61, 0xe, 0x61, 0x42f, 0xb, 0x61, 0x3, 0x61, 
       0x3, 0x61, 0x3, 0x62, 0x7, 0x62, 0x434, 0xa, 0x62, 0xc, 0x62, 0xe, 
       0x62, 0x437, 0xb, 0x62, 0x3, 0x62, 0x3, 0x62, 0x3, 0x63, 0x7, 0x63, 
       0x43c, 0xa, 0x63, 0xc, 0x63, 0xe, 0x63, 0x43f, 0xb, 0x63, 0x3, 0x63, 
       0x3, 0x63, 0x3, 0x64, 0x7, 0x64, 0x444, 0xa, 0x64, 0xc, 0x64, 0xe, 
       0x64, 0x447, 0xb, 0x64, 0x3, 0x64, 0x3, 0x64, 0x3, 0x65, 0x7, 0x65, 
       0x44c, 0xa, 0x65, 0xc, 0x65, 0xe, 0x65, 0x44f, 0xb, 0x65, 0x3, 0x65, 
       0x3, 0x65, 0x3, 0x66, 0x7, 0x66, 0x454, 0xa, 0x66, 0xc, 0x66, 0xe, 
       0x66, 0x457, 0xb, 0x66, 0x3, 0x66, 0x3, 0x66, 0x3, 0x67, 0x7, 0x67, 
       0x45c, 0xa, 0x67, 0xc, 0x67, 0xe, 0x67, 0x45f, 0xb, 0x67, 0x3, 0x67, 
       0x3, 0x67, 0x3, 0x68, 0x3, 0x68, 0x3, 0x69, 0x3, 0x69, 0x3, 0x6a, 
       0x3, 0x6a, 0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6c, 0x3, 0x6c, 0x3, 0x6d, 
       0x3, 0x6d, 0x3, 0x6d, 0x2, 0x2, 0x6e, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
       0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 
       0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 
       0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 
       0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 
       0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 
       0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 
       0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 
       0xa8, 0xaa, 0xac, 0xae, 0xb0, 0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0xbc, 
       0xbe, 0xc0, 0xc2, 0xc4, 0xc6, 0xc8, 0xca, 0xcc, 0xce, 0xd0, 0xd2, 
       0xd4, 0xd6, 0xd8, 0x2, 0x18, 0x3, 0x2, 0x2c, 0x2f, 0x3, 0x2, 0x16, 
       0x19, 0x3, 0x2, 0x25, 0x26, 0x3, 0x2, 0x3f, 0x40, 0x3, 0x2, 0x41, 
       0x42, 0x3, 0x2, 0x4b, 0x4e, 0x3, 0x2, 0x6e, 0x70, 0x3, 0x2, 0x57, 
       0x5d, 0x4, 0x2, 0x52, 0x55, 0x5e, 0x5f, 0x3, 0x2, 0x61, 0x62, 0x3, 
       0x2, 0x6b, 0x6c, 0x3, 0x2, 0x72, 0x73, 0x3, 0x2, 0x80, 0x82, 0x5, 
       0x2, 0x36, 0x36, 0x81, 0x82, 0x87, 0x87, 0x4, 0x2, 0x83, 0x83, 0x86, 
       0x86, 0x3, 0x2, 0x84, 0x86, 0x3, 0x2, 0x21, 0x22, 0x3, 0x2, 0x23, 
       0x24, 0x3, 0x2, 0x3, 0x4, 0x3, 0x2, 0x1d, 0x1e, 0x3, 0x2, 0x27, 0x28, 
       0x3, 0x2, 0x3a, 0x3b, 0x2, 0x4ac, 0x2, 0xe1, 0x3, 0x2, 0x2, 0x2, 
       0x4, 0xec, 0x3, 0x2, 0x2, 0x2, 0x6, 0xf0, 0x3, 0x2, 0x2, 0x2, 0x8, 
       0xf5, 0x3, 0x2, 0x2, 0x2, 0xa, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xc, 0xfd, 
       0x3, 0x2, 0x2, 0x2, 0xe, 0x105, 0x3, 0x2, 0x2, 0x2, 0x10, 0x10e, 
       0x3, 0x2, 0x2, 0x2, 0x12, 0x112, 0x3, 0x2, 0x2, 0x2, 0x14, 0x121, 
       0x3, 0x2, 0x2, 0x2, 0x16, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x18, 0x138, 
       0x3, 0x2, 0x2, 0x2, 0x1a, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x14c, 
       0x3, 0x2, 0x2, 0x2, 0x1e, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x20, 0x16b, 
       0x3, 0x2, 0x2, 0x2, 0x22, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x24, 0x18a, 
       0x3, 0x2, 0x2, 0x2, 0x26, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x28, 0x191, 
       0x3, 0x2, 0x2, 0x2, 0x2a, 0x194, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x199, 
       0x3, 0x2, 0x2, 0x2, 0x2e, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x30, 0x1ac, 
       0x3, 0x2, 0x2, 0x2, 0x32, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x34, 0x1da, 
       0x3, 0x2, 0x2, 0x2, 0x36, 0x218, 0x3, 0x2, 0x2, 0x2, 0x38, 0x221, 
       0x3, 0x2, 0x2, 0x2, 0x3a, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x22c, 
       0x3, 0x2, 0x2, 0x2, 0x3e, 0x230, 0x3, 0x2, 0x2, 0x2, 0x40, 0x236, 
       0x3, 0x2, 0x2, 0x2, 0x42, 0x241, 0x3, 0x2, 0x2, 0x2, 0x44, 0x247, 
       0x3, 0x2, 0x2, 0x2, 0x46, 0x254, 0x3, 0x2, 0x2, 0x2, 0x48, 0x25d, 
       0x3, 0x2, 0x2, 0x2, 0x4a, 0x25f, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x26d, 
       0x3, 0x2, 0x2, 0x2, 0x4e, 0x271, 0x3, 0x2, 0x2, 0x2, 0x50, 0x277, 
       0x3, 0x2, 0x2, 0x2, 0x52, 0x280, 0x3, 0x2, 0x2, 0x2, 0x54, 0x287, 
       0x3, 0x2, 0x2, 0x2, 0x56, 0x297, 0x3, 0x2, 0x2, 0x2, 0x58, 0x29b, 
       0x3, 0x2, 0x2, 0x2, 0x5a, 0x2a4, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x2ab, 
       0x3, 0x2, 0x2, 0x2, 0x5e, 0x2b2, 0x3, 0x2, 0x2, 0x2, 0x60, 0x2b9, 
       0x3, 0x2, 0x2, 0x2, 0x62, 0x2c4, 0x3, 0x2, 0x2, 0x2, 0x64, 0x2d2, 
       0x3, 0x2, 0x2, 0x2, 0x66, 0x2d6, 0x3, 0x2, 0x2, 0x2, 0x68, 0x2d9, 
       0x3, 0x2, 0x2, 0x2, 0x6a, 0x2e7, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x2eb, 
       0x3, 0x2, 0x2, 0x2, 0x6e, 0x2ee, 0x3, 0x2, 0x2, 0x2, 0x70, 0x2fb, 
       0x3, 0x2, 0x2, 0x2, 0x72, 0x2ff, 0x3, 0x2, 0x2, 0x2, 0x74, 0x30d, 
       0x3, 0x2, 0x2, 0x2, 0x76, 0x31a, 0x3, 0x2, 0x2, 0x2, 0x78, 0x339, 
       0x3, 0x2, 0x2, 0x2, 0x7a, 0x33b, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x34b, 
       0x3, 0x2, 0x2, 0x2, 0x7e, 0x34f, 0x3, 0x2, 0x2, 0x2, 0x80, 0x35a, 
       0x3, 0x2, 0x2, 0x2, 0x82, 0x367, 0x3, 0x2, 0x2, 0x2, 0x84, 0x36b, 
       0x3, 0x2, 0x2, 0x2, 0x86, 0x374, 0x3, 0x2, 0x2, 0x2, 0x88, 0x37a, 
       0x3, 0x2, 0x2, 0x2, 0x8a, 0x385, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x389, 
       0x3, 0x2, 0x2, 0x2, 0x8e, 0x38c, 0x3, 0x2, 0x2, 0x2, 0x90, 0x399, 
       0x3, 0x2, 0x2, 0x2, 0x92, 0x3a6, 0x3, 0x2, 0x2, 0x2, 0x94, 0x3aa, 
       0x3, 0x2, 0x2, 0x2, 0x96, 0x3ae, 0x3, 0x2, 0x2, 0x2, 0x98, 0x3bd, 
       0x3, 0x2, 0x2, 0x2, 0x9a, 0x3c1, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x3ca, 
       0x3, 0x2, 0x2, 0x2, 0x9e, 0x3d0, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x3d6, 
       0x3, 0x2, 0x2, 0x2, 0xa2, 0x3da, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x3dc, 
       0x3, 0x2, 0x2, 0x2, 0xa6, 0x3ea, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x3ee, 
       0x3, 0x2, 0x2, 0x2, 0xaa, 0x3f0, 0x3, 0x2, 0x2, 0x2, 0xac, 0x3f2, 
       0x3, 0x2, 0x2, 0x2, 0xae, 0x3f4, 0x3, 0x2, 0x2, 0x2, 0xb0, 0x3f6, 
       0x3, 0x2, 0x2, 0x2, 0xb2, 0x3f8, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x3fd, 
       0x3, 0x2, 0x2, 0x2, 0xb6, 0x405, 0x3, 0x2, 0x2, 0x2, 0xb8, 0x40d, 
       0x3, 0x2, 0x2, 0x2, 0xba, 0x415, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x41d, 
       0x3, 0x2, 0x2, 0x2, 0xbe, 0x425, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x42d, 
       0x3, 0x2, 0x2, 0x2, 0xc2, 0x435, 0x3, 0x2, 0x2, 0x2, 0xc4, 0x43d, 
       0x3, 0x2, 0x2, 0x2, 0xc6, 0x445, 0x3, 0x2, 0x2, 0x2, 0xc8, 0x44d, 
       0x3, 0x2, 0x2, 0x2, 0xca, 0x455, 0x3, 0x2, 0x2, 0x2, 0xcc, 0x45d, 
       0x3, 0x2, 0x2, 0x2, 0xce, 0x462, 0x3, 0x2, 0x2, 0x2, 0xd0, 0x464, 
       0x3, 0x2, 0x2, 0x2, 0xd2, 0x466, 0x3, 0x2, 0x2, 0x2, 0xd4, 0x468, 
       0x3, 0x2, 0x2, 0x2, 0xd6, 0x46a, 0x3, 0x2, 0x2, 0x2, 0xd8, 0x46c, 
       0x3, 0x2, 0x2, 0x2, 0xda, 0xe0, 0x5, 0x4, 0x3, 0x2, 0xdb, 0xe0, 0x5, 
       0x12, 0xa, 0x2, 0xdc, 0xe0, 0x5, 0x14, 0xb, 0x2, 0xdd, 0xe0, 0x5, 
       0x16, 0xc, 0x2, 0xde, 0xe0, 0x5, 0x18, 0xd, 0x2, 0xdf, 0xda, 0x3, 
       0x2, 0x2, 0x2, 0xdf, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xdc, 0x3, 0x2, 
       0x2, 0x2, 0xdf, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xde, 0x3, 0x2, 0x2, 
       0x2, 0xe0, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xdf, 0x3, 0x2, 0x2, 0x2, 
       0xe1, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe3, 
       0xe1, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe5, 0x7, 0x2, 0x2, 0x3, 0xe5, 0x3, 
       0x3, 0x2, 0x2, 0x2, 0xe6, 0xed, 0x5, 0x6, 0x4, 0x2, 0xe7, 0xed, 0x5, 
       0x8, 0x5, 0x2, 0xe8, 0xed, 0x5, 0xa, 0x6, 0x2, 0xe9, 0xed, 0x5, 0xc, 
       0x7, 0x2, 0xea, 0xed, 0x5, 0xe, 0x8, 0x2, 0xeb, 0xed, 0x5, 0x10, 
       0x9, 0x2, 0xec, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xec, 0xe7, 0x3, 0x2, 0x2, 
       0x2, 0xec, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xec, 0xe9, 0x3, 0x2, 0x2, 0x2, 
       0xec, 0xea, 0x3, 0x2, 0x2, 0x2, 0xec, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xed, 
       0xee, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0x7, 0x79, 0x2, 0x2, 0xef, 
       0x5, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 0x7, 0x7, 0x2, 0x2, 0xf1, 0xf2, 
       0x7, 0x8e, 0x2, 0x2, 0xf2, 0xf3, 0x7, 0x8f, 0x2, 0x2, 0xf3, 0xf4, 
       0x7, 0x90, 0x2, 0x2, 0xf4, 0x7, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf6, 0x7, 
       0x7e, 0x2, 0x2, 0xf6, 0xf7, 0x7, 0x7a, 0x2, 0x2, 0xf7, 0xf8, 0x5, 
       0xa2, 0x52, 0x2, 0xf8, 0x9, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x7, 
       0xc, 0x2, 0x2, 0xfa, 0xfb, 0x5, 0xae, 0x58, 0x2, 0xfb, 0xfc, 0x5, 
       0xae, 0x58, 0x2, 0xfc, 0xb, 0x3, 0x2, 0x2, 0x2, 0xfd, 0x100, 0x7, 
       0x37, 0x2, 0x2, 0xfe, 0x101, 0x5, 0xa8, 0x55, 0x2, 0xff, 0x101, 0x5, 
       0xa2, 0x52, 0x2, 0x100, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x100, 0xff, 0x3, 
       0x2, 0x2, 0x2, 0x101, 0x102, 0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 0x5, 
       0x96, 0x4c, 0x2, 0x103, 0x104, 0x7, 0x7e, 0x2, 0x2, 0x104, 0xd, 0x3, 
       0x2, 0x2, 0x2, 0x105, 0x106, 0x7, 0x34, 0x2, 0x2, 0x106, 0x107, 0x7, 
       0x86, 0x2, 0x2, 0x107, 0x10a, 0x7, 0x86, 0x2, 0x2, 0x108, 0x109, 
       0x7, 0x32, 0x2, 0x2, 0x109, 0x10b, 0x7, 0x86, 0x2, 0x2, 0x10a, 0x108, 
       0x3, 0x2, 0x2, 0x2, 0x10a, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x10c, 
       0x3, 0x2, 0x2, 0x2, 0x10c, 0x10d, 0x5, 0xac, 0x57, 0x2, 0x10d, 0xf, 
       0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 0x7, 0x35, 0x2, 0x2, 0x10f, 0x110, 
       0x5, 0x3a, 0x1e, 0x2, 0x110, 0x111, 0x5, 0xac, 0x57, 0x2, 0x111, 
       0x11, 0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 0x7, 0x8, 0x2, 0x2, 0x113, 
       0x115, 0x5, 0xae, 0x58, 0x2, 0x114, 0x116, 0x7, 0x1a, 0x2, 0x2, 0x115, 
       0x114, 0x3, 0x2, 0x2, 0x2, 0x115, 0x116, 0x3, 0x2, 0x2, 0x2, 0x116, 
       0x117, 0x3, 0x2, 0x2, 0x2, 0x117, 0x119, 0x7, 0x74, 0x2, 0x2, 0x118, 
       0x11a, 0x5, 0x1a, 0xe, 0x2, 0x119, 0x118, 0x3, 0x2, 0x2, 0x2, 0x11a, 
       0x11b, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x119, 0x3, 0x2, 0x2, 0x2, 0x11b, 
       0x11c, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11d, 
       0x11e, 0x7, 0x75, 0x2, 0x2, 0x11e, 0x11f, 0x5, 0xae, 0x58, 0x2, 0x11f, 
       0x120, 0x7, 0x79, 0x2, 0x2, 0x120, 0x13, 0x3, 0x2, 0x2, 0x2, 0x121, 
       0x12b, 0x7, 0x9, 0x2, 0x2, 0x122, 0x12c, 0x5, 0x4a, 0x26, 0x2, 0x123, 
       0x12c, 0x5, 0x54, 0x2b, 0x2, 0x124, 0x12c, 0x5, 0x60, 0x31, 0x2, 
       0x125, 0x12c, 0x5, 0x62, 0x32, 0x2, 0x126, 0x12c, 0x5, 0x68, 0x35, 
       0x2, 0x127, 0x12c, 0x5, 0x6e, 0x38, 0x2, 0x128, 0x12c, 0x5, 0x74, 
       0x3b, 0x2, 0x129, 0x12c, 0x5, 0x7a, 0x3e, 0x2, 0x12a, 0x12c, 0x5, 
       0x90, 0x49, 0x2, 0x12b, 0x122, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x123, 
       0x3, 0x2, 0x2, 0x2, 0x12b, 0x124, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x125, 
       0x3, 0x2, 0x2, 0x2, 0x12b, 0x126, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x127, 
       0x3, 0x2, 0x2, 0x2, 0x12b, 0x128, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x129, 
       0x3, 0x2, 0x2, 0x2, 0x12b, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x15, 
       0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 0x5, 0xd2, 0x6a, 0x2, 0x12e, 0x12f, 
       0x7, 0x89, 0x2, 0x2, 0x12f, 0x133, 0x7, 0x8a, 0x2, 0x2, 0x130, 0x132, 
       0x7, 0x8c, 0x2, 0x2, 0x131, 0x130, 0x3, 0x2, 0x2, 0x2, 0x132, 0x135, 
       0x3, 0x2, 0x2, 0x2, 0x133, 0x131, 0x3, 0x2, 0x2, 0x2, 0x133, 0x134, 
       0x3, 0x2, 0x2, 0x2, 0x134, 0x136, 0x3, 0x2, 0x2, 0x2, 0x135, 0x133, 
       0x3, 0x2, 0x2, 0x2, 0x136, 0x137, 0x7, 0x8b, 0x2, 0x2, 0x137, 0x17, 
       0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 0x7, 0xe, 0x2, 0x2, 0x139, 0x13b, 
       0x5, 0xac, 0x57, 0x2, 0x13a, 0x13c, 0x7, 0x1a, 0x2, 0x2, 0x13b, 0x13a, 
       0x3, 0x2, 0x2, 0x2, 0x13b, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13d, 
       0x3, 0x2, 0x2, 0x2, 0x13d, 0x13f, 0x7, 0x74, 0x2, 0x2, 0x13e, 0x140, 
       0x5, 0x24, 0x13, 0x2, 0x13f, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x140, 0x141, 
       0x3, 0x2, 0x2, 0x2, 0x141, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x141, 0x142, 
       0x3, 0x2, 0x2, 0x2, 0x142, 0x143, 0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 
       0x7, 0x75, 0x2, 0x2, 0x144, 0x145, 0x5, 0xac, 0x57, 0x2, 0x145, 0x146, 
       0x7, 0x79, 0x2, 0x2, 0x146, 0x19, 0x3, 0x2, 0x2, 0x2, 0x147, 0x14b, 
       0x5, 0x24, 0x13, 0x2, 0x148, 0x14b, 0x5, 0x1c, 0xf, 0x2, 0x149, 0x14b, 
       0x5, 0x1e, 0x10, 0x2, 0x14a, 0x147, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x148, 
       0x3, 0x2, 0x2, 0x2, 0x14a, 0x149, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x1b, 
       0x3, 0x2, 0x2, 0x2, 0x14c, 0x14d, 0x7, 0xe, 0x2, 0x2, 0x14d, 0x15a, 
       0x5, 0xac, 0x57, 0x2, 0x14e, 0x150, 0x7, 0x1a, 0x2, 0x2, 0x14f, 0x14e, 
       0x3, 0x2, 0x2, 0x2, 0x14f, 0x150, 0x3, 0x2, 0x2, 0x2, 0x150, 0x151, 
       0x3, 0x2, 0x2, 0x2, 0x151, 0x153, 0x7, 0x74, 0x2, 0x2, 0x152, 0x154, 
       0x5, 0x24, 0x13, 0x2, 0x153, 0x152, 0x3, 0x2, 0x2, 0x2, 0x154, 0x155, 
       0x3, 0x2, 0x2, 0x2, 0x155, 0x153, 0x3, 0x2, 0x2, 0x2, 0x155, 0x156, 
       0x3, 0x2, 0x2, 0x2, 0x156, 0x157, 0x3, 0x2, 0x2, 0x2, 0x157, 0x158, 
       0x7, 0x75, 0x2, 0x2, 0x158, 0x159, 0x5, 0xac, 0x57, 0x2, 0x159, 0x15b, 
       0x3, 0x2, 0x2, 0x2, 0x15a, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x15b, 
       0x3, 0x2, 0x2, 0x2, 0x15b, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x15d, 
       0x7, 0x79, 0x2, 0x2, 0x15d, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15f, 
       0x7, 0x2b, 0x2, 0x2, 0x15f, 0x163, 0x7, 0x74, 0x2, 0x2, 0x160, 0x162, 
       0x5, 0x20, 0x11, 0x2, 0x161, 0x160, 0x3, 0x2, 0x2, 0x2, 0x162, 0x165, 
       0x3, 0x2, 0x2, 0x2, 0x163, 0x161, 0x3, 0x2, 0x2, 0x2, 0x163, 0x164, 
       0x3, 0x2, 0x2, 0x2, 0x164, 0x166, 0x3, 0x2, 0x2, 0x2, 0x165, 0x163, 
       0x3, 0x2, 0x2, 0x2, 0x166, 0x167, 0x7, 0x75, 0x2, 0x2, 0x167, 0x168, 
       0x7, 0x79, 0x2, 0x2, 0x168, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x169, 0x16c, 
       0x5, 0x22, 0x12, 0x2, 0x16a, 0x16c, 0x5, 0x6, 0x4, 0x2, 0x16b, 0x169, 
       0x3, 0x2, 0x2, 0x2, 0x16b, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x16d, 
       0x3, 0x2, 0x2, 0x2, 0x16d, 0x16e, 0x7, 0x79, 0x2, 0x2, 0x16e, 0x21, 
       0x3, 0x2, 0x2, 0x2, 0x16f, 0x170, 0x9, 0x2, 0x2, 0x2, 0x170, 0x172, 
       0x7, 0x74, 0x2, 0x2, 0x171, 0x173, 0x5, 0x8a, 0x46, 0x2, 0x172, 0x171, 
       0x3, 0x2, 0x2, 0x2, 0x173, 0x174, 0x3, 0x2, 0x2, 0x2, 0x174, 0x172, 
       0x3, 0x2, 0x2, 0x2, 0x174, 0x175, 0x3, 0x2, 0x2, 0x2, 0x175, 0x176, 
       0x3, 0x2, 0x2, 0x2, 0x176, 0x177, 0x7, 0x75, 0x2, 0x2, 0x177, 0x17b, 
       0x3, 0x2, 0x2, 0x2, 0x178, 0x179, 0x7, 0x30, 0x2, 0x2, 0x179, 0x17b, 
       0x5, 0xb2, 0x5a, 0x2, 0x17a, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x178, 
       0x3, 0x2, 0x2, 0x2, 0x17b, 0x23, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x18b, 
       0x5, 0x26, 0x14, 0x2, 0x17d, 0x18b, 0x5, 0x28, 0x15, 0x2, 0x17e, 
       0x18b, 0x5, 0x2a, 0x16, 0x2, 0x17f, 0x18b, 0x5, 0x2c, 0x17, 0x2, 
       0x180, 0x18b, 0x5, 0x8, 0x5, 0x2, 0x181, 0x18b, 0x5, 0x30, 0x19, 
       0x2, 0x182, 0x18b, 0x5, 0x32, 0x1a, 0x2, 0x183, 0x18b, 0x5, 0xc, 
       0x7, 0x2, 0x184, 0x18b, 0x5, 0x34, 0x1b, 0x2, 0x185, 0x18b, 0x5, 
       0x42, 0x22, 0x2, 0x186, 0x18b, 0x5, 0x44, 0x23, 0x2, 0x187, 0x18b, 
       0x5, 0x46, 0x24, 0x2, 0x188, 0x18b, 0x5, 0x48, 0x25, 0x2, 0x189, 
       0x18b, 0x5, 0x6, 0x4, 0x2, 0x18a, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x18a, 
       0x17d, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x18a, 
       0x17f, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x180, 0x3, 0x2, 0x2, 0x2, 0x18a, 
       0x181, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x182, 0x3, 0x2, 0x2, 0x2, 0x18a, 
       0x183, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x184, 0x3, 0x2, 0x2, 0x2, 0x18a, 
       0x185, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x186, 0x3, 0x2, 0x2, 0x2, 0x18a, 
       0x187, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x188, 0x3, 0x2, 0x2, 0x2, 0x18a, 
       0x189, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18c, 
       0x18d, 0x7, 0x79, 0x2, 0x2, 0x18d, 0x25, 0x3, 0x2, 0x2, 0x2, 0x18e, 
       0x18f, 0x7, 0x8, 0x2, 0x2, 0x18f, 0x190, 0x5, 0xae, 0x58, 0x2, 0x190, 
       0x27, 0x3, 0x2, 0x2, 0x2, 0x191, 0x192, 0x7, 0xa, 0x2, 0x2, 0x192, 
       0x193, 0x5, 0xae, 0x58, 0x2, 0x193, 0x29, 0x3, 0x2, 0x2, 0x2, 0x194, 
       0x195, 0x7, 0xb, 0x2, 0x2, 0x195, 0x197, 0x5, 0xae, 0x58, 0x2, 0x196, 
       0x198, 0x9, 0x3, 0x2, 0x2, 0x197, 0x196, 0x3, 0x2, 0x2, 0x2, 0x197, 
       0x198, 0x3, 0x2, 0x2, 0x2, 0x198, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x199, 
       0x1a0, 0x7, 0xf, 0x2, 0x2, 0x19a, 0x1a1, 0x7, 0x86, 0x2, 0x2, 0x19b, 
       0x19d, 0x5, 0x2e, 0x18, 0x2, 0x19c, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x19d, 
       0x19e, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x19e, 
       0x19f, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x1a0, 
       0x19a, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x1a1, 
       0x2d, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1ab, 0x7, 0x10, 0x2, 0x2, 0x1a3, 
       0x1ab, 0x7, 0x11, 0x2, 0x2, 0x1a4, 0x1ab, 0x7, 0x12, 0x2, 0x2, 0x1a5, 
       0x1ab, 0x7, 0x13, 0x2, 0x2, 0x1a6, 0x1a7, 0x7, 0x15, 0x2, 0x2, 0x1a7, 
       0x1ab, 0x5, 0xa2, 0x52, 0x2, 0x1a8, 0x1a9, 0x7, 0x14, 0x2, 0x2, 0x1a9, 
       0x1ab, 0x5, 0xa2, 0x52, 0x2, 0x1aa, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1aa, 
       0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1aa, 
       0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1aa, 
       0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x1ac, 
       0x1b0, 0x7, 0x20, 0x2, 0x2, 0x1ad, 0x1b1, 0x5, 0xce, 0x68, 0x2, 0x1ae, 
       0x1b1, 0x5, 0xd0, 0x69, 0x2, 0x1af, 0x1b1, 0x5, 0xd6, 0x6c, 0x2, 
       0x1b0, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1ae, 0x3, 0x2, 0x2, 0x2, 
       0x1b0, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1b2, 0x3, 0x2, 0x2, 0x2, 
       0x1b2, 0x1b7, 0x5, 0x98, 0x4d, 0x2, 0x1b3, 0x1b4, 0x7, 0x7c, 0x2, 
       0x2, 0x1b4, 0x1b6, 0x5, 0x98, 0x4d, 0x2, 0x1b5, 0x1b3, 0x3, 0x2, 
       0x2, 0x2, 0x1b6, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b5, 0x3, 0x2, 
       0x2, 0x2, 0x1b7, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x31, 0x3, 0x2, 
       0x2, 0x2, 0x1b9, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1ba, 0x1bb, 0x7, 0x1f, 
       0x2, 0x2, 0x1bb, 0x1c0, 0x5, 0x98, 0x4d, 0x2, 0x1bc, 0x1bd, 0x7, 
       0x7c, 0x2, 0x2, 0x1bd, 0x1bf, 0x5, 0x98, 0x4d, 0x2, 0x1be, 0x1bc, 
       0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1be, 
       0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1c1, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c4, 
       0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1ba, 
       0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1d7, 
       0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c6, 0x5, 0xd0, 0x69, 0x2, 0x1c6, 0x1cc, 
       0x5, 0x98, 0x4d, 0x2, 0x1c7, 0x1ca, 0x7, 0x25, 0x2, 0x2, 0x1c8, 0x1cb, 
       0x7, 0x3d, 0x2, 0x2, 0x1c9, 0x1cb, 0x5, 0x98, 0x4d, 0x2, 0x1ca, 0x1c8, 
       0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1cd, 
       0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1cd, 
       0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1cf, 
       0x5, 0xce, 0x68, 0x2, 0x1cf, 0x1d5, 0x5, 0x98, 0x4d, 0x2, 0x1d0, 
       0x1d3, 0x9, 0x4, 0x2, 0x2, 0x1d1, 0x1d4, 0x7, 0x3d, 0x2, 0x2, 0x1d2, 
       0x1d4, 0x5, 0x98, 0x4d, 0x2, 0x1d3, 0x1d1, 0x3, 0x2, 0x2, 0x2, 0x1d3, 
       0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d5, 
       0x1d0, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d6, 
       0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1d7, 
       0x1ce, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x33, 0x3, 0x2, 0x2, 0x2, 0x1d9, 
       0x1db, 0x5, 0xd4, 0x6b, 0x2, 0x1da, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1da, 
       0x1db, 0x3, 0x2, 0x2, 0x2, 0x1db, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1dc, 
       0x1de, 0x5, 0xd6, 0x6c, 0x2, 0x1dd, 0x1df, 0x5, 0x9c, 0x4f, 0x2, 
       0x1de, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1df, 0x3, 0x2, 0x2, 0x2, 
       0x1df, 0x216, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1e4, 0x5, 0x38, 0x1d, 
       0x2, 0x1e1, 0x1e3, 0x5, 0x36, 0x1c, 0x2, 0x1e2, 0x1e1, 0x3, 0x2, 
       0x2, 0x2, 0x1e3, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1e2, 0x3, 0x2, 
       0x2, 0x2, 0x1e4, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x217, 0x3, 0x2, 
       0x2, 0x2, 0x1e6, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e8, 0x7, 0xe, 
       0x2, 0x2, 0x1e8, 0x1ea, 0x5, 0xac, 0x57, 0x2, 0x1e9, 0x1e7, 0x3, 
       0x2, 0x2, 0x2, 0x1ea, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1eb, 0x1e9, 0x3, 
       0x2, 0x2, 0x2, 0x1eb, 0x1ec, 0x3, 0x2, 0x2, 0x2, 0x1ec, 0x1f0, 0x3, 
       0x2, 0x2, 0x2, 0x1ed, 0x1ef, 0x5, 0x9a, 0x4e, 0x2, 0x1ee, 0x1ed, 
       0x3, 0x2, 0x2, 0x2, 0x1ef, 0x1f2, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1ee, 
       0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1f1, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x217, 
       0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f4, 
       0x7, 0x38, 0x2, 0x2, 0x1f4, 0x1f6, 0x5, 0x3c, 0x1f, 0x2, 0x1f5, 0x1f7, 
       0x5, 0x9c, 0x4f, 0x2, 0x1f6, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f6, 0x1f7, 
       0x3, 0x2, 0x2, 0x2, 0x1f7, 0x217, 0x3, 0x2, 0x2, 0x2, 0x1f8, 0x1f9, 
       0x7, 0x39, 0x2, 0x2, 0x1f9, 0x1fb, 0x5, 0x9c, 0x4f, 0x2, 0x1fa, 0x1fc, 
       0x5, 0x3e, 0x20, 0x2, 0x1fb, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1fd, 
       0x3, 0x2, 0x2, 0x2, 0x1fd, 0x1fb, 0x3, 0x2, 0x2, 0x2, 0x1fd, 0x1fe, 
       0x3, 0x2, 0x2, 0x2, 0x1fe, 0x200, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x201, 
       0x5, 0x9c, 0x4f, 0x2, 0x200, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x200, 0x201, 
       0x3, 0x2, 0x2, 0x2, 0x201, 0x217, 0x3, 0x2, 0x2, 0x2, 0x202, 0x203, 
       0x5, 0xd8, 0x6d, 0x2, 0x203, 0x205, 0x5, 0x9c, 0x4f, 0x2, 0x204, 
       0x206, 0x5, 0x40, 0x21, 0x2, 0x205, 0x204, 0x3, 0x2, 0x2, 0x2, 0x206, 
       0x207, 0x3, 0x2, 0x2, 0x2, 0x207, 0x205, 0x3, 0x2, 0x2, 0x2, 0x207, 
       0x208, 0x3, 0x2, 0x2, 0x2, 0x208, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x209, 
       0x20b, 0x5, 0x9c, 0x4f, 0x2, 0x20a, 0x209, 0x3, 0x2, 0x2, 0x2, 0x20a, 
       0x20b, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x217, 0x3, 0x2, 0x2, 0x2, 0x20c, 
       0x20d, 0x7, 0x36, 0x2, 0x2, 0x20d, 0x20f, 0x5, 0x9c, 0x4f, 0x2, 0x20e, 
       0x210, 0x5, 0x3e, 0x20, 0x2, 0x20f, 0x20e, 0x3, 0x2, 0x2, 0x2, 0x210, 
       0x211, 0x3, 0x2, 0x2, 0x2, 0x211, 0x20f, 0x3, 0x2, 0x2, 0x2, 0x211, 
       0x212, 0x3, 0x2, 0x2, 0x2, 0x212, 0x214, 0x3, 0x2, 0x2, 0x2, 0x213, 
       0x215, 0x5, 0x9c, 0x4f, 0x2, 0x214, 0x213, 0x3, 0x2, 0x2, 0x2, 0x214, 
       0x215, 0x3, 0x2, 0x2, 0x2, 0x215, 0x217, 0x3, 0x2, 0x2, 0x2, 0x216, 
       0x1e0, 0x3, 0x2, 0x2, 0x2, 0x216, 0x1e9, 0x3, 0x2, 0x2, 0x2, 0x216, 
       0x1f3, 0x3, 0x2, 0x2, 0x2, 0x216, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x216, 
       0x202, 0x3, 0x2, 0x2, 0x2, 0x216, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x217, 
       0x35, 0x3, 0x2, 0x2, 0x2, 0x218, 0x21a, 0x5, 0x9e, 0x50, 0x2, 0x219, 
       0x21b, 0x5, 0x38, 0x1d, 0x2, 0x21a, 0x219, 0x3, 0x2, 0x2, 0x2, 0x21a, 
       0x21b, 0x3, 0x2, 0x2, 0x2, 0x21b, 0x37, 0x3, 0x2, 0x2, 0x2, 0x21c, 
       0x21d, 0x7, 0x1b, 0x2, 0x2, 0x21d, 0x21e, 0x5, 0xac, 0x57, 0x2, 0x21e, 
       0x21f, 0x7, 0x1c, 0x2, 0x2, 0x21f, 0x222, 0x3, 0x2, 0x2, 0x2, 0x220, 
       0x222, 0x5, 0x3a, 0x1e, 0x2, 0x221, 0x21c, 0x3, 0x2, 0x2, 0x2, 0x221, 
       0x220, 0x3, 0x2, 0x2, 0x2, 0x222, 0x39, 0x3, 0x2, 0x2, 0x2, 0x223, 
       0x224, 0x7, 0x1b, 0x2, 0x2, 0x224, 0x225, 0x7, 0x86, 0x2, 0x2, 0x225, 
       0x226, 0x7, 0x86, 0x2, 0x2, 0x226, 0x227, 0x7, 0x86, 0x2, 0x2, 0x227, 
       0x228, 0x7, 0x86, 0x2, 0x2, 0x228, 0x22b, 0x7, 0x1c, 0x2, 0x2, 0x229, 
       0x22b, 0x7, 0x86, 0x2, 0x2, 0x22a, 0x223, 0x3, 0x2, 0x2, 0x2, 0x22a, 
       0x229, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x22c, 
       0x22d, 0x5, 0x9e, 0x50, 0x2, 0x22d, 0x22e, 0x5, 0x96, 0x4c, 0x2, 
       0x22e, 0x22f, 0x5, 0x96, 0x4c, 0x2, 0x22f, 0x3d, 0x3, 0x2, 0x2, 0x2, 
       0x230, 0x231, 0x5, 0x96, 0x4c, 0x2, 0x231, 0x232, 0x7, 0x36, 0x2, 
       0x2, 0x232, 0x234, 0x7, 0x7e, 0x2, 0x2, 0x233, 0x235, 0x7, 0x7b, 
       0x2, 0x2, 0x234, 0x233, 0x3, 0x2, 0x2, 0x2, 0x234, 0x235, 0x3, 0x2, 
       0x2, 0x2, 0x235, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x236, 0x239, 0x5, 0x96, 
       0x4c, 0x2, 0x237, 0x238, 0x7, 0x36, 0x2, 0x2, 0x238, 0x23a, 0x7, 
       0x7e, 0x2, 0x2, 0x239, 0x237, 0x3, 0x2, 0x2, 0x2, 0x239, 0x23a, 0x3, 
       0x2, 0x2, 0x2, 0x23a, 0x23c, 0x3, 0x2, 0x2, 0x2, 0x23b, 0x23d, 0x7, 
       0x3c, 0x2, 0x2, 0x23c, 0x23b, 0x3, 0x2, 0x2, 0x2, 0x23c, 0x23d, 0x3, 
       0x2, 0x2, 0x2, 0x23d, 0x23f, 0x3, 0x2, 0x2, 0x2, 0x23e, 0x240, 0x7, 
       0x7b, 0x2, 0x2, 0x23f, 0x23e, 0x3, 0x2, 0x2, 0x2, 0x23f, 0x240, 0x3, 
       0x2, 0x2, 0x2, 0x240, 0x41, 0x3, 0x2, 0x2, 0x2, 0x241, 0x243, 0x7, 
       0x29, 0x2, 0x2, 0x242, 0x244, 0x5, 0xb0, 0x59, 0x2, 0x243, 0x242, 
       0x3, 0x2, 0x2, 0x2, 0x244, 0x245, 0x3, 0x2, 0x2, 0x2, 0x245, 0x243, 
       0x3, 0x2, 0x2, 0x2, 0x245, 0x246, 0x3, 0x2, 0x2, 0x2, 0x246, 0x43, 
       0x3, 0x2, 0x2, 0x2, 0x247, 0x24e, 0x7, 0x31, 0x2, 0x2, 0x248, 0x24c, 
       0x5, 0xb2, 0x5a, 0x2, 0x249, 0x24a, 0x5, 0xb2, 0x5a, 0x2, 0x24a, 
       0x24b, 0x5, 0xb2, 0x5a, 0x2, 0x24b, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x24c, 
       0x249, 0x3, 0x2, 0x2, 0x2, 0x24c, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x24d, 
       0x24f, 0x3, 0x2, 0x2, 0x2, 0x24e, 0x248, 0x3, 0x2, 0x2, 0x2, 0x24e, 
       0x24f, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x250, 0x3, 0x2, 0x2, 0x2, 0x250, 
       0x251, 0x7, 0x7d, 0x2, 0x2, 0x251, 0x252, 0x7, 0x91, 0x2, 0x2, 0x252, 
       0x253, 0x7, 0x92, 0x2, 0x2, 0x253, 0x45, 0x3, 0x2, 0x2, 0x2, 0x254, 
       0x255, 0x7, 0x2a, 0x2, 0x2, 0x255, 0x257, 0x7, 0x74, 0x2, 0x2, 0x256, 
       0x258, 0x5, 0x8a, 0x46, 0x2, 0x257, 0x256, 0x3, 0x2, 0x2, 0x2, 0x258, 
       0x259, 0x3, 0x2, 0x2, 0x2, 0x259, 0x257, 0x3, 0x2, 0x2, 0x2, 0x259, 
       0x25a, 0x3, 0x2, 0x2, 0x2, 0x25a, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x25b, 
       0x25c, 0x7, 0x75, 0x2, 0x2, 0x25c, 0x47, 0x3, 0x2, 0x2, 0x2, 0x25d, 
       0x25e, 0x7, 0xd, 0x2, 0x2, 0x25e, 0x49, 0x3, 0x2, 0x2, 0x2, 0x25f, 
       0x260, 0x7, 0x3e, 0x2, 0x2, 0x260, 0x262, 0x7, 0x74, 0x2, 0x2, 0x261, 
       0x263, 0x5, 0x4c, 0x27, 0x2, 0x262, 0x261, 0x3, 0x2, 0x2, 0x2, 0x263, 
       0x264, 0x3, 0x2, 0x2, 0x2, 0x264, 0x262, 0x3, 0x2, 0x2, 0x2, 0x264, 
       0x265, 0x3, 0x2, 0x2, 0x2, 0x265, 0x266, 0x3, 0x2, 0x2, 0x2, 0x266, 
       0x267, 0x7, 0x75, 0x2, 0x2, 0x267, 0x268, 0x7, 0x3e, 0x2, 0x2, 0x268, 
       0x269, 0x7, 0x79, 0x2, 0x2, 0x269, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x26a, 
       0x26e, 0x5, 0x4e, 0x28, 0x2, 0x26b, 0x26e, 0x5, 0x50, 0x29, 0x2, 
       0x26c, 0x26e, 0x5, 0x6, 0x4, 0x2, 0x26d, 0x26a, 0x3, 0x2, 0x2, 0x2, 
       0x26d, 0x26b, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x26c, 0x3, 0x2, 0x2, 0x2, 
       0x26e, 0x26f, 0x3, 0x2, 0x2, 0x2, 0x26f, 0x270, 0x7, 0x79, 0x2, 0x2, 
       0x270, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x271, 0x273, 0x9, 0x5, 0x2, 0x2, 
       0x272, 0x274, 0x5, 0xae, 0x58, 0x2, 0x273, 0x272, 0x3, 0x2, 0x2, 
       0x2, 0x274, 0x275, 0x3, 0x2, 0x2, 0x2, 0x275, 0x273, 0x3, 0x2, 0x2, 
       0x2, 0x275, 0x276, 0x3, 0x2, 0x2, 0x2, 0x276, 0x4f, 0x3, 0x2, 0x2, 
       0x2, 0x277, 0x278, 0x9, 0x6, 0x2, 0x2, 0x278, 0x27d, 0x5, 0x52, 0x2a, 
       0x2, 0x279, 0x27a, 0x7, 0x7c, 0x2, 0x2, 0x27a, 0x27c, 0x5, 0x52, 
       0x2a, 0x2, 0x27b, 0x279, 0x3, 0x2, 0x2, 0x2, 0x27c, 0x27f, 0x3, 0x2, 
       0x2, 0x2, 0x27d, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x27d, 0x27e, 0x3, 0x2, 
       0x2, 0x2, 0x27e, 0x51, 0x3, 0x2, 0x2, 0x2, 0x27f, 0x27d, 0x3, 0x2, 
       0x2, 0x2, 0x280, 0x281, 0x5, 0xae, 0x58, 0x2, 0x281, 0x283, 0x5, 
       0xae, 0x58, 0x2, 0x282, 0x284, 0x7, 0x86, 0x2, 0x2, 0x283, 0x282, 
       0x3, 0x2, 0x2, 0x2, 0x284, 0x285, 0x3, 0x2, 0x2, 0x2, 0x285, 0x283, 
       0x3, 0x2, 0x2, 0x2, 0x285, 0x286, 0x3, 0x2, 0x2, 0x2, 0x286, 0x53, 
       0x3, 0x2, 0x2, 0x2, 0x287, 0x288, 0x7, 0x43, 0x2, 0x2, 0x288, 0x28a, 
       0x7, 0x74, 0x2, 0x2, 0x289, 0x28b, 0x5, 0x56, 0x2c, 0x2, 0x28a, 0x289, 
       0x3, 0x2, 0x2, 0x2, 0x28b, 0x28c, 0x3, 0x2, 0x2, 0x2, 0x28c, 0x28a, 
       0x3, 0x2, 0x2, 0x2, 0x28c, 0x28d, 0x3, 0x2, 0x2, 0x2, 0x28d, 0x28e, 
       0x3, 0x2, 0x2, 0x2, 0x28e, 0x28f, 0x7, 0x75, 0x2, 0x2, 0x28f, 0x290, 
       0x7, 0x43, 0x2, 0x2, 0x290, 0x291, 0x7, 0x79, 0x2, 0x2, 0x291, 0x55, 
       0x3, 0x2, 0x2, 0x2, 0x292, 0x298, 0x5, 0x58, 0x2d, 0x2, 0x293, 0x298, 
       0x5, 0x5a, 0x2e, 0x2, 0x294, 0x298, 0x5, 0x5c, 0x2f, 0x2, 0x295, 
       0x298, 0x5, 0x5e, 0x30, 0x2, 0x296, 0x298, 0x5, 0x6, 0x4, 0x2, 0x297, 
       0x292, 0x3, 0x2, 0x2, 0x2, 0x297, 0x293, 0x3, 0x2, 0x2, 0x2, 0x297, 
       0x294, 0x3, 0x2, 0x2, 0x2, 0x297, 0x295, 0x3, 0x2, 0x2, 0x2, 0x297, 
       0x296, 0x3, 0x2, 0x2, 0x2, 0x298, 0x299, 0x3, 0x2, 0x2, 0x2, 0x299, 
       0x29a, 0x7, 0x79, 0x2, 0x2, 0x29a, 0x57, 0x3, 0x2, 0x2, 0x2, 0x29b, 
       0x29c, 0x7, 0x44, 0x2, 0x2, 0x29c, 0x29d, 0x5, 0xa0, 0x51, 0x2, 0x29d, 
       0x29e, 0x7, 0x7c, 0x2, 0x2, 0x29e, 0x29f, 0x5, 0xa0, 0x51, 0x2, 0x29f, 
       0x2a0, 0x7, 0x7c, 0x2, 0x2, 0x2a0, 0x2a1, 0x5, 0xa0, 0x51, 0x2, 0x2a1, 
       0x2a2, 0x7, 0x7c, 0x2, 0x2, 0x2a2, 0x2a3, 0x5, 0xa0, 0x51, 0x2, 0x2a3, 
       0x59, 0x3, 0x2, 0x2, 0x2, 0x2a4, 0x2a5, 0x7, 0x45, 0x2, 0x2, 0x2a5, 
       0x2a7, 0x5, 0x98, 0x4d, 0x2, 0x2a6, 0x2a8, 0x7, 0x86, 0x2, 0x2, 0x2a7, 
       0x2a6, 0x3, 0x2, 0x2, 0x2, 0x2a8, 0x2a9, 0x3, 0x2, 0x2, 0x2, 0x2a9, 
       0x2a7, 0x3, 0x2, 0x2, 0x2, 0x2a9, 0x2aa, 0x3, 0x2, 0x2, 0x2, 0x2aa, 
       0x5b, 0x3, 0x2, 0x2, 0x2, 0x2ab, 0x2ac, 0x7, 0x46, 0x2, 0x2, 0x2ac, 
       0x2ae, 0x5, 0x98, 0x4d, 0x2, 0x2ad, 0x2af, 0x7, 0x86, 0x2, 0x2, 0x2ae, 
       0x2ad, 0x3, 0x2, 0x2, 0x2, 0x2af, 0x2b0, 0x3, 0x2, 0x2, 0x2, 0x2b0, 
       0x2ae, 0x3, 0x2, 0x2, 0x2, 0x2b0, 0x2b1, 0x3, 0x2, 0x2, 0x2, 0x2b1, 
       0x5d, 0x3, 0x2, 0x2, 0x2, 0x2b2, 0x2b3, 0x7, 0x47, 0x2, 0x2, 0x2b3, 
       0x2b5, 0x5, 0x98, 0x4d, 0x2, 0x2b4, 0x2b6, 0x7, 0x86, 0x2, 0x2, 0x2b5, 
       0x2b4, 0x3, 0x2, 0x2, 0x2, 0x2b6, 0x2b7, 0x3, 0x2, 0x2, 0x2, 0x2b7, 
       0x2b5, 0x3, 0x2, 0x2, 0x2, 0x2b7, 0x2b8, 0x3, 0x2, 0x2, 0x2, 0x2b8, 
       0x5f, 0x3, 0x2, 0x2, 0x2, 0x2b9, 0x2ba, 0x7, 0x48, 0x2, 0x2, 0x2ba, 
       0x2bd, 0x7, 0x74, 0x2, 0x2, 0x2bb, 0x2bc, 0x7, 0x49, 0x2, 0x2, 0x2bc, 
       0x2be, 0x7, 0x83, 0x2, 0x2, 0x2bd, 0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2bd, 
       0x2be, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2bf, 0x3, 0x2, 0x2, 0x2, 0x2bf, 
       0x2c0, 0x7, 0x79, 0x2, 0x2, 0x2c0, 0x2c1, 0x7, 0x75, 0x2, 0x2, 0x2c1, 
       0x2c2, 0x7, 0x48, 0x2, 0x2, 0x2c2, 0x2c3, 0x7, 0x79, 0x2, 0x2, 0x2c3, 
       0x61, 0x3, 0x2, 0x2, 0x2, 0x2c4, 0x2c5, 0x7, 0x4a, 0x2, 0x2, 0x2c5, 
       0x2c9, 0x7, 0x74, 0x2, 0x2, 0x2c6, 0x2c8, 0x5, 0x64, 0x33, 0x2, 0x2c7, 
       0x2c6, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2cb, 0x3, 0x2, 0x2, 0x2, 0x2c9, 
       0x2c7, 0x3, 0x2, 0x2, 0x2, 0x2c9, 0x2ca, 0x3, 0x2, 0x2, 0x2, 0x2ca, 
       0x2cc, 0x3, 0x2, 0x2, 0x2, 0x2cb, 0x2c9, 0x3, 0x2, 0x2, 0x2, 0x2cc, 
       0x2cd, 0x7, 0x75, 0x2, 0x2, 0x2cd, 0x2ce, 0x7, 0x4a, 0x2, 0x2, 0x2ce, 
       0x2cf, 0x7, 0x79, 0x2, 0x2, 0x2cf, 0x63, 0x3, 0x2, 0x2, 0x2, 0x2d0, 
       0x2d3, 0x5, 0x66, 0x34, 0x2, 0x2d1, 0x2d3, 0x5, 0x6, 0x4, 0x2, 0x2d2, 
       0x2d0, 0x3, 0x2, 0x2, 0x2, 0x2d2, 0x2d1, 0x3, 0x2, 0x2, 0x2, 0x2d3, 
       0x2d4, 0x3, 0x2, 0x2, 0x2, 0x2d4, 0x2d5, 0x7, 0x79, 0x2, 0x2, 0x2d5, 
       0x65, 0x3, 0x2, 0x2, 0x2, 0x2d6, 0x2d7, 0x9, 0x7, 0x2, 0x2, 0x2d7, 
       0x2d8, 0x7, 0x86, 0x2, 0x2, 0x2d8, 0x67, 0x3, 0x2, 0x2, 0x2, 0x2d9, 
       0x2da, 0x7, 0x6d, 0x2, 0x2, 0x2da, 0x2de, 0x7, 0x74, 0x2, 0x2, 0x2db, 
       0x2dd, 0x5, 0x6a, 0x36, 0x2, 0x2dc, 0x2db, 0x3, 0x2, 0x2, 0x2, 0x2dd, 
       0x2e0, 0x3, 0x2, 0x2, 0x2, 0x2de, 0x2dc, 0x3, 0x2, 0x2, 0x2, 0x2de, 
       0x2df, 0x3, 0x2, 0x2, 0x2, 0x2df, 0x2e1, 0x3, 0x2, 0x2, 0x2, 0x2e0, 
       0x2de, 0x3, 0x2, 0x2, 0x2, 0x2e1, 0x2e2, 0x7, 0x75, 0x2, 0x2, 0x2e2, 
       0x2e3, 0x7, 0x6d, 0x2, 0x2, 0x2e3, 0x2e4, 0x7, 0x79, 0x2, 0x2, 0x2e4, 
       0x69, 0x3, 0x2, 0x2, 0x2, 0x2e5, 0x2e8, 0x5, 0x6c, 0x37, 0x2, 0x2e6, 
       0x2e8, 0x5, 0x6, 0x4, 0x2, 0x2e7, 0x2e5, 0x3, 0x2, 0x2, 0x2, 0x2e7, 
       0x2e6, 0x3, 0x2, 0x2, 0x2, 0x2e8, 0x2e9, 0x3, 0x2, 0x2, 0x2, 0x2e9, 
       0x2ea, 0x7, 0x79, 0x2, 0x2, 0x2ea, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x2eb, 
       0x2ec, 0x9, 0x8, 0x2, 0x2, 0x2ec, 0x2ed, 0x7, 0x86, 0x2, 0x2, 0x2ed, 
       0x6d, 0x3, 0x2, 0x2, 0x2, 0x2ee, 0x2ef, 0x7, 0x4f, 0x2, 0x2, 0x2ef, 
       0x2f1, 0x7, 0x74, 0x2, 0x2, 0x2f0, 0x2f2, 0x5, 0x70, 0x39, 0x2, 0x2f1, 
       0x2f0, 0x3, 0x2, 0x2, 0x2, 0x2f2, 0x2f3, 0x3, 0x2, 0x2, 0x2, 0x2f3, 
       0x2f1, 0x3, 0x2, 0x2, 0x2, 0x2f3, 0x2f4, 0x3, 0x2, 0x2, 0x2, 0x2f4, 
       0x2f5, 0x3, 0x2, 0x2, 0x2, 0x2f5, 0x2f6, 0x7, 0x75, 0x2, 0x2, 0x2f6, 
       0x2f7, 0x7, 0x4f, 0x2, 0x2, 0x2f7, 0x2f8, 0x7, 0x79, 0x2, 0x2, 0x2f8, 
       0x6f, 0x3, 0x2, 0x2, 0x2, 0x2f9, 0x2fc, 0x5, 0x72, 0x3a, 0x2, 0x2fa, 
       0x2fc, 0x5, 0x6, 0x4, 0x2, 0x2fb, 0x2f9, 0x3, 0x2, 0x2, 0x2, 0x2fb, 
       0x2fa, 0x3, 0x2, 0x2, 0x2, 0x2fc, 0x2fd, 0x3, 0x2, 0x2, 0x2, 0x2fd, 
       0x2fe, 0x7, 0x79, 0x2, 0x2, 0x2fe, 0x71, 0x3, 0x2, 0x2, 0x2, 0x2ff, 
       0x300, 0x7, 0x50, 0x2, 0x2, 0x300, 0x307, 0x5, 0xb2, 0x5a, 0x2, 0x301, 
       0x305, 0x5, 0xb2, 0x5a, 0x2, 0x302, 0x303, 0x5, 0xb2, 0x5a, 0x2, 
       0x303, 0x304, 0x5, 0xb2, 0x5a, 0x2, 0x304, 0x306, 0x3, 0x2, 0x2, 
       0x2, 0x305, 0x302, 0x3, 0x2, 0x2, 0x2, 0x305, 0x306, 0x3, 0x2, 0x2, 
       0x2, 0x306, 0x308, 0x3, 0x2, 0x2, 0x2, 0x307, 0x301, 0x3, 0x2, 0x2, 
       0x2, 0x307, 0x308, 0x3, 0x2, 0x2, 0x2, 0x308, 0x309, 0x3, 0x2, 0x2, 
       0x2, 0x309, 0x30a, 0x7, 0x7d, 0x2, 0x2, 0x30a, 0x30b, 0x7, 0x91, 
       0x2, 0x2, 0x30b, 0x30c, 0x7, 0x92, 0x2, 0x2, 0x30c, 0x73, 0x3, 0x2, 
       0x2, 0x2, 0x30d, 0x30e, 0x7, 0x51, 0x2, 0x2, 0x30e, 0x310, 0x7, 0x74, 
       0x2, 0x2, 0x30f, 0x311, 0x5, 0x76, 0x3c, 0x2, 0x310, 0x30f, 0x3, 
       0x2, 0x2, 0x2, 0x311, 0x312, 0x3, 0x2, 0x2, 0x2, 0x312, 0x310, 0x3, 
       0x2, 0x2, 0x2, 0x312, 0x313, 0x3, 0x2, 0x2, 0x2, 0x313, 0x314, 0x3, 
       0x2, 0x2, 0x2, 0x314, 0x315, 0x7, 0x75, 0x2, 0x2, 0x315, 0x316, 0x7, 
       0x51, 0x2, 0x2, 0x316, 0x317, 0x7, 0x79, 0x2, 0x2, 0x317, 0x75, 0x3, 
       0x2, 0x2, 0x2, 0x318, 0x31b, 0x5, 0x78, 0x3d, 0x2, 0x319, 0x31b, 
       0x5, 0x6, 0x4, 0x2, 0x31a, 0x318, 0x3, 0x2, 0x2, 0x2, 0x31a, 0x319, 
       0x3, 0x2, 0x2, 0x2, 0x31b, 0x31c, 0x3, 0x2, 0x2, 0x2, 0x31c, 0x31d, 
       0x7, 0x79, 0x2, 0x2, 0x31d, 0x77, 0x3, 0x2, 0x2, 0x2, 0x31e, 0x31f, 
       0x9, 0x9, 0x2, 0x2, 0x31f, 0x33a, 0x7, 0x86, 0x2, 0x2, 0x320, 0x321, 
       0x9, 0xa, 0x2, 0x2, 0x321, 0x33a, 0x7, 0x86, 0x2, 0x2, 0x322, 0x323, 
       0x7, 0x63, 0x2, 0x2, 0x323, 0x33a, 0x5, 0xb2, 0x5a, 0x2, 0x324, 0x325, 
       0x7, 0x60, 0x2, 0x2, 0x325, 0x326, 0x7, 0x7d, 0x2, 0x2, 0x326, 0x327, 
       0x7, 0x91, 0x2, 0x2, 0x327, 0x33a, 0x7, 0x92, 0x2, 0x2, 0x328, 0x329, 
       0x7, 0x56, 0x2, 0x2, 0x329, 0x32a, 0x7, 0x86, 0x2, 0x2, 0x32a, 0x32b, 
       0x7, 0x86, 0x2, 0x2, 0x32b, 0x32c, 0x7, 0x86, 0x2, 0x2, 0x32c, 0x32d, 
       0x7, 0x86, 0x2, 0x2, 0x32d, 0x32e, 0x7, 0x86, 0x2, 0x2, 0x32e, 0x32f, 
       0x7, 0x86, 0x2, 0x2, 0x32f, 0x330, 0x7, 0x86, 0x2, 0x2, 0x330, 0x331, 
       0x7, 0x86, 0x2, 0x2, 0x331, 0x332, 0x7, 0x86, 0x2, 0x2, 0x332, 0x33a, 
       0x7, 0x86, 0x2, 0x2, 0x333, 0x335, 0x9, 0xb, 0x2, 0x2, 0x334, 0x336, 
       0x7, 0x86, 0x2, 0x2, 0x335, 0x334, 0x3, 0x2, 0x2, 0x2, 0x336, 0x337, 
       0x3, 0x2, 0x2, 0x2, 0x337, 0x335, 0x3, 0x2, 0x2, 0x2, 0x337, 0x338, 
       0x3, 0x2, 0x2, 0x2, 0x338, 0x33a, 0x3, 0x2, 0x2, 0x2, 0x339, 0x31e, 
       0x3, 0x2, 0x2, 0x2, 0x339, 0x320, 0x3, 0x2, 0x2, 0x2, 0x339, 0x322, 
       0x3, 0x2, 0x2, 0x2, 0x339, 0x324, 0x3, 0x2, 0x2, 0x2, 0x339, 0x328, 
       0x3, 0x2, 0x2, 0x2, 0x339, 0x333, 0x3, 0x2, 0x2, 0x2, 0x33a, 0x79, 
       0x3, 0x2, 0x2, 0x2, 0x33b, 0x33c, 0x7, 0x64, 0x2, 0x2, 0x33c, 0x33e, 
       0x7, 0x74, 0x2, 0x2, 0x33d, 0x33f, 0x5, 0x7c, 0x3f, 0x2, 0x33e, 0x33d, 
       0x3, 0x2, 0x2, 0x2, 0x33f, 0x340, 0x3, 0x2, 0x2, 0x2, 0x340, 0x33e, 
       0x3, 0x2, 0x2, 0x2, 0x340, 0x341, 0x3, 0x2, 0x2, 0x2, 0x341, 0x342, 
       0x3, 0x2, 0x2, 0x2, 0x342, 0x343, 0x7, 0x75, 0x2, 0x2, 0x343, 0x344, 
       0x7, 0x64, 0x2, 0x2, 0x344, 0x345, 0x7, 0x79, 0x2, 0x2, 0x345, 0x7b, 
       0x3, 0x2, 0x2, 0x2, 0x346, 0x34c, 0x5, 0x7e, 0x40, 0x2, 0x347, 0x34c, 
       0x5, 0x80, 0x41, 0x2, 0x348, 0x34c, 0x5, 0x88, 0x45, 0x2, 0x349, 
       0x34c, 0x5, 0x8c, 0x47, 0x2, 0x34a, 0x34c, 0x5, 0x6, 0x4, 0x2, 0x34b, 
       0x346, 0x3, 0x2, 0x2, 0x2, 0x34b, 0x347, 0x3, 0x2, 0x2, 0x2, 0x34b, 
       0x348, 0x3, 0x2, 0x2, 0x2, 0x34b, 0x349, 0x3, 0x2, 0x2, 0x2, 0x34b, 
       0x34a, 0x3, 0x2, 0x2, 0x2, 0x34c, 0x34d, 0x3, 0x2, 0x2, 0x2, 0x34d, 
       0x34e, 0x7, 0x79, 0x2, 0x2, 0x34e, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x34f, 
       0x350, 0x7, 0x67, 0x2, 0x2, 0x350, 0x351, 0x5, 0xae, 0x58, 0x2, 0x351, 
       0x352, 0x7, 0x86, 0x2, 0x2, 0x352, 0x354, 0x7, 0x74, 0x2, 0x2, 0x353, 
       0x355, 0x5, 0x8a, 0x46, 0x2, 0x354, 0x353, 0x3, 0x2, 0x2, 0x2, 0x355, 
       0x356, 0x3, 0x2, 0x2, 0x2, 0x356, 0x354, 0x3, 0x2, 0x2, 0x2, 0x356, 
       0x357, 0x3, 0x2, 0x2, 0x2, 0x357, 0x358, 0x3, 0x2, 0x2, 0x2, 0x358, 
       0x359, 0x7, 0x75, 0x2, 0x2, 0x359, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x35a, 
       0x35b, 0x7, 0x68, 0x2, 0x2, 0x35b, 0x35d, 0x7, 0x74, 0x2, 0x2, 0x35c, 
       0x35e, 0x5, 0x82, 0x42, 0x2, 0x35d, 0x35c, 0x3, 0x2, 0x2, 0x2, 0x35e, 
       0x35f, 0x3, 0x2, 0x2, 0x2, 0x35f, 0x35d, 0x3, 0x2, 0x2, 0x2, 0x35f, 
       0x360, 0x3, 0x2, 0x2, 0x2, 0x360, 0x361, 0x3, 0x2, 0x2, 0x2, 0x361, 
       0x362, 0x7, 0x75, 0x2, 0x2, 0x362, 0x81, 0x3, 0x2, 0x2, 0x2, 0x363, 
       0x368, 0x5, 0x8e, 0x48, 0x2, 0x364, 0x368, 0x5, 0x84, 0x43, 0x2, 
       0x365, 0x368, 0x5, 0x86, 0x44, 0x2, 0x366, 0x368, 0x5, 0x6, 0x4, 
       0x2, 0x367, 0x363, 0x3, 0x2, 0x2, 0x2, 0x367, 0x364, 0x3, 0x2, 0x2, 
       0x2, 0x367, 0x365, 0x3, 0x2, 0x2, 0x2, 0x367, 0x366, 0x3, 0x2, 0x2, 
       0x2, 0x368, 0x369, 0x3, 0x2, 0x2, 0x2, 0x369, 0x36a, 0x7, 0x79, 0x2, 
       0x2, 0x36a, 0x83, 0x3, 0x2, 0x2, 0x2, 0x36b, 0x36c, 0x7, 0x6a, 0x2, 
       0x2, 0x36c, 0x36d, 0x5, 0xae, 0x58, 0x2, 0x36d, 0x372, 0x5, 0xb0, 
       0x59, 0x2, 0x36e, 0x370, 0x5, 0xb0, 0x59, 0x2, 0x36f, 0x371, 0x5, 
       0xb0, 0x59, 0x2, 0x370, 0x36f, 0x3, 0x2, 0x2, 0x2, 0x370, 0x371, 
       0x3, 0x2, 0x2, 0x2, 0x371, 0x373, 0x3, 0x2, 0x2, 0x2, 0x372, 0x36e, 
       0x3, 0x2, 0x2, 0x2, 0x372, 0x373, 0x3, 0x2, 0x2, 0x2, 0x373, 0x85, 
       0x3, 0x2, 0x2, 0x2, 0x374, 0x376, 0x7, 0x69, 0x2, 0x2, 0x375, 0x377, 
       0x9, 0xc, 0x2, 0x2, 0x376, 0x375, 0x3, 0x2, 0x2, 0x2, 0x377, 0x378, 
       0x3, 0x2, 0x2, 0x2, 0x378, 0x376, 0x3, 0x2, 0x2, 0x2, 0x378, 0x379, 
       0x3, 0x2, 0x2, 0x2, 0x379, 0x87, 0x3, 0x2, 0x2, 0x2, 0x37a, 0x37b, 
       0x7, 0x65, 0x2, 0x2, 0x37b, 0x37d, 0x7, 0x74, 0x2, 0x2, 0x37c, 0x37e, 
       0x5, 0x8a, 0x46, 0x2, 0x37d, 0x37c, 0x3, 0x2, 0x2, 0x2, 0x37e, 0x37f, 
       0x3, 0x2, 0x2, 0x2, 0x37f, 0x37d, 0x3, 0x2, 0x2, 0x2, 0x37f, 0x380, 
       0x3, 0x2, 0x2, 0x2, 0x380, 0x381, 0x3, 0x2, 0x2, 0x2, 0x381, 0x382, 
       0x7, 0x75, 0x2, 0x2, 0x382, 0x89, 0x3, 0x2, 0x2, 0x2, 0x383, 0x386, 
       0x5, 0x8e, 0x48, 0x2, 0x384, 0x386, 0x5, 0x6, 0x4, 0x2, 0x385, 0x383, 
       0x3, 0x2, 0x2, 0x2, 0x385, 0x384, 0x3, 0x2, 0x2, 0x2, 0x386, 0x387, 
       0x3, 0x2, 0x2, 0x2, 0x387, 0x388, 0x7, 0x79, 0x2, 0x2, 0x388, 0x8b, 
       0x3, 0x2, 0x2, 0x2, 0x389, 0x38a, 0x7, 0x66, 0x2, 0x2, 0x38a, 0x38b, 
       0x5, 0xb2, 0x5a, 0x2, 0x38b, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x38c, 0x393, 
       0x7, 0x4f, 0x2, 0x2, 0x38d, 0x391, 0x5, 0xb2, 0x5a, 0x2, 0x38e, 0x38f, 
       0x5, 0xb2, 0x5a, 0x2, 0x38f, 0x390, 0x5, 0xb2, 0x5a, 0x2, 0x390, 
       0x392, 0x3, 0x2, 0x2, 0x2, 0x391, 0x38e, 0x3, 0x2, 0x2, 0x2, 0x391, 
       0x392, 0x3, 0x2, 0x2, 0x2, 0x392, 0x394, 0x3, 0x2, 0x2, 0x2, 0x393, 
       0x38d, 0x3, 0x2, 0x2, 0x2, 0x393, 0x394, 0x3, 0x2, 0x2, 0x2, 0x394, 
       0x395, 0x3, 0x2, 0x2, 0x2, 0x395, 0x396, 0x7, 0x7d, 0x2, 0x2, 0x396, 
       0x397, 0x7, 0x91, 0x2, 0x2, 0x397, 0x398, 0x7, 0x92, 0x2, 0x2, 0x398, 
       0x8f, 0x3, 0x2, 0x2, 0x2, 0x399, 0x39a, 0x7, 0x71, 0x2, 0x2, 0x39a, 
       0x39c, 0x7, 0x74, 0x2, 0x2, 0x39b, 0x39d, 0x5, 0x92, 0x4a, 0x2, 0x39c, 
       0x39b, 0x3, 0x2, 0x2, 0x2, 0x39d, 0x39e, 0x3, 0x2, 0x2, 0x2, 0x39e, 
       0x39c, 0x3, 0x2, 0x2, 0x2, 0x39e, 0x39f, 0x3, 0x2, 0x2, 0x2, 0x39f, 
       0x3a0, 0x3, 0x2, 0x2, 0x2, 0x3a0, 0x3a1, 0x7, 0x75, 0x2, 0x2, 0x3a1, 
       0x3a2, 0x7, 0x71, 0x2, 0x2, 0x3a2, 0x3a3, 0x7, 0x79, 0x2, 0x2, 0x3a3, 
       0x91, 0x3, 0x2, 0x2, 0x2, 0x3a4, 0x3a7, 0x5, 0x94, 0x4b, 0x2, 0x3a5, 
       0x3a7, 0x5, 0x6, 0x4, 0x2, 0x3a6, 0x3a4, 0x3, 0x2, 0x2, 0x2, 0x3a6, 
       0x3a5, 0x3, 0x2, 0x2, 0x2, 0x3a7, 0x3a8, 0x3, 0x2, 0x2, 0x2, 0x3a8, 
       0x3a9, 0x7, 0x79, 0x2, 0x2, 0x3a9, 0x93, 0x3, 0x2, 0x2, 0x2, 0x3aa, 
       0x3ab, 0x9, 0xd, 0x2, 0x2, 0x3ab, 0x3ac, 0x5, 0xa8, 0x55, 0x2, 0x3ac, 
       0x3ad, 0x7, 0x86, 0x2, 0x2, 0x3ad, 0x95, 0x3, 0x2, 0x2, 0x2, 0x3ae, 
       0x3af, 0x7, 0x1b, 0x2, 0x2, 0x3af, 0x3b8, 0x7, 0x33, 0x2, 0x2, 0x3b0, 
       0x3b1, 0x7, 0x86, 0x2, 0x2, 0x3b1, 0x3b4, 0x7, 0x86, 0x2, 0x2, 0x3b2, 
       0x3b3, 0x7, 0x32, 0x2, 0x2, 0x3b3, 0x3b5, 0x7, 0x86, 0x2, 0x2, 0x3b4, 
       0x3b2, 0x3, 0x2, 0x2, 0x2, 0x3b4, 0x3b5, 0x3, 0x2, 0x2, 0x2, 0x3b5, 
       0x3b9, 0x3, 0x2, 0x2, 0x2, 0x3b6, 0x3b9, 0x7, 0x3d, 0x2, 0x2, 0x3b7, 
       0x3b9, 0x5, 0xac, 0x57, 0x2, 0x3b8, 0x3b0, 0x3, 0x2, 0x2, 0x2, 0x3b8, 
       0x3b6, 0x3, 0x2, 0x2, 0x2, 0x3b8, 0x3b7, 0x3, 0x2, 0x2, 0x2, 0x3b9, 
       0x3ba, 0x3, 0x2, 0x2, 0x2, 0x3ba, 0x3bb, 0x7, 0x1c, 0x2, 0x2, 0x3bb, 
       0x97, 0x3, 0x2, 0x2, 0x2, 0x3bc, 0x3be, 0x5, 0x9a, 0x4e, 0x2, 0x3bd, 
       0x3bc, 0x3, 0x2, 0x2, 0x2, 0x3be, 0x3bf, 0x3, 0x2, 0x2, 0x2, 0x3bf, 
       0x3bd, 0x3, 0x2, 0x2, 0x2, 0x3bf, 0x3c0, 0x3, 0x2, 0x2, 0x2, 0x3c0, 
       0x99, 0x3, 0x2, 0x2, 0x2, 0x3c1, 0x3c6, 0x5, 0x9e, 0x50, 0x2, 0x3c2, 
       0x3c3, 0x7, 0xe, 0x2, 0x2, 0x3c3, 0x3c5, 0x5, 0xac, 0x57, 0x2, 0x3c4, 
       0x3c2, 0x3, 0x2, 0x2, 0x2, 0x3c5, 0x3c8, 0x3, 0x2, 0x2, 0x2, 0x3c6, 
       0x3c4, 0x3, 0x2, 0x2, 0x2, 0x3c6, 0x3c7, 0x3, 0x2, 0x2, 0x2, 0x3c7, 
       0x9b, 0x3, 0x2, 0x2, 0x2, 0x3c8, 0x3c6, 0x3, 0x2, 0x2, 0x2, 0x3c9, 
       0x3cb, 0x5, 0x9e, 0x50, 0x2, 0x3ca, 0x3c9, 0x3, 0x2, 0x2, 0x2, 0x3cb, 
       0x3cc, 0x3, 0x2, 0x2, 0x2, 0x3cc, 0x3ca, 0x3, 0x2, 0x2, 0x2, 0x3cc, 
       0x3cd, 0x3, 0x2, 0x2, 0x2, 0x3cd, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x3ce, 
       0x3d1, 0x5, 0xa2, 0x52, 0x2, 0x3cf, 0x3d1, 0x5, 0xa8, 0x55, 0x2, 
       0x3d0, 0x3ce, 0x3, 0x2, 0x2, 0x2, 0x3d0, 0x3cf, 0x3, 0x2, 0x2, 0x2, 
       0x3d1, 0x3d3, 0x3, 0x2, 0x2, 0x2, 0x3d2, 0x3d4, 0x7, 0x7b, 0x2, 0x2, 
       0x3d3, 0x3d2, 0x3, 0x2, 0x2, 0x2, 0x3d3, 0x3d4, 0x3, 0x2, 0x2, 0x2, 
       0x3d4, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x3d5, 0x3d7, 0x5, 0xa2, 0x52, 0x2, 
       0x3d6, 0x3d5, 0x3, 0x2, 0x2, 0x2, 0x3d6, 0x3d7, 0x3, 0x2, 0x2, 0x2, 
       0x3d7, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x3d8, 0x3db, 0x7, 0x7e, 0x2, 0x2, 
       0x3d9, 0x3db, 0x5, 0xa4, 0x53, 0x2, 0x3da, 0x3d8, 0x3, 0x2, 0x2, 
       0x2, 0x3da, 0x3d9, 0x3, 0x2, 0x2, 0x2, 0x3db, 0xa3, 0x3, 0x2, 0x2, 
       0x2, 0x3dc, 0x3de, 0x7, 0x76, 0x2, 0x2, 0x3dd, 0x3df, 0x5, 0xa6, 
       0x54, 0x2, 0x3de, 0x3dd, 0x3, 0x2, 0x2, 0x2, 0x3df, 0x3e0, 0x3, 0x2, 
       0x2, 0x2, 0x3e0, 0x3de, 0x3, 0x2, 0x2, 0x2, 0x3e0, 0x3e1, 0x3, 0x2, 
       0x2, 0x2, 0x3e1, 0x3e2, 0x3, 0x2, 0x2, 0x2, 0x3e2, 0x3e3, 0x7, 0x77, 
       0x2, 0x2, 0x3e3, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x3e4, 0x3e7, 0x5, 0xa8, 
       0x55, 0x2, 0x3e5, 0x3e6, 0x7, 0x78, 0x2, 0x2, 0x3e6, 0x3e8, 0x5, 
       0xa8, 0x55, 0x2, 0x3e7, 0x3e5, 0x3, 0x2, 0x2, 0x2, 0x3e7, 0x3e8, 
       0x3, 0x2, 0x2, 0x2, 0x3e8, 0x3eb, 0x3, 0x2, 0x2, 0x2, 0x3e9, 0x3eb, 
       0x7, 0x7e, 0x2, 0x2, 0x3ea, 0x3e4, 0x3, 0x2, 0x2, 0x2, 0x3ea, 0x3e9, 
       0x3, 0x2, 0x2, 0x2, 0x3eb, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x3ec, 0x3ef, 
       0x5, 0xaa, 0x56, 0x2, 0x3ed, 0x3ef, 0x7, 0x7f, 0x2, 0x2, 0x3ee, 0x3ec, 
       0x3, 0x2, 0x2, 0x2, 0x3ee, 0x3ed, 0x3, 0x2, 0x2, 0x2, 0x3ef, 0xa9, 
       0x3, 0x2, 0x2, 0x2, 0x3f0, 0x3f1, 0x9, 0xe, 0x2, 0x2, 0x3f1, 0xab, 
       0x3, 0x2, 0x2, 0x2, 0x3f2, 0x3f3, 0x7, 0x81, 0x2, 0x2, 0x3f3, 0xad, 
       0x3, 0x2, 0x2, 0x2, 0x3f4, 0x3f5, 0x9, 0xf, 0x2, 0x2, 0x3f5, 0xaf, 
       0x3, 0x2, 0x2, 0x2, 0x3f6, 0x3f7, 0x9, 0x10, 0x2, 0x2, 0x3f7, 0xb1, 
       0x3, 0x2, 0x2, 0x2, 0x3f8, 0x3f9, 0x9, 0x11, 0x2, 0x2, 0x3f9, 0xb3, 
       0x3, 0x2, 0x2, 0x2, 0x3fa, 0x3fc, 0x5, 0x1a, 0xe, 0x2, 0x3fb, 0x3fa, 
       0x3, 0x2, 0x2, 0x2, 0x3fc, 0x3ff, 0x3, 0x2, 0x2, 0x2, 0x3fd, 0x3fb, 
       0x3, 0x2, 0x2, 0x2, 0x3fd, 0x3fe, 0x3, 0x2, 0x2, 0x2, 0x3fe, 0x400, 
       0x3, 0x2, 0x2, 0x2, 0x3ff, 0x3fd, 0x3, 0x2, 0x2, 0x2, 0x400, 0x401, 
       0x7, 0x2, 0x2, 0x3, 0x401, 0xb5, 0x3, 0x2, 0x2, 0x2, 0x402, 0x404, 
       0x5, 0x24, 0x13, 0x2, 0x403, 0x402, 0x3, 0x2, 0x2, 0x2, 0x404, 0x407, 
       0x3, 0x2, 0x2, 0x2, 0x405, 0x403, 0x3, 0x2, 0x2, 0x2, 0x405, 0x406, 
       0x3, 0x2, 0x2, 0x2, 0x406, 0x408, 0x3, 0x2, 0x2, 0x2, 0x407, 0x405, 
       0x3, 0x2, 0x2, 0x2, 0x408, 0x409, 0x7, 0x2, 0x2, 0x3, 0x409, 0xb7, 
       0x3, 0x2, 0x2, 0x2, 0x40a, 0x40c, 0x5, 0x20, 0x11, 0x2, 0x40b, 0x40a, 
       0x3, 0x2, 0x2, 0x2, 0x40c, 0x40f, 0x3, 0x2, 0x2, 0x2, 0x40d, 0x40b, 
       0x3, 0x2, 0x2, 0x2, 0x40d, 0x40e, 0x3, 0x2, 0x2, 0x2, 0x40e, 0x410, 
       0x3, 0x2, 0x2, 0x2, 0x40f, 0x40d, 0x3, 0x2, 0x2, 0x2, 0x410, 0x411, 
       0x7, 0x2, 0x2, 0x3, 0x411, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x412, 0x414, 
       0x5, 0x4c, 0x27, 0x2, 0x413, 0x412, 0x3, 0x2, 0x2, 0x2, 0x414, 0x417, 
       0x3, 0x2, 0x2, 0x2, 0x415, 0x413, 0x3, 0x2, 0x2, 0x2, 0x415, 0x416, 
       0x3, 0x2, 0x2, 0x2, 0x416, 0x418, 0x3, 0x2, 0x2, 0x2, 0x417, 0x415, 
       0x3, 0x2, 0x2, 0x2, 0x418, 0x419, 0x7, 0x2, 0x2, 0x3, 0x419, 0xbb, 
       0x3, 0x2, 0x2, 0x2, 0x41a, 0x41c, 0x5, 0x64, 0x33, 0x2, 0x41b, 0x41a, 
       0x3, 0x2, 0x2, 0x2, 0x41c, 0x41f, 0x3, 0x2, 0x2, 0x2, 0x41d, 0x41b, 
       0x3, 0x2, 0x2, 0x2, 0x41d, 0x41e, 0x3, 0x2, 0x2, 0x2, 0x41e, 0x420, 
       0x3, 0x2, 0x2, 0x2, 0x41f, 0x41d, 0x3, 0x2, 0x2, 0x2, 0x420, 0x421, 
       0x7, 0x2, 0x2, 0x3, 0x421, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x422, 0x424, 
       0x5, 0x6a, 0x36, 0x2, 0x423, 0x422, 0x3, 0x2, 0x2, 0x2, 0x424, 0x427, 
       0x3, 0x2, 0x2, 0x2, 0x425, 0x423, 0x3, 0x2, 0x2, 0x2, 0x425, 0x426, 
       0x3, 0x2, 0x2, 0x2, 0x426, 0x428, 0x3, 0x2, 0x2, 0x2, 0x427, 0x425, 
       0x3, 0x2, 0x2, 0x2, 0x428, 0x429, 0x7, 0x2, 0x2, 0x3, 0x429, 0xbf, 
       0x3, 0x2, 0x2, 0x2, 0x42a, 0x42c, 0x5, 0x56, 0x2c, 0x2, 0x42b, 0x42a, 
       0x3, 0x2, 0x2, 0x2, 0x42c, 0x42f, 0x3, 0x2, 0x2, 0x2, 0x42d, 0x42b, 
       0x3, 0x2, 0x2, 0x2, 0x42d, 0x42e, 0x3, 0x2, 0x2, 0x2, 0x42e, 0x430, 
       0x3, 0x2, 0x2, 0x2, 0x42f, 0x42d, 0x3, 0x2, 0x2, 0x2, 0x430, 0x431, 
       0x7, 0x2, 0x2, 0x3, 0x431, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x432, 0x434, 
       0x5, 0x70, 0x39, 0x2, 0x433, 0x432, 0x3, 0x2, 0x2, 0x2, 0x434, 0x437, 
       0x3, 0x2, 0x2, 0x2, 0x435, 0x433, 0x3, 0x2, 0x2, 0x2, 0x435, 0x436, 
       0x3, 0x2, 0x2, 0x2, 0x436, 0x438, 0x3, 0x2, 0x2, 0x2, 0x437, 0x435, 
       0x3, 0x2, 0x2, 0x2, 0x438, 0x439, 0x7, 0x2, 0x2, 0x3, 0x439, 0xc3, 
       0x3, 0x2, 0x2, 0x2, 0x43a, 0x43c, 0x5, 0x92, 0x4a, 0x2, 0x43b, 0x43a, 
       0x3, 0x2, 0x2, 0x2, 0x43c, 0x43f, 0x3, 0x2, 0x2, 0x2, 0x43d, 0x43b, 
       0x3, 0x2, 0x2, 0x2, 0x43d, 0x43e, 0x3, 0x2, 0x2, 0x2, 0x43e, 0x440, 
       0x3, 0x2, 0x2, 0x2, 0x43f, 0x43d, 0x3, 0x2, 0x2, 0x2, 0x440, 0x441, 
       0x7, 0x2, 0x2, 0x3, 0x441, 0xc5, 0x3, 0x2, 0x2, 0x2, 0x442, 0x444, 
       0x5, 0x76, 0x3c, 0x2, 0x443, 0x442, 0x3, 0x2, 0x2, 0x2, 0x444, 0x447, 
       0x3, 0x2, 0x2, 0x2, 0x445, 0x443, 0x3, 0x2, 0x2, 0x2, 0x445, 0x446, 
       0x3, 0x2, 0x2, 0x2, 0x446, 0x448, 0x3, 0x2, 0x2, 0x2, 0x447, 0x445, 
       0x3, 0x2, 0x2, 0x2, 0x448, 0x449, 0x7, 0x2, 0x2, 0x3, 0x449, 0xc7, 
       0x3, 0x2, 0x2, 0x2, 0x44a, 0x44c, 0x5, 0x7c, 0x3f, 0x2, 0x44b, 0x44a, 
       0x3, 0x2, 0x2, 0x2, 0x44c, 0x44f, 0x3, 0x2, 0x2, 0x2, 0x44d, 0x44b, 
       0x3, 0x2, 0x2, 0x2, 0x44d, 0x44e, 0x3, 0x2, 0x2, 0x2, 0x44e, 0x450, 
       0x3, 0x2, 0x2, 0x2, 0x44f, 0x44d, 0x3, 0x2, 0x2, 0x2, 0x450, 0x451, 
       0x7, 0x2, 0x2, 0x3, 0x451, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x452, 0x454, 
       0x5, 0x82, 0x42, 0x2, 0x453, 0x452, 0x3, 0x2, 0x2, 0x2, 0x454, 0x457, 
       0x3, 0x2, 0x2, 0x2, 0x455, 0x453, 0x3, 0x2, 0x2, 0x2, 0x455, 0x456, 
       0x3, 0x2, 0x2, 0x2, 0x456, 0x458, 0x3, 0x2, 0x2, 0x2, 0x457, 0x455, 
       0x3, 0x2, 0x2, 0x2, 0x458, 0x459, 0x7, 0x2, 0x2, 0x3, 0x459, 0xcb, 
       0x3, 0x2, 0x2, 0x2, 0x45a, 0x45c, 0x5, 0x8a, 0x46, 0x2, 0x45b, 0x45a, 
       0x3, 0x2, 0x2, 0x2, 0x45c, 0x45f, 0x3, 0x2, 0x2, 0x2, 0x45d, 0x45b, 
       0x3, 0x2, 0x2, 0x2, 0x45d, 0x45e, 0x3, 0x2, 0x2, 0x2, 0x45e, 0x460, 
       0x3, 0x2, 0x2, 0x2, 0x45f, 0x45d, 0x3, 0x2, 0x2, 0x2, 0x460, 0x461, 
       0x7, 0x2, 0x2, 0x3, 0x461, 0xcd, 0x3, 0x2, 0x2, 0x2, 0x462, 0x463, 
       0x9, 0x12, 0x2, 0x2, 0x463, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x464, 0x465, 
       0x9, 0x13, 0x2, 0x2, 0x465, 0xd1, 0x3, 0x2, 0x2, 0x2, 0x466, 0x467, 
       0x9, 0x14, 0x2, 0x2, 0x467, 0xd3, 0x3, 0x2, 0x2, 0x2, 0x468, 0x469, 
       0x9, 0x15, 0x2, 0x2, 0x469, 0xd5, 0x3, 0x2, 0x2, 0x2, 0x46a, 0x46b, 
       0x9, 0x16, 0x2, 0x2, 0x46b, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x46c, 0x46d, 
       0x9, 0x17, 0x2, 0x2, 0x46d, 0xd9, 0x3, 0x2, 0x2, 0x2, 0x7a, 0xdf, 
       0xe1, 0xec, 0x100, 0x10a, 0x115, 0x11b, 0x12b, 0x133, 0x13b, 0x141, 
       0x14a, 0x14f, 0x155, 0x15a, 0x163, 0x16b, 0x174, 0x17a, 0x18a, 0x197, 
       0x19e, 0x1a0, 0x1aa, 0x1b0, 0x1b7, 0x1c0, 0x1c3, 0x1ca, 0x1cc, 0x1d3, 
       0x1d5, 0x1d7, 0x1da, 0x1de, 0x1e4, 0x1eb, 0x1f0, 0x1f6, 0x1fd, 0x200, 
       0x207, 0x20a, 0x211, 0x214, 0x216, 0x21a, 0x221, 0x22a, 0x234, 0x239, 
       0x23c, 0x23f, 0x245, 0x24c, 0x24e, 0x259, 0x264, 0x26d, 0x275, 0x27d, 
       0x285, 0x28c, 0x297, 0x2a9, 0x2b0, 0x2b7, 0x2bd, 0x2c9, 0x2d2, 0x2de, 
       0x2e7, 0x2f3, 0x2fb, 0x305, 0x307, 0x312, 0x31a, 0x337, 0x339, 0x340, 
       0x34b, 0x356, 0x35f, 0x367, 0x370, 0x372, 0x378, 0x37f, 0x385, 0x391, 
       0x393, 0x39e, 0x3a6, 0x3b4, 0x3b8, 0x3bf, 0x3c6, 0x3cc, 0x3d0, 0x3d3, 
       0x3d6, 0x3da, 0x3e0, 0x3e7, 0x3ea, 0x3ee, 0x3fd, 0x405, 0x40d, 0x415, 
       0x41d, 0x425, 0x42d, 0x435, 0x43d, 0x445, 0x44d, 0x455, 0x45d, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

FeatParser::Initializer FeatParser::_init;
