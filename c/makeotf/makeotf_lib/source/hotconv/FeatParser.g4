parser grammar FeatParser;

options { tokenVocab = FeatLexer; }

featureFile:
    ( topLevelStatement
    | featureBlock
    )* EOF
;

// For include directive in a feature block
statementFile:
    statement* EOF
;

topLevelStatement:
    ( include
    | langsysAssign
    )
    SEMI
;

include:
    INCLUDE I_RPAREN IFILE I_LPAREN
;

langsysAssign:
    LANGSYS script=tag lang=tag
;

featureBlock:
    FEATURE starttag=tag LCBRACE
    statement+
    RCBRACE endtag=tag SEMI
;

statement:
    ( featureUse
    | substitute
    | include
    ) SEMI
;

featureUse:
    FEATURE tag
;

substitute: // XXX add except
      revtok startpat=pattern BY ( KNULL | endpat=pattern )
    | subtok startpat=pattern ( BY | FROM ) ( KNULL | endpat=pattern )
;

pattern:
    patternElement+
;

patternElement: // add lookup
    ( glyphClass | glyph ) MARKER?
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

tag:
    NAMELABEL | EXTNAME | CATCHTAG
;

subtok:
    SUB | SUBV
;

revtok:
    REV | REVV
;
