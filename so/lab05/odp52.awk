#!/usr/bin/awk -f
{
suma = 0

a = $1

for( i = 1 ; i <= NF; i++){
  suma = suma + $i
  if($i >= a) maksimum = $i;
  if($i <= a) minimum = $i;
}

print "Wiersz " NR": min = " minimum " max = " maksimum " suma =  "suma

}
