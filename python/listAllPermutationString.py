#! /usr/bin/env python

from math import factorial
 
def print_permutations_lexicographic_order(s):
    """Print all permutations of string s in lexicographic order."""
    seq = list(s)
    for _ in range(factorial(len(seq))):
        print(''.join(seq))
        nxt = get_next_permutation(seq)
        # if seq is the highest permutation
        if nxt is None:
            # then reverse it
            seq.reverse()
        else:
            seq = nxt
 
def get_next_permutation(seq):
    """Return next greater lexicographic permutation. Return None if cannot.
 
    This will return the next greater permutation of seq in lexicographic
    order. If seq is the highest permutation then this will return None.
 
    seq is a list.
    """
    if len(seq) == 0:
        return None
 
    nxt = get_next_permutation(seq[1:])
 
    # if seq[1:] is the highest permutation
    if nxt is None:
        # reverse seq[1:], so that seq[1:] now is in ascending order
        seq[1:] = reversed(seq[1:])
 
        # find q such that seq[q] is the smallest element in seq[1:] such that
        # seq[q] > seq[0]
        q = 1
        while q < len(seq) and seq[0] > seq[q]:
            q += 1
 
        # if cannot find q, then seq is the highest permutation
        if q == len(seq):
            return None
 
        # swap seq[0] and seq[q]
        seq[0], seq[q] = seq[q], seq[0]
 
        return seq
    else:
        return [seq[0]] + nxt
 
 
s = input('Enter the string: ')
print_permutations_lexicographic_order(s)
