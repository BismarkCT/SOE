# include <stdio.h>

void main()
{
	FILE *fp;
	char conteudo[] = "Ola mundo!";
	fp = fopen("ola_mundo.txt", "wb");
	//fputs(conteudo, fp); 	Para usar a função fputs em vez do fwrite
	int i = sizeof(conteudo) - 1;
	fwrite(conteudo, sizeof(char), i, fp);
	fclose(fp);
}
