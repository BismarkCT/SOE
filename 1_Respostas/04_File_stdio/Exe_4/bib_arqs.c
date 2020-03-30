// Exemplo 4 do 04_File_stdio

#include "bib_arqs.h"

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
	while (fgets(lido, t, fp)!= NULL)

	fclose(fp);
	return lido;
}
