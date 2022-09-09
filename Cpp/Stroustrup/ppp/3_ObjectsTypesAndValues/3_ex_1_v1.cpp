#include "../std_lib_facilities.h"
/*
accepte une distance en miles et converti en kilomètres.
ppp., ex., page 85

*/

int main()
{
    double nbr_Of_Miles{0};
    cout << "Donnez le nombre de miles (Ctrl-D pour terminer): \n";
    while (cin >> nbr_Of_Miles)
    {
        cout << nbr_Of_Miles << " miles == " << (nbr_Of_Miles * 1.609) << " Km.\n";
        cout << "Donnez le nombre de miles (Ctrl-D pour terminer): \n";
    }
    return 0;

}
