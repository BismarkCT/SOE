#include <stdio.h>
#include <stdlib.h>

int main (int argc, char**argv)
{
    printf("Coloque o pino desejado para piscar e o pino para o botão :");
    if (argc >= 3)
    {
        printf("Foi adicionado mais variáveis\n");
        return -1;
    }

    char comando[1000];
    sprintf(comando, "sudo echo %s > /sys/class/gpio/export", argv[1]);
    system(comando);
    sprintf(comando, "sudo echo out > /sys/class/gpio%s/direction", argv[1]);
    system(comando);
    sprintf(comando, "sudo echo %s > /sys/class/gpio/export", argv[2]);
    system(comando);
    sprintf(comando, "sudo echo in > /sys/class/gpio%s/direction", argv[2]);
    system(comando);
    
    printf("Para sair do loop basta \n");

    int freq = 1;
    int time = freq/2;

    int fd[2];
	pipe(fd);
    int i;
    pid_t pid_filho;
    pid_filho = fork();
    if(pid_filho == 0)
    {
        
        if(read(fd[0], &freq, sizeof(int)) < 0)
            printf("Erro na leitura do pipe\n");
        
        while(freq > 0)
        {
            sprintf(comando, "sudo echo 1 > /sys/class/gpio%s/value", argv[1]);
            system(comando);
            sleep(time);
            sprintf(comando, "sudo echo 0 > /sys/class/gpio%s/value", argv[1]);
            system(comando);
            sleep(time); 
        }
    }

    else
    {
        char valor_char = "";
        int valor_int = 0;
        int valor_freq = 1;
        sprintf(comando, "/sys/class/gpio%s/value", argv[2]);
        
        while(1)
        {
            FILE* fp = fopen(comando, "r");
            if(fp==NULL)
                return -1;
            
            int i = fread(valor_char, 1, sizeof(char), fp);
            valor_int = (int)valor_char;
            fclose(fp);
            if(i<1)
                return -2;
            if (valor_int == 1)
            {
                if (valor_freq == 64)
                {
                    valor_freq = 1;
                }
                else
                {
                    valor_freq = valor_freq*2;    
                }
                
                if(write(fd[1], &valor_int, sizeof(int)) < 0)
                    printf("Erro na escrita do pipe\n");
            }
        }   
    }

    sprintf(comando, "sudo echo 0 > /sys/class/gpio%s/value", argv[1]);
    system(comando);
    sprintf(comando, "sudo echo %s > /sys/class/gpio/unexport", argv[1]);
    system(comando);
    sprintf(comando, "sudo echo 0 > /sys/class/gpio%s/value", argv[2]);
    system(comando);
    sprintf(comando, "sudo echo %s > /sys/class/gpio/unexport", argv[2]);
    system(comando);
    
    return 0;
}