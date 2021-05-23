
// Generated from FeatLexer.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  FeatLexer : public antlr4::Lexer {
public:
  enum {
    ANON = 1, ANON_v = 2, COMMENT = 3, WHITESPACE = 4, INCLUDE = 5, FEATURE = 6, 
    TABLE = 7, SCRIPT = 8, LANGUAGE = 9, LANGSYS = 10, SUBTABLE = 11, LOOKUP = 12, 
    LOOKUPFLAG = 13, RIGHT_TO_LEFT = 14, IGNORE_BASE_GLYPHS = 15, IGNORE_LIGATURES = 16, 
    IGNORE_MARKS = 17, USE_MARK_FILTERING_SET = 18, MARK_ATTACHMENT_TYPE = 19, 
    EXCLUDE_DFLT = 20, INCLUDE_DFLT = 21, EXCLUDE_dflt = 22, INCLUDE_dflt = 23, 
    USE_EXTENSION = 24, BEGINVALUE = 25, ENDVALUE = 26, ENUMERATE = 27, 
    ENUMERATE_v = 28, EXCEPT = 29, IGNORE = 30, SUBSTITUTE = 31, SUBSTITUTE_v = 32, 
    REVERSE = 33, REVERSE_v = 34, BY = 35, FROM = 36, POSITION = 37, POSITION_v = 38, 
    PARAMETERS = 39, FEATURE_NAMES = 40, CV_PARAMETERS = 41, CV_UI_LABEL = 42, 
    CV_TOOLTIP = 43, CV_SAMPLE_TEXT = 44, CV_PARAM_LABEL = 45, CV_CHARACTER = 46, 
    SIZEMENUNAME = 47, CONTOURPOINT = 48, ANCHOR = 49, ANCHOR_DEF = 50, 
    VALUE_RECORD_DEF = 51, MARK = 52, MARK_CLASS = 53, CURSIVE = 54, MARKBASE = 55, 
    MARKLIG = 56, MARKLIG_v = 57, LIG_COMPONENT = 58, KNULL = 59, BASE = 60, 
    HA_BTL = 61, VA_BTL = 62, HA_BSL = 63, VA_BSL = 64, GDEF = 65, GLYPH_CLASS_DEF = 66, 
    ATTACH = 67, LIG_CARET_BY_POS = 68, LIG_CARET_BY_IDX = 69, HEAD = 70, 
    FONT_REVISION = 71, HHEA = 72, ASCENDER = 73, DESCENDER = 74, LINE_GAP = 75, 
    CARET_OFFSET = 76, NAME = 77, NAMEID = 78, OS_2 = 79, FS_TYPE = 80, 
    FS_TYPE_v = 81, OS2_LOWER_OP_SIZE = 82, OS2_UPPER_OP_SIZE = 83, PANOSE = 84, 
    TYPO_ASCENDER = 85, TYPO_DESCENDER = 86, TYPO_LINE_GAP = 87, WIN_ASCENT = 88, 
    WIN_DESCENT = 89, X_HEIGHT = 90, CAP_HEIGHT = 91, WEIGHT_CLASS = 92, 
    WIDTH_CLASS = 93, VENDOR = 94, UNICODE_RANGE = 95, CODE_PAGE_RANGE = 96, 
    FAMILY_CLASS = 97, STAT = 98, ELIDED_FALLBACK_NAME = 99, ELIDED_FALLBACK_NAME_ID = 100, 
    DESIGN_AXIS = 101, AXIS_VALUE = 102, FLAG = 103, LOCATION = 104, AXIS_EAVN = 105, 
    AXIS_OSFA = 106, VHEA = 107, VERT_TYPO_ASCENDER = 108, VERT_TYPO_DESCENDER = 109, 
    VERT_TYPO_LINE_GAP = 110, VMTX = 111, VERT_ORIGIN_Y = 112, VERT_ADVANCE_Y = 113, 
    LCBRACE = 114, RCBRACE = 115, LBRACKET = 116, RBRACKET = 117, HYPHEN = 118, 
    SEMI = 119, EQUALS = 120, MARKER = 121, COMMA = 122, QUOTE = 123, GCLASS = 124, 
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

   /* All the TSTART/TCHR characters are grouped together, so just
    * look for the string and if its there verify that the characters
    * on either side are from the appropriate set (in case there are
    * "extra" characters).
    */

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

