#include <iostream>
#include<cmath>

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
    void displayComplexNumber() const;

    Complex operator=(Complex& c);
    Complex operator+(Complex& c) const;
    Complex operator-(Complex& c) const;
    Complex operator*(Complex& c) const;
    Complex operator/(Complex& c) const;

    double normOfComplex() const;
};