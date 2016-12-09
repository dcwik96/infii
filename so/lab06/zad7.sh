#!/bin/bash

# Sprawdzenie, ile argumentow
if (( $#==0 )) ; then
	echo "Mialo byc dokladnie dwa argumenty! Koncze program"
	exit 0
elif (( $#==1 )) ; then
	echo "Mialo byc dokladnie dwa argumenty! Koncze program"
	exit 0
elif (( $#>2 )) ; then
  echo "Mialo byc dokladnie dwa argumenty! Koncze program"
  exit 0
# Gdy podane sa dwa argumenty
else
. nwd.sh
nwd $1 $2
fi
exit 0
