

#CXX=g++
CXX=clang++

BINARIES = setTests01

CXXFLAGS =
#CXXFLAGS = -Lgtest

#LDFLAGS = -lgtest -lgtest_main -lstdc++

LDFLAGS=-lgtest_main -lgtest

all: ${BINARIES}

setTests01: setTests01.o set.o
	${CXX} $(LDFLAGS) $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o

