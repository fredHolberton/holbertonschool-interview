#!/usr/bin/python3
""" Module : N Queens """


import sys

nbArg = len(sys.argv)
if nbArg != 2:
    print("Usage: nqueens N")
    sys.exit(1)
    
a = int(sys.argv[1])
if a < 4:
    print("N must be at least 4")
    sys.exit(1)
    
print("Command OK")
sys.exit(0)
