#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tam_arq_texto(char*nome_arquivo)
{
	FILE *fp;
	fp = fopen(nome_arquivo, "r");
	fseek(fp, 0, SEEK_END);
	int t = ftell(fp);
	fclose(fp);
	return t;
}

char*le_arq_texto(char*nome_arquivo)
{
	char* lido;  
	int t = tam_arq_texto(nome_arquivo);
	lido = malloc(t * sizeof(char));
	FILE *fp;
	fp = fopen(nome_arquivo, "r");
	fgets(lido, t, fp);

	fclose(fp);
	return lido;
}

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

