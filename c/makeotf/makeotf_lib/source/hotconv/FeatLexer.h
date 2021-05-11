
// Generated from FeatLexer.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  FeatLexer : public antlr4::Lexer {
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
    Anon = 1, AnonContent = 2, Include = 3, Ifile = 4, String = 5
  };

  explicit FeatLexer(antlr4::CharStream *input);
  ~FeatLexer();


   std::string anon_tag;

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

  virtual void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;
  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.
  void A_LABELAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.
  bool A_CLOSESempred(antlr4::RuleContext *_localctx, size_t predicateIndex);

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

