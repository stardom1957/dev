#include <iostream>
using namespace std;

double square(double x)
{
  return x*x;
}

void print_square(double x)
{
  cout<<"Le carré de "<< x << " est " << square(x) << ".\n";
}

int main()
{
  print_square(2.2345);
}
