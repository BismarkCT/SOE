#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int aux = 1;

void sair (void)
{
    aux = 0;
}

int main (int argc, char**argv)
{
    printf("Coloque o pino desejado e a frequência :");
    if (argc >= 3)
    {
        printf("Foi adicionado mais variáveis\n");
        return -1;
    }
    
    signal(SIGINT, sair);

    int freq = ((int)argv[2])/2;

    char comando[1000];
    sprintf(comando, "sudo echo %s > /sys/class/gpio/export", argv[1]);
    system(comando);
    sprintf(comando, "sudo echo out > /sys/class/gpio%s/direction", argv[1]);
    system(comando);

    printf("Para sair do loop basta apertar Ctrl + C\n");

    while(aux)
    {
        sprintf(comando, "sudo echo 1 > /sys/class/gpio%s/value", argv[1]);
        system(comando);
        sleep(freq);
        sprintf(comando, "sudo echo 0 > /sys/class/gpio%s/value", argv[1]);
        system(comando);
        sleep(freq);
        
    }
    sprintf(comando, "sudo echo 0 > /sys/class/gpio%s/value", argv[1]);
    system(comando);
    sprintf(comando, "sudo echo %s > /sys/class/gpio/unexport", argv[1]);
    system(comando);
    return 0;
}