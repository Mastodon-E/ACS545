#!/usr/bin/env python3
from scapy.all import *

def print_pkt(pkt):
    pkt.show()

pkt = sniff(iface='br-9f637162b355', filter='icmp', prn=print_pkt)

