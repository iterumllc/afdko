# Copyright 2021 Adobe Systems Incorporated (http://www.adobe.com/). All Rights Reserved.
# This software is licensed as OpenSource, under the Apache License, Version 2.0. 
# This license is available at: http://opensource.org/licenses/Apache-2.0.

all: featgram

SRC_DIR = .
ANTLR4	= antlr4

ANTLR_FLAGS = -no-listener -Dlanguage=Cpp

featgram: FeaParser.cpp

FeaLexer.cpp: FeaLexer.g4
	$(ANTLR4) $(ANTLR_FLAGS) $<

FeaParser.cpp: FeaParser.g4 FeaLexer.cpp
	$(ANTLR4) $(ANTLR_FLAGS) -visitor $<
