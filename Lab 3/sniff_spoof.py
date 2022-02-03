#!/usr/bin/env python3
from scapy.all import *

def print_pkt(pkt):
    if ICMP in pkt and pkt[ICMP].type == 8:
        ip = IP(src=pkt[IP].dst, dst=pkt[IP].src, ihl=pkt[IP].ihl)
        icmp = ICMP(type=0, id=pkt[ICMP].id, seq=pkt[ICMP].seq)
        data = pkt[Raw].load
        newpkt = ip/icmp/data

        send(newpkt, verbose=0)
        
        print("Spoof packet sent")

pkt = sniff(iface='br-6f245d759a03', filter='icmp and src host 10.9.0.5', prn=print_pkt)


