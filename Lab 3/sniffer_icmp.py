#!/usr/bin/env python3
from scapy.all import *

def print_pkt(pkt):
    pkt.show()

pkt = sniff(iface='br-6f245d759a03', filter='icmp and host 10.9.0.5 and host 8.8.4.4', prn=print_pkt)


