#include "Complex.hpp"
using namespace std;

Complex::Complex()
{
    cout << "constructor method" << endl;
}

double Complex::getReal()
{
    return this->real;
}
void Complex::setReal(double r)
{
    this->real = r;
}

double Complex::getImag()
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