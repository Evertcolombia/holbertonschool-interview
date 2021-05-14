#!/usr/bin/python3
"""
method that calculates the fewest number of operations
needed to result in exactly n H characters in the file.
"""

def minOperations(n):
    cont = n
    res = 0
    i = 2

    if (type(n) != int or n <= 0):
        return 0

    while i <= n and cont > 1:
        if cont % i == 0:
            cont = cont / i
            res = res + i
        else:
            i = i + 1
        
    return res
