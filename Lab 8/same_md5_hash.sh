#!/bin/bash
set -u

md5collgen -p prefix.txt -o out1.bin out2.bin

diff out1.bin out2.bin
md5sum out1.bin
md5sum out2.bin

bless out1.bin out2.bin

