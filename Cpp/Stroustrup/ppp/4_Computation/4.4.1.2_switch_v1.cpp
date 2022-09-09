#include "../std_lib_facilities.h"
// ppp, chap4., p. 105
int main()
{
    cout << "4.4.1.2_switch_v1.cpp\n\n";
    constexpr double cmPerInch = 2.54;
    double length =1;
    char unit ='a';
    cout << "SVP, entrez une longueur suivie d'une unité (c || p || i) :\n";
    cin >> length >> unit;
    switch (unit) {
    case 'p': case 'i':
        cout << length << " po == " << cmPerInch*length << " cm\n";
        break;
    case 'c':
        cout << length << " cm == " << length/cmPerInch << " po\n";
        break;
    default:
        cout << "Désolé, l'unité «" << unit << "» est inconnue";
    }
}
