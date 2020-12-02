# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

# define TAM 50000

double v[TAM] = {0};
double x = 2.0;

void* Multiplicar_1 (void*nada)
{
    for (int i=0; i < TAM/4; i++)
    {
        v[i] = v[i] * x; 
    }
    return NULL;
}

void* Multiplicar_2 (void*nada)
{
    for (int i=TAM/4; i < TAM/2; i++)
    {
        v[i] = v[i] * x;
    }
    return NULL;
}
void* Multiplicar_3 (void*nada)
{
    for (int i=TAM/2; i < (3*TAM)/4; i++)
    {
        v[i] = v[i] * x;
    }
    return NULL;
}
void* Multiplicar_4 (void*nada)
{
    for (int i=(3*TAM)/4; i < TAM; i++)
    {
        v[i] = v[i] * x;
    }
    return NULL;
}

int main ()
{   
    for (int i=0; i<TAM; i++)
    {
        v[i] = (double)(rand()&100);
    }
    
    // Veer um valor de amostra, para validação
    printf("Valor antes : %f\n", v[1000]);

    pthread_t thread_1, thread_2, thread_3, thread_4 ;
	pthread_create (&thread_1, NULL, Multiplicar_1, NULL);
    pthread_create (&thread_2, NULL, Multiplicar_2, NULL);
    pthread_create (&thread_3, NULL, Multiplicar_3, NULL);
    pthread_create (&thread_4, NULL, Multiplicar_4, NULL);
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    pthread_join(thread_3, NULL);
    pthread_join(thread_4, NULL);

    // Veer um valor de amostra, para validação
    printf("Valor depois : %f\n", v[1000]);
    
    return 0;
}