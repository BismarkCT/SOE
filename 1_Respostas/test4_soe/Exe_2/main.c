#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	FILE *fp;
	char nome[15] = {""};
	char filenom[15] = {""};
	char idade[3] = {""};
	char strida[20] = {""};
	char strnom[20] = {""};
	
	printf("Digite o seu nome: ");
	// gets(nome); Para usar gets em vez do fgets e tirar o for do strncpy
	fgets(nome, 15, stdin);

	printf("Digite a sua idade: ");
	// gets(idade); Para usar gets em vez do fgets 
	fgets(idade, 3, stdin);

    for (size_t i = 0; i <= (strlen(nome) - 1); i++)
    {
        if (nome[i] == '\n')
            strncpy(filenom, nome , i);
    }

    strcpy(nome, filenom);
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
