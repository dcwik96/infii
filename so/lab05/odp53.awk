#!/usr/bin/awk -f

function licz(n, k){
  n=n^k
  return n
}


BEGIN{print n}
{
if(n != NULL)
  print licz(n, $1);
}
