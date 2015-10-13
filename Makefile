

#CXX=g++
CXX=clang++

BINARIES = setTests01

CXXFLAGS = -g  --std=c++11
#CXXFLAGS = -Lgtest

#LDFLAGS = -lgtest -lgtest_main -lstdc++

LDFLAGS=-lgtest_main -lgtest

all: ${BINARIES}

tests: test

test: ${BINARIES}
	./setTests01

setTests01: setTests01.o set.o
	${CXX} $(LDFLAGS) $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o

