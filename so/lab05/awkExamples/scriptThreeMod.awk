#!/usr/bin/awk -f

BEGIN { FS = "," }

{
  print ""
  print $2
  print $3
  print $4
}