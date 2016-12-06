#!/usr/bin/awk -f
BEGIN { FS = ","
 OFS = ";" }
{ print $2, $3 }
END { }
