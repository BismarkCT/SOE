#include <stdio.h>

int main(int argc, char**argv)
{
    if(argc<2) return -1;
	printf("Ola %s",argv[1]);
	printf("\n");
	return 0;
}
