# include <stdio.h>
# include <stdlib.h>

int main(int argc, char**argv)
{
	int atri = argc - 1;
	for (int i = 1 ; i <= atri ; i++)
	{	
		system(argv[i]);
	}
	return 0;
}