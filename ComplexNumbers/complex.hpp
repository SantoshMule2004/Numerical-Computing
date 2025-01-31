#include <iostream>

class Complex
{

private:
    double real;
    double imag;

public:
    Complex();
    double getReal();
    void setReal(double r);
    double getImag();
    void setImag(double i);
    Complex Complex::addComplexNum(Complex b);
    Complex Complex::substractComplexNum(Complex b);
};