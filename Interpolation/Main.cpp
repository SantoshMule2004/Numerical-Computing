#include"Interpolation.hpp"
using namespace std;

int main()
{
    Interpolation I("a.txt");
    // I.lagrangesPolynomiyal(2);
    double rms = I.LeastSquareLineFit();
    cout << "RMS error : " << rms << endl;
    return 0;
}