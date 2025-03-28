#include "Interpolation.hpp"
using namespace std;

// function to calculate average
double Interpolation::calculateAverage(vector<int>& A)
{
    double sum(0);
    for (int i = 0; i < n; i++)
        sum += A[i];
    double avg = sum / n;
    return avg;
}

// function for calculations
void Interpolation::calculate(double& xdiff, double& fdiff, double& xf, double& sq, double& a, double& b, double& avgX, double& avgF)
{
    for (int i = 0; i < n; i++)
    {
        xdiff = avgX - X[i]; 
        fdiff = avgF - F[i];
        xf += xdiff * fdiff;
        sq += xdiff * xdiff;
    }
    a = xf / sq;
    b = avgF - a * avgX;   
}

// function to calculate least square linear fit and RMS error
double Interpolation::LeastSquareLineFit()
{
    double avgX = calculateAverage(X);
    double avgF = calculateAverage(F);

    double xdiff(0), fdiff(0), xf(0), sq(0), a, b;

    calculate(xdiff, fdiff, xf, sq, a, b, avgX, avgF);
    
    double y(0), fySum(0), diff(0);
    for (int i = 0; i < n; i++)
    {
        y = a * X[i] + b;   // calculating y for each value of x
        diff = (F[i] - y);
        fySum += diff * diff;
    }

    double rms = sqrt(fySum / n); // calculating RMS error

    return rms;
}