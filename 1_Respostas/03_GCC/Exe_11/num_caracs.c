// Exemplo 8 do 03_GCC

#include "num_caracs.h"

int Num_Caracs(char *string)
{	
	int i = 0;
	while(string[i] != '\0')
	{
		i++;
	}
	return (i);
}

