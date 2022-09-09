#include <iostream>
using namespace std;

double square(double x)
{
  return x*x;
}

void print_square(double d)
{
  cout<<"Le carré de "<< d << " est " << square(d) << ".\n";
}

int main()
{
  double x;
  cout << "entrez x : ";
  cin >> x;
  print_square(x);
}
