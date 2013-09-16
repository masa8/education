#!/bin/bash
echo Name of the script:$'\t' $0
echo All the value of args:$'\t' $@
echo Number of args :$'\t'$#
for i; do
	((count++))
	echo Value of arg[$count]:$'\t'$i
done
