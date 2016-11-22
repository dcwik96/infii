#!/bin/bash

function nwd
{
  A=$1
  B=$2
  while [ $A -ne $B ]
  do
  	if [ $A -gt $B ] ; then
  		let "A=A-B"
  	else
  		let "B=B-A"
  	fi
  done
  echo "NWD( $1 , $2 ) = $A"
}
