#include "../std_lib_facilities.h"

int main()
{
    cout << "3_ex_6_v1.cpp v1\n";
    cout << "SVP, entrer trois nombres entiers (Ctrl-D pour quitter) : \n";
    // double n;
    int val1;
    int val2;
    int val3;

    while (cin >> val1 >> val2 >> val3)
    {
        cout << "Mise en ordre : ";
        if ((val1 < val2) && (val1 < val3))
        {
          cout << val1 << ", "; // val1 plus petite, alors ...
          //... comparer val2 et val3
          if (val2 < val3) cout << val2 << ", " << val3 << "\n";
          else cout << val3 << ", " << val2 << "\n";
        }
        else if ((val2 < val1) && (val2 < val3))
         {
           cout << val2 << ", "; // val2 plus petite...
           // ... alors, comparer valeur 1 et 3
           if (val1 < val3) cout << val1 << ", " << val3 << "\n";
           else cout << val3 << ", " << val1 << "\n";
         }
           else
           {
             // forcément val3 plus petite, alors...
             //comparer val1 et val2
             cout << val3 << ", ";
             if (val1 < val2) cout << val1 << ", " << val2 << "\n";
             else cout << val2 << ", " << val1 << "\n";
           }

        cout << "SVP, entrer trois nombres entiers (Ctrl-D pour quitter) : \n";
    }
    return 0;
}
