// Exemplo 1 do 04_File_stdio

# include <stdio.h>

void main()
{
	FILE *fp;
	char conteudo[] = "Ola mundo!";
	fp = fopen("ola_mundo.txt", "wb");
	fputs(conteudo, fp);
	fclose(fp);
}
