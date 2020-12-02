#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char**argv)
{
	FILE *fp;
	char nome[15] = {""};
	char filenom[15] = {""};
	char idade[3] = {""};
	char strida[20] = {""};
	char strnom[20] = {""};
	
	for(int i = 1; i <= (argc - 1); i++)
	{
		if (i == 1)
			strcpy(nome, argv[i]);
		else
			strcpy(idade, argv[i]);
	}

	strcpy(filenom, nome);
	strcat(filenom, ".txt");
	strcat(strnom, "Nome: ");
	strcat(strnom, nome);
	strcat(strida, "Idade: ");
	strcat(strida, idade);
	strcat(strida, " anos");

	fp = fopen(filenom, "w");
	
	//fputs(strnom, fp); Para usar fputs em vez do fwrite
	for(int i=0; strnom[i] != 0; i++)
	{
		fwrite(&(strnom[i]), sizeof(char), 1, fp);
	}
	putc('\n',fp);
	
	//fputs(strida, fp); Para usar fputs em vez do fwrite
	for(int i=0; strida[i] != 0; i++)
	{
		fwrite(&(strida[i]), sizeof(char), 1, fp);
	}
	fclose(fp);		
}
