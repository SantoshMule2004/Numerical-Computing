CC=g++
CCFLAGS=-c -I.
DEPS=Matrix.hpp
TARGET=matrix
OBJS=Main.o Matrix.o choleskyDecomposition.o croutsDecomposition.o doolittleDecomposition.o gaussElimination.o gaussSeidel.o gaussJacobi.o

%.o: %.cpp $(DEPS)
	$(CC) -o $@ $(CCFLAGS) $<

$(TARGET): $(OBJS)
	$(CC) -o $@ $^