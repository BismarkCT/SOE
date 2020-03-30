// Exercicio 3 do 04_File_stdio

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char**argv)
{
	FILE *fp;
	char nome[100] = {""};
	char filenom[100] = {""};
	char idade[100] = {""};
	char strida[100] = {""};
	char strnom[100] = {""};
	
	for(int i = 1; i <= (argc -1) ; i++)
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
	fputs(strnom, fp);
	putc('\n',fp);
	fputs(strida, fp);
	fclose(fp);
		
}
