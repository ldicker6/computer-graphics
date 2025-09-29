TARGET = jpeg
SOURCE = ckconfig.cpp jcapimin.cpp jcapistd.cpp jccoefct.cpp jccolor.cpp jcdctmgr.cpp jchuff.cpp jcinit.cpp     jcmainct.cpp jcmarker.cpp jcmaster.cpp jcomapi.cpp jcparam.cpp jcphuff.cpp jcprepct.cpp jcsample.cpp jctrans.cpp jdapimin.cpp jdapistd.cpp jdatadst.cpp jdatasrc.cpp jdcoefct.cpp jdcolor.cpp jddctmgr.cpp jdhuff.cpp jdinput.cpp jdmainct.cpp jdmarker.cpp jdmaster.cpp jdmerge.cpp jdphuff.cpp jdpostct.cpp jdsample.cpp jdtrans.cpp jerror.cpp jfdctflt.cpp jfdctfst.cpp jfdctint.cpp jidctflt.cpp jidctfst.cpp jidctint.cpp jidctred.cpp jmemmgr.cpp jmemnobs.cpp jquant1.cpp jquant2.cpp jutils.cpp



TARGET_LIB = lib$(TARGET).a

CFLAGS += -I. -I.. -std=c++20 -Wunused-result

CFLAGS_DEBUG = -DDEBUG -g3
CFLAGS_RELEASE = -O3 -DRELEASE -funroll-loops -ffast-math -DNDEBUG

SRC = ./
BIN = ../
BIN_O = ../Bin/Linux/Release/$(TARGET)/
INCLUDE = /usr/include/

CC  = gcc
CXX = g++
MD  = mkdir
AR  = ar

OBJECTS=$(addprefix $(BIN_O), $(addsuffix .o, $(basename $(SOURCE))))

all: CFLAGS += $(CFLAGS_RELEASE)
all: $(BIN)
all: $(BIN_O)
all: $(BIN)$(TARGET_LIB)

allNoGL: CFLAGS += $(CFLAGS_RELEASE)
allNoGL: $(BIN)
allNoGL: $(BIN_O)
allNoGL: $(BIN)$(TARGET_LIB)

debug: CFLAGS += $(CFLAGS_DEBUG)
debug: $(BIN)
debug: $(BIN)$(TARGET_LIB)

clean:
	rm -f $(BIN)$(TARGET_LIB)
	rm -f $(OBJECTS)

depend:
	makedepend -- $(CFLAGS) -- -Y $(SOURCE)

$(BIN):
	$(MD) -p $(BIN)

$(BIN_O):
	$(MD) -p $(BIN_O)

$(BIN)$(TARGET_LIB): $(OBJECTS)
	$(AR) rcs $@ $(OBJECTS)

$(BIN_O)%.o: $(SRC)%.c
	$(CC) -c -o $@ $(CFLAGS) -I$(INCLUDE) $<

$(BIN_O)%.o: $(SRC)%.cpp
	$(CXX) -c -o $@ $(CFLAGS) -I$(INCLUDE) $<
	
# DO NOT DELETE

jcapimin.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jcapistd.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jccoefct.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jccolor.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jcdctmgr.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jcdctmgr.o: jdct.h
jchuff.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jchuff.o: jchuff.h
jcinit.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jcmainct.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jcmarker.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jcmaster.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jcomapi.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jcparam.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jcphuff.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jcphuff.o: jchuff.h
jcprepct.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jcsample.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jctrans.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jdapimin.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jdapistd.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jdatadst.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jdatasrc.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jdcoefct.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jdcolor.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jddctmgr.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jddctmgr.o: jdct.h
jdhuff.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jdhuff.o: jdhuff.h
jdinput.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jdmainct.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jdmarker.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jdmaster.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jdmerge.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jdphuff.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jdphuff.o: jdhuff.h
jdpostct.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jdsample.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jdtrans.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jerror.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jerror.o: jversion.h
jfdctflt.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jfdctflt.o: jdct.h
jfdctfst.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jfdctfst.o: jdct.h
jfdctint.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jfdctint.o: jdct.h
jidctflt.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jidctflt.o: jdct.h
jidctfst.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jidctfst.o: jdct.h
jidctint.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jidctint.o: jdct.h
jidctred.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jidctred.o: jdct.h
jmemmgr.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jmemmgr.o: jmemsys.h
jmemnobs.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jmemnobs.o: jmemsys.h
jquant1.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jquant2.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
jutils.o: jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h jerror.h
