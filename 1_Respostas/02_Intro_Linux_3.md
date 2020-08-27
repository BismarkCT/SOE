Para todas as questões, escreva os scripts e as chamadas correspondentes no terminal.

1. Crie um arquivo com nome teste1.txt, e escreva nele o texto "Número do arquivo = 1". 
Repita o procedimento para os arquivos teste2.txt, teste3.txt, ..., teste100.txt, escrevendo o texto correspondente para cada um deles ("Número do arquivo = 2", "Número do arquivo = 3", ..., "Número do arquivo = 100").

	$ echo '#!/bin/bash' > Exe_1.sh
	$ echo '#Exemplo 1 do 02_Intro_Linux_3' >> Exe_1.sh
	$ echo 'for i in {1..100}' >> Exe_1.sh 
	$ echo 'do' >> Exe_1.sh 
	$ echo ' echo Número do arquivo = $i > teste$i.txt' >> Exe_1.sh 
	$ echo 'done' >> Exe_1.sh 
	$ chmod 755 Exe_1.sh 
	$ ./Exe_1.sh 
	$ ls

Exe_1.sh      teste18.txt  teste27.txt  teste36.txt  teste45.txt  teste54.txt  teste63.txt  teste72.txt  teste81.txt  teste90.txt  teste9.txt
teste100.txt  teste19.txt  teste28.txt  teste37.txt  teste46.txt  teste55.txt  teste64.txt  teste73.txt  teste82.txt  teste91.txt
teste10.txt   teste1.txt   teste29.txt  teste38.txt  teste47.txt  teste56.txt  teste65.txt  teste74.txt  teste83.txt  teste92.txt
teste11.txt   teste20.txt  teste2.txt   teste39.txt  teste48.txt  teste57.txt  teste66.txt  teste75.txt  teste84.txt  teste93.txt
teste12.txt   teste21.txt  teste30.txt  teste3.txt   teste49.txt  teste58.txt  teste67.txt  teste76.txt  teste85.txt  teste94.txt
teste13.txt   teste22.txt  teste31.txt  teste40.txt  teste4.txt   teste59.txt  teste68.txt  teste77.txt  teste86.txt  teste95.txt
teste14.txt   teste23.txt  teste32.txt  teste41.txt  teste50.txt  teste5.txt   teste69.txt  teste78.txt  teste87.txt  teste96.txt
teste15.txt   teste24.txt  teste33.txt  teste42.txt  teste51.txt  teste60.txt  teste6.txt   teste79.txt  teste88.txt  teste97.txt
teste16.txt   teste25.txt  teste34.txt  teste43.txt  teste52.txt  teste61.txt  teste70.txt  teste7.txt   teste89.txt  teste98.txt
teste17.txt   teste26.txt  teste35.txt  teste44.txt  teste53.txt  teste62.txt  teste71.txt  teste80.txt  teste8.txt   teste99.txt


2. Faça um script chamado cals.sh que apresente o calendário de vários meses indicados pelo usuário, usando o seguinte formato:

	./cals.sh MES1 ANO1 MES2 ANO2 MES3 ANO3

Não limite o script a 3 meses. Ele deve funcionar para vários casos, como por exemplo:

	./cals.sh 1 2020
	./cals.sh 1 2019 2 2020 3 2021 1 2010

	$ echo '#!/bin/bash' > cals.sh
	$ echo '#Exemplo 2 do 02_Intro_Linux_3' >> cals.sh
	$ echo 'for i in $(seq $#)' >> cals.sh 
	$ echo 'do' >> cals.sh 
	$ echo ' if [ $((i%2)) == 1 ]; then' >> cals.sh
  	$ echo '  case $i in' >> cals.sh	 
   	$ echo '   '1')' >> cals.sh
     	$ echo '       cal $1 $2' >> cals.sh
     	$ echo '       ;;' >> cals.sh
   	$ echo '   '3')' >> cals.sh
     	$ echo '       cal $3 $4' >> cals.sh
     	$ echo '       ;;' >> cals.sh
   	$ echo '   '5')' >> cals.sh
     	$ echo '       cal $5 $6' >> cals.sh
     	$ echo '       ;;' >> cals.sh
   	$ echo '   '7')' >> cals.sh
     	$ echo '       cal $7 $8' >> cals.sh
     	$ echo '       ;;' >> cals.sh
	$ echo '  esac' >> cals.sh
	$ echo ' fi' >> cals.sh    
	$ echo 'done' >> cals.sh 
	$ chmod 755 cals.sh 
	$ ./cals.sh 1 2020

    January 2020      
Su Mo Tu We Th Fr Sa  
          1  2  3  4  
 5  6  7  8  9 10 11  
12 13 14 15 16 17 18  
19 20 21 22 23 24 25  
26 27 28 29 30 31 

	$ ./cals.sh 1 2019 2 2020 3 2021 1 2010

    January 2019      
Su Mo Tu We Th Fr Sa  
       1  2  3  4  5  
 6  7  8  9 10 11 12  
13 14 15 16 17 18 19  
20 21 22 23 24 25 26  
27 28 29 30 31        
                      
   February 2020      
Su Mo Tu We Th Fr Sa  
                   1  
 2  3  4  5  6  7  8  
 9 10 11 12 13 14 15  
16 17 18 19 20 21 22  
23 24 25 26 27 28 29  
                      
     March 2021       
Su Mo Tu We Th Fr Sa  
    1  2  3  4  5  6  
 7  8  9 10 11 12 13  
14 15 16 17 18 19 20  
21 22 23 24 25 26 27  
28 29 30 31           
                      
    January 2010      
Su Mo Tu We Th Fr Sa  
                1  2  
 3  4  5  6  7  8  9  
10 11 12 13 14 15 16  
17 18 19 20 21 22 23  
24 25 26 27 28 29 30  
31                    


3. Utilizando a lógica do script anterior, descubra em que dia da semana caiu o seu aniversário nos ultimos dez anos.

	$ echo '#!/bin/bash' > Exe_3.sh
	$ echo '#Exemplo 3 do 02_Intro_Linux_3' >> Exe_3.sh
	$ echo 'for i in {0..10}' >> Exe_3.sh 
	$ echo 'do' >> Exe_3.sh 
	$ echo ' date +"%d de %B de %Y, %A" -d "05/03 "+"$i"+" year ago"' >> Exe_3.sh
	$ echo 'done' >> Exe_3.sh
	$ chmod 755 Exe_3.sh 
	$ ./Exe_3.sh 

03 de May de 2020, Sunday
03 de May de 2019, Friday
03 de May de 2018, Thursday
03 de May de 2017, Wednesday
03 de May de 2016, Tuesday
03 de May de 2015, Sunday
03 de May de 2014, Saturday
03 de May de 2013, Friday
03 de May de 2012, Thursday
03 de May de 2011, Tuesday
03 de May de 2010, Monday

4. Crie um arquivo sites.txt com o seguinte conteúdo:

	https://github.com/DiogoCaetanoGarcia/Sistemas_Embarcados/raw/master/Aulas/01_Linux%20b%C3%A1sico.pdf
	https://github.com/DiogoCaetanoGarcia/Sistemas_Embarcados/raw/master/Aulas/01_Linux%20b%C3%A1sico_Shell_Script.pdf
	https://github.com/DiogoCaetanoGarcia/Sistemas_Embarcados/raw/master/Aulas/01_Sistemas%20Embarcados%20-%20Aula%201%20-%20Introdu%C3%A7%C3%A3o.pdf

Estes são links para slides de 3 aulas desta dsciplina, um para cada linha do arquivo sites.txt. 
Faça um script que faz o download destes slides automaticamente, a partir do arquivo sites.txt. (DICA: use o comando wget.)

	$ echo 'https://github.com/DiogoCaetanoGarcia/Sistemas_Embarcados/raw/master/Aulas/01_Linux%20b%C3%A1sico.pdf' > sites.txt
	$ echo 'https://github.com/DiogoCaetanoGarcia/Sistemas_Embarcados/raw/master/Aulas/01_Linux%20b%C3%A1sico_Shell_Script.pdf' >> sites.txt
	$ echo 'https://github.com/DiogoCaetanoGarcia/Sistemas_Embarcados/raw/master/Aulas/01_Sistemas%20Embarcados%20-%20Aula%201%20-%20Introdu%C3%A7%C3%A3o.pdf' >> sites.txt

	$ echo '#!/bin/bash' > Exe_4.sh
	$ echo '#Exemplo 4 do 02_Intro_Linux_3' >> Exe_4.sh
	$ echo 'for i in $(cat sites.txt)' >> Exe_4.sh
	$ echo 'do' >> Exe_4.sh
	$ echo ' wget  $i' >> Exe_4.sh 
	$ echo 'done' >> Exe_4.sh
	$ chmod 755 Exe_4.sh 
	$ ./Exe_4.sh
 
--2020-03-28 17:58:19--  https://github.com/DiogoCaetanoGarcia/Sistemas_Embarcados/raw/master/Aulas/01_Linux%20b%C3%A1sico.pdf
Resolving github.com (github.com)... 18.231.5.6
Connecting to github.com (github.com)|18.231.5.6|:443... connected.
HTTP request sent, awaiting response... 302 Found
Location: https://raw.githubusercontent.com/DiogoCaetanoGarcia/Sistemas_Embarcados/master/Aulas/01_Linux%20b%C3%A1sico.pdf [following]
--2020-03-28 17:58:19--  https://raw.githubusercontent.com/DiogoCaetanoGarcia/Sistemas_Embarcados/master/Aulas/01_Linux%20b%C3%A1sico.pdf
Resolving raw.githubusercontent.com (raw.githubusercontent.com)... 151.101.92.133
Connecting to raw.githubusercontent.com (raw.githubusercontent.com)|151.101.92.133|:443... connected.
HTTP request sent, awaiting response... 200 OK
Length: 229748 (224K) [application/octet-stream]
Saving to: 01_Linux basico.pdf

01_Linux basico.pdf 100%[==================>] 224.36K   357KB/s    in 0.6s    

2020-03-28 17:58:20 (357 KB/s) - 01_Linux basico.pdf saved [229748/229748]

--2020-03-28 17:58:20--  https://github.com/DiogoCaetanoGarcia/Sistemas_Embarcados/raw/master/Aulas/01_Linux%20b%C3%A1sico_Shell_Script.pdf
Resolving github.com (github.com)... 18.231.5.6
Connecting to github.com (github.com)|18.231.5.6|:443... connected.
HTTP request sent, awaiting response... 302 Found
Location: https://raw.githubusercontent.com/DiogoCaetanoGarcia/Sistemas_Embarcados/master/Aulas/01_Linux%20b%C3%A1sico_Shell_Script.pdf [following]
--2020-03-28 17:58:20--  https://raw.githubusercontent.com/DiogoCaetanoGarcia/Sistemas_Embarcados/master/Aulas/01_Linux%20b%C3%A1sico_Shell_Script.pdf
Resolving raw.githubusercontent.com (raw.githubusercontent.com)... 151.101.92.133
Connecting to raw.githubusercontent.com (raw.githubusercontent.com)|151.101.92.133|:443... connected.
HTTP request sent, awaiting response... 200 OK
Length: 258246 (252K) [application/octet-stream]
Saving to: 01_Linux basico_Shell_Script.pdf

01_Linux basico_She 100%[==================>] 252.19K   391KB/s    in 0.6s    

2020-03-28 17:58:21 (391 KB/s) - 01_Linux basico_Shell_Script.pdf saved [258246/258246]

--2020-03-28 17:58:21--  https://github.com/DiogoCaetanoGarcia/Sistemas_Embarcados/raw/master/Aulas/01_Sistemas%20Embarcados%20-%20Aula%201%20-%20Introdu%C3%A7%C3%A3o.pdf
Resolving github.com (github.com)... 18.231.5.6
Connecting to github.com (github.com)|18.231.5.6|:443... connected.
HTTP request sent, awaiting response... 302 Found
Location: https://raw.githubusercontent.com/DiogoCaetanoGarcia/Sistemas_Embarcados/master/Aulas/01_Sistemas%20Embarcados%20-%20Aula%201%20-%20Introdu%C3%A7%C3%A3o.pdf [following]
--2020-03-28 17:58:22--  https://raw.githubusercontent.com/DiogoCaetanoGarcia/Sistemas_Embarcados/master/Aulas/01_Sistemas%20Embarcados%20-%20Aula%201%20-%20Introdu%C3%A7%C3%A3o.pdf
Resolving raw.githubusercontent.com (raw.githubusercontent.com)... 151.101.92.133
Connecting to raw.githubusercontent.com (raw.githubusercontent.com)|151.101.92.133|:443... connected.
HTTP request sent, awaiting response... 200 OK
Length: 1707021 (1.6M) [application/octet-stream]
Saving to: 01_Sistemas Embarcados - Aula 1 - Introdução.pdf

01_Sistemas Embarca 100%[==================>]   1.63M  65.4KB/s    in 33s     

2020-03-28 17:58:55 (50.8 KB/s) - 01_Sistemas Embarcados - Aula 1 - Introdução.pdf saved [1707021/1707021]

5. Faça um script chamado up.sh que sobe N níveis na pasta onde você estiver, usando $1 como parâmetro de entrada. 
Por exemplo, se você estiver em /home/aluno/Documents e executar ./up.sh 2, você automaticamente vai para a pasta /home.

	$ echo '#!/bin/bash' > up.sh
	$ echo '#Exemplo 5 do 02_Intro_Linux_3' >> up.sh
	$ echo 'pwd' >> up.sh	
	$ echo 'for i in $(seq $1)' >> up.sh 
	$ echo ' do' >> up.sh 
	$ echo '  cd ..' >> up.sh
	$ echo ' done' >> up.sh
	$ echo 'pwd' >> up.sh
	$ chmod 755 up.sh 
	$ ./up.sh 2

/home/bismark/Desktop/02_Intro_Linux_3_1
/home/bismark