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
p = re.compile("\*\*\ debug")
for line in contents:
    i = i + 1
    m = p.search(line)

    if m:
#        contents.remove(contents[i+1])
        print i
        str = "debug_break_point_" + `j` + ":\n"
        contents.insert(i, str)
        j = j + 1



f = open("cc.c", "w")
contents = "".join(contents)
f.write(contents)
f.close()
