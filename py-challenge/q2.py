#!/usr/bin/python
# cloud: http://www.codeskulptor.org/#user30_dyrWR0kxxL_2.py 
s = "%%$@_$^__#)^)&!_+]!*@&^}@[@%]()%+$&[(_@%+%$*^@$^!+]!&_#)_*}{}}!}_]$[%}@[{_@#_^{*"
s = s + "@##&{#&{&)*%(]{{([*}@[@&]+!!*{)!}{%+{))])[!^})+)$]#{*+^((@^@}$[**$&^{$!@#$%)!@(&"
s = s + "+^!{%_$&@^!}$_${)$_#)!({@!)(^}!*^&!$%_&&}&_#&@{)]{+)%*{&*%*&@%$+]!*__(#!*){%&@++"
s = s + "!_)^$&&%#+)}!@!)&^}**#!_$([$!$}#*^}$+&#[{*{}{((#$]{[$[$$()_#}!@}^@_&%^*!){*^^_$^"
s = s + "]@}#%[%!^[^_})+@&}{@*!(@$%$^)}[_!}(*}#}#___}!](@_{{(*#%!%%+*)^+#%}$+_]#}%!**#!^_"
s = s + ")@)$%%^{_%!@(&{!}$_$[)*!^&{}*#{!)@})!*{^&[&$#@)*@#@_@^_#*!@_#})+[^&!@*}^){%%{&#@"
s = s + "@{%(&{+(#^{@{)%_$[+}]$]^{^#(*}%)@$@}(#{_&]#%#]{_*({(])$%[!}#@@&_)([*]}$}&${^}@(%"
s = s + "(%[@%!}%*$}(*@)}){+@(%@*$&]*^*}*]&$[}*]%]+*}^!}*$^^_()#$^]++@__){&&+((#%+(&+){)$"
s = s + "%&&#($[[+##*%${)_!+{_[})%++)$#))]]]$]@]@($+{&%&%+!!!@]_]+])^*@$(@#${}}#}{%}#+{(@"
s = s + "#__+{{]${]!{(%${%%^)(_*_@+)$]$#_@$)]](}{}$(}*%+!}#+)$%$}+#@*&^{##}+@(%[*@_}{(^]^"
print len(s)

d = {}

for i in xrange(0, len(s)):
    if s[i] in d:
        d[s[i]] += 1
    else:
        d[s[i]] = 1

print d

print d.keys()

t = ""

for i in d.keys():
    t += i
print t

d2 = {}
for i in xrange(0, len(s), 2):
  if s[i:i+2] in d2:
    d2[s[i:i+2]] += 1
  else:
    d2[s[i:i+2]] = 1

print d2

print d2.keys()

print len(d2.keys())

u = "0213456789abcdef"

#--

trantab = maketrans(t, u)
ss = s.translate(trantab);
print ss

c = ""
for i in xrange(0, 20):
    x = int(ss[2*i:2*i+2], 16)
    c += chr(x)
print c
#--
