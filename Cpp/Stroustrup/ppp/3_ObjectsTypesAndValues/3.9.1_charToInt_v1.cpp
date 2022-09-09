#include "../std_lib_facilities.h"
/*
Génère tout l'alphabet majuscule et minuscule; à partir du point de départ en int. Démontre conversion int à char.'
ppp., page 79

Note : il y a 5 caractères non alphabétiques entre z et A
*/

int main()
{
    cout << "charToInt v1\n";
    char c = ' ';
    int i;
    // 65 to 122 gives a to z, + 5 non alpha car + A to Z
    for (i = 1; i <= 255; ++i)
    {
      c=i;
      cout << "i= " << i << ", " << "car. corr. = '" << c << "'\n";

    }
}
