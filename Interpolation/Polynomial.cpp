#include"Polynomial.hpp"
using namespace std;

Polynomial::Polynomial()
{
    p = {0};
}

Polynomial::Polynomial(vector<double> p)
{
    this->p = p;
}

void Polynomial::display()
{
    int xPower = p.size() - 1;;
    for(int i=(p.size() - 1); i>=0; i--)
    {
        cout << p[i] << "x^" << xPower << " + " ;
        xPower--;
    }
}

double Polynomial::evaluatePolynomial(double x)
{
    double result(0);
    double xPower = 1;

    for(double coef : p) {
        result += coef * xPower;
        xPower *= x;
    }
    return result;
}

double Polynomial::evaluateExpoPolynomial(double x)
{
    double result(0);
    result += (p[0]) * (exp(p[1] * x));
    return result;
}

double Polynomial::evaluatePowerPolynomial(double x)
{
    double result(0);
    result += (p[0]) * (pow(x, p[1]));
    return result;
}