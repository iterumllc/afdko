lexer grammar FeatLexer;
import FeatLexerBase;

@members {
 std::string anon_tag;
}

ANON        : 'anon' -> pushMode(Anon) ;
ANONV       : 'anonymous' -> pushMode(Anon) ;

mode Anon;

A_WHITESPACE    : [ \t\r\n]+ -> skip ;
A_LABEL    : TSTART+ { anon_tag = getText(); } ;
A_LBRACE    : '{' -> mode(AnonContent) ;

mode AnonContent;

// The only TSTART characters allowed in the closing line
// must be grouped together, so just search for that
// string in A_CLOSE as the semantic predicate.
A_CLOSE    : '\r'? '\n}' [ \t]* TSTART+ [ \t]* ';' {getText().find(anon_tag) != std::string::npos}? -> popMode ;
A_LINE     : '\r'? '\n' ~[\r\n]* ;
