lexer grammar FeatLexer;
import FeatLexerBase;

@members {
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
A_CLOSE    : '\r'? '\n}' [ \t]* TSTART+ [ \t]* ';' {verify_anon(getText())}? -> popMode ;
A_LINE     : '\r'? '\n' ~[\r\n]* ;
