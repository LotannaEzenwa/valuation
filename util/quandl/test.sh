#!/bin/bash


DATE=$(date +"%a_%b_%d_%T_%Y")
TIKR=GOOG
OUTPUT=../logs/stocktest.$DATE

echo $OUTPUT > $OUTPUT
echo "Hostname:" `echo $HOSTNAME` >> $OUTPUT
echo "Operating System: OSX 10.11 El Capitan" >> $OUTPUT 
echo "" >> $OUTPUT
echo "Author: Lotanna Ezenwa" >> $OUTPUT
echo "Date written: 01/20/16" >> $OUTPUT

echo 'make clean: ' `make clean` | cat >> $OUTPUT 
make >> $OUTPUT

./stock $TIKR >> $OUTPUT


