#!/usr/bin/awk -f
{
sum = 0
for ( i = 1; i <= NR; i++){
    sum += $6
    }
print sum
}

