#include "Matrix.hpp"
using namespace std;

int main()
{
     Matrix a("textFiles/s.txt", "textFiles/r.txt");
     // Matrix a("textFiles/c.txt");
     a.Run();
     return 0;
}