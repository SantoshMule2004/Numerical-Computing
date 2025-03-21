#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<math.h>
#include <cmath>
#define TOI 0.001

class Matrix
{
private:
    int rows, cols;
    long double **mat;

public:
    Matrix();
    Matrix(std::string);
    Matrix(std::string, std::string);
    Matrix(int, int);
    Matrix(const Matrix&);
    
    int getRows() const;
    int getCols() const;
    void display();

    void allocateMemory(int, int);

    Matrix operator+(const Matrix &);
    Matrix addMatrix(const Matrix &);

    Matrix operator-(const Matrix &);
    Matrix subMatrix(const Matrix &);

    Matrix operator=(const Matrix &);

    Matrix multiplyMatrix(const Matrix &);

    void upperTriangular();
    void swapRows(long double **, int, int);
    Matrix backSubstitution();
    Matrix backSubstitution(Matrix&);
    Matrix forwardSubstitution();
    Matrix forwardSubstitution(Matrix&);

    Matrix gaussElimination();

    Matrix gaussJacobi();

    Matrix gaussSeidel();

    Matrix croutsDecomposition();
    Matrix doolittleDecomposition();
    Matrix choleskyDecomposition();

    bool isIdentity() const;
    bool isSymmetric() const;
    bool isDiagonallyDominant() const;

    void Run();
    
    ~Matrix();
};
