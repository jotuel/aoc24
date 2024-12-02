#!/usr/bin/bash

# Solves the first part of the puzzle, for one star
cat input.txt | sort -n -k 1,1 | awk '{print $1}' > sort.txt
cat input.txt | sort -n -k 2,2 | awk '{print $2}' > sort1.txt
paste sort.txt  sort1.txt > awk.txt
cat awk.txt | awk 'function abs(x) {return ((x < 0) ? -x : x)} {sum += abs($1 - $2)}; END {print sum}'
# This solves the second part
grep -Ff sort.txt sort1.txt | uniq -c | awk '{sum += $1 * $2}; END {print sum}'
rm -r *sort* aw*

