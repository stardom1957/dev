#include "../std_lib_facilities.h"

int main()
{
    cout << "3_ex_10_v2.cpp v1\n";
    cout << "SVP, entrer une opérande suivie de deux nombres (trl-D pour quitter) : \n";

    //string operande;
    char operande;
    double val1;
    double val2;

    while (cin >> operande >> val1 >> val2)
    {
        switch (operande) {
        case '+':
          cout << val1+val2;
          break;
        case '-':
            cout << val1-val2;
            break;
        case '*':
            cout << val1*val2;
            break;
        case '/':
            if (val2 !=0) cout << val1/val2;
            else cout << "Erreur, division par zéro!";
      }

      cout << "\nSVP, entrer une opérande suivie de deux nombres (trl-D pour quitter) : \n";
    }
    return 0;
}
