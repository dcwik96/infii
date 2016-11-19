#!/usr/bin/awk -f
{
suma=0
a=$1

for(i=1; i<=NF; i++){
suma = suma+ $i
if($i>=a)max =$i;

if($i<=a) min=$i;
}


print "Wiersz " NR": " "min = "min " max = "max " suma = "suma
}
