#include<iostream>
#include<vector>
#include<cmath>

class Polynomial
{
private:
    std::vector<double> p;
public:
    Polynomial();
    Polynomial(std::vector<double>);

    void display();
    Polynomial getPolynomial();
    void setPolynomial();

    double evaluatePolynomial(double);
    double evaluateExpoPolynomial(double);
    double evaluatePowerPolynomial(double);
};
