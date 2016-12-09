#!/bin/bash

echo "Podaj liczbę:"
read liczba
if echo "$liczba" | grep -qE ^\-?[0-9]+$; then
        for ((i=0;i<=liczba;i++)); do

                echo -ne "$((2**$i)) "
                done
else
        echo "To nie liczba kolego, nie żartuj sobie ze mnie"
fi
