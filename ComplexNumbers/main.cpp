#include "complex.hpp"
using namespace std;

int main()
{
    Complex a;
    a.setReal(1.0);
    a.setImag(2.0);

    Complex b;
    b.setReal(2.0);
    b.setImag(3.0);

    Complex c = a.addComplexNum(b);

    cout << c.getReal() << " + " << c.getImag() << "i" << endl;
}