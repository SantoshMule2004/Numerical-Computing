#include "Complex.hpp"
using namespace std;

Complex::Complex()
{
    this->real = 0.0;
    this->imag = 0.0;
}

Complex::Complex(double real, double imag)
{
    this->real = real;
    this->imag = imag;
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
void Complex::displayComplexNumber() const
{
    std::cout << "Real :" << this->real << " Imaginary :" << this->imag << "i" << std::endl;
}

Complex Complex::operator=(Complex &c)
{
    this->real = c.getReal();
    this->imag = c.getImag();
    return (*this);
}

Complex Complex::operator+(Complex &c) const
{
    Complex a;
    a.setReal(this->real + c.getReal());
    a.setImag(this->imag + c.getImag());
    return a;
}

Complex Complex::operator-(Complex &c) const
{
    Complex a;
    a.setReal(this->real - c.getReal());
    a.setImag(this->imag - c.getImag());
    return a;
}

Complex Complex::operator*(Complex &c) const
{
    Complex c;
    c.setReal((this->real * c.getReal()) - (this->imag * c.getImag()));
    c.setImag((this->real * c.getImag()) + (this->imag * c.getReal()));
    return c;
}

Complex Complex::operator/(Complex &b) const
{
    Complex c;
    c.setReal(((this->real * b.getReal()) + (this->imag * b.getImag())) / ((b.getReal() * b.getReal()) + (b.getImag() * b.getImag())));
    c.setImag(((this->imag * b.getReal()) - (this->real * b.getImag())) / ((b.getReal() * b.getReal()) + (b.getImag() * b.getImag())));
    return c;
}

double Complex::normOfComplex() const
{
    double r;
    r = sqrt((this->real * this->real) + (this->imag * this->imag));
    return r;
}