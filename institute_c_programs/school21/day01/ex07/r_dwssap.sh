#!/bin/sh
cat /etc/passwd | grep -v "#" | awk -F: '{print $1}' | awk '{if (FNR%2 == 0) {print$0} }' | rev | sort -r | awk  '{ if ((FNR >= ENVIRON["FT_LINE1"]) && (FNR <= ENVIRON["FT_LINE2"])) {print$0}}' | tr "\n" "," | sed 's/,/, /g' | sed 's/, $/./g' 
