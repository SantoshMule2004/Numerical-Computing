#include"Interpolation.hpp"
using namespace std;

// lagranges polynomial
double Interpolation::lagrangesPolynomiyal(int ux)
{
    double sum(0);
    for(int i=0; i<n;i++)
    {
        double nSum(1), dSum(1);
        for(int j=0; j<n;j++)
        {
            if(i != j)
            {
                nSum *= (ux - X[j]);  // calculating numerator
                dSum *= (X[i] - X[j]); // calculating the denominator
            }
        }
        sum += (nSum / dSum) * F[i];
    }
    return sum;
}