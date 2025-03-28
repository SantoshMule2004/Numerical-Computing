#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<fstream>

class Interpolation
{
private:
    std::vector<int> X;
    std::vector<int> F;
    int n;
    
public:
    // constructors
    Interpolation();
    Interpolation(std::string);
    Interpolation(std::vector<int>&, std::vector<int>&, int);

    // display functions
    void display(std::vector<int>&);
    void displayX();
    void displayF();

    // getters
    std::vector<int> getX();
    std::vector<int> getF();

    // setters
    void setX(std::vector<int>&);
    void setF(std::vector<int>&);

    double lagrangesPolynomiyal(int);

    double LeastSquareLineFit();
    double calculateAverage(std::vector<int>&);
    void calculate(double&, double&, double&, double&, double&, double&, double&, double&);
};