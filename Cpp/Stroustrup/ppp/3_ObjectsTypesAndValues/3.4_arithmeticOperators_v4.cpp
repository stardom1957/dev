#include "../std_lib_facilities.h"

int main()
{
    cout << "Version 4\n";
    cout << "Please enter two integer values (a and b): ";
    // double n;
    int a;
    int b;
    cin >> a >> b;
    cout << "a == " << a
         << "\nb == " << b
         << "\na+1 == " << a+1
         << "\ntree times a == " << 3*a
         << "\na+a == " << a+a
         << "\na squared == " << a*a
         << "\nhalf of a == " << a/2
         << "\na/b == " << a/b
         << "\nsquare root of a == " << sqrt(a)
         << "\na-3 == " << a-3
         << "\n" << a << " modulo " << b << " == " << a%b
         << "\n";

    /* The operations ++ and -- must be carried out in a new statement. If not, the compiler will issue this:
        warning: operation on ‘a’ may be undefined [-Wsequence-point]|
        warning: operation on ‘b’ may be undefined [-Wsequence-point]|
    */

    cout << "\n++a (increment a by 1) == " << ++a
         << "\n--b (decrement b by 1) == " << --b
         << "\n";

    cout << "\nFinaly:"
         << "\na == " << a
         << "\nb == " << b
         << "\n and... \n\n";

    cout << "The definitions of integer *, / and % guarantee that for positive integers a and b:\n";
    //cout << "  ((a/b) * b) + a % b == a, so:\n";
    cout << "  a/b * b + a%b == a, so:\n";
    //cout << "  ((" << a << "/" << b << ")" << " * " << b << ")" << " + " << a << " % " << b << " == " << ((a/b) * b) + a%b;
    cout << a << "/" << b << " * " << b << " + " << a << "%" << b << " == " << a/b * b + a%b;
    return 0;
}

