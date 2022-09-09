#! /usr/bin/env python
import os
import time
monChemin = os.path.expanduser('~') + '/dev/python'
print ('Chemin : ' + monChemin + '\n')

# liste les fichiers du chemin
listeFichiers = os.listdir(monChemin)
print ('Liste des fichiers de ' + monChemin + '\n')
for f in listeFichiers:
    #inf= statinfo = os.stat(f).st_size
    print (f, '(', os.stat(f).st_size, 'octets)', end='\n')

print ('\n\nPlus de détails sur le fichier "' + f + '"')
d = os.stat(f)
print (' st_size : ' + str(d.st_size) + ' octets')
print (' st_mode : ' + str(d.st_mode))
print (' st_uid : ' + str(d.st_uid))
print (' st_gid : ' + str(d.st_gid))
print (' st_atime : ' + str(d.st_atime) + ' ( access: ' + time.ctime(d.st_atime) + ')')
print (' st_mtime : ' + str(d.st_mtime)+ ' ( modif: ' + time.ctime(d.st_mtime) + ')')

