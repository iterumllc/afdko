parser grammar FeatParser;

options { tokenVocab = FeatLexer; }

tag:
	NAMELABEL | EXTNAME | CATCHTAG
;

glyphName:
	ESCGNAME | NAMELABEL | EXTNAME
;

glyph:
      glyphName
    | CID
;

// XXX The gcLiteral/glyphOrRange grammar parses "a - z" as
// a "range" and "a-z" as a "glyph"; the latter must be handled
// when walking the tree. The grammar doesn't address "a- z",
// where "a-" will be treated as a glyph but not associated with
// "z".
gcLiteralElement:
    startg=glyph ( HYPHEN endg=glyph )?
    | GCLASS
;

gcLiteral:
    LBRACKET gcLiteralElement+ RBRACKET
;

glyphClass:
	GCLASS | gcLiteral
;

patternElement: // add lookup
	( glyph | glyphClass ) MARKER?
;

pattern:
	patternElement+
;

substitute: // XXX add except
      REV startpat=pattern BY ( KNULL | endpat=pattern )
	| SUB startpat=pattern ( BY | FROM ) ( KNULL | endpat=pattern )
;

include:
	INCLUDE I_RPAREN IFILE I_LPAREN
;

statement:
	( substitute
	| include
	) SEMI
;

topLevelStatement:
	( include
	)
	SEMI
;

featureBlock:
	FEATURE starttag=tag LCBRACE
	statement+
	RCBRACE endtag=tag SEMI
;

featureFile:
	( topLevelStatement
	| featureBlock
	)* EOF
;
