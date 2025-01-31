#include "Complex.hpp"
using namespace std;

Complex::Complex()
{
    cout << "constructor method" << endl;
}

double Complex::getReal() const
{
    return this->real;
}
void Complex::setReal(double r)
{
    this->real = r;
}

double Complex::getImag() const
{
    return this->imag;
}
void Complex::setImag(double i)
{
    this->imag = i;
}

Complex Complex::addComplexNum(Complex b)
{
    Complex a;
    a.real = this->real + b.real;
    a.imag = this->imag + b.imag;
    return a;
}

Complex Complex::substractComplexNum(Complex b)
{
    Complex a;
    a.real = this->real - b.real;
    a.imag = this->imag - b.imag;
    return a;
}

Complex Complex::multiplyComplexNum(Complex b)
{
    Complex c;
    c.real = (this->real * b.getReal()) - (this->imag * b.getImag());
    c.imag = (this->real * b.getImag()) + (this->imag * b.getReal());
    return c;
}