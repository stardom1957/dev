#! /usr/bin/env python
import os
import time

'''
L'on devra parcourir la liste des répertoires récursivement.
'''

def imprimeListeFichiers(ch):
    if os.path.isdir(ch):
        # liste les fichiers du chemin
        lf = os.listdir(ch)
        print ('Liste des fichiers de ' + ch + '\n')
        for f in lf:
            if os.path.isfile(f):
                #inf= statinfo = os.stat(f).st_size
                print (f, '(', os.stat(f).st_size, 'octets)', end='\n')
    return


monChemin = os.path.expanduser('~') + '/Arduino'
print ('Le chemin de base est : ' + monChemin + '\n')

listeRep = os.listdir(monChemin)
#print ('Liste du contenu de ' + monChemin + '\n')
for rep in listeRep:
    #inf= statinfo = os.stat(f).st_size
    #print (f, '(', os.stat(f).st_size, 'octets)', end='\n')
    imprimeListeFichiers(rep)

'''
print ('\n\nPlus de détails sur le fichier "' + f + '"')
d = os.stat(monChemin + '/' + f)
print (' st_size : ' + str(d.st_size) + ' octets')
print (' st_mode : ' + str(d.st_mode))
print (' st_uid : ' + str(d.st_uid))
print (' st_gid : ' + str(d.st_gid))
print (' st_atime : ' + str(d.st_atime) + ' ( access: ' + time.ctime(d.st_atime) + ')')
print (' st_mtime : ' + str(d.st_mtime)+ ' ( modif: ' + time.ctime(d.st_mtime) + ')')
'''

