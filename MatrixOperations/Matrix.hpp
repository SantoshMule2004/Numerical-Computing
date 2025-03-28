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
    void copyMatrix(const Matrix &);

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
    Matrix addMat(const Matrix &);
    Matrix subMat(const Matrix &);

    Matrix operator+(const Matrix &);
    Matrix addMatrix(const Matrix &);

    Matrix operator-(const Matrix &);
    Matrix subMatrix(const Matrix &);

    Matrix operator=(const Matrix &);

    Matrix multiplyMatrix(const Matrix &);

    void upperTriangular();
    void swapRows(int, int);
    Matrix backSubstitution();
    Matrix backSubstitution(Matrix&);
    Matrix forwardSubstitution();
    Matrix forwardSubstitution(Matrix&);

    Matrix gaussElimination();

    Matrix gaussJacobi();
    void Jacobi(Matrix &, Matrix &, double &, double &);


    Matrix gaussSeidel();
    void Seidel(Matrix &, double &);

    Matrix calculateAnsForLU(Matrix &, Matrix &);
    Matrix doolittleDecomposition();
    Matrix croutsDecomposition();
    Matrix choleskyDecomposition();

    bool isIdentity() const;
    bool isSymmetric() const;
    bool isDiagonallyDominant() const;
    bool isDiagonallyDominantRow(int) const;
    bool makeDiagonallyDominant();
    void checkDiagonallyDominant();

    void Run();
    
    ~Matrix();
};
