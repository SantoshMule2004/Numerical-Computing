#include "Root.hpp"
using namespace std;

double evaluatePolynomial(double x)
{
    // return (4 * x * x * x - 3 * x);
    // return (x*x - 5*x + 5);
    return (x*x + 5)/5;
}

double evaluatePolynomialDerivative(double x)
{
    // return (4 * x * x * x - 3 * x);
    // return (12 * x * x - 3);
    return 2 * x - 5;
}

int main(){

    Root r;
    r.setT(0.0001);

    double a,b;

    // cout << "enter range :" << endl;
    // cin >> a >> b;

    // double x = r.BisectionMethod(a, b, evaluatePolynomial);

    // double y = r.NewtonRaphson(1.0, evaluatePolynomial, evaluatePolynomialDerivative);

    double x = r.FixedPointMethod(1.0, evaluatePolynomial);

    // cout << "Root of polynomial (bisection) :" << x << endl;

    // cout << "Root of polynomial (newton) :" << y << endl;

    cout << "Root of polynomial (fixed point) :" << x << endl;

    return 0;
}