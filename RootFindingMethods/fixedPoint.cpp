#include "Root.hpp"
using namespace std;

double Root::FixedPointMethod(double x, double (*func)(double))
{
    // std::cout << "| x |" << " f(x) |" << std::endl;

    double fx = func(x);
    // std::cout << std::fixed << std::setprecision(4) << x << " | " << fx << std::endl;

    while (std::abs(fx - x) >= t)
    {
        x = fx;
        fx = func(x);
        // std::cout << std::fixed << std::setprecision(4) << x << " | " << fx << std::endl;
    }
    return x;
}