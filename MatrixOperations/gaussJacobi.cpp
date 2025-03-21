#include "Matrix.hpp"
using namespace std;

// gauss jacobi (iterative method to solve linear system of equation)
Matrix Matrix::gaussJacobi()
{
    if(!isDiagonallyDominant())
        throw runtime_error("Matrix is not diagonally dominant...");   // checking if matrix is diagonally dominant or not

    Matrix ans(1, rows), ansX(1, rows);  // matrices to store values from previous and current iteration 

    double sumK(0.0), sumX(0.0);

    for(int i=0;i<rows;i++)
    {
        ans.mat[0][i] += (mat[i][cols-1] / mat[i][i]);  // calculating first iterationvalues
        sumK += ans.mat[0][i];
    }

    while(abs(sumK - sumX) >= 0.000001)  // loop will run untill the sum of last iteration and current iteration has difference less than 0.000001
    {
        sumK = 0, sumX =0;
        for(int i=0;i<rows;i++)
        {
            double sum = 0.0;
            for(int j=0;j<rows;j++)
            {
                if(i != j) {
                    sum += mat[i][j] * ans.mat[0][j];
                }
            }
            ansX.mat[0][i] = (mat[i][cols-1] - sum) / mat[i][i];
            sumK += ansX.mat[0][i];
            sumX += ans.mat[0][i];
        }

        for(int i=0;i<rows;i++)
        {
            ans.mat[0][i] = ansX.mat[0][i];
        }
    }
    return ans;
}