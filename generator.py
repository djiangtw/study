#!/usr/bin/python
import random

def lottery():
    # return 6 numbers between 1 and 40
    for i in xrange(6):
        yield random.randint(1, 40)

    #return a 7th number between 1 and 15
    yield random.randint(1, 15)

def print_lottery():
    for random_number in lottery():
        print "And the next number is ... %d!" % random_number

print_lottery()
