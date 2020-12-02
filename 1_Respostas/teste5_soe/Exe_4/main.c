# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

int tam_arq_texto(char*nome_arquivo)
{
	int fd = open(nome_arquivo, O_RDWR );
    if(fd == -1)
    {
        printf("Erro na abertura do arquivo.\n");
        exit(-1);
    }
	int t = lseek(fd, 0, SEEK_END);
	close(fd);
	return t;
}

char*le_arq_texto(char*nome_arquivo)
{
	char* lido;  
	int t = tam_arq_texto(nome_arquivo);
	lido = malloc(t * sizeof(char));
	int fd = open(nome_arquivo, O_RDWR);
	if(fd == -1)
    {
        printf("Erro na abertura do arquivo.\n");
        exit(-1);
    }
    read(fd, lido, t);
	close(fd);
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

