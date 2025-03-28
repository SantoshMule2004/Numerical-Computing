#include "Interpolation.hpp"
using namespace std;

Interpolation::Interpolation()
{
    X = {0};
    F = {0};
}

// reading values from file 
Interpolation::Interpolation(string filename)
{
    ifstream file;
    file.open(filename);

    if (!file)
        cerr << "Error opening file" << endl;

    file >> n;
    X.resize(n);
    F.resize(n);

    for (int i = 0; i < n; i++)
        file >> X[i];

    for (int i = 0; i < n; i++)
        file >> F[i];

    file.close();
}

Interpolation::Interpolation(std::vector<int> &X, std::vector<int> &F, int n)
{
    this->X = X;
    this->F = F;
    this->n = n;
}

// getters
vector<int> Interpolation::getX()
{
    return X;
}

vector<int> Interpolation::getF()
{
    return F;
}

// setters
void Interpolation::setX(std::vector<int> &X)
{
    this->X = X;
}

void Interpolation::setF(std::vector<int> &F)
{
    this->F = F;
}

// fuction to display
void Interpolation::display(std::vector<int>& A)
{
    for (int i = 0; i < X.size(); i++)
    {
        cout << A[i] << "\t" << endl;
    }
    cout << endl;
}

// function to display X
void Interpolation::displayX()
{
    display(X);
}

// function to display F
void Interpolation::displayF()
{
    display(X);
}