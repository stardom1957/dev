#! /usr/bin/env python
import os
#from os.path import join, getsize
import os.path
import time

'''
L'on devra parcourir la liste des répertoires récursivement.
'''

def parcoure_chemin_au_complet(ch):
    for root, dirs, files in os.walk(ch):
        print (root + ' :')
        for name in files:
            if os.path.isfile(os.path.join(root, name)):
                print ('   ', name, ' (', os.path.getsize(os.path.join(root, name)), ' octets)', end='\n')
        if 'libraries' in dirs:
            dirs.remove('libraries')  # don't visit librairie directories
    return

monChemin = os.path.expanduser('~') + '/Arduino/robotics/'
print ('Le chemin de base est : ' + monChemin + '\n')
parcoure_chemin_au_complet(monChemin)

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

