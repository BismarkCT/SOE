# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

int count = 0;

void* leer (void *nada) 
{
    int aux = -1;
    while(count <= 10)
    {
        if (aux != count)
        {
            printf("%d\n", count);
            aux = count;
        }
        else if (aux == 10)
            pthread_exit(0);
    }
}

int main()
{
    pthread_t thread_1;
	pthread_create (&thread_1, NULL, leer, NULL);
    for (int i = 1; i <= 10; i++)
    {
        count++;
        sleep(1);
    }
    pthread_join(thread_1, NULL);
    return 0;
}