#!/bin/bash
set -u

gcc benign_evil.c -Wall
bless a.out
head -c 12352 a.out > prefix
md5collgen -p prefix -o out1.bin out2.bin
ll 
		
tail -c +12481 a.out > suffix
tail -c 128 out1.bin > P
tail -c 128 out2.bin > Q

head -c 288 suffix > suffix_1
tail -c +417 suffix > suffix_2
	
cat prefix P suffix_1 P suffix_2 > a1.out
cat prefix Q suffix_1 P suffix_2 > a2.out
chmod a+x a1.out a2.out
	
a1.out
a2.out
md5sum a1.out a2.out 

