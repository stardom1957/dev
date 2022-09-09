#include <iostream>
using namespace std;

int main()
{
  int i1, i2, i3;
  double d1, d2, d3;
  bool bo1, bo2;
  unsigned u1, u2;
  const double gravity {9.82};

  cout << "Test des opérations arithmétiques usuelles.\n";
  cout << "------------------------------------------\n";
  i1=22;
  i2=54;
  i3=0;
  cout << "i1+i2= " << i1+i2 << "\n";
  cout << "i2%i1= " << i2%i1 << "\n";
  cout << "i3= " << i3 << " ~i3= " << ~i3 << "\n\n";

  d1=2.1458;
  d2=-4.568;
  d3=445945789123;
  cout << "d1/d2= " << d1/d2 << "\n";
  cout << "d3*2= " << d3*2 << "\n\n";

  bo1=true;
  bo2=false;
  cout << "bo1 && bo2= " << (bo1 && bo2)  << "\n";
  cout << "bo1 || bo2= " << (bo1 || bo2)  << "\n\n";

  u1=0;
  u2=64;
  cout << "~u1= " << ~u1  << "\n";
  cout << "~u2= " << ~u2  << "\n";

  cout << "sizeof(u1)= " << sizeof(u1) << "\n\n";

  cout << "i1 = " << i1 << ", i2= " << i2 << "\n";
  cout << "i1+=i2 = " << (i1+=i2)  << "\n";
  cout << "i1-=i2 = " << (i1-=i2)  << "\n";
  cout << "i1*=i2 = " << (i1*=i2)  << "\n";
  cout << "i1/=i2 = " << (i1/=i2)  << "\n";

  cout << "la valeur de la gravité est " << gravity << "m/s²";

  cout << "\n\nEnter your age: ";
  int age;
  cin >> age;

  const int usersAge {age}; // usersAge can not be changed
  cout << "usersAge= " << usersAge;
}
