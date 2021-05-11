
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


//----------------- FeatureFileContext ------------------------------------------------------------------

FeatParser::FeatureFileContext::FeatureFileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::FeatureFileContext::EOF() {
  return getToken(FeatParser::EOF, 0);
}

std::vector<FeatParser::TopLevelStatementContext *> FeatParser::FeatureFileContext::topLevelStatement() {
  return getRuleContexts<FeatParser::TopLevelStatementContext>();
}

FeatParser::TopLevelStatementContext* FeatParser::FeatureFileContext::topLevelStatement(size_t i) {
  return getRuleContext<FeatParser::TopLevelStatementContext>(i);
}

std::vector<FeatParser::AnonBlockContext *> FeatParser::FeatureFileContext::anonBlock() {
  return getRuleContexts<FeatParser::AnonBlockContext>();
}

FeatParser::AnonBlockContext* FeatParser::FeatureFileContext::anonBlock(size_t i) {
  return getRuleContext<FeatParser::AnonBlockContext>(i);
}

std::vector<FeatParser::FeatureBlockContext *> FeatParser::FeatureFileContext::featureBlock() {
  return getRuleContexts<FeatParser::FeatureBlockContext>();
}

FeatParser::FeatureBlockContext* FeatParser::FeatureFileContext::featureBlock(size_t i) {
  return getRuleContext<FeatParser::FeatureBlockContext>(i);
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
  enterRule(_localctx, 0, FeatParser::RuleFeatureFile);
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
    setState(47);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FeatParser::ANON)
      | (1ULL << FeatParser::ANONV)
      | (1ULL << FeatParser::FEATURE)
      | (1ULL << FeatParser::LANGSYS)
      | (1ULL << FeatParser::INCLUDE))) != 0)) {
      setState(45);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case FeatParser::LANGSYS:
        case FeatParser::INCLUDE: {
          setState(42);
          topLevelStatement();
          break;
        }

        case FeatParser::ANON:
        case FeatParser::ANONV: {
          setState(43);
          anonBlock();
          break;
        }

        case FeatParser::FEATURE: {
          setState(44);
          featureBlock();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(49);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(50);
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
  enterRule(_localctx, 2, FeatParser::RuleStatementFile);
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
    setState(55);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FeatParser::FEATURE)
      | (1ULL << FeatParser::SUB)
      | (1ULL << FeatParser::SUBV)
      | (1ULL << FeatParser::REV)
      | (1ULL << FeatParser::REVV)
      | (1ULL << FeatParser::INCLUDE))) != 0)) {
      setState(52);
      statement();
      setState(57);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(58);
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

FeatParser::LangsysAssignContext* FeatParser::TopLevelStatementContext::langsysAssign() {
  return getRuleContext<FeatParser::LangsysAssignContext>(0);
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
  enterRule(_localctx, 4, FeatParser::RuleTopLevelStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(62);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::INCLUDE: {
        setState(60);
        include();
        break;
      }

      case FeatParser::LANGSYS: {
        setState(61);
        langsysAssign();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(64);
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
  enterRule(_localctx, 6, FeatParser::RuleInclude);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    match(FeatParser::INCLUDE);
    setState(67);
    match(FeatParser::I_RPAREN);
    setState(68);
    match(FeatParser::IFILE);
    setState(69);
    match(FeatParser::I_LPAREN);
   
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
    setState(71);
    match(FeatParser::LANGSYS);
    setState(72);
    dynamic_cast<LangsysAssignContext *>(_localctx)->script = tag();
    setState(73);
    dynamic_cast<LangsysAssignContext *>(_localctx)->lang = tag();
   
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
  enterRule(_localctx, 10, FeatParser::RuleAnonBlock);
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
    setState(75);
    anontok();
    setState(76);
    match(FeatParser::A_LABEL);
    setState(77);
    match(FeatParser::A_LBRACE);
    setState(81);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FeatParser::A_LINE) {
      setState(78);
      match(FeatParser::A_LINE);
      setState(83);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(84);
    match(FeatParser::A_CLOSE);
   
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

std::vector<FeatParser::StatementContext *> FeatParser::FeatureBlockContext::statement() {
  return getRuleContexts<FeatParser::StatementContext>();
}

FeatParser::StatementContext* FeatParser::FeatureBlockContext::statement(size_t i) {
  return getRuleContext<FeatParser::StatementContext>(i);
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
  enterRule(_localctx, 12, FeatParser::RuleFeatureBlock);
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
    setState(86);
    match(FeatParser::FEATURE);
    setState(87);
    dynamic_cast<FeatureBlockContext *>(_localctx)->starttag = tag();
    setState(88);
    match(FeatParser::LCBRACE);
    setState(90); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(89);
      statement();
      setState(92); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FeatParser::FEATURE)
      | (1ULL << FeatParser::SUB)
      | (1ULL << FeatParser::SUBV)
      | (1ULL << FeatParser::REV)
      | (1ULL << FeatParser::REVV)
      | (1ULL << FeatParser::INCLUDE))) != 0));
    setState(94);
    match(FeatParser::RCBRACE);
    setState(95);
    dynamic_cast<FeatureBlockContext *>(_localctx)->endtag = tag();
    setState(96);
    match(FeatParser::SEMI);
   
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

FeatParser::SubstituteContext* FeatParser::StatementContext::substitute() {
  return getRuleContext<FeatParser::SubstituteContext>(0);
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
  enterRule(_localctx, 14, FeatParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::FEATURE: {
        setState(98);
        featureUse();
        break;
      }

      case FeatParser::SUB:
      case FeatParser::SUBV:
      case FeatParser::REV:
      case FeatParser::REVV: {
        setState(99);
        substitute();
        break;
      }

      case FeatParser::INCLUDE: {
        setState(100);
        include();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(103);
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
  enterRule(_localctx, 16, FeatParser::RuleFeatureUse);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(105);
    match(FeatParser::FEATURE);
    setState(106);
    tag();
   
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

tree::TerminalNode* FeatParser::SubstituteContext::BY() {
  return getToken(FeatParser::BY, 0);
}

std::vector<FeatParser::PatternContext *> FeatParser::SubstituteContext::pattern() {
  return getRuleContexts<FeatParser::PatternContext>();
}

FeatParser::PatternContext* FeatParser::SubstituteContext::pattern(size_t i) {
  return getRuleContext<FeatParser::PatternContext>(i);
}

tree::TerminalNode* FeatParser::SubstituteContext::KNULL() {
  return getToken(FeatParser::KNULL, 0);
}

FeatParser::SubtokContext* FeatParser::SubstituteContext::subtok() {
  return getRuleContext<FeatParser::SubtokContext>(0);
}

tree::TerminalNode* FeatParser::SubstituteContext::FROM() {
  return getToken(FeatParser::FROM, 0);
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
  enterRule(_localctx, 18, FeatParser::RuleSubstitute);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(122);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::REV:
      case FeatParser::REVV: {
        enterOuterAlt(_localctx, 1);
        setState(108);
        revtok();
        setState(109);
        dynamic_cast<SubstituteContext *>(_localctx)->startpat = pattern();
        setState(110);
        match(FeatParser::BY);
        setState(113);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case FeatParser::KNULL: {
            setState(111);
            match(FeatParser::KNULL);
            break;
          }

          case FeatParser::LBRACKET:
          case FeatParser::GCLASS:
          case FeatParser::CID:
          case FeatParser::ESCGNAME:
          case FeatParser::NAMELABEL:
          case FeatParser::EXTNAME: {
            setState(112);
            dynamic_cast<SubstituteContext *>(_localctx)->endpat = pattern();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case FeatParser::SUB:
      case FeatParser::SUBV: {
        enterOuterAlt(_localctx, 2);
        setState(115);
        subtok();
        setState(116);
        dynamic_cast<SubstituteContext *>(_localctx)->startpat = pattern();
        setState(117);
        _la = _input->LA(1);
        if (!(_la == FeatParser::BY

        || _la == FeatParser::FROM)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(120);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case FeatParser::KNULL: {
            setState(118);
            match(FeatParser::KNULL);
            break;
          }

          case FeatParser::LBRACKET:
          case FeatParser::GCLASS:
          case FeatParser::CID:
          case FeatParser::ESCGNAME:
          case FeatParser::NAMELABEL:
          case FeatParser::EXTNAME: {
            setState(119);
            dynamic_cast<SubstituteContext *>(_localctx)->endpat = pattern();
            break;
          }

        default:
          throw NoViableAltException(this);
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
  enterRule(_localctx, 20, FeatParser::RulePattern);
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
    setState(125); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(124);
      patternElement();
      setState(127); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FeatParser::LBRACKET)
      | (1ULL << FeatParser::GCLASS)
      | (1ULL << FeatParser::CID)
      | (1ULL << FeatParser::ESCGNAME)
      | (1ULL << FeatParser::NAMELABEL)
      | (1ULL << FeatParser::EXTNAME))) != 0));
   
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
  enterRule(_localctx, 22, FeatParser::RulePatternElement);
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
    setState(131);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::LBRACKET:
      case FeatParser::GCLASS: {
        setState(129);
        glyphClass();
        break;
      }

      case FeatParser::CID:
      case FeatParser::ESCGNAME:
      case FeatParser::NAMELABEL:
      case FeatParser::EXTNAME: {
        setState(130);
        glyph();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(134);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FeatParser::MARKER) {
      setState(133);
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
  enterRule(_localctx, 24, FeatParser::RuleGlyphClass);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(138);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::GCLASS: {
        enterOuterAlt(_localctx, 1);
        setState(136);
        match(FeatParser::GCLASS);
        break;
      }

      case FeatParser::LBRACKET: {
        enterOuterAlt(_localctx, 2);
        setState(137);
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
  enterRule(_localctx, 26, FeatParser::RuleGcLiteral);
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
    setState(140);
    match(FeatParser::LBRACKET);
    setState(142); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(141);
      gcLiteralElement();
      setState(144); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FeatParser::GCLASS)
      | (1ULL << FeatParser::CID)
      | (1ULL << FeatParser::ESCGNAME)
      | (1ULL << FeatParser::NAMELABEL)
      | (1ULL << FeatParser::EXTNAME))) != 0));
    setState(146);
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
  enterRule(_localctx, 28, FeatParser::RuleGcLiteralElement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(154);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::CID:
      case FeatParser::ESCGNAME:
      case FeatParser::NAMELABEL:
      case FeatParser::EXTNAME: {
        enterOuterAlt(_localctx, 1);
        setState(148);
        dynamic_cast<GcLiteralElementContext *>(_localctx)->startg = glyph();
        setState(151);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == FeatParser::HYPHEN) {
          setState(149);
          match(FeatParser::HYPHEN);
          setState(150);
          dynamic_cast<GcLiteralElementContext *>(_localctx)->endg = glyph();
        }
        break;
      }

      case FeatParser::GCLASS: {
        enterOuterAlt(_localctx, 2);
        setState(153);
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
  enterRule(_localctx, 30, FeatParser::RuleGlyph);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(158);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FeatParser::ESCGNAME:
      case FeatParser::NAMELABEL:
      case FeatParser::EXTNAME: {
        enterOuterAlt(_localctx, 1);
        setState(156);
        glyphName();
        break;
      }

      case FeatParser::CID: {
        enterOuterAlt(_localctx, 2);
        setState(157);
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
  enterRule(_localctx, 32, FeatParser::RuleGlyphName);
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
    setState(160);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FeatParser::ESCGNAME)
      | (1ULL << FeatParser::NAMELABEL)
      | (1ULL << FeatParser::EXTNAME))) != 0))) {
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
  enterRule(_localctx, 34, FeatParser::RuleTag);
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
    setState(162);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FeatParser::NAMELABEL)
      | (1ULL << FeatParser::EXTNAME)
      | (1ULL << FeatParser::CATCHTAG))) != 0))) {
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

//----------------- SubtokContext ------------------------------------------------------------------

FeatParser::SubtokContext::SubtokContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FeatParser::SubtokContext::SUB() {
  return getToken(FeatParser::SUB, 0);
}

tree::TerminalNode* FeatParser::SubtokContext::SUBV() {
  return getToken(FeatParser::SUBV, 0);
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
  enterRule(_localctx, 36, FeatParser::RuleSubtok);
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
    setState(164);
    _la = _input->LA(1);
    if (!(_la == FeatParser::SUB

    || _la == FeatParser::SUBV)) {
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

tree::TerminalNode* FeatParser::RevtokContext::REV() {
  return getToken(FeatParser::REV, 0);
}

tree::TerminalNode* FeatParser::RevtokContext::REVV() {
  return getToken(FeatParser::REVV, 0);
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
  enterRule(_localctx, 38, FeatParser::RuleRevtok);
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
    setState(166);
    _la = _input->LA(1);
    if (!(_la == FeatParser::REV

    || _la == FeatParser::REVV)) {
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

tree::TerminalNode* FeatParser::AnontokContext::ANONV() {
  return getToken(FeatParser::ANONV, 0);
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
  enterRule(_localctx, 40, FeatParser::RuleAnontok);
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
    setState(168);
    _la = _input->LA(1);
    if (!(_la == FeatParser::ANON

    || _la == FeatParser::ANONV)) {
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
  "featureFile", "statementFile", "topLevelStatement", "include", "langsysAssign", 
  "anonBlock", "featureBlock", "statement", "featureUse", "substitute", 
  "pattern", "patternElement", "glyphClass", "gcLiteral", "gcLiteralElement", 
  "glyph", "glyphName", "tag", "subtok", "revtok", "anontok"
};

std::vector<std::string> FeatParser::_literalNames = {
  "", "'anon'", "'anonymous'", "", "", "'by'", "'from'", "'feature'", "'substitute'", 
  "'sub'", "'reversesub'", "'rsub'", "'languagesystem'", "'NULL'", "'include'", 
  "", "'}'", "'['", "']'", "'-'", "';'", "'''", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "'('", "", "')'"
};

std::vector<std::string> FeatParser::_symbolicNames = {
  "", "ANON", "ANONV", "COMMENT", "WHITESPACE", "BY", "FROM", "FEATURE", 
  "SUB", "SUBV", "REV", "REVV", "LANGSYS", "KNULL", "INCLUDE", "LCBRACE", 
  "RCBRACE", "LBRACKET", "RBRACKET", "HYPHEN", "SEMI", "MARKER", "QUOTE", 
  "GCLASS", "CID", "ESCGNAME", "NAMELABEL", "EXTNAME", "CATCHTAG", "A_WHITESPACE", 
  "A_LABEL", "A_LBRACE", "A_CLOSE", "A_LINE", "I_WHITESPACE", "I_RPAREN", 
  "IFILE", "I_LPAREN", "STRVAL", "EQUOTE"
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
       0x3, 0x29, 0xad, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x3, 0x2, 
       0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x30, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 
       0x33, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x7, 0x3, 0x38, 0xa, 
       0x3, 0xc, 0x3, 0xe, 0x3, 0x3b, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x4, 0x3, 0x4, 0x5, 0x4, 0x41, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 
       0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 
       0x7, 0x52, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x55, 0xb, 0x7, 0x3, 0x7, 
       0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x6, 0x8, 0x5d, 
       0xa, 0x8, 0xd, 0x8, 0xe, 0x8, 0x5e, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x68, 0xa, 0x9, 
       0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 
       0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x74, 0xa, 0xb, 0x3, 
       0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x7b, 0xa, 
       0xb, 0x5, 0xb, 0x7d, 0xa, 0xb, 0x3, 0xc, 0x6, 0xc, 0x80, 0xa, 0xc, 
       0xd, 0xc, 0xe, 0xc, 0x81, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x86, 0xa, 
       0xd, 0x3, 0xd, 0x5, 0xd, 0x89, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x5, 
       0xe, 0x8d, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x6, 0xf, 0x91, 0xa, 0xf, 
       0xd, 0xf, 0xe, 0xf, 0x92, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 
       0x3, 0x10, 0x5, 0x10, 0x9a, 0xa, 0x10, 0x3, 0x10, 0x5, 0x10, 0x9d, 
       0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xa1, 0xa, 0x11, 0x3, 
       0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 
       0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x2, 0x2, 0x17, 
       0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 
       0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2, 0x8, 0x3, 
       0x2, 0x7, 0x8, 0x3, 0x2, 0x1b, 0x1d, 0x3, 0x2, 0x1c, 0x1e, 0x3, 0x2, 
       0xa, 0xb, 0x3, 0x2, 0xc, 0xd, 0x3, 0x2, 0x3, 0x4, 0x2, 0xab, 0x2, 
       0x31, 0x3, 0x2, 0x2, 0x2, 0x4, 0x39, 0x3, 0x2, 0x2, 0x2, 0x6, 0x40, 
       0x3, 0x2, 0x2, 0x2, 0x8, 0x44, 0x3, 0x2, 0x2, 0x2, 0xa, 0x49, 0x3, 
       0x2, 0x2, 0x2, 0xc, 0x4d, 0x3, 0x2, 0x2, 0x2, 0xe, 0x58, 0x3, 0x2, 
       0x2, 0x2, 0x10, 0x67, 0x3, 0x2, 0x2, 0x2, 0x12, 0x6b, 0x3, 0x2, 0x2, 
       0x2, 0x14, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x16, 0x7f, 0x3, 0x2, 0x2, 0x2, 
       0x18, 0x85, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x1c, 
       0x8e, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x20, 0xa0, 
       0x3, 0x2, 0x2, 0x2, 0x22, 0xa2, 0x3, 0x2, 0x2, 0x2, 0x24, 0xa4, 0x3, 
       0x2, 0x2, 0x2, 0x26, 0xa6, 0x3, 0x2, 0x2, 0x2, 0x28, 0xa8, 0x3, 0x2, 
       0x2, 0x2, 0x2a, 0xaa, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x30, 0x5, 0x6, 0x4, 
       0x2, 0x2d, 0x30, 0x5, 0xc, 0x7, 0x2, 0x2e, 0x30, 0x5, 0xe, 0x8, 0x2, 
       0x2f, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2f, 
       0x2e, 0x3, 0x2, 0x2, 0x2, 0x30, 0x33, 0x3, 0x2, 0x2, 0x2, 0x31, 0x2f, 
       0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x3, 0x2, 0x2, 0x2, 0x32, 0x34, 0x3, 
       0x2, 0x2, 0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x34, 0x35, 0x7, 0x2, 
       0x2, 0x3, 0x35, 0x3, 0x3, 0x2, 0x2, 0x2, 0x36, 0x38, 0x5, 0x10, 0x9, 
       0x2, 0x37, 0x36, 0x3, 0x2, 0x2, 0x2, 0x38, 0x3b, 0x3, 0x2, 0x2, 0x2, 
       0x39, 0x37, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3a, 
       0x3c, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x39, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 
       0x7, 0x2, 0x2, 0x3, 0x3d, 0x5, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x41, 0x5, 
       0x8, 0x5, 0x2, 0x3f, 0x41, 0x5, 0xa, 0x6, 0x2, 0x40, 0x3e, 0x3, 0x2, 
       0x2, 0x2, 0x40, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x3, 0x2, 0x2, 
       0x2, 0x42, 0x43, 0x7, 0x16, 0x2, 0x2, 0x43, 0x7, 0x3, 0x2, 0x2, 0x2, 
       0x44, 0x45, 0x7, 0x10, 0x2, 0x2, 0x45, 0x46, 0x7, 0x25, 0x2, 0x2, 
       0x46, 0x47, 0x7, 0x26, 0x2, 0x2, 0x47, 0x48, 0x7, 0x27, 0x2, 0x2, 
       0x48, 0x9, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x7, 0xe, 0x2, 0x2, 0x4a, 
       0x4b, 0x5, 0x24, 0x13, 0x2, 0x4b, 0x4c, 0x5, 0x24, 0x13, 0x2, 0x4c, 
       0xb, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x5, 0x2a, 0x16, 0x2, 0x4e, 
       0x4f, 0x7, 0x20, 0x2, 0x2, 0x4f, 0x53, 0x7, 0x21, 0x2, 0x2, 0x50, 
       0x52, 0x7, 0x23, 0x2, 0x2, 0x51, 0x50, 0x3, 0x2, 0x2, 0x2, 0x52, 
       0x55, 0x3, 0x2, 0x2, 0x2, 0x53, 0x51, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 
       0x3, 0x2, 0x2, 0x2, 0x54, 0x56, 0x3, 0x2, 0x2, 0x2, 0x55, 0x53, 0x3, 
       0x2, 0x2, 0x2, 0x56, 0x57, 0x7, 0x22, 0x2, 0x2, 0x57, 0xd, 0x3, 0x2, 
       0x2, 0x2, 0x58, 0x59, 0x7, 0x9, 0x2, 0x2, 0x59, 0x5a, 0x5, 0x24, 
       0x13, 0x2, 0x5a, 0x5c, 0x7, 0x11, 0x2, 0x2, 0x5b, 0x5d, 0x5, 0x10, 
       0x9, 0x2, 0x5c, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0x3, 0x2, 0x2, 
       0x2, 0x5e, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x3, 0x2, 0x2, 0x2, 
       0x5f, 0x60, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x7, 0x12, 0x2, 0x2, 
       0x61, 0x62, 0x5, 0x24, 0x13, 0x2, 0x62, 0x63, 0x7, 0x16, 0x2, 0x2, 
       0x63, 0xf, 0x3, 0x2, 0x2, 0x2, 0x64, 0x68, 0x5, 0x12, 0xa, 0x2, 0x65, 
       0x68, 0x5, 0x14, 0xb, 0x2, 0x66, 0x68, 0x5, 0x8, 0x5, 0x2, 0x67, 
       0x64, 0x3, 0x2, 0x2, 0x2, 0x67, 0x65, 0x3, 0x2, 0x2, 0x2, 0x67, 0x66, 
       0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x7, 
       0x16, 0x2, 0x2, 0x6a, 0x11, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x7, 
       0x9, 0x2, 0x2, 0x6c, 0x6d, 0x5, 0x24, 0x13, 0x2, 0x6d, 0x13, 0x3, 
       0x2, 0x2, 0x2, 0x6e, 0x6f, 0x5, 0x28, 0x15, 0x2, 0x6f, 0x70, 0x5, 
       0x16, 0xc, 0x2, 0x70, 0x73, 0x7, 0x7, 0x2, 0x2, 0x71, 0x74, 0x7, 
       0xf, 0x2, 0x2, 0x72, 0x74, 0x5, 0x16, 0xc, 0x2, 0x73, 0x71, 0x3, 
       0x2, 0x2, 0x2, 0x73, 0x72, 0x3, 0x2, 0x2, 0x2, 0x74, 0x7d, 0x3, 0x2, 
       0x2, 0x2, 0x75, 0x76, 0x5, 0x26, 0x14, 0x2, 0x76, 0x77, 0x5, 0x16, 
       0xc, 0x2, 0x77, 0x7a, 0x9, 0x2, 0x2, 0x2, 0x78, 0x7b, 0x7, 0xf, 0x2, 
       0x2, 0x79, 0x7b, 0x5, 0x16, 0xc, 0x2, 0x7a, 0x78, 0x3, 0x2, 0x2, 
       0x2, 0x7a, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7d, 0x3, 0x2, 0x2, 0x2, 
       0x7c, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x75, 0x3, 0x2, 0x2, 0x2, 0x7d, 
       0x15, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x80, 0x5, 0x18, 0xd, 0x2, 0x7f, 
       0x7e, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 0x3, 0x2, 0x2, 0x2, 0x81, 0x7f, 
       0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x3, 0x2, 0x2, 0x2, 0x82, 0x17, 0x3, 
       0x2, 0x2, 0x2, 0x83, 0x86, 0x5, 0x1a, 0xe, 0x2, 0x84, 0x86, 0x5, 
       0x20, 0x11, 0x2, 0x85, 0x83, 0x3, 0x2, 0x2, 0x2, 0x85, 0x84, 0x3, 
       0x2, 0x2, 0x2, 0x86, 0x88, 0x3, 0x2, 0x2, 0x2, 0x87, 0x89, 0x7, 0x17, 
       0x2, 0x2, 0x88, 0x87, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x3, 0x2, 0x2, 
       0x2, 0x89, 0x19, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8d, 0x7, 0x19, 0x2, 
       0x2, 0x8b, 0x8d, 0x5, 0x1c, 0xf, 0x2, 0x8c, 0x8a, 0x3, 0x2, 0x2, 
       0x2, 0x8c, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x1b, 0x3, 0x2, 0x2, 0x2, 
       0x8e, 0x90, 0x7, 0x13, 0x2, 0x2, 0x8f, 0x91, 0x5, 0x1e, 0x10, 0x2, 
       0x90, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x3, 0x2, 0x2, 0x2, 0x92, 
       0x90, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 
       0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x7, 0x14, 0x2, 0x2, 0x95, 0x1d, 
       0x3, 0x2, 0x2, 0x2, 0x96, 0x99, 0x5, 0x20, 0x11, 0x2, 0x97, 0x98, 
       0x7, 0x15, 0x2, 0x2, 0x98, 0x9a, 0x5, 0x20, 0x11, 0x2, 0x99, 0x97, 
       0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9d, 0x3, 
       0x2, 0x2, 0x2, 0x9b, 0x9d, 0x7, 0x19, 0x2, 0x2, 0x9c, 0x96, 0x3, 
       0x2, 0x2, 0x2, 0x9c, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x1f, 0x3, 0x2, 
       0x2, 0x2, 0x9e, 0xa1, 0x5, 0x22, 0x12, 0x2, 0x9f, 0xa1, 0x7, 0x1a, 
       0x2, 0x2, 0xa0, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x9f, 0x3, 0x2, 0x2, 
       0x2, 0xa1, 0x21, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 0x9, 0x3, 0x2, 0x2, 
       0xa3, 0x23, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x9, 0x4, 0x2, 0x2, 0xa5, 
       0x25, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x9, 0x5, 0x2, 0x2, 0xa7, 0x27, 
       0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x9, 0x6, 0x2, 0x2, 0xa9, 0x29, 0x3, 
       0x2, 0x2, 0x2, 0xaa, 0xab, 0x9, 0x7, 0x2, 0x2, 0xab, 0x2b, 0x3, 0x2, 
       0x2, 0x2, 0x14, 0x2f, 0x31, 0x39, 0x40, 0x53, 0x5e, 0x67, 0x73, 0x7a, 
       0x7c, 0x81, 0x85, 0x88, 0x8c, 0x92, 0x99, 0x9c, 0xa0, 
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
