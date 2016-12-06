#!/usr/bin/awk -f

{
z = split($0, array, " ")
for (i = 1; i <= z; i++)
   ++table[array[i]]
}
END {
    for (word in table)
       print word ":" table[word]
}
