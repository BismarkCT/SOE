#!/bin/bash
#Exemplo 3 do 02_Intro_Linux_3

for i in {0..10}
do
 date +"%d de %B de %Y, %A" -d "05/03 "+"$i"+" year ago"
done
