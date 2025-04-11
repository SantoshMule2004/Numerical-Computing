#include"Interpolation.hpp"
using namespace std;

int main()
{
    Interpolation I("a.txt");
    // I.lagrangesPolynomiyal(2);
    // Polynomial P = I.LeastSquareLineFit();
    Polynomial P = I.LeastSquareExponentialFit();
    return 0;
}