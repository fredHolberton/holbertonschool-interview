#!/usr/bin/python3
""" Module : Minority Operations """
from math import *


def isPrimeNumber(n):
    m = 2
    isPrime = True
    while (m < n) and (isPrime is True):
        if n % m == 0:
            isPrime = False
        else:
            m = m + 1
    return isPrime

def greatestDivisor(n):
    m = n // 2
    while (n % m != 0) and m > 3:
       m = m - 1
    return m

def PowerOf(n):
    i = int(n/4)
    p = i
    isPowerOf = False
    while (p < i) and (isPowerOf is False):
        m = 2
        while (m < i) and (isPowerOf is False):
            #print("{} ^ {}".format(m,p))
            if (m ** p) == n:
                isPowerOf = True
            else:
                m = m + 1
        if isPowerOf is False:
            p = p + 1
    if isPowerOf is True:
        return p
    else:
        return 0
                  
def minOperations(n):
    if n <= 1:
        return 0
    if n <= 5:
        return n
    if isPrimeNumber (n):
        #print("{} est un nombre premier".format(n))
        return n
    p = PowerOf(n)
    if p != 0:
        m = int(n ** (1/p))
        #print("{} = {} ^ {}".format(n, m, p))
        return minOperations(m) + p + 1
    else:
        m = greatestDivisor(n)
        d = n // m
        #print("{} = {} x {}".format(n, m, d))
        return minOperations(m) + d
    
    
    
