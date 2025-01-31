#include "complex.hpp"
using namespace std;

int main()
{
    Complex a;
    a.setReal(6.0);
    a.setImag(-5.0);

    Complex b;
    b.setReal(3.0);
    b.setImag(7.0);

    //Complex c = a.addComplexNum(b);

    Complex c = a.multiplyComplexNum(b);

    cout << c.getReal() << " + " << c.getImag() << "i" << endl;

    return 0;
}