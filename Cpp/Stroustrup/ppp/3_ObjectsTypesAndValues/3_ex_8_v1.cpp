#include "../std_lib_facilities.h"

int main()
{
    cout << "3_ex_8_v1.cpp v1\n";
    cout << "SVP, entrer un nombre entier (trl-D pour quitter) : \n";
    // double n;
    int val1;

    while (cin >> val1)
    {
        if (val1 % 2 == 0) cout << val1 << " est pair.\n";
        else cout << val1 << " est impair.\n";

        cout << "SVP, entrer un nombre entier (Ctrl-D pour quitter) : \n";
    }
    return 0;
}
