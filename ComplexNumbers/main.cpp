#include "complex.hpp"
using namespace std;

int main()
{
    Complex a;
    a.setReal(4.0);
    a.setImag(5.0);

    Complex b;
    b.setReal(3.0);
    b.setImag(2.0);

    // Complex c = a + b;
    // Complex c = a - b;
    // Complex c = a * b;
    Complex c = a / b;

    c.displayComplexNumber();

    return 0;
}