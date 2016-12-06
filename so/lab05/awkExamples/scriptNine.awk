#!/usr/bin/awk -f
{
sum = 0.0
for ( i = 4; i <= NF; i++){
    sum += $i
    }
avg = sum / (NF - 3)
students_avg[NR] = avg
}
END {
  print "Oto srednie uczniow"
  sum = 0
  for (i = 1; i <= NR; i++){
    print students_avg[i]
    sum += students_avg[i]
  }
  print "Srednia uczniow wynosi:" , sum / NR
}
