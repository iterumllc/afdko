parser grammar FeatParser;

options { tokenVocab = FeatLexer; }

file:
    ( topLevelStatement
    | featureBlock
    | tableBlock
    | anonBlock
    | lookupBlockTopLevel
    )* EOF
;

// For include directive in a block with statements

featureFile:
    featureStatement* EOF
;

statementFile:
    statement* EOF
;

cvStatementFile:
    cvParameterStatement* EOF
;

baseFile:
    baseStatement* EOF
;

hheaFile:
    hheaStatement* EOF
;

vheaFile:
    vheaStatement* EOF
;

// For include directive in GDEF table
gdefFile:
    gdefStatement* EOF
;

// For include directive in name table
nameFile:
    nameStatement* EOF
;

vmtxFile:
    vmtxStatement* EOF
;

os_2File:
    os_2Statement* EOF
;

statFile:
    statStatement* EOF
;

axisValueFile:
    axisValueStatement* EOF
;

nameEntryFile:
    nameEntryStatement* EOF
;

topLevelStatement:
    ( glyphClassAssign
    | langsysAssign
    | mark_statement
    | anchorDef
    | valueRecordDef
    | include
    )
    SEMI
;

include:
    INCLUDE I_RPAREN IFILE I_LPAREN
;

langsysAssign:
    LANGSYS script=tag lang=tag
;

valueRecordDef:
    VALUERECORDDEF valueLiteral label
;

valueRecord:
    BEGINVALUE valuename=label ENDVALUE | valueLiteral
;

valueLiteral:
    ( BEGINVALUE NUM NUM NUM NUM ENDVALUE ) | NUM
;

anonBlock:
    anontok A_LABEL A_LBRACE A_LINE* A_CLOSE
;

lookupBlockTopLevel:
    LOOKUP startlabel=label USEEXTENSION? LCBRACE
    statement+
    RCBRACE endlabel=label SEMI
;

lookupBlockOrUse:
    LOOKUP startlabel=label ( USEEXTENSION? LCBRACE
    statement+
    RCBRACE endlabel=label )? SEMI
;

featureBlock:
    FEATURE starttag=tag USEEXTENSION? LCBRACE
    featureStatement+
    RCBRACE endtag=tag SEMI
;

featureStatement:
      statement
    | lookupBlockOrUse
    | cvParameterBlock
;

statement:
    ( featureUse
    | scriptAssign
    | langAssign
    | lookupflagAssign
    | glyphClassAssign
    | ignoreSubOrPos
    | substitute
    | mark_statement
    | position
    | parameters
    | sizemenuname
    | featureNames
    | subtable
    | include
    ) SEMI
;

featureUse:
    FEATURE tag
;

scriptAssign:
    SCRIPT tag
;

langAssign:
    LANG tag ( EXCLUDE_DFLT | INCLUDE_DFLT | EXCLUDE_dflt | INCLUDE_dflt | )
;

lookupflagAssign:
    LOOKUPFLAG ( NUM | lookupflagElement+ )
;

lookupflagElement:
      RIGHTTOLEFT | IGNOREBASEGLYPHS | IGNORELIGATURES | IGNOREMARKS
    | ( MARKATTACHMENTTYPE glyphClass )
    | ( USEMARKFILTERINGSET glyphClass )
;

ignoreSubOrPos:
    IGNORE ( subtok | revtok | postok ) lookupPattern ( COMMA lookupPattern )*
;

substitute:
    ( EXCEPT lookupPattern ( COMMA lookupPattern )* )?
    ( revtok startpat=lookupPattern ( BY ( KNULL | endpat=lookupPattern ) )?
    | subtok startpat=lookupPattern ( ( BY | FROM ) ( KNULL | endpat=lookupPattern ) )? )
;

position:
    enumtok? postok startpat=pattern?
    ( 
        ( valueRecord valuePattern* )
      | ( ( LOOKUP label )+ lookupPatternElement+ )
      | ( CURSIVE cursive endpat=pattern? )
      | ( MARKBASE midpat=pattern baseToMarkElement+ endpat=pattern? )
      | ( markligtok midpat=pattern ligatureMarkElement+ endpat=pattern? )
      | ( MARK midpat=pattern baseToMarkElement+ endpat=pattern? )
    )
;

valuePattern:
    patternElement valueRecord?
;

cursive:
    patternElement anchor anchor
;

baseToMarkElement:
    anchor MARK GCLASS MARKER?
;

ligatureMarkElement:
    anchor ( MARK GCLASS )? LIGATURECOMPONENT? MARKER?
;

mark_statement:
    MARKCLASS ( glyph | glyphClass ) anchor GCLASS
;

featureNames:
    FEATNAMES LCBRACE
    nameEntryStatement+
    RCBRACE
;

subtable:
    SUBTABLE
;

parameters:
    PARAMETERS fixedNum+
;

cvParameterBlock:
    CVPARAMETERS LCBRACE
    cvParameterStatement*
    RCBRACE SEMI
;

cvParameterStatement: // No longer enforcing ordering
    ( cvParameter
    | include
    ) SEMI
;   

cvParameter:
      ( CVUILABEL | CVTOOLTIP | CVSAMPLETEXT | CVPARAMLABEL ) LCBRACE
      nameEntryStatement+
      RCBRACE
    | CVCHARACTER genNum
;

tableBlock:
    TABLE
    ( table_BASE
    | table_GDEF
    | table_head
    | table_hhea
    | table_vhea
    | table_OS_2
    | table_STAT
    | table_name
    | table_vmtx
    )
;

table_BASE:
    BASE LCBRACE
    baseStatement+
    RCBRACE BASE SEMI
;

baseStatement:
    ( axisTags
    | axisScripts
    | include
    ) SEMI
;

axisTags:
    ( HA_BTL | VA_BTL ) tag+ 
;

axisScripts:
    ( HA_BSL | VA_BSL ) baseScript ( COMMA baseScript )*
;

baseScript:
    script=tag db=tag NUM+
;

table_GDEF:
    GDEF LCBRACE
    gdefStatement+
    RCBRACE GDEF SEMI
;

gdefStatement:
    ( gdefGlyphClass
    | gdefAttach
    | gdefLigCaretPos
    | gdefLigCaretIndex
    | include
    ) SEMI
;

gdefGlyphClass:
    GCD glyphClassOptional COMMA
        glyphClassOptional COMMA
        glyphClassOptional COMMA
        glyphClassOptional
;

gdefAttach:
    ATTACH lookupPattern NUM+
;

gdefLigCaretPos:
    LIGCARETPOS lookupPattern NUM+
;
    
gdefLigCaretIndex:
    LIGCARETIDX lookupPattern NUM+
;

table_head:
    HEAD LCBRACE
    ( FONTREV POINTNUM | ) SEMI
    RCBRACE HEAD SEMI
;

table_hhea:
    HHEA LCBRACE
    hheaStatement*
    RCBRACE HHEA SEMI
;

hheaStatement:
    ( hhea
    | include
    ) SEMI
;

hhea:
    ( CARETOFF | ASCENDER | DESCENDER | LINEGAP ) NUM
;

table_vhea:
    VHEA LCBRACE
    vheaStatement*
    RCBRACE VHEA SEMI
;

vheaStatement:
    ( vhea
    | include
    ) SEMI
;

vhea:
    ( VASCENDER | VDESCENDER | VLINEGAP ) NUM
;

table_name:
    NAME LCBRACE
    nameStatement+
    RCBRACE NAME SEMI
;

nameStatement:
    ( nameID
    | include )
    SEMI
;

nameID:
    NAMEID id=genNum ( plat=genNum ( spec=genNum lang=genNum )? )? QUOTE STRVAL EQUOTE
;

table_vmtx:
    VMTX LCBRACE
    vmtxStatement+
    RCBRACE VMTX SEMI
;

vmtxStatement:
    ( vmtx
    | include )
    SEMI
;

vmtx:
    ( VERTORIY | VERTADVY ) glyph NUM
;

table_OS_2:
    OS_2 LCBRACE
    os_2Statement+
    RCBRACE OS_2 SEMI
;

os_2Statement:
    ( os_2
    | include
    ) SEMI
;

os_2:
      ( TYPOASC | TYPODESC | TYPOLINEGAP | WINASC | WINDESC
      | XHEIGHT | CAPHEIGHT ) num=NUM
    |
      ( FSTYPE | FSTYPE2 | WEIGHTCLASS | WIDTHCLASS
      | OS2_LOPS | OS2_UOPS ) unum=NUM
    | FAMCLASS gnum=genNum
    | VENDOR QUOTE STRVAL EQUOTE
    | PANOSE NUM NUM NUM NUM NUM NUM NUM NUM NUM NUM
    | ( UNIRANGE | CODEPAGERANGE ) NUM+
;
    

table_STAT:
    STAT LCBRACE
    statStatement+
    RCBRACE STAT SEMI
;

statStatement:
    ( designAxis
    | axisValue
    | elidedFallbackName
    | elidedFallbackNameID
    | include
    ) SEMI
;

designAxis:
    DESIGNAXIS tag NUM LCBRACE
    nameEntryStatement+
    RCBRACE
;

axisValue:
    AXISVALUE LCBRACE
    axisValueStatement+
    RCBRACE
;

axisValueStatement:
    ( nameEntry
    | axisValueLocation
    | axisValueFlags
    | include
    ) SEMI
;

axisValueLocation:
    LOCATION tag fixedNum ( fixedNum fixedNum? )?
;

axisValueFlags:
    FLAG ( AXIS_OSFA | AXIS_EAVN )+
;

elidedFallbackName:
    ELIDFALLNAME LCBRACE
    nameEntryStatement+
    RCBRACE
;

nameEntryStatement:
    ( nameEntry
    | include
    ) SEMI
;

elidedFallbackNameID:
    ELIDFALLNAMEID genNum
;

nameEntry:
    NAME ( genNum ( genNum genNum )? )? QUOTE STRVAL EQUOTE
;

sizemenuname:
    SIZEMENUNAME ( genNum ( genNum genNum )? )? QUOTE STRVAL EQUOTE
;

anchorDef:
    ANCHORDEF xval=NUM yval=NUM ( CONTOURPOINT cp=NUM )? name=label
;

anchor:
    BEGINVALUE ANCHOR
    (   ( xval=NUM yval=NUM ( CONTOURPOINT cp=NUM )? )
      | KNULL
      | name=label
    ) ENDVALUE
;

lookupPattern:
    lookupPatternElement+
;

lookupPatternElement:
    patternElement ( LOOKUP label )*
;

pattern:
    patternElement+
;

patternElement:
    ( glyphClass | glyph ) MARKER?
;

glyphClassAssign:
    GCLASS EQUALS glyphClass
;

glyphClassOptional:
    glyphClass |
;

glyphClass:
    GCLASS | gcLiteral
;

gcLiteral:
    LBRACKET gcLiteralElement+ RBRACKET
;

// The gcLiteral/glyphOrRange grammar parses "a - z" as startg=a and endg=z.
// In contrast "a-z" is parsed as startg=a-z. The latter must be handled when
// walking the tree.
gcLiteralElement:
    startg=glyph ( HYPHEN endg=glyph )?
    | GCLASS
;

glyph:
      glyphName
    | CID
;

glyphName:
    ESCGNAME | NAMELABEL | EXTNAME
;

label: // XXX add conditional keywords
    NAMELABEL
;

tag:
    NAMELABEL | EXTNAME | CATCHTAG | MARK // XXX MARK probably against spec
;

fixedNum:
    POINTNUM | NUM
;

genNum:
    NUM | NUMOCT | NUMEXT
;

subtok:
    SUB | SUBV
;

revtok:
    REV | REVV
;

anontok:
    ANON | ANONV
;

enumtok:
    ENUM | ENUMV
;

postok:
    POSITION | POSITIONV
;

markligtok:
    MARKLIG | MARKLIGV
;
