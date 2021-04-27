# Copyright 2021 Adobe Systems Incorporated (http://www.adobe.com/). All Rights Reserved.
# This software is licensed as OpenSource, under the Apache License, Version 2.0. 
# This license is available at: http://opensource.org/licenses/Apache-2.0.

all: FeatParser.cpp

SRC_DIR = .
ANTLR4	= antlr4

ANTLR_FLAGS = -no-listener -Dlanguage=Cpp

FeatLexer.cpp: FeatLexer.g4
	$(ANTLR4) $(ANTLR_FLAGS) $<

FeatParser.cpp: FeatParser.g4 FeatLexer.cpp
	$(ANTLR4) $(ANTLR_FLAGS) -visitor $<

LEX_FILES = FeatLexer.interp FeatLexer.h FeatLexer.tokens FeatLexer.cpp

PARSE_FILES = FeatParser.interp FeatParser.h FeatParserVisitor.h \
              FeatParserVisitor.cpp FeatParser.cpp FeatParserBaseVisitor.h \
              FeatParserBaseVisitor.cpp FeatParser.tokens

clean:
	$(RM) -f $(LEX_FILES) $(PARSE_FILES)
