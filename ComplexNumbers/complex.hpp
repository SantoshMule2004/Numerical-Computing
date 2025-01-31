#include <iostream>

class Complex
{
private:
    double real;
    double imag;

public:
    Complex();
    Complex(double real, double imag);
    double getReal() const;
    void setReal(double r);
    double getImag() const;
    void setImag(double i);
    Complex addComplexNum(Complex b);
    Complex substractComplexNum(Complex b);
    Complex multiplyComplexNum(Complex b);
};