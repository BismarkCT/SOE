# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int main()
{
	int pid;
	int fd[2];
	pipe(fd);
	pid = fork();
	if(pid == 0)
	{
		char msg_filho1[100] = "FILHO: Pai, qual é a verdadeira essência da sabedoria?";
        char msg_filho2[100] = "FILHO: Mas até uma criança de três anos sabe disso!";
        char buffer_filho[100] = {""};
		if (write(fd[1], msg_filho1, 100) < 0)
			printf("Erro na escrita do pipe\n");
        
        sleep(1);

        if(read(fd[0], buffer_filho, 100) < 0) 
			printf("Erro na leitura do pipe\n");
        else
            printf("%s\n", buffer_filho);
            
        sleep(1);

		if (write(fd[1], msg_filho2, 100) < 0)
			printf("Erro na escrita do pipe\n");

        sleep(1);

        if(read(fd[0], buffer_filho, 100) < 0) 
			printf("Erro na leitura do pipe\n");
        else
            printf("%s\n", buffer_filho);
	}

	else
	{
		char msg_pai1[100] = "PAI: Não façais nada violento, praticai somente aquilo que é justo e equilibrado.";
		char msg_pai2[100] = "PAI: Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...";
        char buffer_pai[100] = {""};

		if(read(fd[0], buffer_pai, 100) < 0) 
			printf("Erro na leitura do pipe\n");
        else
            printf("%s\n", buffer_pai);

        sleep(1);

        if (write(fd[1], msg_pai1, 100) < 0)
			printf("Erro na escrita do pipe\n");

        sleep(1);

        if(read(fd[0], buffer_pai, 100) < 0) 
			printf("Erro na leitura do pipe\n");
        else
            printf("%s\n", buffer_pai);

        sleep(1);

        if (write(fd[1], msg_pai2, 100) < 0)
			printf("Erro na escrita do pipe\n");

	}
	return 0;
}