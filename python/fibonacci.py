#!/usr/bin/python
# Author: djiangtw

a = 1
b = 1
#print a, ", ", b,
for i in range(2, 20):
    a, b = b, a+b
#    print ", ", b,
    print i,
