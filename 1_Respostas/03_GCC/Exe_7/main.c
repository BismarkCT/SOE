// Exemplo 7 do 03_GCC

#include <stdio.h>

int main(int argc, char**argv)
{
	printf("Argumentos :");
	int atri = argc - 1;
	for (int i = 1 ; i <= atri ; i++)
	{	
		printf(" %s",argv[i]);
	}
	printf("\n");
	return 0;
}
