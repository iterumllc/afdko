lexer grammar FeatLexer;
import FeatLexerBase;

@members {
    std::string anon_tag;
    bool is_anon_close(const std::string &str) {
        std::cout << "here " << str << std::endl;
        auto i = str.begin();
        if ( *i == '\r' )
            i++;
        if ( *i++ != '\n' )
            return false;
        if ( *i++ != '}' )
            return false;
        while ( *i == ' ' || *i == '\t' )
            i++;
        if ( str.compare(i-str.begin(), anon_tag.size(), anon_tag)!=0 )
            return false;
        i += anon_tag.size();
        while ( *i == ' ' || *i == '\t' )
            i++;
        if ( *i != ';' )
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

A_CLOSE    : '\r'? '\n}' [ \t]* TSTART+ [ \t]* ';' {is_anon_close(getText())}? -> popMode ;
A_LINE     : '\r'? '\n' ~[\r\n]* ;
