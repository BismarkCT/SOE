// Exemplo 7 do 04_File_stdio

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib_arqs.h"

void main(int argc, char**argv)
{	
	char* palavra = argv[1];
	int count = 0;

	char* saida = le_arq_texto(argv[2]);

	char* token;
	token = strtok(saida, " ");
	
	while(token != NULL)
	{
		if(strcmp(token, palavra) == 0)
			count++;
		
		token = strtok(NULL, " ");

	}

	printf("'%s' ocorre %d vezes no arquivo '%s'.\n", palavra, count, argv[2]);
	free(saida);	
}

