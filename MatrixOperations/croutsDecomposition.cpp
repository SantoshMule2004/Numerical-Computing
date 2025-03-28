#include "Matrix.hpp"
using namespace std;

// LU decomposition using crouts algorithm
Matrix Matrix::croutsDecomposition()
{
    if(rows != (cols-1))
        throw runtime_error("matrix is not augumented matrix");

    Matrix l(rows, cols);   // matrix to store lower traingular matrix 
    Matrix u(rows, cols);   // matrix to store upper traingular matrix

    for (int i = 0; i < rows; i++)
    {
        for (int j = i; j < rows; j++)
        {
            l.mat[j][i] = mat[j][i];
            for (int k = 0; k < i; k++)
                l.mat[j][i] -= l.mat[j][k] * u.mat[k][i];
        }
        l.mat[i][cols - 1] = mat[i][cols - 1];  // adding values of last column of matrix

        u.mat[i][i] = 1;      // making diagonal element as 1 in upper traingular matrix
        for(int j=i+1;j<rows;j++)
        {
            u.mat[i][j] = mat[i][j];
            for(int k=0;k<i;k++)
                u.mat[i][j] -= l.mat[i][k] * u.mat[k][j];
            u.mat[i][j] /= l.mat[i][i];
        }
    }

    cout << "crout`s decomposition :" << endl;
    return calculateAnsForLU(l,u);;
}
