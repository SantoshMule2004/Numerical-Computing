#include "Root.hpp"
using namespace std;

double Root::NewtonRaphson(double a, double (*fx)(double), double (*dfx)(double))
{
    // std::cout << "| x |" << " f(x) |" << " f'(x) |" << std::endl;
    double x = fx(a) / dfx(a);

    // std::cout << std::fixed << std::setprecision(4) << a << " | " << evaluatePolynomial(a) << " | " << evaluatePolynomialDerivative(a) << std::endl;

    while (std::abs(x) >= t)
    {
        x = fx(a) / dfx(a);
        a = a - x;

        // std::cout << std::fixed << std::setprecision(4) << a << " | " << evaluatePolynomial(a) << " | " << evaluatePolynomialDerivative(a) << std::endl;
    }
    return a;
}