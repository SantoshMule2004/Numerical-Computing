#include "Matrix.hpp"
using namespace std;

// gauss seidel (iterative method to solve linear system of equation)
Matrix Matrix::gaussSeidel()
{
   checkDiagonallyDominant();

    Matrix ans(1, rows); // matrix to store values of current iteration

    double sumK(0.0), sumX(0.0);

    Seidel(ans, sumK);
    
    while (abs(sumK - sumX) >= 0.0001) // loop will run untill the sum of last iteration and current iteration has difference less than 0.000001
    {
        sumX = 0;
        sumX = sumK;
        sumK = 0;
        
        Seidel(ans, sumK);
    }
    return ans;
}

void Matrix::Seidel(Matrix &ans, double &sumK)
{
    for (int i = 0; i < rows; i++)
    {
        double sum = 0.0;
        for (int j = 0; j < rows; j++)
        {
            if (i != j)
                sum += mat[i][j] * ans.mat[0][j]; // calculating first iterationvalues
        }
        ans.mat[0][i] = (mat[i][cols - 1] - sum) / mat[i][i];
        sumK += ans.mat[0][i];
    }
}