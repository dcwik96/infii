#!/usr/bin/awk -f
{
  total = $4 + $5 + $6 + $7 + $8
  avg = total / 5
  print $2, $3, avg
}
