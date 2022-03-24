#!/usr/bin/python3

from Crypto.Cipher import AES
from Crypto.Util import Padding

#key_string = 'computer########'
#key = bytes.fromhex(key_string.encode('utf-8').hex())

iv_hex_string  = 'aabbccddeeff00998877665544332211'
iv  = bytes.fromhex(iv_hex_string)

data = b'This is a top secret.'
print("Length of data: {0:d}".format(len(data)))

expected_ciphertext = '3879c71b232cd0d2fc6f5ffcc1d76f074c0fcbe007d9cc53939fdeebf1d6ffd2'
print("Expected ciphertext: {0}".format(expected_ciphertext))

file1 = open("words.txt", "r")
Lines = file1.readlines()

for line in Lines:
   key_string = line.strip()
   #print(key_string)
   if (len(key_string) < 16):
       add = 16 - len(key_string)
       for x in range(add):
           key_string = key_string + "#"
   elif (len(key_string) > 16):
        key_string = '################'
   
   key = bytes.fromhex(key_string.encode('utf-8').hex())
   
   # Encrypt the entire data
   cipher = AES.new(key, AES.MODE_CBC, iv)                   
   ciphertext = cipher.encrypt(Padding.pad(data, 16))
   b = format(ciphertext.hex())

   if expected_ciphertext == b:
       print("Ciphertext: {0}".format(ciphertext.hex()))
       print(key_string)

file1.close()

