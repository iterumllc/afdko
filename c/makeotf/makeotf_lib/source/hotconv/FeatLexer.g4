lexer grammar FeatLexer;

COMMENT		: '#' ~[\r\n]* -> skip ;
WHITESPACE	: [ \t\r\n]+ -> skip ;
BY		: 'by' ;
FROM		: 'from' ;
FEATURE		: 'feature';
SUB		: 'substitute' ;
SUBV		: 'sub' ;
REV		: 'reversesub' ;
REVV	: 'rsub' ;
LANGSYS : 'languagesystem' ;
KNULL   : 'NULL' ;
INCLUDE		: 'include' -> pushMode(Include) ;
LCBRACE		: '{' ;
RCBRACE		: '}' ;
LBRACKET    : '[' ;
RBRACKET    : ']' ;
HYPHEN      : '-' ;
SEMI		: ';' ;
MARKER      : '\'' ;
QUOTE       : '"' -> pushMode(String) ;
fragment GNST	: 'A'..'Z' | 'a' .. 'z' | '_' | '.' ;
fragment GCCHR	: GNST | '0' .. '9' | '-' ;
GCLASS		: '@' GCCHR+ ;
CID         : '\\' ( '0' .. '9' )+ ;
fragment GNCHR	: GCCHR | '+' | '*' | ':' | '~' | '^' | '|' ; // XXX change from source
ESCGNAME	: '\\' GNST GNCHR* ;
NAMELABEL	: GNST+ ;
EXTNAME		: GNST GNCHR* ;
fragment TSTART : '!' | '$' | '%' | '&' | '*' | '+' | '-' .. ':' | '?' | 'A' .. 'Z' | '^' .. 'z' | '|' | '~' ; // XXX change from source
CATCHTAG	: TSTART+ ;

mode Include;

I_WHITESPACE	: [ \t\r\n]+ -> skip ;
I_RPAREN	: '(' -> pushMode(Ifile) ;

mode Ifile;

IFILE		: ~')'+ ;
I_LPAREN	: ')' -> popMode,popMode ;

mode String;

STRVAL      : ~'"'* ;
EQUOTE      : '"' -> popMode ;
