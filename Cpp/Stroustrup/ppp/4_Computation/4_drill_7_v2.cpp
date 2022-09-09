#include "../std_lib_facilities.h"
// ppp, chap4., Drills, p. 126
// toutes les unité convertis en mètres

//enum class Units {cm, po, m, pi};

double trouvePlusPetit (double d1, double d2) {
    if (d1 < d2) return d1;
    else return d2;
}

double trouvePlusGrand (double d1, double d2) {
    if (d1 > d2) return d1;
    else return d2;
}


int main()
{
    enum Units {cm, po, m, pi};
    constexpr double cmParPouce = 2.54;
    double longueur{0};
    //string unite = "rien";
    cout << "longueur et unité (cm | po | m | pi : ";

    string unite="";
    double sumlongueurs = 0; // la somme des entrées convertis en m
    vector<double> longueurs;
    double plus_petit = 0; // plus petite valeur entrée
    double plus_grand = 0; // plus grande valeur entrée
    double longueur_en_metres = 0; // longueur converti en m

    while (cin>>longueur>>unite) {
//        cout << "longueur == " << longueur << " " << unite << "\n";

        /* s'il faut convertir unite en type Units, alors ce qui suit est ridicule
           car on pourrait tout faire ici sans le switch !!!

           Cependant, je pense que la structure du switch est plus claire.
        */

        Units u;
        if (unite=="cm") u=Units::cm;
        else if (unite=="m") u=Units::m;
         else if (unite=="pi") u=Units::pi;
           else if (unite=="po") u=Units::po;
             else {
               cout << "erreur, unité inconnue : «" << unite << "»\n";
               //return 1;
               goto icitte;
              }

        switch (u) {
         case Units::cm :
            longueur_en_metres = longueur/100;
            cout << longueur << " " << unite << "== " << longueur_en_metres << " m\n";
            break;

         case Units::m :
            longueur_en_metres = longueur;
            cout << longueur << " " << unite << "== " << longueur_en_metres << " m\n";
            break;

         case Units::pi :
            longueur_en_metres = longueur * 12 * cmParPouce/100;
            cout << longueur << " " << unite << "== " << longueur_en_metres << " m\n";
            break;

         case Units::po :
            longueur_en_metres = longueur * cmParPouce/100;
            cout << longueur << " " << unite << "== " << longueur_en_metres << " m\n";
            break;
        }
        if (longueurs.size() == 0) plus_petit = longueur_en_metres; // la première valeur entrée est la plus petite
        else plus_petit = trouvePlusPetit(plus_petit, longueur_en_metres);

        plus_grand = trouvePlusGrand(plus_grand, longueur_en_metres);

        longueurs.push_back(longueur_en_metres);
        sumlongueurs+=longueur_en_metres;

        icitte:
        cout << "longueur et unité (cm | po | m | pi : ";
    }
    cout << "\n\nVous avez entré " << longueurs.size() << " longueurs (ici triées et converties en m) :\n";
    sort(longueurs);
    for (double l:longueurs)
        cout << l << " m\n";

    cout << "\nLe total des valeurs entrées est " << sumlongueurs << " m.\n";
    cout << "... la plus petite est : " << plus_petit << " m.\n";
    cout << "... la plus grande est : " << plus_grand << " m.\n";
    return 0;
}
