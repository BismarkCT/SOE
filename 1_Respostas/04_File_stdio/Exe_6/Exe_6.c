// Exemplo 6 do 04_File_stdio

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib_arqs.h"

void main(int argc, char**argv)
{	
	char* saida = le_arq_texto(argv[1]); 
	printf("%s \n", saida);
	free(saida);	
}

