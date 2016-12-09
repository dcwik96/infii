#!/bin/bash
if [ $#==0 ]
then
 echo "pedal"
else
 for ((i=1;i<=$#;i++)); do
 printf "${!i} "
 done
 echo ""
fi
