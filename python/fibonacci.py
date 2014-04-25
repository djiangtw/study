#!/usr/bin/python

a = 1
b = 1
#print a, ", ", b,
for i in range(2, 10):
    a, b = b, a+b
#    print ", ", b,
    print i,
