#!/bin/bash
#Exemplo 4 do 02_Intro_Linux_3
for i in $(cat sites.txt)
do
 wget  $i  
done

