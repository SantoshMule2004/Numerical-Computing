CC=g++
CCFLAGS=-c -I.
DEPS=Interpolation.hpp
TARGET=interpolation
MATRIX_DIR = ../MatrixOperations
MATRIX_OBJS = $(MATRIX_DIR)/Matrix.o $(MATRIX_DIR)/gaussElimination.o $(MATRIX_DIR)/choleskyDecomposition.o $(MATRIX_DIR)/croutsDecomposition.o $(MATRIX_DIR)/doolittleDecomposition.o $(MATRIX_DIR)/gaussSeidel.o $(MATRIX_DIR)/gaussJacobi.o
OBJS=Main.o Interpolation.o LagrangesPolynomial.o LeastSquare.o Polynomial.o $(MATRIX_OBJS)

%.o: %.cpp $(DEPS)
	$(CC) -o $@ $(CCFLAGS) $<

$(TARGET): $(OBJS)
	$(CC) -o $@ $^