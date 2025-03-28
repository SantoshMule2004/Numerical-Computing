#include "Matrix.hpp"
using namespace std;

// default constructor
Matrix::Matrix()
{
    this->rows = 0;
    this->cols = 0;
}

// constructor to read single file
Matrix::Matrix(string filename)
{
    ifstream file;
    file.open(filename);

    if (!file)
        cerr << "Error opening file" << endl;

    file >> this->rows >> this->cols;

    allocateMemory(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            file >> mat[i][j];
    }

    file.close();
}

// constructor to read two file
Matrix::Matrix(string filename, string filename2)
{
    ifstream file, file2;
    file.open(filename);
    file2.open(filename2);

    if (!file && !file2)
        cerr << "Error opening file" << endl;

    file >> this->rows >> this->cols;

    allocateMemory(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (j == cols - 1) // reading last column from file2
                file2 >> mat[i][j];
            else
                file >> mat[i][j];
        }
    }
    file.close();
    file2.close();
}

// constructor to allocate memory for a matrix
Matrix::Matrix(int r, int c)
{
    rows = r;
    cols = c;
    allocateMemory(rows, cols);
}

// copy constructor
Matrix::Matrix(const Matrix &M)
{
    copyMatrix(M);
}

// function to allocate memory to a matrix
void Matrix::allocateMemory(int r, int c)
{
    this->mat = new long double *[r];
    for (int i = 0; i < r; i++)
    {
        this->mat[i] = new long double[c];
        for (int j = 0; j < c; j++)
            mat[i][j] = 0;
    }
}

// function to copy matrices
void Matrix::copyMatrix(const Matrix &M)
{
    rows = M.rows;
    cols = M.cols;

    allocateMemory(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            mat[i][j] = M.mat[i][j];
    }
}

// getters
int Matrix::getRows() const
{
    return rows;
}

int Matrix::getCols() const
{
    return cols;
}

// function to display matrix
void Matrix::display()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << fixed << setprecision(2) << mat[i][j] << " ";
        cout << endl;
    }
}

// overloading = operator
Matrix Matrix::operator=(const Matrix &M)
{
    if (this == &M)
        return *this;

    for (int i = 0; i < rows; ++i)
    {
        delete[] mat[i];
    }
    delete[] mat;

    copyMatrix(M);

    return *this;
}

// function to perform addition
Matrix Matrix::addMat(const Matrix &M)
{
    if (this->rows != M.rows || this->cols != M.cols)
        throw runtime_error("Addition not possible");

    Matrix a(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            a.mat[i][j] = this->mat[i][j] + M.mat[i][j];
    }
    return a;
}

// function to perform substraction
Matrix Matrix::subMat(const Matrix &M)
{
    if (this->rows != M.rows || this->cols != M.cols)
        throw runtime_error("Substraction not possible");

    Matrix a(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            a.mat[i][j] = this->mat[i][j] - M.mat[i][j];
    }
    return a;
}

// overloading + operator
Matrix Matrix::operator+(const Matrix &M)
{
    return addMat(M); // calling addMat function to perform addition
}

// function to add matrices
Matrix Matrix::addMatrix(const Matrix &M)
{
    return addMat(M); // calling addMat function to perform addition
}

// overloading - operator
Matrix Matrix::operator-(const Matrix &M)
{
    return subMat(M); // calling subMat function to perform substraction
}

// function to substract matrices
Matrix Matrix::subMatrix(const Matrix &M)
{
    return subMat(M); // calling subMat function to perform substraction
}

// function to multiply matrices
Matrix Matrix::multiplyMatrix(const Matrix &M)
{
    if (cols != M.rows)
        throw runtime_error("Multiplication not possible");

    Matrix a(rows, M.cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < M.cols; j++)
        {
            for (int k = 0; k < M.rows; k++)
                a.mat[i][j] += mat[i][k] * M.mat[k][j];
        }
    }

    return a;
}

// function to check if a matrix is identity or not
bool Matrix::isIdentity() const
{
    if (rows != (cols - 1))
        return false;

    for (int i = 0; i < rows; i++)
    {
        if (mat[i][i] != 1)
            return false;

        for (int j = 0; j < rows; j++)
        {
            if (i != j)
            {
                if (mat[i][j] != 0)
                    return false;
            }
        }
    }
    return true;
}

// function to check if a matrix is symmetric or not
bool Matrix::isSymmetric() const
{
    if (rows != cols - 1)
        return false;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if (i != j)
            {
                if (mat[i][j] != mat[j][i])
                    return false;
            }
        }
    }
    return true;
}

// function to check if a matrix is diagonally dominant or not
bool Matrix::isDiagonallyDominant() const
{
    for (int i = 0; i < rows; i++)
    {
        double rSum(0);
        for (int j = 0; j < rows; j++)
        {
            if (i != j)
                rSum += abs(mat[i][j]);
        }
        if (abs(mat[i][i]) < rSum)
            return false;
    }
    return true;
}

// function to check if a row is diagonally dominant or not
bool Matrix::isDiagonallyDominantRow(int r) const
{
    double rSum(0);
    for (int i = 0; i < rows; i++)
    {
        if (i != r)
            rSum += abs(mat[r][i]);
    }

    if (abs(mat[r][r]) < rSum)
        return false;
    else
        return true;
}

// function to make matrix diagonally dominant
bool Matrix::makeDiagonallyDominant()
{
    // making Diagonally Dominant by just swapping
    // for (int i = 0; i < rows; i++)
    // {
    //     int j = i + 1;
    //     while (!isDiagonallyDominantRow(i) && j < rows)
    //     {
    //         swapRows(i, j);
    //         j++;
    //     }
    //     if (!isDiagonallyDominantRow(i) && j == rows - 1)
    //         break;
    // }

    // if (isDiagonallyDominant())
    //     return true;
    // else
    //     return false;

    // making Diagonally Dominant by max row and then swapping
    for (int i = 0; i < rows; i++)
    {
        if (!isDiagonallyDominantRow(i))
        {
            double maxValue = mat[i][i];
            int maxRow = i;
            for (int j = i+1; j < rows; j++)
            {
                if(abs(mat[j][i]) >= maxValue)
                {
                    maxValue = mat[j][i];
                    maxRow = j;
                }
            }
            swapRows(i, maxRow);
        }
    }

    if(isDiagonallyDominant())
        return true;
    else
        return false;
}

// destructor
Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;
}

// run function
void Matrix::Run()
{
    //  // cholesky decomposition
    //  Matrix ans4 = choleskyDecomposition();
    //  cout << endl
    //       << "values using cholesky:" << endl;
    //  ans4.display();

    // // doolittle decomposition
    // Matrix ans1 = doolittleDecomposition();
    // cout << endl
    //      << "values using Doolottle:" << endl;
    // ans1.display();

    // // crouts decomposition
    // Matrix ans2 = croutsDecomposition();
    // cout << endl
    //      << "values using crouts:" << endl;
    // ans2.display();

    // // gauss elimination
    // Matrix ans3 = gaussElimination();
    // cout << endl
    //      << "values using gauss elimination:" << endl;
    // ans3.display();

    // gauss jacobi
    Matrix ans5 = gaussJacobi();
    cout << endl
         << "values using gauss jacobi:" << endl;
    ans5.display();

    // gauss seidel
    Matrix ans6 = gaussSeidel();
    cout << endl
         << "values using gauss seidel:" << endl;
    ans6.display();
}