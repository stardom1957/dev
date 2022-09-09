#include "../std_lib_facilities.h"
// ppp, chap4., p. 130
// exercice 13 : Sieve of Eratosthenes
// réf : https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
/* pseudo code

Input: an integer n > 1.

 Let A be an array of Boolean values, indexed by integers 2 to n,
 initially all set to true.
 for i = 2, 3, 4, ..., not exceeding √n:
   if A[i] is true:
     for j = i^2, i^2+i, i^2+2i, i^2+3i, ..., not exceeding n:
       A[j] := false.

 Output: all i such that A[i] is true.
*/
int main()
{
  int n;
  cout << "Entrez n : ";
  cin >> n;
  vector<int>N;
  //initialiser les éléments à 1
  for (int i=0; i <= n+1; i++) {N.push_back(1);}
  //cout << "n= " << n << " :: table de " << N.size() << " éléments.\n";

  //trouve tous les nombres premiers
  int j= 0;
  for (int i = 2; i < sqrt(n); i++) {
    if (N[i]==1) {
        j = i*i;
        int k= 0;
        while (j<n+1) {
          N[j]=0;
          k++;
          j=(i*i) + (k*i);
        }
    }
  }

  //écriture dans fichier
  string chemin = "/home/dominique/Documents/";
  string fichier;
  cout<<"Entrer le nom du fichier : ";
  cin>>fichier;
  ofstream ost {chemin+fichier};
  if (!ost) error("peut pas ouvrir fichier ", fichier);
  ost << "Voici les nombres premiers jusqu'à " << n << " :\n";

  cout << "voir fichier " << chemin+fichier << " :\n";
// résultat
  for (int i = 2; i<=n; i++) {
    if (N[i]==1) ost << i << ", ";
  }
}
