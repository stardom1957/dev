# Programme original fourni par Stardom
# La provenance exacte du fichier source est inconnue,
#  mais nous croyons que ça a un rapport avec
#  le Raspberry Pi
# **************************************************
# Reçu:2022-10-07 de Stardom
# C:2022-10-07 : M:2022-11-20
# primes_GN.py version 1.1c
# **************************************************
# Remplacement des prints par l'utilisation d'une liste
# Ajout de commentaires expliquant le fonctionnement
# Correction de l'indentation
# Transformation en programme avec une fonction
# Lecture d'un argument de la ligne de commande
# Ajout de documentation intégrée
# **************************************************
#!/usr/bin/env python3

import sys

def prem(n):
    '''
        Fonction retournant un ensemble contenant
         les nombres premiers entre 2 et n.
        n est est inclu s'il est premier.
    '''
    sieve=set(range(2,n+1))
    liste_prem=[]
    while sieve:					# Tant que l'ensemble n'est pas vide
        prime=min(sieve)			# Obtenir la valeur du plus petit élément
        liste_prem.append(prime)			# Ajouter le nouveau nombre premier dans la liste
        sieve-=set(range(prime, n+1, prime))	# Enlever de l'ensemble cet élément et tous ses multiples
                                    # Recommencer ...
    return(liste_prem)

def main():
    '''
        Programme servant à la génération d'une liste
         de nombres premiers.
        On peut saisir le nombre maximum sur la ligne de
         commande ou en réponse à la question quand le
         programme s'exécute.
    '''
    if len(sys.argv) == 1:	# S'il n'y a pas d'arguments,
      nb=int(input("Quel est le nombre maximum désiré ? "))
    else:
      nb=int(sys.argv[1])
    
    resul=prem(nb)	# La fonction prem retourne un ensemble
                    #  l'ensemble n'est pas nécessairement ordonné,
                    #  il faut le mettre dans une liste et le trier
    liste=list(resul)
    liste.sort()
    print(liste)

if __name__ == "__main__":
    main()
