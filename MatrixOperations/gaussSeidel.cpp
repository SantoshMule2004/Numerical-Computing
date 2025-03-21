#include "Matrix.hpp"
using namespace std;

// gauss seidel (iterative method to solve linear system of equation)
Matrix Matrix::gaussSeidel()
{
    if(!isDiagonallyDominant())
        throw runtime_error("Matrix is not diagonally dominant...");   // checking if matrix is diagonally dominant or not

    Matrix ans(1, rows);   // matrix to store values of current iteration

    double sumK(0.0), sumX(0.0);

    for (int i = 0; i < rows; i++)
    {
        double sum = 0.0;
        for (int j = 0; j < rows; j++)
        {
            if (i != j)
            {
                sum += mat[i][j] * ans.mat[0][j];  // calculating first iterationvalues
            }
        }
        ans.mat[0][i] = (mat[i][cols - 1] - sum) / mat[i][i];
        sumK += ans.mat[0][i];
    }

    while (abs(sumK - sumX) >= 0.0001)  // loop will run untill the sum of last iteration and current iteration has difference less than 0.000001
    {
        sumX = 0;
        sumX = sumK;
        sumK = 0;
        for (int i = 0; i < rows; i++)
        {
            double sum = 0.0;
            for (int j = 0; j < rows; j++)
            {
                if (i != j)
                {
                    sum += mat[i][j] * ans.mat[0][j];
                }
            }
            ans.mat[0][i] = (mat[i][cols - 1] - sum) / mat[i][i];
            sumK += ans.mat[0][i];
        }
    }
    return ans;
}