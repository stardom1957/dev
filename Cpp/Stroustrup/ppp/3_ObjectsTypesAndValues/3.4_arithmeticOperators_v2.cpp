#include "../std_lib_facilities.h"

int main()
{file:///home/dominique/devC/Stroustrup/ppp/3_ObjectsTypesAndValues/3.4_arithmeticOperators_v3.cpp

    cout << "Please enter an integer value: ";
    // double n;
    int n;
    cin >> n;
    double d=n;
    cout << "n == " << n
         << "\nn+1 == " << n+1
         << "\ntree times n == " << 3*n
         << "\nn+n == " << n+n
         << "\nn squared == " << n*n
         << "\nhalf of n == " << n/2
         << "\nsquare root of n == " << sqrt(d)
         << "\n";
    return 0;
}

