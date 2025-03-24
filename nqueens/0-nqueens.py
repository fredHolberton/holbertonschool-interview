#!/usr/bin/python3
""" Module : N Queens """


import sys

if sys.argv.count != 2:
    print("Usage: nqueens N\n")
    sys.exit(1)
    
a = int(sys.argv[1])
if a < 4:
    print("N must be at least 4\n")
    sys.exit(1)
