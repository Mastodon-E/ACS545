#!/bin/bash
set -u

gcc print_array.c -Wall
bless a.out

head -c 12352 a.out > prefix
md5collgen -p prefix -o out1.bin out2.bin
ll

tail -c +12481 a.out > suffix
tail -c 128 out1.bin > P
tail -c 128 out2.bin > Q
cat prefix P suffix > a1.out
cat prefix Q suffix > a2.out

chmod a+x a1.out a2.out
diff a1.out a2.out

md5sum a1.out a2.out

