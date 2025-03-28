#include "Root.hpp"
using namespace std;

void Root::bracketingInterval(double m, double n, double &a, double &b, double (*fx)(double))
{
    int i, j;
    int flag = 0;
    for (i = m; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (fx(i) * fx(j) < 0)
            {
                a = i;
                b = j;
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            break;
    }
}

double Root::BisectionMethod(double m, double n, double (*fx)(double))
{
    double a,b;
    bracketingInterval(m, n, a, b, fx);

    if (fx(a) * fx(b) >= 0)
        std::cout << "wrong interval..!" << std::endl;
    double x;

    // std::cout << "| a |" << " b |" << " f(a) |" << " f(b) |" << " x |" << " f(x) |" << std::endl;
    while (abs(b - a) >= t)
    {
        x = (a + b) / 2;

        // std::cout << std::fixed << std::setprecision(4) << "| " << a << " | " << b << " | " << evaluatePolynomial(a) << " | " << evaluatePolynomial(b) << " | " << x << " | " << evaluatePolynomial(x) << std::endl;

        if (fx(x) == 0.00)
            break;

        else if (fx(x) * fx(a) < 0)
            b = x;
        else
            a = x;
    }
    return x;
}