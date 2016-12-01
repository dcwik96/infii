#!/bin/bash

y=$1

  if [ $y == 0 ] ;then
    exit 1

  fi

./1b.sh $((y-1)) &

wait $!
wynik=$?

exit $((y*wynik))
