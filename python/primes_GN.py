# Programme original fourni par Stardom
#  il ne se souvient plus trop d'où il provient,
#  mais nous croyons que ça a un rapport avec
#  le Raspberry Pi
# Reçu:2022-10-07 de Stardom
# C:2022-10-07 : M:2022-10-09
# primes.py version 1.1a
# Remplacement des prints par l'utilisation d'une liste
# Ajout de commentaires expliquant le fonctionnement
#!/usr/bin/env python3
n=int(input("Quel est le nombre maximum désiré ? "))
sieve=set(range(2,n+1))
liste=[]
while sieve:					# Tant que l'ensemble n'est pas vide
    prime=min(sieve)				# Obtenir la valeur du plus petit élément
    liste.append(prime)				# Ajouter le nouveau nombre premier dans la liste
    sieve-=set(range(prime, n+1, prime))	# Enlever de l'ensemble cet élément et tous ses multiples
 						# Recommencer ...
print(liste)
