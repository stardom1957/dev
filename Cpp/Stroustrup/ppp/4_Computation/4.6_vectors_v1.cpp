#include "../std_lib_facilities.h"
// ppp, chap4., p. 118 à 120
// différentes façons de déclarer des vector
int main()
{
    vector<int>vi1{5, 7, 9, 4, 6, 8}; // tous les éléments int sont initialisés
    cout << "vector<int>vi1{5, 7, 9, 4, 6, 8};\n";
    cout << "Contenu de vi1 :\n";
    for (int e : vi1)
         cout << "\t" << e << "\n";

    vector<string>philosophes{"Kant", "Platon", "Hume", "Pierce"}; // tous les éléments string sont initialisés
    cout << "\nvector<string>philosophes{""Kant"", ""Platon"", ""Hume"", ""Pierce""};\n";
    cout << "Contenu de philosophes : \n";
    for (string p : philosophes)
         cout << "\t" << p << "\n";

    vector<int>vi2(6); // pas d'élément déclaré, juste la taille :: tous les éléments initialisés à 0 par défaut
    cout << "\nvector<int>vi2(6);\n";
    cout << "Contenu de vi2 :\n";
    for (int e : vi2)
         cout << "\t" << e << "\n";

    /*for (int e{0}; e < vi2.size(); ++e) {
        cout << "Entrez un élément : ";
        cin >> vi2[e];
        }

    cout << "Nouveau contenu de vi2 :\n";
    for (int e : vi2)
         cout << "\t" << e << "\n";
*/
    vector<double>temperatures; //pas de taille, on construit le vecteur au fur et à mesure
    cout << "vector<double>temperatures;\n";
    cout << "Entrez les températures (Ctrl-D pour terminer) :\n";
    for (double temp; cin >> temp;)
        temperatures.push_back(temp);

    cout << "Contenu de temperatures :\n";
    for (double t : temperatures)
         cout << "\t" << t << " C°\n";

    // calcule la moyenne des températures
    double sum_temps = 0;
    for (double t : temperatures) sum_temps+=t;
    cout << "Température moyenne == " << sum_temps/temperatures.size() << " °C\n";

    sort(temperatures);
    cout << "\nContenu trié de temperatures :\n";
    for (int t : temperatures)
         cout << "\t" << t << " °C\n";

    return 0;
}
