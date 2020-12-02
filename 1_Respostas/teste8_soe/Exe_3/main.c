# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

long int v[50000] = {0};
long int max_total, max_parcial, max[4] = {0};

void Max_Total ()
{
    for (int i=0; i < 50000; i++)
    {
        if (v[i] > max_total)
            max_total=v[i];
    }
}

void Max_Par ()
{
    for (int i=0; i < 4; i++)
    {
        if (max[i] > max_parcial)
            max_parcial=max[i];
    }
}

void* Max_Par1 (void*nada)
{
    for (int i=0; i < 12500; i++)
    {
        if (v[i] > max[0])
            max[0]=v[i];
    }
    return NULL;
}

void* Max_Par2 (void*nada)
{
    for (int i=12500; i < 25000; i++)
    {
        if (v[i] > max[1])
            max[1]=v[i];
    }
    return NULL;
}
void* Max_Par3 (void*nada)
{
    for (int i=25000; i < 37500; i++)
    {
        if (v[i] > max[2])
            max[2]=v[i];
    }
    return NULL;
}
void* Max_Par4 (void*nada)
{
    for (int i=37500; i < 50000; i++)
    {
        if (v[i] > max[3])
            max[3]=v[i];
    }
    return NULL;
}

int main ()
{   
    for (int i=0; i < 50000; i++)
    {
        v[i] = random();
    }
    pthread_t thread_1, thread_2, thread_3, thread_4 ;
	pthread_create (&thread_1, NULL, Max_Par1, NULL);
    pthread_create (&thread_2, NULL, Max_Par2, NULL);
    pthread_create (&thread_3, NULL, Max_Par3, NULL);
    pthread_create (&thread_4, NULL, Max_Par4, NULL);
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    pthread_join(thread_3, NULL);
    pthread_join(thread_4, NULL);

    Max_Total();
    Max_Par();
    
    printf("%ld\n", max_total);
    printf("%ld\n", max_parcial);
    return 0;
}