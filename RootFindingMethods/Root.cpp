#include "Root.hpp"
using namespace std;

Root::Root()
{
    t = 0.0;
}

Root::Root(double t)
{
    this->t = t;
}

double Root::getT() const
{
    return t;
}

void Root::setT(double t)
{
    this->t = t;
}

// double Root::evaluatePolynomial(double x)
// {
//     return (4 * x * x * x - 3 * x);
//     // return (x * x - 5 * x + 5);
//     // return (x*x + 5)/5;
//     // return (2 * x * x - 1);
// }

// double Root::evaluatePolynomial(double x)
// {
//     return ptr(x);
// }

// double Root::evaluatePolynomialDerivative(double x)
// {
//     // return (4 * x * x * x - 3 * x);
//     // return (12 * x * x - 3);
//     return 2 * x - 5;
// }