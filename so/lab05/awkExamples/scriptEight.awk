#!/usr/bin/awk -f
{
sum = 0.0
for ( i = 4; i <= NF; i++)
    sum += $i
}
{
avg = sum / (NF - 3)
 if ( avg > 4) print $2, $3, "ma wysoka srednia"
      else
      print $2, $3, "ma niska srednia"
}
