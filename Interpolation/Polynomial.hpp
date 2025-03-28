#include<iostream>
#include<vector>

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

    double evaluatePolynomial(int);
};
