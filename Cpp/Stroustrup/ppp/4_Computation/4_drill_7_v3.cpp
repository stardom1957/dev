#include "../std_lib_facilities.h"
// ppp, chap4., Drills, p. 126
// toutes les unité convertis en mètres
// par rapport à version 1, on se débarrasse du goto
//enum class Units {cm, po, m, pi};

int main()
{
    enum Units {cm, po, m, pi, xx}; // xx == erreur, on passe
    constexpr double cmParPouce = 2.54;
    double longueur{0};
    //string unite = "rien";
    cout << "longueur et unité (cm | po | m | pi : ";

    string unite="";
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
               u=Units::xx;
              }

        switch (u) {
         case Units::cm :
            cout << longueur << " " << unite << "== " << longueur / 100 << " m\n";
            break;

         case Units::m :
            cout << longueur << " " << unite << "== " << longueur << " m\n";
            break;

         case Units::pi :
            cout << longueur << " " << unite << "== " << (longueur * 12 * cmParPouce)/100 << " m\n";
            break;

         case Units::po :
            cout << longueur << " " << unite << "== " << (longueur * cmParPouce)/100 << " m\n";
            break;

         case Units::xx : ;//on fait rien
        }
       cout << "longueur et unité (cm | po | m | pi : ";
    }
    return 0;
}

