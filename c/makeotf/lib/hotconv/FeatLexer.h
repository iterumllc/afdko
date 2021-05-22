
// Generated from FeatLexer.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  FeatLexer : public antlr4::Lexer {
public:
  enum {
    ANON = 1, ANONV = 2, COMMENT = 3, WHITESPACE = 4, BY = 5, FROM = 6, 
    FEATURE = 7, SUB = 8, SUBV = 9, EXCEPT = 10, ANCHORDEF = 11, ANCHOR = 12, 
    CONTOURPOINT = 13, REV = 14, REVV = 15, MARKCLASS = 16, LANGSYS = 17, 
    BASE = 18, TABLE = 19, SCRIPT = 20, LANG = 21, GDEF = 22, GCD = 23, 
    ATTACH = 24, HEAD = 25, FONTREV = 26, HHEA = 27, CARETOFF = 28, ASCENDER = 29, 
    DESCENDER = 30, LINEGAP = 31, VHEA = 32, VASCENDER = 33, VDESCENDER = 34, 
    VLINEGAP = 35, VMTX = 36, VERTORIY = 37, VERTADVY = 38, NAME = 39, NAMEID = 40, 
    LIGCARETPOS = 41, LIGCARETIDX = 42, STAT = 43, ELIDFALLNAME = 44, ELIDFALLNAMEID = 45, 
    DESIGNAXIS = 46, AXISVALUE = 47, FLAG = 48, AXIS_OSFA = 49, AXIS_EAVN = 50, 
    LOCATION = 51, OS_2 = 52, FSTYPE = 53, FSTYPE2 = 54, OS2_LOPS = 55, 
    OS2_UOPS = 56, PANOSE = 57, TYPOASC = 58, TYPODESC = 59, TYPOLINEGAP = 60, 
    WINASC = 61, WINDESC = 62, XHEIGHT = 63, CAPHEIGHT = 64, WEIGHTCLASS = 65, 
    WIDTHCLASS = 66, VENDOR = 67, UNIRANGE = 68, CODEPAGERANGE = 69, FAMCLASS = 70, 
    LOOKUP = 71, USEEXTENSION = 72, EXCLUDE_DFLT = 73, INCLUDE_DFLT = 74, 
    EXCLUDE_dflt = 75, INCLUDE_dflt = 76, HA_BTL = 77, VA_BTL = 78, HA_BSL = 79, 
    VA_BSL = 80, SUBTABLE = 81, LOOKUPFLAG = 82, VALUERECORDDEF = 83, BEGINVALUE = 84, 
    ENDVALUE = 85, FEATNAMES = 86, RIGHTTOLEFT = 87, IGNOREBASEGLYPHS = 88, 
    IGNORELIGATURES = 89, IGNOREMARKS = 90, MARKATTACHMENTTYPE = 91, USEMARKFILTERINGSET = 92, 
    SIZEMENUNAME = 93, CVPARAMETERS = 94, CVUILABEL = 95, CVTOOLTIP = 96, 
    CVSAMPLETEXT = 97, CVPARAMLABEL = 98, CVCHARACTER = 99, PARAMETERS = 100, 
    IGNORE = 101, ENUM = 102, ENUMV = 103, POSITION = 104, POSITIONV = 105, 
    CURSIVE = 106, MARKBASE = 107, MARKLIG = 108, MARKLIGV = 109, MARK = 110, 
    LIGATURECOMPONENT = 111, KNULL = 112, INCLUDE = 113, LCBRACE = 114, 
    RCBRACE = 115, LBRACKET = 116, RBRACKET = 117, HYPHEN = 118, SEMI = 119, 
    EQUALS = 120, MARKER = 121, COMMA = 122, QUOTE = 123, GCLASS = 124, 
    CID = 125, ESCGNAME = 126, NAMELABEL = 127, EXTNAME = 128, POINTNUM = 129, 
    NUMEXT = 130, NUMOCT = 131, NUM = 132, CATCHTAG = 133, A_WHITESPACE = 134, 
    A_LABEL = 135, A_LBRACE = 136, A_CLOSE = 137, A_LINE = 138, I_WHITESPACE = 139, 
    I_RPAREN = 140, IFILE = 141, I_LPAREN = 142, STRVAL = 143, EQUOTE = 144
  };

  enum {
    Anon = 1, AnonContent = 2, Include = 3, Ifile = 4, String = 5
  };

  explicit FeatLexer(antlr4::CharStream *input);
  ~FeatLexer();


   std::string anon_tag;
   bool verify_anon(const std::string &line) {
       auto p = line.find(anon_tag);
       if ( p == std::string::npos )
           return false;
       --p;
       if ( ! ( line[p] == ' ' || line[p] == '\t' || line[p] == '}' ) )
           return false;
       p += anon_tag.size() + 1;
       if ( ! ( line[p] == ' ' || line[p] == '\t' || line[p] == ';' ) )
           return false;
       return true;
   }

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

