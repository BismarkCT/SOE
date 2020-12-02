# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/wait.h>

int main(int argc, char**argv)
{
	int atri = argc - 1;
	for (int i = 1 ; i <= atri ; i++)
	{	
        pid_t pid_filho;
		pid_filho = fork();
		if (pid_filho == 0)
		{ 
        	char* saida[] = {argv[i], NULL};
			execvp(saida[0], saida);
			break;
    	}
		else 
		{
			wait(NULL);
			continue;
    	}
	}
	return 0;
}