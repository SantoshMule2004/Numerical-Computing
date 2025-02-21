#include <iostream>
#include <iomanip>
#include <cmath>

class Root
{
private:
    double t;

public:
    Root();
    Root(double);
    double getT() const; 
    void setT(double);
    // double evaluatePolynomial(double);
    void bracketingInterval(double x, double y, double &, double &, double (*fx)(double));
    double BisectionMethod(double, double, double (*fx)(double));
    // double evaluatePolynomialDerivative(double);
    double NewtonRaphson(double, double (*fx)(double), double (*dfx)(double));
    double FixedPointMethod(double, double (*fx)(double));
};