#include "../std_lib_facilities.h"
/*
accepte diverses valeurs et compose une lettre.
ppp., drill, page 83

*/

int main()
{
  cout << "3_drill_v1\n";
  string prenomPersonne{" "};
  string genrePersonne{" "};
  string votrePrenom{" "};
  int agePersonne{0};

  cout << "Indiquez le prénom de votre ami(e), son genre (m | f) et son age :\n";
  cin >> prenomPersonne >> genrePersonne >> agePersonne;

  cout << "Indiquez votre prénom : \n";
  cin >> votrePrenom;

  string genre{"féminin"};
  string genitif{"elle"};
  string terminaisonGenre = "e";

  if ((genrePersonne == "m") || (genrePersonne == "M"))
  {
    genre = "masculin";
    genitif = "il";
    terminaisonGenre = "";
  }

  cout << "Bonjour " << votrePrenom << ", \n";
  cout << "Votre ami" << terminaisonGenre << " ";
  cout << prenomPersonne << " est du genre " << genre << " et " << genitif << " a " << agePersonne << " ans.\n";
  return 0;

}
