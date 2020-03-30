// Exemplo 2 do 04_File_stdio

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	FILE *fp;
	char nome[100] = {""};
	char filenom[100] = {""};
	char idade[100] = {""};
	char strida[100] = {""};
	char strnom[100] = {""};
	
	printf("Digite o seu nome: ");
	gets(nome);

	printf("Digite a sua idade: ");
	gets(idade);

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
