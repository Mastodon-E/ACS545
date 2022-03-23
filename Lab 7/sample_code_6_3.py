#!/usr/bin/python3

from sys import argv
from Crypto.Util import Padding

script, userIV, nextIV = argv

# XOR two bytearrays
def xor(first, second):
   return bytearray(x^y for x,y in zip(first, second))

MSG = b'Yes'

# Convert ascii string to bytearray
D1 = Padding.pad(MSG, 16)

# Convert hex string to bytearray
D2 = bytearray.fromhex(userIV)
D3 = bytearray.fromhex(nextIV)

r1 = xor(D1, D2)
r2 = xor(r1, D3)

print(r2.hex())

