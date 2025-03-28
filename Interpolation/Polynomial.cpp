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
    for(int i=0; i<p.size();i++)
    {
        cout << p[i] << " + " ;
    }
}

double Polynomial::evaluatePolynomial(int x)
{
    double sum(0)
    for(int i=0;i<p.size();i++)
    {

    }
}