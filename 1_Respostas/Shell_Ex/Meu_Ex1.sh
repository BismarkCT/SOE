#!/bin/bash
echo O nome desse script é $0
echo $# argumentos passados pelo usuário
if [ $# -ge 1 ] ; then
  echo 'Os parâmetros de entrada foram:'
  echo $@
  echo 'Em particular...'
  for i in $*; do 
    echo  "Arg = $i"
  done

else 
  echo Não tem nenhum argumento
fi
