#!/usr/bin/awk -f
BEGIN { FS = "," }
{ print }
END { print ""
      print "Przetworzonych " , NR, "rekordow"
    }
