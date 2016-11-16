#!/bin/bash

for ((i=0;i<10;i++))
do
 array[i]=$(($RANDOM%20))
done

echo "Oryginalna tablica: "
for (( i=0; i<10; i++ ))
do
  printf "${array[$i]} "
done
echo
echo "Tablica do kwadratu: "
for (( i=0; i<10; i++ ))
do
  printf "$((${array[$i]} ** 2)) "
done
echo

