#include "../std_lib_facilities.h"
// ppp, chap4., p. 116

int mySquare(int i)
{
    int x;
    int resultat = 0;
    for (x=0; x<i; ++x) resultat+=i;
    return resultat;
}


int main(){
    cout << "4.5.1_try_v1.cpp\n";
    cout << "SVP, entrez un entier:\n";
    int val1;
    while (cin>>val1)
    {
        cout << "Le carré de " << val1 << " est " << mySquare(val1) << "\n";
        cout << "SVP, entrez un entier:\n";
    }
    return 0;
}
