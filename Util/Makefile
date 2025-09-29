TARGET = Util
SOURCE = geometry.cpp geometry.todo.cpp interpolation.cpp poly34.cpp threads.cpp

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
	makedepend -- $(CFLAGS) -- -I../SVD -Y $(SOURCE)

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

geometry.o: ../SVD/SVDFit.h ../SVD/MatrixMNTC.h ../SVD/MatrixMNTC.inl
geometry.o: ../SVD/SVD.h ../SVD/SVD.inl ../SVD/SVDFit.inl ../SVD/MatrixMNTC.h
geometry.o: ../Util/exceptions.h geometry.h ../Util/algebra.h geometry.inl
geometry.o: geometry.todo.inl
geometry.todo.o: ../SVD/SVDFit.h ../SVD/MatrixMNTC.h ../SVD/MatrixMNTC.inl
geometry.todo.o: ../SVD/SVD.h ../SVD/SVD.inl ../SVD/SVDFit.inl
geometry.todo.o: ../SVD/MatrixMNTC.h ../Util/exceptions.h geometry.h
geometry.todo.o: ../Util/algebra.h geometry.inl geometry.todo.inl
interpolation.o: ../Util/interpolation.h interpolation.todo.inl
interpolation.o: ../Util/exceptions.h
poly34.o: poly34.h
threads.o: threads.h exceptions.h
