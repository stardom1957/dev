#!/usr/bin/env python3
# simule le controle d'un moteur avec le clavier
# avec l'aide d'un dictionnaire
key_mapping = {'w': [ 1, 1], 'x': [-1, -1],
               'a': [-1, 0], 'd': [1,  0],
               's': [ 0, 0]}
sens = {1: 'avance', -1: 'recule', 0: 'stop'}

while dir != 's':
    dir=input("Direction : ")
    print("Direction choisie : ", key_mapping[dir], '(' + sens[key_mapping[dir][0]] + ', ', sens[key_mapping[dir][1]]+ ')')

