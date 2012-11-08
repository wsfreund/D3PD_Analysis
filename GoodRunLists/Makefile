CC=g++

INCLUDES=Makefile

LIB=libGRL.so

LIB_OBJ= StrUtil.o TMsgLogger.o TUniqueGRLString.o TLumiBlockRange.o TGoodRun.o TGoodRunsList.o \
         TGRLCollection.o TGoodRunsListReader.o rootdic.o
LIB_INC= StrUtil.h TMsgLogger.h TUniqueGRLString.h TLumiBlockRange.h TGoodRun.h TGoodRunsList.h \
         TGRLCollection.h TGoodRunsListReader.h

#INCFLAGS=-m32 -I$(shell root-config --incdir) -O
INCFLAGS=$(shell root-config --cflags) -fPIC

##INCFLAGS=-m32 -I$(shell root-config --incdir) -I$(TestArea)/DataQuality/GoodRunsLists/  -O
# decomment the line and follow the GRL tutorial for standalone usage

ROOTLIBS = $(shell root-config --libs)  -lvectorDict -lXMLIO -lXMLParser -fPIC
# -lTreePlayer
LIBS= $(shell root-config --ldflags) $(ROOTLIBS)
##LIBS=-m32 -L$(TestArea)/DataQuality/GoodRunsLists/StandAlone/ $(ROOTLIBS) -ldl -lGoodRunsLists
# decomment the line and follow the GRL tutorial for standalone usage

INCLUDES=Makefile

$(LIB): $(LIB_OBJ) $(INCLUDES)
	@echo "**"
	@echo "** Linking Executable RUN"
	@echo "**"
	$(CC) $(LIB_OBJ) -shared $(LIBS) -o $(LIB)

%.o: %.cxx $(INCLUDES)
	@echo "**"
	@echo "** Compiling C++ Source"
	@echo "**"
	$(CC) -Wall -c $(INCFLAGS) $<

clean:
	@echo Cleaning all objects and executables
	@rm -rf *.o *.so


rootdic.cxx: $(LIB_INC) LinkDef.h
	@echo "**"
	@echo "** Creating Root dictionary"
	@echo "**"
	rootcint -f $@ -c -I./ -p $^

# Hack to avoid need to re-run make file following code generation target.
rootdic.o: rootdic.cxx
	@echo "**"
	@echo "** Compiling C++ Source" 
	@echo "**"
	$(CC) -Wall -I./ -c $(CCFLAGS) $(INCFLAGS) $^ -o $@

