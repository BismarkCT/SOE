#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main () {
    for (int i = 1; i <= 3; ++i) 
	{
    	pid_t pid_filho;
		pid_t pid_pai = getpid();
		pid_filho = fork();
		if (pid_filho == 0)
		{ 
        	if(getpid() == (pid_pai + 1))
			{
				printf("Sou Filho1 PID = %d\n", getpid());
				break;
			}
			else if(getpid() == (pid_pai + 2))
			{
				printf("Sou Filho2 PID = %d\n", getpid());
				break;
			}
			else if(getpid() == (pid_pai + 3))
			{
				printf("Sou Filho3 PID = %d\n", getpid());
				break;
			}
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