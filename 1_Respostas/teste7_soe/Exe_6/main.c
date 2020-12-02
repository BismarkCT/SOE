# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>

int main () {
    int fd[2];
	pipe(fd);
    for (int i = 1; i <= 2; ++i) 
	{
    	pid_t pid_filho;
		pid_filho = fork();
		if (pid_filho == 0)
		{ 
        	if (i == 1)
            {
                char msg_filho1[100] = "FILHO1: Quando o vento passa, é a bandeira que se move.";
                if (write(fd[1], msg_filho1, 100) < 0)
			        printf("Erro na escrita do pipe\n");
            }

            else
            {
                char msg_filho2[100] = "FILHO2: Não, é o vento que se move.";
                char buffer_filho2[100] = {""};
                
                sleep(1);

                if (write(fd[1], msg_filho2, 100) < 0)
                    printf("Erro na escrita do pipe\n");

                sleep(1);

                if(read(fd[0], buffer_filho2, 100) < 0) 
                    printf("Erro na leitura do pipe\n");
                else
                    printf("%s\n", buffer_filho2);
            }
			break;
    	}

		else 
		{
            char msg_pai[100] = "PAI: Os dois se enganam. É a mente dos senhores que se move.";
            char buffer_pai[100] = {""};
            
            if(i == 1)
            {
                if(read(fd[0], buffer_pai, 100) < 0) 
                    printf("Erro na leitura do pipe\n");
                else
                    printf("%s\n", buffer_pai);
            }
            else
            {
                sleep(1);

                if(read(fd[0], buffer_pai, 100) < 0) 
                    printf("Erro na leitura do pipe\n");
                else
                    printf("%s\n", buffer_pai);

                sleep(1);

                if (write(fd[1], msg_pai, 100) < 0)
                    printf("Erro na escrita do pipe\n");
            }
            wait(NULL);
    	}
	}
	return 0;
}