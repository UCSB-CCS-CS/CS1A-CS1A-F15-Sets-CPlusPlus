

CXX=g++
# CXX=clang++

BINARIES = setTests01

CXXFLAGS = -Lgtest
LDFLAGS = -lgtest -lgtest_main -lstdc++

all: ${BINARIES}

setTests01: setTests01.o set.o
	${CXX} $(LDFLAGS) $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o

