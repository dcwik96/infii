#!/bin/bash
clear
echo -n "Podaj liczbe naturalna: "
read x
./syn.sh $x &
ojc_wynik=$((x*x))
wait $!
syn_wynik=$?
echo "Wynik obliczenia: $((ojc_wynik+syn_wynik))"
exit 0
