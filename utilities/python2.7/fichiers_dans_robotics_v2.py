#! /usr/bin/env python2.7
# -*- coding: utf-8 -*-
import os
#from os.path import join, getsize
import os.path
#import time
from time import localtime, strftime

def parcoure_chemin_au_complet(ch):
    for root, dirs, files in os.walk(ch):
        print root + ' :'
        for name in files:
            if os.path.isfile(os.path.join(root, name)):
                s_mtime = localtime(os.path.getmtime(os.path.join(root, name)))
                str_timef =  strftime("%Y-%m-%d %H:%M:%S", s_mtime)
                fsize = str(os.path.getsize(os.path.join(root, name)))
                print '   ', name, ' (' + fsize, 'octets) ' + str_timef 
        if 'libraries' in dirs:
            dirs.remove('libraries')  # ne pas visiter le dossier «librairie»
    return


monChemin = os.path.expanduser('~') + '/Arduino/robotics/Kookye_vehicule'
print 'Liste des fichiers du projet KVA'
print 'Le dossier de base base est : ' + monChemin + '\n'
parcoure_chemin_au_complet(monChemin)

#time.strftime("%d %b %Y %H:%M:%S +0000", time.localtime())

#print ('\n\nPlus de détails sur le fichier "' + f + '"')
#d = os.stat(monChemin + '/' + f)
#print (' st_size : ' + str(d.st_size) + ' octets')
#print (' st_mode : ' + str(d.st_mode))
#print (' st_uid : ' + str(d.st_uid))
#print (' st_gid : ' + str(d.st_gid))
#print (' st_atime : ' + str(d.st_atime) + ' ( access: ' + time.ctime(d.st_atime) + ')')
#print (' st_mtime : ' + str(d.st_mtime)+ ' ( modif: ' + time.ctime(d.st_mtime) + ')')


