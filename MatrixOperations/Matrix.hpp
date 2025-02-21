#include <iostream>
#include <fstream>
#include <string>

class Matrix
{
private:
    int rows, cols;
    long double **mat;

public:
    Matrix();
    Matrix(std::string);
    Matrix(int, int);
    Matrix(const Matrix&);
    
    int getRows() const;
    int getCols() const;
    void display() const;

    Matrix operator+(const Matrix &);
    Matrix addMatrix(const Matrix &);

    Matrix operator-(const Matrix &);
    Matrix subMatrix(const Matrix &);

    Matrix multiplyMatrix(const Matrix &);

    bool isIdentity() const;
    bool isSymmetric() const;
    ~Matrix();

    friend std::ifstream& operator>>(std::ifstream& fin, Matrix& M);
};
