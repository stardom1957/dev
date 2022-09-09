#!/usr/bin/env python3
def printno(upper):
    if(upper>0):
        printno(upper-1)
        print(upper, end="\t")
upper=int(input("Enter upper limit: "))
printno(upper)
