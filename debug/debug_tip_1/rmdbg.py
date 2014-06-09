#!/usr/bin/python

import re

f = open("cc.c", "r")
contents = f.readlines()
f.close()

#index = 8 
#value = "/** debug */\n"
#contents.insert(index, value)

i = 0
j = 0
p = re.compile(r'debug_break_point')
for line in contents:
    i = i + 1
    m = p.search(line)

#    print contents[i-1]
    if m:
        print contents[i-1]
        contents[i-1] = "" 

f = open("cc.c", "w")
contents = "".join(contents)
f.write(contents)
f.close()
