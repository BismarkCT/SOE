# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

void main()
{
	char conteudo[] = "Ola mundo!";
	int fd = open("ola_mundo.txt", O_RDWR | O_CREAT, S_IRWXU);

	if(fd == -1)
    {
        printf("Erro na abertura do arquivo.\n");
        exit(-1);
    }
	int i = sizeof(conteudo) - 1;
	write(fd, conteudo, i);
	close(fd);
}
