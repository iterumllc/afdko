# Copyright 2021 Adobe Systems Incorporated (http://www.adobe.com/). All Rights Reserved.
# This software is licensed as OpenSource, under the Apache License, Version 2.0. 
# This license is available at: http://opensource.org/licenses/Apache-2.0.

all: FeaParser.cpp

SRC_DIR = .
ANTLR4	= antlr4

ANTLR_FLAGS = -no-listener -Dlanguage=Cpp

FeaLexer.cpp: FeaLexer.g4
	$(ANTLR4) $(ANTLR_FLAGS) $<

FeaParser.cpp: FeaParser.g4 FeaLexer.cpp
	$(ANTLR4) $(ANTLR_FLAGS) -visitor $<

LEX_FILES = FeaLexer.interp FeaLexer.h FeaLexer.tokens FeaLexer.cpp

PARSE_FILES = FeaParser.interp FeaParser.h FeaParserVisitor.h \
              FeaParserVisitor.cpp FeaParser.cpp FeaParserBaseVisitor.h \
              FeaParserBaseVisitor.cpp FeaParser.tokens

clean:
	$(RM) -f $(LEX_FILES) $(PARSE_FILES)
