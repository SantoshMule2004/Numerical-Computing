#include "Matrix.hpp"
using namespace std;

// gauss jacobi (iterative method to solve linear system of equation)
Matrix Matrix::gaussJacobi()
{
    checkDiagonallyDominant();

    Matrix ans(1, rows), ansX(1, rows); // matrices to store values from previous and current iteration

    double sumK(0.0), sumX(0.0);

    // calling jacobi function to find values for first iteration
    Jacobi(ans, ansX, sumK, sumX);

    while (abs(sumK - sumX) >= 0.000001) // loop will run untill the sum of last iteration and current iteration has difference less than 0.000001
    {
        sumK = 0, sumX = 0;
        Jacobi(ans, ansX, sumK, sumX);

        for (int i = 0; i < rows; i++)
            ans.mat[0][i] = ansX.mat[0][i];
    }
    return ans;
}

void Matrix::checkDiagonallyDominant()
{
    if (!isDiagonallyDominant()) // checking if matrix is diagonally dominant or not
    {
        cout << "Matrix is not diagonally dominant." << endl;
        cout << "Trying to make it diagonally dominanat" << endl;

        if (makeDiagonallyDominant())
            cout << "Success to make diagonally dominanat" << endl;
        else
            throw runtime_error("unable to make the Matrix diagonally dominant...");
    }
}

void Matrix::Jacobi(Matrix &ans, Matrix &ansX, double &sumK, double &sumX)
{
    for (int i = 0; i < rows; i++)
    {
        double sum = 0.0;
        for (int j = 0; j < rows; j++)
        {
            if (i != j)
                sum += mat[i][j] * ans.mat[0][j];
        }
        ansX.mat[0][i] = (mat[i][cols - 1] - sum) / mat[i][i];
        sumK += ansX.mat[0][i];
        sumX += ans.mat[0][i];
    }
}