#!/usr/bin/awk -f
BEGIN {print n}
{
wynik=0
k=$1
wynik=n^k
print wynik
}
