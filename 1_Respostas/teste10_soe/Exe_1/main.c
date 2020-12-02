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
    printf("Coloque o pino desejado :");
    if (argc >= 2)
    {
        printf("Foi adicionado mais de uma variável\n");
        return -1;
    }
    
    signal(SIGINT, sair);

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
        sleep(0.5);
        sprintf(comando, "sudo echo 0 > /sys/class/gpio%s/value", argv[1]);
        system(comando);
        sleep(0.5);
        
    }
    sprintf(comando, "sudo echo 0 > /sys/class/gpio%s/value", argv[1]);
    system(comando);
    sprintf(comando, "sudo echo %s > /sys/class/gpio/unexport", argv[1]);
    system(comando);
    return 0;
}