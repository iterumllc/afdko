parser grammar FeatParser;

options { tokenVocab = FeatLexer; }

tag:
	NAMELABEL | EXTNAME | CATCHTAG
;

glyph:
	ESCGNAME | NAMELABEL | EXTNAME
;

glyphclass:
	GCLASS
;

pattern:
	( glyph | glyphclass )+
;

substitute:
	SUB startpat=pattern ( BY | FROM ) endpat=pattern
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
