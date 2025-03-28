CC=g++
CCFLAGS=-c -I.
DEPS=Interpolation.hpp
TARGET=interpolation
OBJS=Main.o Interpolation.o LagrangesPolynomial.o LeastSquare.o

%.o: %.cpp $(DEPS)
	$(CC) -o $@ $(CCFLAGS) $<

$(TARGET): $(OBJS)
	$(CC) -o $@ $^