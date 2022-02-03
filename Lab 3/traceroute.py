#!/usr/bin/env python3
from scapy.all import *

a = IP()
a.dst = '8.8.4.4'
a.ttl = 1
b = ICMP()

while a.ttl <= 20:
    reply = sr1(a/b, verbose=0)
    print(str(a.ttl)+ '\t' + reply.src)

    if (reply.src == a.dst):
        break

    a.ttl += 1


