
// Generated from FeatParser.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  FeatParser : public antlr4::Parser {
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
    RuleFile = 0, RuleFeatureFile = 1, RuleStatementFile = 2, RuleCvStatementFile = 3, 
    RuleBaseFile = 4, RuleHheaFile = 5, RuleVheaFile = 6, RuleGdefFile = 7, 
    RuleNameFile = 8, RuleVmtxFile = 9, RuleOs_2File = 10, RuleStatFile = 11, 
    RuleAxisValueFile = 12, RuleNameEntryFile = 13, RuleTopLevelStatement = 14, 
    RuleInclude = 15, RuleLangsysAssign = 16, RuleValueRecordDef = 17, RuleValueRecord = 18, 
    RuleValueLiteral = 19, RuleAnonBlock = 20, RuleLookupBlockTopLevel = 21, 
    RuleLookupBlockOrUse = 22, RuleFeatureBlock = 23, RuleFeatureStatement = 24, 
    RuleStatement = 25, RuleFeatureUse = 26, RuleScriptAssign = 27, RuleLangAssign = 28, 
    RuleLookupflagAssign = 29, RuleLookupflagElement = 30, RuleIgnoreSubOrPos = 31, 
    RuleSubstitute = 32, RulePosition = 33, RuleValuePattern = 34, RuleCursiveElement = 35, 
    RuleBaseToMarkElement = 36, RuleLigatureMarkElement = 37, RuleMark_statement = 38, 
    RuleFeatureNames = 39, RuleSubtable = 40, RuleParameters = 41, RuleCvParameterBlock = 42, 
    RuleCvParameterStatement = 43, RuleCvParameter = 44, RuleTableBlock = 45, 
    RuleTable_BASE = 46, RuleBaseStatement = 47, RuleAxisTags = 48, RuleAxisScripts = 49, 
    RuleBaseScript = 50, RuleTable_GDEF = 51, RuleGdefStatement = 52, RuleGdefGlyphClass = 53, 
    RuleGdefAttach = 54, RuleGdefLigCaretPos = 55, RuleGdefLigCaretIndex = 56, 
    RuleTable_head = 57, RuleTable_hhea = 58, RuleHheaStatement = 59, RuleHhea = 60, 
    RuleTable_vhea = 61, RuleVheaStatement = 62, RuleVhea = 63, RuleTable_name = 64, 
    RuleNameStatement = 65, RuleNameID = 66, RuleTable_vmtx = 67, RuleVmtxStatement = 68, 
    RuleVmtx = 69, RuleTable_OS_2 = 70, RuleOs_2Statement = 71, RuleOs_2 = 72, 
    RuleTable_STAT = 73, RuleStatStatement = 74, RuleDesignAxis = 75, RuleAxisValue = 76, 
    RuleAxisValueStatement = 77, RuleAxisValueLocation = 78, RuleAxisValueFlags = 79, 
    RuleElidedFallbackName = 80, RuleNameEntryStatement = 81, RuleElidedFallbackNameID = 82, 
    RuleNameEntry = 83, RuleSizemenuname = 84, RuleAnchorDef = 85, RuleAnchor = 86, 
    RuleLookupPattern = 87, RuleLookupPatternElement = 88, RulePattern = 89, 
    RulePatternElement = 90, RuleGlyphClassAssign = 91, RuleGlyphClassOptional = 92, 
    RuleGlyphClass = 93, RuleGcLiteral = 94, RuleGcLiteralElement = 95, 
    RuleGlyph = 96, RuleGlyphName = 97, RuleLabel = 98, RuleTag = 99, RuleFixedNum = 100, 
    RuleGenNum = 101, RuleSubtok = 102, RuleRevtok = 103, RuleAnontok = 104, 
    RuleEnumtok = 105, RulePostok = 106, RuleMarkligtok = 107
  };

  explicit FeatParser(antlr4::TokenStream *input);
  ~FeatParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class FileContext;
  class FeatureFileContext;
  class StatementFileContext;
  class CvStatementFileContext;
  class BaseFileContext;
  class HheaFileContext;
  class VheaFileContext;
  class GdefFileContext;
  class NameFileContext;
  class VmtxFileContext;
  class Os_2FileContext;
  class StatFileContext;
  class AxisValueFileContext;
  class NameEntryFileContext;
  class TopLevelStatementContext;
  class IncludeContext;
  class LangsysAssignContext;
  class ValueRecordDefContext;
  class ValueRecordContext;
  class ValueLiteralContext;
  class AnonBlockContext;
  class LookupBlockTopLevelContext;
  class LookupBlockOrUseContext;
  class FeatureBlockContext;
  class FeatureStatementContext;
  class StatementContext;
  class FeatureUseContext;
  class ScriptAssignContext;
  class LangAssignContext;
  class LookupflagAssignContext;
  class LookupflagElementContext;
  class IgnoreSubOrPosContext;
  class SubstituteContext;
  class PositionContext;
  class ValuePatternContext;
  class CursiveElementContext;
  class BaseToMarkElementContext;
  class LigatureMarkElementContext;
  class Mark_statementContext;
  class FeatureNamesContext;
  class SubtableContext;
  class ParametersContext;
  class CvParameterBlockContext;
  class CvParameterStatementContext;
  class CvParameterContext;
  class TableBlockContext;
  class Table_BASEContext;
  class BaseStatementContext;
  class AxisTagsContext;
  class AxisScriptsContext;
  class BaseScriptContext;
  class Table_GDEFContext;
  class GdefStatementContext;
  class GdefGlyphClassContext;
  class GdefAttachContext;
  class GdefLigCaretPosContext;
  class GdefLigCaretIndexContext;
  class Table_headContext;
  class Table_hheaContext;
  class HheaStatementContext;
  class HheaContext;
  class Table_vheaContext;
  class VheaStatementContext;
  class VheaContext;
  class Table_nameContext;
  class NameStatementContext;
  class NameIDContext;
  class Table_vmtxContext;
  class VmtxStatementContext;
  class VmtxContext;
  class Table_OS_2Context;
  class Os_2StatementContext;
  class Os_2Context;
  class Table_STATContext;
  class StatStatementContext;
  class DesignAxisContext;
  class AxisValueContext;
  class AxisValueStatementContext;
  class AxisValueLocationContext;
  class AxisValueFlagsContext;
  class ElidedFallbackNameContext;
  class NameEntryStatementContext;
  class ElidedFallbackNameIDContext;
  class NameEntryContext;
  class SizemenunameContext;
  class AnchorDefContext;
  class AnchorContext;
  class LookupPatternContext;
  class LookupPatternElementContext;
  class PatternContext;
  class PatternElementContext;
  class GlyphClassAssignContext;
  class GlyphClassOptionalContext;
  class GlyphClassContext;
  class GcLiteralContext;
  class GcLiteralElementContext;
  class GlyphContext;
  class GlyphNameContext;
  class LabelContext;
  class TagContext;
  class FixedNumContext;
  class GenNumContext;
  class SubtokContext;
  class RevtokContext;
  class AnontokContext;
  class EnumtokContext;
  class PostokContext;
  class MarkligtokContext; 

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<TopLevelStatementContext *> topLevelStatement();
    TopLevelStatementContext* topLevelStatement(size_t i);
    std::vector<FeatureBlockContext *> featureBlock();
    FeatureBlockContext* featureBlock(size_t i);
    std::vector<TableBlockContext *> tableBlock();
    TableBlockContext* tableBlock(size_t i);
    std::vector<AnonBlockContext *> anonBlock();
    AnonBlockContext* anonBlock(size_t i);
    std::vector<LookupBlockTopLevelContext *> lookupBlockTopLevel();
    LookupBlockTopLevelContext* lookupBlockTopLevel(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FileContext* file();

  class  FeatureFileContext : public antlr4::ParserRuleContext {
  public:
    FeatureFileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<FeatureStatementContext *> featureStatement();
    FeatureStatementContext* featureStatement(size_t i);


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

  class  CvStatementFileContext : public antlr4::ParserRuleContext {
  public:
    CvStatementFileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<CvParameterStatementContext *> cvParameterStatement();
    CvParameterStatementContext* cvParameterStatement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CvStatementFileContext* cvStatementFile();

  class  BaseFileContext : public antlr4::ParserRuleContext {
  public:
    BaseFileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<BaseStatementContext *> baseStatement();
    BaseStatementContext* baseStatement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BaseFileContext* baseFile();

  class  HheaFileContext : public antlr4::ParserRuleContext {
  public:
    HheaFileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<HheaStatementContext *> hheaStatement();
    HheaStatementContext* hheaStatement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  HheaFileContext* hheaFile();

  class  VheaFileContext : public antlr4::ParserRuleContext {
  public:
    VheaFileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<VheaStatementContext *> vheaStatement();
    VheaStatementContext* vheaStatement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VheaFileContext* vheaFile();

  class  GdefFileContext : public antlr4::ParserRuleContext {
  public:
    GdefFileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<GdefStatementContext *> gdefStatement();
    GdefStatementContext* gdefStatement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GdefFileContext* gdefFile();

  class  NameFileContext : public antlr4::ParserRuleContext {
  public:
    NameFileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<NameStatementContext *> nameStatement();
    NameStatementContext* nameStatement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NameFileContext* nameFile();

  class  VmtxFileContext : public antlr4::ParserRuleContext {
  public:
    VmtxFileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<VmtxStatementContext *> vmtxStatement();
    VmtxStatementContext* vmtxStatement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VmtxFileContext* vmtxFile();

  class  Os_2FileContext : public antlr4::ParserRuleContext {
  public:
    Os_2FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Os_2StatementContext *> os_2Statement();
    Os_2StatementContext* os_2Statement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Os_2FileContext* os_2File();

  class  StatFileContext : public antlr4::ParserRuleContext {
  public:
    StatFileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<StatStatementContext *> statStatement();
    StatStatementContext* statStatement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatFileContext* statFile();

  class  AxisValueFileContext : public antlr4::ParserRuleContext {
  public:
    AxisValueFileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<AxisValueStatementContext *> axisValueStatement();
    AxisValueStatementContext* axisValueStatement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AxisValueFileContext* axisValueFile();

  class  NameEntryFileContext : public antlr4::ParserRuleContext {
  public:
    NameEntryFileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<NameEntryStatementContext *> nameEntryStatement();
    NameEntryStatementContext* nameEntryStatement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NameEntryFileContext* nameEntryFile();

  class  TopLevelStatementContext : public antlr4::ParserRuleContext {
  public:
    TopLevelStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMI();
    GlyphClassAssignContext *glyphClassAssign();
    LangsysAssignContext *langsysAssign();
    Mark_statementContext *mark_statement();
    AnchorDefContext *anchorDef();
    ValueRecordDefContext *valueRecordDef();
    IncludeContext *include();


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

  class  ValueRecordDefContext : public antlr4::ParserRuleContext {
  public:
    ValueRecordDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VALUERECORDDEF();
    ValueLiteralContext *valueLiteral();
    LabelContext *label();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ValueRecordDefContext* valueRecordDef();

  class  ValueRecordContext : public antlr4::ParserRuleContext {
  public:
    FeatParser::LabelContext *valuename = nullptr;
    ValueRecordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BEGINVALUE();
    antlr4::tree::TerminalNode *ENDVALUE();
    LabelContext *label();
    ValueLiteralContext *valueLiteral();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ValueRecordContext* valueRecord();

  class  ValueLiteralContext : public antlr4::ParserRuleContext {
  public:
    ValueLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BEGINVALUE();
    std::vector<antlr4::tree::TerminalNode *> NUM();
    antlr4::tree::TerminalNode* NUM(size_t i);
    antlr4::tree::TerminalNode *ENDVALUE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ValueLiteralContext* valueLiteral();

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

  class  LookupBlockTopLevelContext : public antlr4::ParserRuleContext {
  public:
    FeatParser::LabelContext *startlabel = nullptr;
    FeatParser::LabelContext *endlabel = nullptr;
    LookupBlockTopLevelContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LOOKUP();
    antlr4::tree::TerminalNode *LCBRACE();
    antlr4::tree::TerminalNode *RCBRACE();
    antlr4::tree::TerminalNode *SEMI();
    std::vector<LabelContext *> label();
    LabelContext* label(size_t i);
    antlr4::tree::TerminalNode *USEEXTENSION();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LookupBlockTopLevelContext* lookupBlockTopLevel();

  class  LookupBlockOrUseContext : public antlr4::ParserRuleContext {
  public:
    FeatParser::LabelContext *startlabel = nullptr;
    FeatParser::LabelContext *endlabel = nullptr;
    LookupBlockOrUseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LOOKUP();
    antlr4::tree::TerminalNode *SEMI();
    std::vector<LabelContext *> label();
    LabelContext* label(size_t i);
    antlr4::tree::TerminalNode *LCBRACE();
    antlr4::tree::TerminalNode *RCBRACE();
    antlr4::tree::TerminalNode *USEEXTENSION();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LookupBlockOrUseContext* lookupBlockOrUse();

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
    antlr4::tree::TerminalNode *USEEXTENSION();
    std::vector<FeatureStatementContext *> featureStatement();
    FeatureStatementContext* featureStatement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FeatureBlockContext* featureBlock();

  class  FeatureStatementContext : public antlr4::ParserRuleContext {
  public:
    FeatureStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();
    LookupBlockOrUseContext *lookupBlockOrUse();
    CvParameterBlockContext *cvParameterBlock();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FeatureStatementContext* featureStatement();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMI();
    FeatureUseContext *featureUse();
    ScriptAssignContext *scriptAssign();
    LangAssignContext *langAssign();
    LookupflagAssignContext *lookupflagAssign();
    GlyphClassAssignContext *glyphClassAssign();
    IgnoreSubOrPosContext *ignoreSubOrPos();
    SubstituteContext *substitute();
    Mark_statementContext *mark_statement();
    PositionContext *position();
    ParametersContext *parameters();
    SizemenunameContext *sizemenuname();
    FeatureNamesContext *featureNames();
    SubtableContext *subtable();
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

  class  ScriptAssignContext : public antlr4::ParserRuleContext {
  public:
    ScriptAssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCRIPT();
    TagContext *tag();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScriptAssignContext* scriptAssign();

  class  LangAssignContext : public antlr4::ParserRuleContext {
  public:
    LangAssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LANG();
    TagContext *tag();
    antlr4::tree::TerminalNode *EXCLUDE_DFLT();
    antlr4::tree::TerminalNode *INCLUDE_DFLT();
    antlr4::tree::TerminalNode *EXCLUDE_dflt();
    antlr4::tree::TerminalNode *INCLUDE_dflt();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LangAssignContext* langAssign();

  class  LookupflagAssignContext : public antlr4::ParserRuleContext {
  public:
    LookupflagAssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LOOKUPFLAG();
    antlr4::tree::TerminalNode *NUM();
    std::vector<LookupflagElementContext *> lookupflagElement();
    LookupflagElementContext* lookupflagElement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LookupflagAssignContext* lookupflagAssign();

  class  LookupflagElementContext : public antlr4::ParserRuleContext {
  public:
    LookupflagElementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RIGHTTOLEFT();
    antlr4::tree::TerminalNode *IGNOREBASEGLYPHS();
    antlr4::tree::TerminalNode *IGNORELIGATURES();
    antlr4::tree::TerminalNode *IGNOREMARKS();
    antlr4::tree::TerminalNode *MARKATTACHMENTTYPE();
    GlyphClassContext *glyphClass();
    antlr4::tree::TerminalNode *USEMARKFILTERINGSET();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LookupflagElementContext* lookupflagElement();

  class  IgnoreSubOrPosContext : public antlr4::ParserRuleContext {
  public:
    IgnoreSubOrPosContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IGNORE();
    std::vector<LookupPatternContext *> lookupPattern();
    LookupPatternContext* lookupPattern(size_t i);
    SubtokContext *subtok();
    RevtokContext *revtok();
    PostokContext *postok();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IgnoreSubOrPosContext* ignoreSubOrPos();

  class  SubstituteContext : public antlr4::ParserRuleContext {
  public:
    FeatParser::LookupPatternContext *startpat = nullptr;
    FeatParser::LookupPatternContext *endpat = nullptr;
    SubstituteContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RevtokContext *revtok();
    SubtokContext *subtok();
    antlr4::tree::TerminalNode *EXCEPT();
    std::vector<LookupPatternContext *> lookupPattern();
    LookupPatternContext* lookupPattern(size_t i);
    antlr4::tree::TerminalNode *BY();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *FROM();
    antlr4::tree::TerminalNode *KNULL();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SubstituteContext* substitute();

  class  PositionContext : public antlr4::ParserRuleContext {
  public:
    FeatParser::PatternContext *startpat = nullptr;
    FeatParser::PatternContext *endpat = nullptr;
    FeatParser::PatternContext *midpat = nullptr;
    PositionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PostokContext *postok();
    EnumtokContext *enumtok();
    std::vector<PatternContext *> pattern();
    PatternContext* pattern(size_t i);
    ValueRecordContext *valueRecord();
    antlr4::tree::TerminalNode *CURSIVE();
    CursiveElementContext *cursiveElement();
    antlr4::tree::TerminalNode *MARKBASE();
    MarkligtokContext *markligtok();
    antlr4::tree::TerminalNode *MARK();
    std::vector<ValuePatternContext *> valuePattern();
    ValuePatternContext* valuePattern(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LOOKUP();
    antlr4::tree::TerminalNode* LOOKUP(size_t i);
    std::vector<LabelContext *> label();
    LabelContext* label(size_t i);
    std::vector<LookupPatternElementContext *> lookupPatternElement();
    LookupPatternElementContext* lookupPatternElement(size_t i);
    std::vector<BaseToMarkElementContext *> baseToMarkElement();
    BaseToMarkElementContext* baseToMarkElement(size_t i);
    std::vector<LigatureMarkElementContext *> ligatureMarkElement();
    LigatureMarkElementContext* ligatureMarkElement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PositionContext* position();

  class  ValuePatternContext : public antlr4::ParserRuleContext {
  public:
    ValuePatternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PatternElementContext *patternElement();
    ValueRecordContext *valueRecord();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ValuePatternContext* valuePattern();

  class  CursiveElementContext : public antlr4::ParserRuleContext {
  public:
    CursiveElementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PatternElementContext *patternElement();
    std::vector<AnchorContext *> anchor();
    AnchorContext* anchor(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CursiveElementContext* cursiveElement();

  class  BaseToMarkElementContext : public antlr4::ParserRuleContext {
  public:
    BaseToMarkElementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AnchorContext *anchor();
    antlr4::tree::TerminalNode *MARK();
    antlr4::tree::TerminalNode *GCLASS();
    antlr4::tree::TerminalNode *MARKER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BaseToMarkElementContext* baseToMarkElement();

  class  LigatureMarkElementContext : public antlr4::ParserRuleContext {
  public:
    LigatureMarkElementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AnchorContext *anchor();
    antlr4::tree::TerminalNode *MARK();
    antlr4::tree::TerminalNode *GCLASS();
    antlr4::tree::TerminalNode *LIGATURECOMPONENT();
    antlr4::tree::TerminalNode *MARKER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LigatureMarkElementContext* ligatureMarkElement();

  class  Mark_statementContext : public antlr4::ParserRuleContext {
  public:
    Mark_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MARKCLASS();
    AnchorContext *anchor();
    antlr4::tree::TerminalNode *GCLASS();
    GlyphContext *glyph();
    GlyphClassContext *glyphClass();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Mark_statementContext* mark_statement();

  class  FeatureNamesContext : public antlr4::ParserRuleContext {
  public:
    FeatureNamesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FEATNAMES();
    antlr4::tree::TerminalNode *LCBRACE();
    antlr4::tree::TerminalNode *RCBRACE();
    std::vector<NameEntryStatementContext *> nameEntryStatement();
    NameEntryStatementContext* nameEntryStatement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FeatureNamesContext* featureNames();

  class  SubtableContext : public antlr4::ParserRuleContext {
  public:
    SubtableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SUBTABLE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SubtableContext* subtable();

  class  ParametersContext : public antlr4::ParserRuleContext {
  public:
    ParametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PARAMETERS();
    std::vector<FixedNumContext *> fixedNum();
    FixedNumContext* fixedNum(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParametersContext* parameters();

  class  CvParameterBlockContext : public antlr4::ParserRuleContext {
  public:
    CvParameterBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CVPARAMETERS();
    antlr4::tree::TerminalNode *LCBRACE();
    antlr4::tree::TerminalNode *RCBRACE();
    antlr4::tree::TerminalNode *SEMI();
    std::vector<CvParameterStatementContext *> cvParameterStatement();
    CvParameterStatementContext* cvParameterStatement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CvParameterBlockContext* cvParameterBlock();

  class  CvParameterStatementContext : public antlr4::ParserRuleContext {
  public:
    CvParameterStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMI();
    CvParameterContext *cvParameter();
    IncludeContext *include();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CvParameterStatementContext* cvParameterStatement();

  class  CvParameterContext : public antlr4::ParserRuleContext {
  public:
    CvParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LCBRACE();
    antlr4::tree::TerminalNode *RCBRACE();
    antlr4::tree::TerminalNode *CVUILABEL();
    antlr4::tree::TerminalNode *CVTOOLTIP();
    antlr4::tree::TerminalNode *CVSAMPLETEXT();
    antlr4::tree::TerminalNode *CVPARAMLABEL();
    std::vector<NameEntryStatementContext *> nameEntryStatement();
    NameEntryStatementContext* nameEntryStatement(size_t i);
    antlr4::tree::TerminalNode *CVCHARACTER();
    GenNumContext *genNum();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CvParameterContext* cvParameter();

  class  TableBlockContext : public antlr4::ParserRuleContext {
  public:
    TableBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TABLE();
    Table_BASEContext *table_BASE();
    Table_GDEFContext *table_GDEF();
    Table_headContext *table_head();
    Table_hheaContext *table_hhea();
    Table_vheaContext *table_vhea();
    Table_OS_2Context *table_OS_2();
    Table_STATContext *table_STAT();
    Table_nameContext *table_name();
    Table_vmtxContext *table_vmtx();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TableBlockContext* tableBlock();

  class  Table_BASEContext : public antlr4::ParserRuleContext {
  public:
    Table_BASEContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> BASE();
    antlr4::tree::TerminalNode* BASE(size_t i);
    antlr4::tree::TerminalNode *LCBRACE();
    antlr4::tree::TerminalNode *RCBRACE();
    antlr4::tree::TerminalNode *SEMI();
    std::vector<BaseStatementContext *> baseStatement();
    BaseStatementContext* baseStatement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Table_BASEContext* table_BASE();

  class  BaseStatementContext : public antlr4::ParserRuleContext {
  public:
    BaseStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMI();
    AxisTagsContext *axisTags();
    AxisScriptsContext *axisScripts();
    IncludeContext *include();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BaseStatementContext* baseStatement();

  class  AxisTagsContext : public antlr4::ParserRuleContext {
  public:
    AxisTagsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HA_BTL();
    antlr4::tree::TerminalNode *VA_BTL();
    std::vector<TagContext *> tag();
    TagContext* tag(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AxisTagsContext* axisTags();

  class  AxisScriptsContext : public antlr4::ParserRuleContext {
  public:
    AxisScriptsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<BaseScriptContext *> baseScript();
    BaseScriptContext* baseScript(size_t i);
    antlr4::tree::TerminalNode *HA_BSL();
    antlr4::tree::TerminalNode *VA_BSL();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AxisScriptsContext* axisScripts();

  class  BaseScriptContext : public antlr4::ParserRuleContext {
  public:
    FeatParser::TagContext *script = nullptr;
    FeatParser::TagContext *db = nullptr;
    BaseScriptContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TagContext *> tag();
    TagContext* tag(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NUM();
    antlr4::tree::TerminalNode* NUM(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BaseScriptContext* baseScript();

  class  Table_GDEFContext : public antlr4::ParserRuleContext {
  public:
    Table_GDEFContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> GDEF();
    antlr4::tree::TerminalNode* GDEF(size_t i);
    antlr4::tree::TerminalNode *LCBRACE();
    antlr4::tree::TerminalNode *RCBRACE();
    antlr4::tree::TerminalNode *SEMI();
    std::vector<GdefStatementContext *> gdefStatement();
    GdefStatementContext* gdefStatement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Table_GDEFContext* table_GDEF();

  class  GdefStatementContext : public antlr4::ParserRuleContext {
  public:
    GdefStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMI();
    GdefGlyphClassContext *gdefGlyphClass();
    GdefAttachContext *gdefAttach();
    GdefLigCaretPosContext *gdefLigCaretPos();
    GdefLigCaretIndexContext *gdefLigCaretIndex();
    IncludeContext *include();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GdefStatementContext* gdefStatement();

  class  GdefGlyphClassContext : public antlr4::ParserRuleContext {
  public:
    GdefGlyphClassContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GCD();
    std::vector<GlyphClassOptionalContext *> glyphClassOptional();
    GlyphClassOptionalContext* glyphClassOptional(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GdefGlyphClassContext* gdefGlyphClass();

  class  GdefAttachContext : public antlr4::ParserRuleContext {
  public:
    GdefAttachContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ATTACH();
    LookupPatternContext *lookupPattern();
    std::vector<antlr4::tree::TerminalNode *> NUM();
    antlr4::tree::TerminalNode* NUM(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GdefAttachContext* gdefAttach();

  class  GdefLigCaretPosContext : public antlr4::ParserRuleContext {
  public:
    GdefLigCaretPosContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LIGCARETPOS();
    LookupPatternContext *lookupPattern();
    std::vector<antlr4::tree::TerminalNode *> NUM();
    antlr4::tree::TerminalNode* NUM(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GdefLigCaretPosContext* gdefLigCaretPos();

  class  GdefLigCaretIndexContext : public antlr4::ParserRuleContext {
  public:
    GdefLigCaretIndexContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LIGCARETIDX();
    LookupPatternContext *lookupPattern();
    std::vector<antlr4::tree::TerminalNode *> NUM();
    antlr4::tree::TerminalNode* NUM(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GdefLigCaretIndexContext* gdefLigCaretIndex();

  class  Table_headContext : public antlr4::ParserRuleContext {
  public:
    Table_headContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> HEAD();
    antlr4::tree::TerminalNode* HEAD(size_t i);
    antlr4::tree::TerminalNode *LCBRACE();
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);
    antlr4::tree::TerminalNode *RCBRACE();
    antlr4::tree::TerminalNode *FONTREV();
    antlr4::tree::TerminalNode *POINTNUM();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Table_headContext* table_head();

  class  Table_hheaContext : public antlr4::ParserRuleContext {
  public:
    Table_hheaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> HHEA();
    antlr4::tree::TerminalNode* HHEA(size_t i);
    antlr4::tree::TerminalNode *LCBRACE();
    antlr4::tree::TerminalNode *RCBRACE();
    antlr4::tree::TerminalNode *SEMI();
    std::vector<HheaStatementContext *> hheaStatement();
    HheaStatementContext* hheaStatement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Table_hheaContext* table_hhea();

  class  HheaStatementContext : public antlr4::ParserRuleContext {
  public:
    HheaStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMI();
    HheaContext *hhea();
    IncludeContext *include();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  HheaStatementContext* hheaStatement();

  class  HheaContext : public antlr4::ParserRuleContext {
  public:
    HheaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUM();
    antlr4::tree::TerminalNode *CARETOFF();
    antlr4::tree::TerminalNode *ASCENDER();
    antlr4::tree::TerminalNode *DESCENDER();
    antlr4::tree::TerminalNode *LINEGAP();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  HheaContext* hhea();

  class  Table_vheaContext : public antlr4::ParserRuleContext {
  public:
    Table_vheaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> VHEA();
    antlr4::tree::TerminalNode* VHEA(size_t i);
    antlr4::tree::TerminalNode *LCBRACE();
    antlr4::tree::TerminalNode *RCBRACE();
    antlr4::tree::TerminalNode *SEMI();
    std::vector<VheaStatementContext *> vheaStatement();
    VheaStatementContext* vheaStatement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Table_vheaContext* table_vhea();

  class  VheaStatementContext : public antlr4::ParserRuleContext {
  public:
    VheaStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMI();
    VheaContext *vhea();
    IncludeContext *include();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VheaStatementContext* vheaStatement();

  class  VheaContext : public antlr4::ParserRuleContext {
  public:
    VheaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUM();
    antlr4::tree::TerminalNode *VASCENDER();
    antlr4::tree::TerminalNode *VDESCENDER();
    antlr4::tree::TerminalNode *VLINEGAP();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VheaContext* vhea();

  class  Table_nameContext : public antlr4::ParserRuleContext {
  public:
    Table_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *LCBRACE();
    antlr4::tree::TerminalNode *RCBRACE();
    antlr4::tree::TerminalNode *SEMI();
    std::vector<NameStatementContext *> nameStatement();
    NameStatementContext* nameStatement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Table_nameContext* table_name();

  class  NameStatementContext : public antlr4::ParserRuleContext {
  public:
    NameStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMI();
    NameIDContext *nameID();
    IncludeContext *include();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NameStatementContext* nameStatement();

  class  NameIDContext : public antlr4::ParserRuleContext {
  public:
    FeatParser::GenNumContext *id = nullptr;
    FeatParser::GenNumContext *plat = nullptr;
    FeatParser::GenNumContext *spec = nullptr;
    FeatParser::GenNumContext *lang = nullptr;
    NameIDContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAMEID();
    antlr4::tree::TerminalNode *QUOTE();
    antlr4::tree::TerminalNode *STRVAL();
    antlr4::tree::TerminalNode *EQUOTE();
    std::vector<GenNumContext *> genNum();
    GenNumContext* genNum(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NameIDContext* nameID();

  class  Table_vmtxContext : public antlr4::ParserRuleContext {
  public:
    Table_vmtxContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> VMTX();
    antlr4::tree::TerminalNode* VMTX(size_t i);
    antlr4::tree::TerminalNode *LCBRACE();
    antlr4::tree::TerminalNode *RCBRACE();
    antlr4::tree::TerminalNode *SEMI();
    std::vector<VmtxStatementContext *> vmtxStatement();
    VmtxStatementContext* vmtxStatement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Table_vmtxContext* table_vmtx();

  class  VmtxStatementContext : public antlr4::ParserRuleContext {
  public:
    VmtxStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMI();
    VmtxContext *vmtx();
    IncludeContext *include();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VmtxStatementContext* vmtxStatement();

  class  VmtxContext : public antlr4::ParserRuleContext {
  public:
    VmtxContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    GlyphContext *glyph();
    antlr4::tree::TerminalNode *NUM();
    antlr4::tree::TerminalNode *VERTORIY();
    antlr4::tree::TerminalNode *VERTADVY();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VmtxContext* vmtx();

  class  Table_OS_2Context : public antlr4::ParserRuleContext {
  public:
    Table_OS_2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> OS_2();
    antlr4::tree::TerminalNode* OS_2(size_t i);
    antlr4::tree::TerminalNode *LCBRACE();
    antlr4::tree::TerminalNode *RCBRACE();
    antlr4::tree::TerminalNode *SEMI();
    std::vector<Os_2StatementContext *> os_2Statement();
    Os_2StatementContext* os_2Statement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Table_OS_2Context* table_OS_2();

  class  Os_2StatementContext : public antlr4::ParserRuleContext {
  public:
    Os_2StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMI();
    Os_2Context *os_2();
    IncludeContext *include();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Os_2StatementContext* os_2Statement();

  class  Os_2Context : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *num = nullptr;
    antlr4::Token *unum = nullptr;
    FeatParser::GenNumContext *gnum = nullptr;
    Os_2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPOASC();
    antlr4::tree::TerminalNode *TYPODESC();
    antlr4::tree::TerminalNode *TYPOLINEGAP();
    antlr4::tree::TerminalNode *WINASC();
    antlr4::tree::TerminalNode *WINDESC();
    antlr4::tree::TerminalNode *XHEIGHT();
    antlr4::tree::TerminalNode *CAPHEIGHT();
    std::vector<antlr4::tree::TerminalNode *> NUM();
    antlr4::tree::TerminalNode* NUM(size_t i);
    antlr4::tree::TerminalNode *FSTYPE();
    antlr4::tree::TerminalNode *FSTYPE2();
    antlr4::tree::TerminalNode *WEIGHTCLASS();
    antlr4::tree::TerminalNode *WIDTHCLASS();
    antlr4::tree::TerminalNode *OS2_LOPS();
    antlr4::tree::TerminalNode *OS2_UOPS();
    antlr4::tree::TerminalNode *FAMCLASS();
    GenNumContext *genNum();
    antlr4::tree::TerminalNode *VENDOR();
    antlr4::tree::TerminalNode *QUOTE();
    antlr4::tree::TerminalNode *STRVAL();
    antlr4::tree::TerminalNode *EQUOTE();
    antlr4::tree::TerminalNode *PANOSE();
    antlr4::tree::TerminalNode *UNIRANGE();
    antlr4::tree::TerminalNode *CODEPAGERANGE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Os_2Context* os_2();

  class  Table_STATContext : public antlr4::ParserRuleContext {
  public:
    Table_STATContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> STAT();
    antlr4::tree::TerminalNode* STAT(size_t i);
    antlr4::tree::TerminalNode *LCBRACE();
    antlr4::tree::TerminalNode *RCBRACE();
    antlr4::tree::TerminalNode *SEMI();
    std::vector<StatStatementContext *> statStatement();
    StatStatementContext* statStatement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Table_STATContext* table_STAT();

  class  StatStatementContext : public antlr4::ParserRuleContext {
  public:
    StatStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMI();
    DesignAxisContext *designAxis();
    AxisValueContext *axisValue();
    ElidedFallbackNameContext *elidedFallbackName();
    ElidedFallbackNameIDContext *elidedFallbackNameID();
    IncludeContext *include();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatStatementContext* statStatement();

  class  DesignAxisContext : public antlr4::ParserRuleContext {
  public:
    DesignAxisContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DESIGNAXIS();
    TagContext *tag();
    antlr4::tree::TerminalNode *NUM();
    antlr4::tree::TerminalNode *LCBRACE();
    antlr4::tree::TerminalNode *RCBRACE();
    std::vector<NameEntryStatementContext *> nameEntryStatement();
    NameEntryStatementContext* nameEntryStatement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DesignAxisContext* designAxis();

  class  AxisValueContext : public antlr4::ParserRuleContext {
  public:
    AxisValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AXISVALUE();
    antlr4::tree::TerminalNode *LCBRACE();
    antlr4::tree::TerminalNode *RCBRACE();
    std::vector<AxisValueStatementContext *> axisValueStatement();
    AxisValueStatementContext* axisValueStatement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AxisValueContext* axisValue();

  class  AxisValueStatementContext : public antlr4::ParserRuleContext {
  public:
    AxisValueStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMI();
    NameEntryContext *nameEntry();
    AxisValueLocationContext *axisValueLocation();
    AxisValueFlagsContext *axisValueFlags();
    IncludeContext *include();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AxisValueStatementContext* axisValueStatement();

  class  AxisValueLocationContext : public antlr4::ParserRuleContext {
  public:
    AxisValueLocationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LOCATION();
    TagContext *tag();
    std::vector<FixedNumContext *> fixedNum();
    FixedNumContext* fixedNum(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AxisValueLocationContext* axisValueLocation();

  class  AxisValueFlagsContext : public antlr4::ParserRuleContext {
  public:
    AxisValueFlagsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FLAG();
    std::vector<antlr4::tree::TerminalNode *> AXIS_OSFA();
    antlr4::tree::TerminalNode* AXIS_OSFA(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AXIS_EAVN();
    antlr4::tree::TerminalNode* AXIS_EAVN(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AxisValueFlagsContext* axisValueFlags();

  class  ElidedFallbackNameContext : public antlr4::ParserRuleContext {
  public:
    ElidedFallbackNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ELIDFALLNAME();
    antlr4::tree::TerminalNode *LCBRACE();
    antlr4::tree::TerminalNode *RCBRACE();
    std::vector<NameEntryStatementContext *> nameEntryStatement();
    NameEntryStatementContext* nameEntryStatement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElidedFallbackNameContext* elidedFallbackName();

  class  NameEntryStatementContext : public antlr4::ParserRuleContext {
  public:
    NameEntryStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMI();
    NameEntryContext *nameEntry();
    IncludeContext *include();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NameEntryStatementContext* nameEntryStatement();

  class  ElidedFallbackNameIDContext : public antlr4::ParserRuleContext {
  public:
    ElidedFallbackNameIDContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ELIDFALLNAMEID();
    GenNumContext *genNum();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElidedFallbackNameIDContext* elidedFallbackNameID();

  class  NameEntryContext : public antlr4::ParserRuleContext {
  public:
    NameEntryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *QUOTE();
    antlr4::tree::TerminalNode *STRVAL();
    antlr4::tree::TerminalNode *EQUOTE();
    std::vector<GenNumContext *> genNum();
    GenNumContext* genNum(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NameEntryContext* nameEntry();

  class  SizemenunameContext : public antlr4::ParserRuleContext {
  public:
    SizemenunameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SIZEMENUNAME();
    antlr4::tree::TerminalNode *QUOTE();
    antlr4::tree::TerminalNode *STRVAL();
    antlr4::tree::TerminalNode *EQUOTE();
    std::vector<GenNumContext *> genNum();
    GenNumContext* genNum(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SizemenunameContext* sizemenuname();

  class  AnchorDefContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *xval = nullptr;
    antlr4::Token *yval = nullptr;
    antlr4::Token *cp = nullptr;
    FeatParser::LabelContext *name = nullptr;
    AnchorDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ANCHORDEF();
    std::vector<antlr4::tree::TerminalNode *> NUM();
    antlr4::tree::TerminalNode* NUM(size_t i);
    LabelContext *label();
    antlr4::tree::TerminalNode *CONTOURPOINT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnchorDefContext* anchorDef();

  class  AnchorContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *xval = nullptr;
    antlr4::Token *yval = nullptr;
    antlr4::Token *cp = nullptr;
    FeatParser::LabelContext *name = nullptr;
    AnchorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BEGINVALUE();
    antlr4::tree::TerminalNode *ANCHOR();
    antlr4::tree::TerminalNode *ENDVALUE();
    antlr4::tree::TerminalNode *KNULL();
    LabelContext *label();
    std::vector<antlr4::tree::TerminalNode *> NUM();
    antlr4::tree::TerminalNode* NUM(size_t i);
    antlr4::tree::TerminalNode *CONTOURPOINT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnchorContext* anchor();

  class  LookupPatternContext : public antlr4::ParserRuleContext {
  public:
    LookupPatternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<LookupPatternElementContext *> lookupPatternElement();
    LookupPatternElementContext* lookupPatternElement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LookupPatternContext* lookupPattern();

  class  LookupPatternElementContext : public antlr4::ParserRuleContext {
  public:
    LookupPatternElementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PatternElementContext *patternElement();
    std::vector<antlr4::tree::TerminalNode *> LOOKUP();
    antlr4::tree::TerminalNode* LOOKUP(size_t i);
    std::vector<LabelContext *> label();
    LabelContext* label(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LookupPatternElementContext* lookupPatternElement();

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

  class  GlyphClassAssignContext : public antlr4::ParserRuleContext {
  public:
    GlyphClassAssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GCLASS();
    antlr4::tree::TerminalNode *EQUALS();
    GlyphClassContext *glyphClass();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GlyphClassAssignContext* glyphClassAssign();

  class  GlyphClassOptionalContext : public antlr4::ParserRuleContext {
  public:
    GlyphClassOptionalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    GlyphClassContext *glyphClass();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GlyphClassOptionalContext* glyphClassOptional();

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

  class  LabelContext : public antlr4::ParserRuleContext {
  public:
    LabelContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAMELABEL();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LabelContext* label();

  class  TagContext : public antlr4::ParserRuleContext {
  public:
    TagContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAMELABEL();
    antlr4::tree::TerminalNode *EXTNAME();
    antlr4::tree::TerminalNode *CATCHTAG();
    antlr4::tree::TerminalNode *MARK();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TagContext* tag();

  class  FixedNumContext : public antlr4::ParserRuleContext {
  public:
    FixedNumContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *POINTNUM();
    antlr4::tree::TerminalNode *NUM();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FixedNumContext* fixedNum();

  class  GenNumContext : public antlr4::ParserRuleContext {
  public:
    GenNumContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUM();
    antlr4::tree::TerminalNode *NUMOCT();
    antlr4::tree::TerminalNode *NUMEXT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GenNumContext* genNum();

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

  class  EnumtokContext : public antlr4::ParserRuleContext {
  public:
    EnumtokContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ENUM();
    antlr4::tree::TerminalNode *ENUMV();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumtokContext* enumtok();

  class  PostokContext : public antlr4::ParserRuleContext {
  public:
    PostokContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *POSITION();
    antlr4::tree::TerminalNode *POSITIONV();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PostokContext* postok();

  class  MarkligtokContext : public antlr4::ParserRuleContext {
  public:
    MarkligtokContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MARKLIG();
    antlr4::tree::TerminalNode *MARKLIGV();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MarkligtokContext* markligtok();


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

