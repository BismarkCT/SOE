// Exemplo 6 do 03_GCC

#include <stdio.h>

int main(int argc, char**argv)
{
	printf("Ola %s",argv[1]);
	printf("\n");
	printf("Numero de entradas = %d",argc);
	printf("\n");
	return 0;
}
