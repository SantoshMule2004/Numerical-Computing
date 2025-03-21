#include "Matrix.hpp"
using namespace std;

int main()
{
     Matrix a("textFiles/mat2l.txt", "textFiles/mat2r.txt");
     a.Run();
     return 0;
}