#include "../std_lib_facilities.h"
/*
Lit une série de mots, l'un après l'autre et indique lorsque deux mots consécutifs se répètent.
ppp., page 71
*/

int main()
{
    int nbrOfWords = 0;
    cout << "stringOperations v1\n";
    string previous = " "; // initialisé à pas un mot
    string current;
    while (cin>>current) { //lit série de mots jusqu'à Ctrl-d
        ++nbrOfWords;
        cout << "previous == «" << previous << "»\n";
        cout << "current  == «" << current << "»\n";

        if (previous == current)
            cout << "mot numéro " << nbrOfWords
                 << " répété : «" << current << "»\n";
        previous = current;
        cout << "\n";
    }
}
