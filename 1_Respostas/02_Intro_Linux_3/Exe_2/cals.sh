#!/bin/bash
#Exemplo 2 do 02_Intro_Linux_3
a=1
for i in $@
do
if [ $a == 1 ]; then
    b=$i
    a=0
else
    c=$i
    a=1
    cal $b $c 
fi
done