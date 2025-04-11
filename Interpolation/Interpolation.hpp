#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<fstream>
#include "../MatrixOperations/Matrix.hpp"
#include "Polynomial.hpp"

class Interpolation
{
private:
    std::vector<double> X;
    std::vector<double> F;
    int n;
    
public:
    // constructors
    Interpolation();
    Interpolation(std::string);
    Interpolation(std::vector<double>&, std::vector<double>&, int);

    // display functions
    void display(std::vector<double>&);
    void displayX();
    void displayF();

    // getters
    std::vector<double> getX();
    std::vector<double> getF();

    // setters
    void setX(std::vector<double>&);
    void setF(std::vector<double>&);

    // lagranges polynomial
    double lagrangesPolynomiyal(int);

    // calculate RMS error
    double calculateRMS(Polynomial, double (Polynomial::*)(double));

    //functions for least square
    double calculateAverage(std::vector<double>&);
    void calculate(double&, double&, double&, double&, double&, double&, double&, double&, std::vector<double>&, std::vector<double>&);
    void calculateParabolaFit(double&, double&, double&);
    std::vector<double> calculateLog(std::vector<double>&);

    // least square line fit
    Polynomial LeastSquareLineFit();
    
    // least square parabola fit
    Polynomial LeastSquareParabolaFit();
    
    // least square exponential fit
    Polynomial LeastSquareExponentialFit();

    // least square power fit
    Polynomial LeastSquarePowerFit();
};