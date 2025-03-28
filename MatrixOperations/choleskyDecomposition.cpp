#include "Matrix.hpp"
using namespace std;

// LU decomposition using cholesky algorithm
Matrix Matrix::choleskyDecomposition()
{
    if(rows != (cols-1))
        throw runtime_error("matrix is not augumented matrix");

    if(!isSymmetric())
        throw runtime_error("Matrix is not symmetric");

    Matrix l(rows, cols);   // matrix to store lower traingular matrix
    Matrix lt(rows, cols);   // matrix to store transpose of lower traingular matrix

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<=i;j++)
        {
            double sum = 0;
            if(i == j)
            {
                for(int k=0;k<i;k++)
                    sum += pow(l.mat[i][k], 2);
                l.mat[i][j] = sqrt(mat[i][j] - sum);
            } 
            else 
            {
                for(int k=0;k<j;k++)
                    sum += (l.mat[i][k] * l.mat[j][k]);
                    l.mat[i][j] = (mat[i][j] - sum) / l.mat[j][j];
            }
        }
        l.mat[i][cols - 1] = mat[i][cols - 1];   // adding values of last column of matrix
    }

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols-1;j++)
            lt.mat[i][j] = l.mat[j][i];   // adding values to transpose matrix
    }

    cout << "cholesky decomposition :" << endl;
    return calculateAnsForLU(l,lt);
}