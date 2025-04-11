#include "Interpolation.hpp"
using namespace std;

// function to calculate RMS error
double Interpolation::calculateRMS(Polynomial P, double (Polynomial::*evaluate)(double))
{
    double y(0), fySum(0), diff(0);
    for (int i = 0; i < n; i++)
    {
        y = (P.*evaluate)(X[i]); // calculating y for each value of x
        diff = (F[i] - y);
        fySum += diff * diff;
    }

    double rms = sqrt(fySum / n); // calculating RMS error

    return rms;
}

// function to calculate average
double Interpolation::calculateAverage(vector<double> &A)
{
    double sum(0);
    for (int i = 0; i < n; i++)
        sum += A[i];
    double avg = sum / n;
    return avg;
}

// function for calculations of least square line fit
void Interpolation::calculate(double &xdiff, double &fdiff, double &xf, double &sq, double &avgX, double &avgF, double &a, double &b, vector<double> &Y, std::vector<double> &Z)
{
    avgX = calculateAverage(Z);
    avgF = calculateAverage(Y);

    for (int i = 0; i < n; i++)
    {
        xdiff = avgX - Z[i];
        fdiff = avgF - Y[i];
        xf += xdiff * fdiff;
        sq += xdiff * xdiff;
    }

    a = xf / sq;
    b = avgF - a * avgX;
}

vector<double> Interpolation::calculateLog(vector<double> &A)
{
    vector<double> xLog;
    for (int i = 0; i < n; i++)
        xLog.push_back(log(A[i])); // calculating ln of F(x)

    return xLog;
}

// function to perform calculation for parabola
void Interpolation::calculateParabolaFit(double &a, double &b, double &c)
{
    double sumX(0), sumX2(0), sumX3(0), sumX4(0), sumF(0), sumFX(0), sumFX2(0);

    for (int i = 0; i < n; i++)
    {
        sumX += X[i];
        sumX2 += X[i] * X[i];
        sumX3 += X[i] * X[i] * X[i];
        sumX4 += X[i] * X[i] * X[i] * X[i];

        sumF += F[i];
        sumFX += X[i] * F[i];
        sumFX2 += X[i] * X[i] * F[i];
    }

    vector<vector<long double>> Mat = {{sumX2, sumX, double(n), sumF},
                                       {sumX3, sumX2, sumX, sumFX},
                                       {sumX4, sumX3, sumX2, sumFX2}};

    // creating a object of MAtrix class and passing vector to it
    Matrix M(Mat.size(), Mat[0].size(), Mat);

    // solving system of linear equation to find out a, b & c
    Matrix ans = M.gaussElimination();

    a = ans.getElement(0, 0);
    b = ans.getElement(1, 0);
    c = ans.getElement(2, 0);
}

// function to calculate least square linear fit and RMS error
Polynomial Interpolation::LeastSquareLineFit()
{
    double avgX(0), avgF(0), xdiff(0), fdiff(0), xf(0), sq(0), a, b;
    calculate(xdiff, fdiff, xf, sq, avgX, avgF, a, b, F, X); // calculating values of the constant a & b

    Polynomial Line({b, a}); // creating an object Polynomial class and passing values a & b as a vector
    cout << "RMS Error: " << calculateRMS(Line, &Polynomial::evaluatePolynomial) << endl;
    return Line;
}

// function to calculate least square parabola fit and RMS error
Polynomial Interpolation::LeastSquareParabolaFit()
{
    double a, b, c;
    calculateParabolaFit(a, b, c); // calculating values of the constant a ,b & c

    Polynomial Parabola({c, b, a}); // creating an object Polynomial class and passing values a, b & c as a vector
    cout << "RMS Error: " << calculateRMS(Parabola, &Polynomial::evaluatePolynomial) << endl;
    return Parabola;
}

// function to calculate least square exponential fit and RMS error
Polynomial Interpolation::LeastSquareExponentialFit()
{
    vector<double> fLog = calculateLog(F);

    double avgX(0), avgF(0), xdiff(0), fdiff(0), xf(0), sq(0), a, b;
    calculate(xdiff, fdiff, xf, sq, avgX, avgF, a, b, fLog, X); // calculating values of the constant a & b

    double c = exp(b);

    Polynomial Exponential({c, a}); // creating an object Polynomial class and passing values a & b as a vector
    cout << "RMS Error: " << calculateRMS(Exponential, &Polynomial::evaluateExpoPolynomial) << endl;
    return Exponential;
}

// function to calculate least square power fit and RMS error
Polynomial Interpolation::LeastSquarePowerFit()
{
    vector<double> fLog = calculateLog(F);
    vector<double> xLog = calculateLog(X);

    double avgX(0), avgF(0), xdiff(0), fdiff(0), xf(0), sq(0), a, b;
    calculate(xdiff, fdiff, xf, sq, avgX, avgF, a, b, fLog, xLog); // calculating values of the constant a & b

    double c = exp(b);

    Polynomial Power({c, a});
    cout << "RMS Error: " << calculateRMS(Power, &Polynomial::evaluatePowerPolynomial) << endl;
    return Power;
}