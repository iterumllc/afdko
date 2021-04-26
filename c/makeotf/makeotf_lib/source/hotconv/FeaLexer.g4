lexer grammar FeaLexer;

COMMENT		: '#' ~[\r\n]* -> skip ;
WHITESPACE	: [ \t\r\n]+ -> skip ;
BY		: 'by' ;
FROM		: 'from' ;
FEATURE		: 'feature';
SUB		: 'substitute' | 'sub' ;
INCLUDE		: 'include' -> pushMode(Include) ;
LCBRACE		: '{' ;
RCBRACE		: '}' ;
SEMI		: ';' ;
fragment GNST	: 'A'..'Z' | 'a' .. 'z' | '0' .. '9' | '_' | '.' ;
GCLASS		: '@' ( GNST | '-' )+ ;
fragment GNCHR	: GNST | '-' | '+' | '*' | ':' | '~' | '^' | '!' ;
ESCGNAME	: '\\' GNST GNCHR? ;
NAMELABEL	: GNST+ ;
EXTNAME		: GNST GNCHR? ;
fragment TSTART : '!' .. ':' | '<' .. '~' ;
CATCHTAG	: TSTART+ ;

mode Include;

I_WHITESPACE	: [ \t\r\n]+ -> skip ;
I_RPAREN	: '(' -> pushMode(Ifile) ;

mode Ifile;

IFILE		: ~')'+ ;
I_LPAREN	: ')' -> popMode,popMode ;
