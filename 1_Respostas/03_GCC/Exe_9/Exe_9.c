// Exemplo 9 do 03_GCC

#include <stdio.h>
#include <stdlib.h>
#include "num_caracs.h"

int saida;

int main(int argc,char **argv)
{
	for (int j = 0 ; j <= (argc-1) ; j++)
	{
		saida = Num_Caracs(argv[j]);
		printf("Argumento : %s", argv[j]);
		printf(" / Numero de caracteres : %d", saida);
		printf("\n");
	}
	return 0;
}


