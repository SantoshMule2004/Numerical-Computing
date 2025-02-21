#include "Matrix.hpp"
using namespace std;

int main()
{
    Matrix a("mat49x49.txt");
    cout << "Matrix a elements :" << endl;
    a.display();

    Matrix b("mat2-49x49.txt");
    cout << "Matrix b elements :" << endl;
    b.display();

    // Matrix add = a + b;
    // cout << "Result Matrix elements :" << endl;
    // add.display();

    // Matrix sub = a - b;
    // cout << "Result Matrix elements :" << endl;
    // sub.display();

    Matrix mul = a.multiplyMatrix(b);
    cout << "Result Matrix elements :" << endl;
    mul.display();

    return 0;
}