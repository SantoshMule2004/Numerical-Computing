#include <iostream>

class Complex
{

private:
    double real;
    double imag;

public:
    Complex();
    double getReal() const;
    void setReal(double r);
    double getImag() const;
    void setImag(double i);
    Complex addComplexNum(Complex b);
    Complex substractComplexNum(Complex b);
    Complex multiplyComplexNum(Complex b);
};