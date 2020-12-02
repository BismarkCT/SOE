# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

void main(int argc, char**argv)
{
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

	int fd = open(filenom, O_RDWR | O_CREAT, S_IRWXU);

    if(fd == -1)
    {
        printf("Erro na abertura do arquivo.\n");
        exit(-1);
    }
 
	for(int i=0; strnom[i] != 0; i++)
	{
		write(fd, &(strnom[i]), 1);
	}
		
	write(fd, "\n", 1);
	
	for(int i=0; strida[i] != 0; i++)
	{
		write(fd, &(strida[i]), 1);
	}
	close(fd);	
}
