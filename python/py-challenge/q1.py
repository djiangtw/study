#!/usr/local/bin/python2.7
from string import maketrans

s = "g fmnc wms bgblr rpylqjyrc gr zw fylb. rfyrq ufyr amknsrcpq ypc dmp. bmgle gr gl zw fylb gq glcddgagclr ylb rfyr'q ufw rfgq rcvr gq qm jmle. sqgle qrpgle.kyicrpylq() gq pcamkkclbcb. lmu ynnjw ml rfc spj."
p = ""
print len(s)

for i in xrange(0, len(s)):
    if(ord(s[i]) >= ord('a') and ord(s[i]) <= ord('z')):
        tmp = ord(s[i])
        tmp = ord('a') + (tmp - ord('a') + 2)%26
        p = p + chr(tmp)
    else:
        p = p + s[i]

print p

t = ""
u = ""

for i in xrange(0, 26):
    u = u + chr(ord('a')+i)
    t = t + chr(ord('a')+(i+2)%26)
    
print t
print u

trantab = maketrans(u, t)
print s.translate(trantab);
v = "map"
print v.translate(trantab)
