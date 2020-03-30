// Exemplo 11 do 03_GCC

#include <stdio.h>
#include <stdlib.h>
#include "num_caracs.h"

int saida = 0;

int main(int argc,char **argv)
{
	for (int j = 0 ; j <= (argc-1) ; j++)
	{
		int i;
		i = Num_Caracs(argv[j]);
		saida += i;
	}
	printf("Total de caracteres de entrada : %d", saida);
	printf("\n");
	return 0;
}

