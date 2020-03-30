Para todas as questões, compile-as com o gcc e execute-as via terminal.

1.Crie um "Olá mundo!" em C.

	$ gcc main.c -o Exe_1
	$ ls
Exe_1  main.c

	$ ./Exe_1 
Olá mundo!

2.Crie um código em C que pergunta ao usuário o seu nome, e imprime no terminal "Ola " e o nome do usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_1':

	$ ./ola_usuario_1
	$ Digite o seu nome: Eu
	$ Ola Eu

	$ gcc main.c -o Exe_2
	$ ./Exe_2 
Digite o seu nome: Eu    
Ola Eu

3.Apresente os comportamentos do código anterior nos seguintes casos:
	(a) Se o usuário insere mais de um nome.

		$./ola_usuario_1
		$ Digite o seu nome: Eu Mesmo

		$ ./Exe_2 
	Digite o seu nome: Eu Mesmo
	Ola Eu

	(b) Se o usuário insere mais de um nome entre aspas duplas. Por exemplo:

		$ ./ola_usuario_1
		$ Digite o seu nome: "Eu Mesmo"
		
		$ ./Exe_2 
	Digite o seu nome: "Eu Mesmo"
	Ola "Eu		

	(c) Se é usado um pipe. Por exemplo:

		$ echo Eu | ./ola_usuario_1

		$ echo Eu | ./Exe_2 
	Digite o seu nome: 
	Ola Eu
	
	(d) Se é usado um pipe com mais de um nome. Por exemplo:

		$ echo Eu Mesmo | ./ola_usuario_1

		$ echo Eu Mesmo | ./Exe_2 
	Digite o seu nome: 
	Ola Eu
	
	(e) Se é usado um pipe com mais de um nome entre aspas duplas. Por exemplo:

		$ echo "Eu Mesmo" | ./ola_usuario_1

		$ echo "Eu Mesmo" | ./Exe_2 
	Digite o seu nome: 
	Ola Eu
	
	(f) Se é usado o redirecionamento de arquivo. Por exemplo:

		$ echo Ola mundo cruel! > ola.txt
		$ ./ola_usuario_1 < ola.txt

		$ echo Ola mundo cruel! > ola.txt
		$ ./Exe_2 < ola.txt
	Digite o seu nome: 
	Ola Ola
	
4.Crie um código em C que recebe o nome do usuário como um argumento de entrada (usando as variáveis argc e *argv[]), e imprime no terminal "Ola " e o nome do usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':
	$ ./ola_usuario_2 Eu
	$ Ola Eu

	$ gcc main.c -o Exe_4
	$ ./Exe_4 Eu
Ola Eu
	
5.Apresente os comportamentos do código anterior nos seguintes casos:
	(a) Se o usuário insere mais de um nome.

		$ ./ola_usuario_2 Eu Mesmo
		
		$ ./Exe_4 Eu Mesmo
	Ola Eu
	
	(b) Se o usuário insere mais de um nome entre aspas duplas. Por exemplo:

		$ ./ola_usuario_2 "Eu Mesmo"

		$ ./Exe_4 "Eu Mesmo"
	Ola Eu Mesmo

	(c) Se é usado um pipe. Por exemplo:

		$ echo Eu | ./ola_usuario_2

		$ echo Eu | ./Exe_4 
	Ola (null)

	(d) Se é usado um pipe com mais de um nome. Por exemplo:

		$ echo Eu Mesmo | ./ola_usuario_2

		$ echo Eu Mesmo | ./Exe_4 
	Ola (null)

	(e) Se é usado um pipe com mais de um nome entre aspas duplas. Por exemplo:

		$ echo "Eu Mesmo" | ./ola_usuario_2

		$ echo "Eu Mesmo" | ./Exe_4 
	Ola (null)

	(f) Se é usado o redirecionamento de arquivo. Por exemplo:

		$ echo Ola mundo cruel! > ola.txt
		$ ./ola_usuario_2 < ola.txt

		$ echo Ola mundo cruel! > ola.txt
		$ ./Exe_4 < ola.txt 
	Ola (null)

6.Crie um código em C que faz o mesmo que o código da questão 4, e em seguida imprime no terminal quantos valores de entrada foram fornecidos pelo usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_3':

	$ ./ola_usuario_3 Eu
	$ Ola Eu
	$ Numero de entradas = 2

	$ gcc main.c -o Exe_6
	$ ./Exe_6 Eu
Ola Eu
Numero de entradas = 2

7.Crie um código em C que imprime todos os argumentos de entrada fornecidos pelo usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_argumentos':

	$ ./ola_argumentos Eu Mesmo e Minha Pessoa
	$ Argumentos: Eu Mesmo e Minha Pessoa

	$ ./Exgcc main.c -o Exe_7
	$ ./Exe_7 Eu Mesmo e Minha Pessoa
Argumentos : Eu Mesmo e Minha Pessoa

8.Crie uma função que retorna a quantidade de caracteres em uma string, usando o seguinte protótipo: int Num_Caracs(char *string); Salve-a em um arquivo separado chamado 'num_caracs.c'. Salve o protótipo em um arquivo chamado 'num_caracs.h'. Compile 'num_caracs.c' para gerar o objeto 'num_caracs.o'.

	$ gcc num_caracs.c -o num_caracs.o -nostartfiles -e Num_Caracs

9.Re-utilize o objeto criado na questão 8 para criar um código que imprime cada argumento de entrada e a quantidade de caracteres de cada um desses argumentos. Por exemplo, considerando que o código criado recebeu o nome de 'ola_num_caracs_1':

	$ ./ola_num_caracs_1 Eu Mesmo
	$ Argumento: ./ola_num_caracs_1 / Numero de caracteres: 18
	$ Argumento: Eu / Numero de caracteres: 2
	$ Argumento: Mesmo / Numero de caracteres: 5

	$ make
gcc -c Exe_9.c
gcc -c num_caracs.c 
gcc -o Exe_9 Exe_9.o num_caracs.o
	$ ./Exe_9 Eu Mesmo
Argumento : ./Exe_9 / Numero de caracteres : 7
Argumento : Eu / Numero de caracteres : 2
Argumento : Mesmo / Numero de caracteres : 5


10.Crie um Makefile para a questão anterior.

Exe_9: Exe_9.o num_caracs.o
	gcc $(CFLAGS)-o Exe_9 Exe_9.o num_caracs.o
Exe_9.o: Exe_9.c num_caracs.h
	gcc $(CFLAGS)-c Exe_9.c
num_caracs.o: num_caracs.c num_caracs.h
	gcc $(CFLAGS)-c num_caracs.c 
clean:
	rm -f*.o Exe_9

11.Re-utilize o objeto criado na questão 8 para criar um código que imprime o total de caracteres nos argumentos de entrada. Por exemplo, considerando que o código criado recebeu o nome de 'ola_num_caracs_2':

	$ ./ola_num_caracs_2 Eu Mesmo
	$ Total de caracteres de entrada: 25

	$ make
gcc -c Exe_11.c
gcc -c num_caracs.c 
gcc -o Exe_11 Exe_11.o num_caracs.o
	$ ./Exe_11 Eu Mesmo
Total de caracteres de entrada : 15

12.Crie um Makefile para a questão anterior.

Exe_11: Exe_11.o num_caracs.o
	gcc $(CFLAGS)-o Exe_11 Exe_11.o num_caracs.o
Exe_11.o: Exe_11.c num_caracs.h
	gcc $(CFLAGS)-c Exe_11.c
num_caracs.o: num_caracs.c num_caracs.h
	gcc $(CFLAGS)-c num_caracs.c 
clean:
	rm -f*.o Exe_11