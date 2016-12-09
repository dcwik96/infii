#!/bin/bash
  trap './dostalem.sh' USR1
  trap './koniec.sh' USR2
  while true
  do
    echo "Czekam"
    sleep 5
  done
  exit 0
