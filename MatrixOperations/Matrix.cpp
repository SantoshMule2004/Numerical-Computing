#include "Matrix.hpp"
using namespace std;

Matrix::Matrix()
{
    this->rows = 0;
    this->cols = 0;
}

Matrix::Matrix(string filename)
{
    ifstream file;
    file.open(filename);

    if(!file)
        cerr << "Error opening file" << endl;

    file >> this->rows >> this->cols;

    this->mat = new long double *[rows];
    int i;
    for (i = 0; i < rows; i++)
    {
        this->mat[i] = new long double[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            file >> mat[i][j];
        }
    }
}

Matrix::Matrix(int r, int c)
{
    rows = r;
    cols = c;

    mat = new long double *[rows];
    int i;
    for (i = 0; i < rows; i++)
    {
        mat[i] = new long double[cols]();
    }
}

Matrix::Matrix(const Matrix &M)
{
    rows = M.rows;
    cols = M.cols;

    mat = new long double *[rows];
    for (int i = 0; i < rows; i++)
        mat[i] = new long double[cols];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            mat[i][j] = M.mat[i][j];
        }
    }
}

int Matrix::getRows() const
{
    return rows;
}

int Matrix::getCols() const
{
    return cols;
}

void Matrix::display() const
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

Matrix Matrix::operator+(const Matrix &M)
{
    if(this->rows != M.rows && this->cols != M.cols){
        cout << "Addition not possible" << endl;
    }

    Matrix a(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            a.mat[i][j] = this->mat[i][j] + M.mat[i][j];
        }
    }
    return a;
}

Matrix Matrix::addMatrix(const Matrix &M)
{
    if(this->rows != M.rows && this->cols != M.cols){
        cout << "Addition not possible" << endl;
    }

    Matrix a(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            a.mat[i][j] = this->mat[i][j] + M.mat[i][j];
        }
    }
    return a;
}

Matrix Matrix::operator-(const Matrix &M)
{
    if(this->rows != M.rows && this->cols != M.cols){
        cout << "Addition not possible" << endl;
    }

    Matrix a(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            a.mat[i][j] = this->mat[i][j] - M.mat[i][j];
        }
    }
    return a;
}

Matrix Matrix::subMatrix(const Matrix &M)
{
    if(this->rows != M.rows && this->cols != M.cols){
        cout << "Addition not possible" << endl;
    }

    Matrix a(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            a.mat[i][j] = this->mat[i][j] - M.mat[i][j];
        }
    }
    return a;
}

Matrix Matrix::multiplyMatrix(const Matrix &M)
{
    if(cols != M.rows)
        cout << "Multiplication not possible" << endl;

        Matrix a(rows, M.cols);

        int i, j ,k;
        for(i=0; i<rows; i++)
        {
            for(j=0; j<M.cols; j++)
            {
                for(k=0; k<M.rows; k++)
                {
                    a.mat[i][j] += mat[i][k] * M.mat[k][j]; 
                }
            }
        }

        return a;
}

bool Matrix::isIdentity() const
{
    if(rows != cols)
        return false;

    for (int i = 0; i < rows; i++)
    {
        if (mat[i][i] != 1)
            return false;

        for (int j = 0; j < cols; j++)
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

bool Matrix::isSymmetric() const
{
    if(rows != cols)
        return false;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
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

std::ifstream &operator>>(std::ifstream &fin, Matrix &M)
{
    for (int i = 0; i < M.rows; i++)
    {
        for (int j = 0; j < M.cols; j++)
        {
            fin >> M.mat[i][j];
        }
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;
}