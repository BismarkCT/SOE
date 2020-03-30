#!/bin/bash
#Exemplo 2 do 02_Intro_Linux_3
for i in $(seq $#) 
do
 if [ $((i%2)) == 1 ]; then
  case $i in 
   '1')
       cal $1 $2
       ;;
   '3')
       cal $3 $4
       ;;
   '5')
       cal $5 $6
       ;;
   '7')
       cal $7 $8
       ;;
  esac    
 fi
done

