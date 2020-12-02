# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int main()
{
    int fd[2];
	pipe(fd);
    int i;
    pid_t pid_filho;
    pid_filho = fork();
    if(pid_filho == 0)
    {
        int buffer_filho;
        while (buffer_filho != 10)
        {
            if(read(fd[0], &buffer_filho, sizeof(int)) < 0) 
			    printf("Erro na leitura do pipe\n");
            printf("%d\n", buffer_filho);
        }
        exit(1);
    }

    else
    {   
        for ( i=1; i<=10; i++ )
        {
            if (write(fd[1], &i, sizeof(int)) < 0)
			    printf("Erro na escrita do pipe\n");
            sleep(1);
        }
    }

    return 0;
}