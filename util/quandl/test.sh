#!/bin/bash


DATE=$(date +"%a_%b_%d_%T_%Y")
TIKR=GOOG
FN=stocktest.$DATE
OUTPUT=../logs/$FN


echo 'make clean: ' `make clean` | cat >> $OUTPUT 
echo $FN > $OUTPUT
echo "Hostname:" `echo $HOSTNAME` >> $OUTPUT
echo "Operating System: OSX 10.11 El Capitan" >> $OUTPUT 
echo "" >> $OUTPUT
echo "Author: Lotanna Ezenwa" >> $OUTPUT
echo "Date written: 01/20/16" >> $OUTPUT

make >> $OUTPUT

./stock $TIKR >> $OUTPUT


