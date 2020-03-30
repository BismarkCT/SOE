Para todas as quest�es, utilize as fun��es da biblioteca stdio.h de leitura e de escrita em arquivo (fopen(), fclose(), fwrite(), fread(), dentre outras). Compile os c�digos com o gcc e execute-os via terminal.

1. Crie um c�digo em C para escrever "Ola mundo!" em um arquivo chamado 'ola_mundo.txt'.

	$ gcc Exe_1.c -o Exe_1
	$ ./Exe_1 
	$ cat ola_mundo.txt
Ola mundo!

2. Crie um c�digo em C que pergunta ao usu�rio seu nome e sua idade, e escreve este conte�do em um arquivo com o seu nome e extens�o '.txt'. Por exemplo, considerando que o c�digo criado recebeu o nome de 'ola_usuario_1':

	$ ./ola_usuario_1
	$ Digite o seu nome: Eu
	$ Digite a sua idade: 30
	$ cat Eu.txt
	$ Nome: Eu
	$ Idade: 30 anos

	$ ./Exe_2 
Digite o seu nome: Bismark
Digite a sua idade: 22
	$ cat Bismark.txt
Nome: Bismark
Idade: 22 anos

3. Crie um c�digo em C que recebe o nome do usu�rio e e sua idade como argumentos de entrada (usando as vari�veis argc e *argv[]), e escreve este conte�do em um arquivo com o seu nome e extens�o '.txt'. Por exemplo, considerando que o c�digo criado recebeu o nome de 'ola_usuario_2':
	$ ./ola_usuario_2 Eu 30
	$ cat Eu.txt
	$ Nome: Eu
	$ Idade: 30 anos

	$ ./Exe_3 Bismark 22 
	$ cat Bismark.txt
Nome: Bismark
Idade: 22 anos

4. Crie uma fun��o que retorna o tamanho de um arquivo, usando o seguinte prot�tipo: int tam_arq_texto(char *nome_arquivo); Salve esta fun��o em um arquivo separado chamado 'bib_arqs.c'. Salve o prot�tipo em um arquivo chamado 'bib_arqs.h'. Compile 'bib_arqs.c' para gerar o objeto 'bib_arqs.o'.

	$ gcc bib_arqs.c -o bib_arqs.o -nostartfiles -e tam_arq_texto

5. Crie uma fun��o que l� o conte�do de um arquivo-texto e o guarda em uma string, usando o seguinte prot�tipo: char* le_arq_texto(char *nome_arquivo); Repare que o conte�do do arquivo � armazenado em um vetor interno � fun��o, e o endere�o do vetor � retornado ao final. (Se voc� alocar este vetor dinamicamente, lembre-se de liberar a mem�ria dele quando acabar o seu uso.) Salve esta fun��o no mesmo arquivo da quest�o 4, chamado 'bib_arqs.c'. Salve o prot�tipo no arquivo 'bib_arqs.h'. Compile 'bib_arqs.c' novamente para gerar o objeto 'bib_arqs.o'.

	$ gcc bib_arqs.c -o bib_arqs.o -nostartfiles -e tam_arq_texto

6. Crie um c�digo em C que copia a funcionalidade b�sica do comando cat: escrever o conte�do de um arquivo-texto no terminal. Reaproveite as fun��es j� criadas nas quest�es anteriores. Por exemplo, considerando que o c�digo criado recebeu o nome de 'cat_falsificado':

	$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
	$ ./cat_falsificado ola.txt
	$ Ola mundo cruel! Ola universo ingrato!

	$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
	$ ./Exe_6 ola.txt
Ola mundo cruel! Ola universo ingrato! 

7. Crie um c�digo em C que conta a ocorr�ncia de uma palavra-chave em um arquivo-texto, e escreve o resultado no terminal. Reaproveite as fun��es j� criadas nas quest�es anteriores. Por exemplo, considerando que o c�digo criado recebeu o nome de 'busca_e_conta':
	$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
	$ ./busca_e_conta Ola ola.txt
	$ 'Ola' ocorre 2 vezes no arquivo 'ola.txt'.

	$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
	$ ./Exe_7 Ola ola.txt
'Ola' ocorre 2 vezes no arquivo 'ola.txt'.