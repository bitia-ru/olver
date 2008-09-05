CC=g++
LL=g++

ANTLR = antlr
DLG = dlg

BIN_DIR = ./bin

LD_LIBRARY_PATH=$(BIN_DIR)

CFLAGS = -g -c -O0 -Wno-deprecated -fPIC

INCDIRS = ./external/PCCTS/h ./src

PCCTS_DIR = ./external/PCCTS/h
DEPTREE_DIR = ./src/deptree
HANDBOOK_DIR = ./src/handbook
CONFIGURATION_DIR = ./src/configuration
TESTPLAN_DIR = ./src/testplan
CONFIGPROCESSOR_DIR = ./src/configprocessor
TESTPLANPROCESSOR_DIR = ./src/testplanprocessor

PCCTS_SRC = \
		$(PCCTS_DIR)/AParser.cpp\
        $(PCCTS_DIR)/ASTBase.cpp\
        $(PCCTS_DIR)/ATokenBuffer.cpp\
        $(PCCTS_DIR)/BufFileInput.cpp\
        $(PCCTS_DIR)/DLexerBase.cpp\
        $(PCCTS_DIR)/PCCTSAST.cpp\
		$(PCCTS_DIR)/slist.cpp

DEPTREE_GRAMMAR = ./src/deptree/deptreegrammar.g
DEPTREE_GRAMMAR_SRC = \
	./src/deptree/deptreegrammar.cpp\
	./src/deptree/DepTreeParser.cpp\
	./src/deptree/DDlgLexer.cpp
DEPTREE_GRAMMAR_INC = \
	./src/deptree/DepTreeParser.h\
	./src/deptree/DDlgLexer.h\
	./src/deptree/dtokens.h\
	./src/deptree/parser.dlg

INCLUDES = $(addprefix -I ,$(INCDIRS))

DEPTREE_SRC = $(wildcard $(addsuffix /*.cpp,$(DEPTREE_DIR)))
HANDBOOK_SRC = $(wildcard $(addsuffix /*.cpp,$(HANDBOOK_DIR)))
CONFIGURATION_SRC = $(wildcard $(addsuffix /*.cpp,$(CONFIGURATION_DIR)))
TESTPLAN_SRC = $(wildcard $(addsuffix /*.cpp,$(TESTPLAN_DIR)))
CONFIGPROCESSOR_SRC = $(wildcard $(addsuffix /*.cpp,$(CONFIGPROCESSOR_DIR)))
TESTPLANPROCESSOR_SRC = $(wildcard $(addsuffix /*.cpp,$(TESTPLANPROCESSOR_DIR)))

SRCS = $(PCCTS_SRC) $(DEPTREE_SRC) $(HANDBOOK_SRC) $(CONFIGURATION_SRC) $(TESTPLAN_SRC) $(CONFIGPROCESSOR_SRC) $(TESTPLANPROCESSOR_SRC)

PCCTS_OBJECTS = $(patsubst %.cpp,%.o,$(PCCTS_SRC))
DEPTREE_OBJECTS = $(patsubst %.cpp,%.o,$(DEPTREE_SRC))
HANDBOOK_OBJECTS = $(patsubst %.cpp,%.o,$(HANDBOOK_SRC))
CONFIGURATION_OBJECTS = $(patsubst %.cpp,%.o,$(CONFIGURATION_SRC))
TESTPLAN_OBJECTS = $(patsubst %.cpp,%.o,$(TESTPLAN_SRC))
CONFIGPROCESSOR_OBJECTS = $(patsubst %.cpp,%.o,$(CONFIGPROCESSOR_SRC))
TESTPLANPROCESSOR_OBJECTS = $(patsubst %.cpp,%.o,$(TESTPLANPROCESSOR_SRC))

OBJECTS = $(patsubst %.cpp,%.o,$(SRCS))
DEPENDS = $(patsubst %.cpp,%.d,$(SRCS))

PCCTS_LIB = $(BIN_DIR)/libpccts.so
DEPTREE_LIB = $(BIN_DIR)/libdeptree.so
HANDBOOK_APP = $(BIN_DIR)/handbook
CONFIGURATION_LIB = $(BIN_DIR)/libconfiguration.so
TESTPLAN_LIB = $(BIN_DIR)/libtestplan.so
CONFIGPROCESSOR_APP = $(BIN_DIR)/configprocessor
TESTPLANPROCESSOR_APP = $(BIN_DIR)/testplanprocessor

.SUFFIXES:

all: $(HANDBOOK_APP) $(CONFIGPROCESSOR_APP) $(TESTPLANPROCESSOR_APP)
	@echo Build completed

include $(DEPENDS)

$(DEPENDS):%.d: $(DEPTREE_GRAMMAR_SRC)
	set -e; $(CC) -MM $(INCLUDES) $(CFLAGS) $*.cpp > $@
	echo "$*.d $(*D)/`cat $@`" > $@

$(OBJECTS):%.o:
	$(CC) $(INCLUDES) $(CFLAGS) $*.cpp -o $*.o

$(DEPTREE_GRAMMAR_SRC) $(DEPTREE_GRAMMAR_INC): $(DEPTREE_GRAMMAR)
	$(ANTLR) -CC $(DEPTREE_GRAMMAR) -o ./src/deptree -ft dtokens.h  -nopurify
	$(DLG) -CC -C1 -i -ci ./src/deptree/parser.dlg -o ./src/deptree -cl DDlgLexer

$(PCCTS_LIB): $(PCCTS_OBJECTS)
	$(LL) -shared -o $(PCCTS_LIB) $(PCCTS_OBJECTS)

$(DEPTREE_LIB): $(PCCTS_LIB) $(DEPTREE_OBJECTS)
	$(LL) -shared -o $(DEPTREE_LIB) $(DEPTREE_OBJECTS)

$(HANDBOOK_APP): $(DEPTREE_LIB) $(CONFIGURATION_LIB) $(TESTPLAN_LIB) $(HANDBOOK_OBJECTS)
	$(LL) -o $(HANDBOOK_APP) $(HANDBOOK_OBJECTS) -L $(BIN_DIR) -ldeptree -lconfiguration -ltestplan -lpccts
	
$(CONFIGURATION_LIB): $(CONFIGURATION_OBJECTS)
	$(LL) -shared -o $(CONFIGURATION_LIB) $(CONFIGURATION_OBJECTS)
	
$(TESTPLAN_LIB): $(TESTPLAN_OBJECTS)
	$(LL) -shared -o $(TESTPLAN_LIB) $(TESTPLAN_OBJECTS)
	
$(CONFIGPROCESSOR_APP): $(CONFIGURATION_LIB) $(CONFIGPROCESSOR_OBJECTS)
	$(LL) -o $(CONFIGPROCESSOR_APP) $(CONFIGPROCESSOR_OBJECTS) -L $(BIN_DIR) -lconfiguration
	
$(TESTPLANPROCESSOR_APP): $(TESTPLAN_LIB) $(TESTPLANPROCESSOR_OBJECTS)
	$(LL) -o $(TESTPLANPROCESSOR_APP) $(TESTPLANPROCESSOR_OBJECTS) -L $(BIN_DIR) -ltestplan


clean:
	-rm -rf $(DEPENDS)
	-rm -rf $(OBJECTS)
	-rm -rf $(BIN_DIR)/*.so
	-rm -rf $(HANDBOOK_APP)
	-rm -rf $(CONFIGPROCESSOR_APP)
	-rm -rf $(TESTPLANPROCESSOR_APP)
