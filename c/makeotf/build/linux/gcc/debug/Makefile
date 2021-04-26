#########################################################################
#                                                                       #
# Copyright 1997-2014 Adobe Systems Incorporated.                       #
# All rights reserved.                                                  #
#                                                                       #
#########################################################################

# Configuration
CONFIG = debug
ROOT_DIR = ../../../..
OBJECT_DIR = .
LIB_DIR = $(ROOT_DIR)/makeotf_lib/lib/$(PLATFORM)/$(CONFIG)
LIB_BUILD_DIR = $(ROOT_DIR)/makeotf_lib/build
CT_LIB_DIR = $(ROOT_DIR)/../public/lib/lib/$(PLATFORM)/$(CONFIG)
CT_LIB_BUILD_DIR = $(ROOT_DIR)/../public/lib/build

INC_FLAGS =                     -I$(ROOT_DIR)/source/include_files \
				-I$(ROOT_DIR)/makeotf_lib/api \
				-I$(ROOT_DIR)/makeotf_lib/resource

CFLAGS = $(STD_OPTS) $(INC_FLAGS) -DMAKEOTFLIB_EXPORTS=1 -g
CXXFLAGS = $(STD_OPTS) $(INC_FLAGS) -DMAKEOTFLIB_EXPORTS=1 -g

OBJS = cb.o cbpriv.o c_main.o fcdb.o file.o mac.o main.o

CT_LIBS = ctutil.a dynarr.a
LIBS = hotconv.a pstoken.a typecomp.a cffread.a

PRG_OBJS = $(addprefix $(OBJECT_DIR)/,$(OBJS))

PRG_LIBS = $(addprefix $(CT_LIB_DIR)/,$(CT_LIBS)) \
           $(addprefix $(LIB_DIR)/,$(LIBS))

PRG_CXX_TARGET = $(EXE_DIR)/makeotfexe


# Build targets
TARGETS = $(PRG_CXX_TARGET)

# Standard definitions
include ../../../../../public/config/linux/gcc/gcc.mak

$(EXE_DIR)/makeotfexe : CXXFLAGS = $(STD_OPTS) -lantlr4-runtime -g

# program rule is in gcc.mak

# Object rules

$(OBJECT_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Lib rules
#
$(CT_LIB_DIR)/%.a: LB_DIR = $(CT_LIB_BUILD_DIR)
$(LIB_DIR)/%.a: LB_DIR = $(LIB_BUILD_DIR)

CLEAN_TOPS = $(addprefix $(CT_LIB_BUILD_DIR)/,$(basename $(CT_LIBS))) \
             $(addprefix $(LIB_BUILD_DIR)/,$(basename $(LIBS)))

CLEAN_DIRS = $(addsuffix /$(PLATFORM)/$(COMPILER)/$(CONFIG), $(CLEAN_TOPS))

%.a:
	$(MAKE) -C $(LB_DIR)/$(*F)/$(PLATFORM)/$(COMPILER)/$(CONFIG)
