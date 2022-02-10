#!/usr/bin/env python3
from scapy.all import *

def print_pkt(pkt):
    pkt.show()

pkt = sniff(iface='br-6f245d759a03', filter='net 128.230.0.0/16', prn=print_pkt)

