#include "../std_lib_facilities.h"

int main()
{
    cout << "Version 3";
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
         << "\nsquare root of a == " << sqrt(a)
         << "\na-3 == " << a-3
         << "\n" << a << " modulo " << b << " == " << a%b
         << "\n++a (increment by 1) == " << ++a
         << "\n--b (decrement by 1) == " << --b
         << "\n";
    cout << "Note\n ++a et --b ci-dessus ne marchent pas. Voir version 4.\n";

         /* Note
            ++a et --b c--dessus ne marchent pas. Voir version 4.
         */
    return 0;
}

