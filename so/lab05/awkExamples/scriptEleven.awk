#!/usr/bin/awk -f
function max (n,m){
  if (n > m)
    return n
  else
    return m
}
{
print max($1, $2)
}
