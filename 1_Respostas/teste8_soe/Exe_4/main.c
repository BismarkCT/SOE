# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

long int v[50000] = {0};
long int med_total, med_parcial, med[4] = {0};

void Med_Total ()
{
    for (int i=0; i < 50000; i++)
    {
        med_total=med_total+v[i];
        if (i == 49999)
            med_total= med_total/(50000);
    }
}

void Med_Par ()
{
    for (int i=0; i < 4; i++)
    {
        med_parcial=med_parcial+med[i];
        if (i == 3)
            med_parcial= med_parcial/(i+1);
    }
}

void* Med_Par1 (void*nada)
{
    for (int i=0; i < 12500; i++)
    {
        med[0]=med[0]+v[i];
        if (i == 12499)
            med[0]= med[0]/(12500);
    }
    return NULL;
}

void* Med_Par2 (void*nada)
{
    for (int i=12500; i < 25000; i++)
    {
        med[1]=med[1]+v[i];
        if (i == 24999)
            med[1]= med[1]/(12500);
    }
    return NULL;
}
void* Med_Par3 (void*nada)
{
    for (int i=25000; i < 37500; i++)
    {
        med[2]=med[2]+v[i];
        if (i == 37499)
            med[2]= med[2]/(12500);
    }
    return NULL;
}
void* Med_Par4 (void*nada)
{
    for (int i=37500; i < 50000; i++)
    {
        med[3]= med[3]+v[i];
        if (i == 49999)
            med[3]= med[3]/(12500);
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
	pthread_create (&thread_1, NULL, Med_Par1, NULL);
    pthread_create (&thread_2, NULL, Med_Par2, NULL);
    pthread_create (&thread_3, NULL, Med_Par3, NULL);
    pthread_create (&thread_4, NULL, Med_Par4, NULL);
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    pthread_join(thread_3, NULL);
    pthread_join(thread_4, NULL);

    Med_Total();
    Med_Par();

    printf("%ld\n", med_total);
    printf("%ld\n", med_parcial);
    return 0;
}