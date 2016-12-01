#!/bin/bash
clear
echo -n "Podaj liczbe naturalna: "
read x
./1b.sh $x &
wait $!
syn_wynik=$?
echo "Wynik obliczenia: $syn_wynik"
exit 0
