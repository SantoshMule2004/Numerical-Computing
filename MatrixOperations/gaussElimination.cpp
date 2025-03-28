#include "Matrix.hpp"
using namespace std;

// function to make a matrix upper triangular
void Matrix::upperTriangular()
{
    for (int i = 0; i < rows; i++)
    {
        if (!mat[i][i])
            swapRows(i, rows - 1);  // if diagonal element is zero swap row 

        double p = mat[i][i];  //storing pivot value (diagonal entry)
        mat[i][i] = 1;  // making diagonal as 1

        for (int j = i + 1; j < cols; j++)
            mat[i][j] /= p;   // multiplying every element of row by pivot 

        for (int k = i + 1; k < rows; k++)
        {
            double e = mat[k][i];
            for (int l = i; l < cols; l++) 
                mat[k][l] -= e * mat[i][l];   // substracting pivot from all column entries below diagonal element to make them zero
        }
    }
}

// function to swap rows of a matrix
void Matrix::swapRows(int i, int j)
{
    for (int k = 0; k <= rows; k++)
    {
        double temp = mat[i][k];
        mat[i][k] = mat[j][k];
        mat[j][k] = temp;
    }
}

// function to back substitute values of a matrix
Matrix Matrix::backSubstitution()
{
    Matrix ans(rows, 1);
    for (int i = (rows - 1); i >= 0; i--)
    {
        ans.mat[i][0] = mat[i][cols - 1];
        for (int j = i + 1; j < rows; j++)
        {
            ans.mat[i][0] -= mat[i][j] * ans.mat[j][0];
        }
        ans.mat[i][0] /= mat[i][i]; 
    }
    return ans;
}

// forward substitution values of a matrix
Matrix Matrix::forwardSubstitution()
{
    Matrix ans(1, rows);
    for (int i = 0; i<rows; i++)
    {
        double sum(0);
        ans.mat[0][i] = mat[i][cols - 1];
        for (int j = 0; j < i; j++)
        {
            sum += mat[i][j] * ans.mat[0][j];
        }
        ans.mat[0][i] = (ans.mat[0][i] - sum) / mat[i][i];
    }
    return ans;
}

// function that makes upper traingular matrix and back substitute the values
Matrix Matrix::gaussElimination()
{
    upperTriangular();
    Matrix ans = backSubstitution();
    return ans;
}
