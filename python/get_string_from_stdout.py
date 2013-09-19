#!/bin/env python


from subprocess import *
output = Popen(["ls","-al"], stdout=PIPE).communicate()[0]
outstr = str(output)

if "stdout" in outstr:
    print("FOUND")


