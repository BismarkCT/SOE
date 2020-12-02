#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int v_global = 0; // Variavel global para este exemplo
void Incrementa_Variavel_Global(pid_t id_atual)
{
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
}

int main () {
    for (int i = 1; i <= 3; ++i) 
	{
    	pid_t pid_filho;
		pid_filho = fork();
		if (pid_filho == 0)
		{ 
        	printf("Sou Filho%d PID = %d\n", i, getpid());
            Incrementa_Variavel_Global(pid_filho);
			break;
    	}
		else 
		{
			wait(NULL);
			if (i == 3)
				printf("Sou Pai PID = %d\n", getpid());
			continue;
    	}
	}
	return 0;
}