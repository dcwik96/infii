#!/usr/bin/awk -f
/pedagog/ {
x++
if (x <= 3) { print }
}

