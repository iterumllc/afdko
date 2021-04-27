#########################################################################
#                                                                       #
# Copyright 2014 Adobe Systems Incorporated.                       #
# All rights reserved.                                                  #
#                                                                       #
#########################################################################

# Configuration
CONFIG = release

.DEFAULT_GOAL: default

# Library
ROOT_DIR = $(realpath ../../../../..)
SRC_DIR = $(ROOT_DIR)/source/hotconv
OBJECT_DIR = .
LIB_TARGET = $(LIB_DIR)/hotconv.a

INC_FLAGS = -I$(ROOT_DIR)/api \
            -I$(ROOT_DIR)/resource \
            -I$(ROOT_DIR)/build/hotpccts/pccts/h \
            -I$(realpath $(ROOT_DIR)/../../public/lib/api) \
            -I$(realpath $(ROOT_DIR)/../../public/lib/resource) \
            -I/usr/include/antlr4-runtime

CXXFLAGS = $(STD_OPTS) $(INC_FLAGS) -DHOT_FEAT_SUPPORT=1 -Wall -Wno-attributes -std=c++11
CFLAGS = $(STD_OPTS) $(INC_FLAGS) -DHOT_FEAT_SUPPORT=1 -Wall

# PARSE_OBJS = featerr.o featgram.o featscan.o

PARSE_OBJS = FeatLexer.o FeatParser.o FeatParserVisitor.o FeatParserBaseVisitor.o FeatVisitor.o FeatCtx.o

OBJS = anon.o BASE.o CFF_.o cmap.o $(PARSE_OBJS) \
       GDEF.o GPOS.o GSUB.o head.o hhea.o hmtx.o hot.o map.o maxp.o \
       name.o OS_2.o otl.o post.o sfnt.o STAT.o vhea.o vmtx.o VORG.o

LIB_OBJS = $(addprefix $(OBJECT_DIR)/,$(OBJS))

# Standard definitions
include  $(ROOT_DIR)/../../public/lib/config/linux/gcc/gcc.mak

$(OBJECT_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
