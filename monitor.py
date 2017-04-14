#!/usr/bin/python
import socket
import re 
from pysnmp.hlapi import *
from threading import Thread
import sys

hostname = '192.168.1.200'
target = '192.168.1.14'
port = 162
serversocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
serversocket.bind((hostname, port))


print "Starting manager -- receives traps"
def send_msg(sock):
    while True:
        data, addr = sock.recvfrom(1024)
        #print data
        #sys.stdout.write(data)
        print("Trap received")

Thread(target=send_msg, args=(serversocket,)).start()  

print "Getting Objects:\n\n"
g = getCmd(SnmpEngine(),CommunityData('public'),UdpTransportTarget((target, 161)),ContextData(),ObjectType(ObjectIdentity('MY-MIB', 'testCount', 0)))
x = next(g)
print(x[3][0])
g = getCmd(SnmpEngine(),CommunityData('public'),UdpTransportTarget((target, 161)),ContextData(),ObjectType(ObjectIdentity('MY-MIB', 'testDescription', 0)))
x = next(g)
print(x[3][0])
g = getCmd(SnmpEngine(),CommunityData('public'),UdpTransportTarget((target, 161)),ContextData(),ObjectType(ObjectIdentity('MY-MIB', 'testInteger', 0)))
x = next(g)
print(x[3][0])

print "Setting Objects:\n\n"
g = setCmd(SnmpEngine(),CommunityData('private'),UdpTransportTarget((target, 161)),ContextData(),ObjectType(ObjectIdentity('MY-MIB', 'testCount', 0), 1000))
x = next(g)
print(x[3][0])
g = setCmd(SnmpEngine(),CommunityData('private'),UdpTransportTarget((target, 161)),ContextData(),ObjectType(ObjectIdentity('MY-MIB', 'testDescription', 0), "New Description"))
x = next(g)
print(x[3][0])
g = setCmd(SnmpEngine(),CommunityData('private'),UdpTransportTarget((target, 161)),ContextData(),ObjectType(ObjectIdentity('MY-MIB', 'testInteger', 0), 2000))
x = next(g)
print(x[3][0])
