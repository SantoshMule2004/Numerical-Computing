#include "Matrix.hpp"
using namespace std;

// LU decomposition using Doolittle algorithm
Matrix Matrix::doolittleDecomposition()
{
    if (rows != (cols - 1))
        throw runtime_error("matrix is not augumented matrix");

    Matrix l(rows, cols); // matrix to store lower traingular matrix
    Matrix u(rows, cols); // matrix to store upper traingular matrix

    for (int i = 0; i < rows; i++)
    {
        for (int j = i; j < rows; j++)
        {
            u.mat[i][j] = mat[i][j];
            for (int k = 0; k < i; k++)
                u.mat[i][j] -= l.mat[i][k] * u.mat[k][j];
        }

        l.mat[i][i] = 1; // making diagonal element as 1 in lower traingular matrix
        for (int j = i + 1; j < rows; j++)
        {
            l.mat[j][i] = mat[j][i];

            for (int k = 0; k < i; k++)
                l.mat[j][i] -= l.mat[j][k] * u.mat[k][i];
            l.mat[j][i] /= u.mat[i][i];
        }
        l.mat[i][cols - 1] = mat[i][cols - 1]; // adding values of last column of matrix
    }

    cout << "Doolittle`s decomposition :" << endl;
    return calculateAnsForLU(l, u);
}

Matrix Matrix::calculateAnsForLU(Matrix &l, Matrix &u)
{
    Matrix X = l.forwardSubstitution(); // performing forward substitution on lower traingular matrix values

    for (int i = 0; i < rows; i++)
        u.mat[i][cols - 1] = X.mat[0][i]; // adding forward substituted values to upper triangular matrix

    Matrix ans = u.backSubstitution(); // performing back substitution on upper traingular matrix values

    return ans;
}
