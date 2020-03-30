1. Escreva o texto "Ola mundo cruel!" em um arquivo denominado "Ola_mundo.txt". Apresente o conteúdo deste arquivo no terminal.

	$ echo "Ola mundo cruel!" > Ola_mundo.txt; cat Ola_mundo.txt
Ola mundo cruel!	

2. Apresente o nome de todos os arquivos e pastas na pasta 'root'.

	$ cd /
	$ ls
bin    etc             lib         mnt   run   swapfile  var
boot   home            lib64       opt   sbin  sys       vmlinuz
cdrom  initrd.img      lost+found  proc  snap  tmp       vmlinuz.old
dev    initrd.img.old  media       root  srv   usr

3. Apresente o tipo de todos os arquivos e pastas na pasta 'root'.

	$ cd /
	$ ls -l
total 970072
drwxr-xr-x   2 root root      4096 Mar 24 12:15 bin
drwxr-xr-x   3 root root      4096 Mar 24 12:17 boot
drwxrwxr-x   2 root root      4096 Sep 15  2019 cdrom
drwxr-xr-x  18 root root      4320 Mar 29 10:48 dev
drwxr-xr-x 124 root root     12288 Mar 28 20:07 etc
drwxr-xr-x   3 root root      4096 Sep 15  2019 home
lrwxrwxrwx   1 root root        32 Mar 24 12:17 initrd.img -> boot/initrd.img-5.0.0-29-generic
lrwxrwxrwx   1 root root        33 Sep 15  2019 initrd.img.old -> boot/initrd.img-4.18.0-15-generic
drwxr-xr-x  21 root root      4096 Sep 15  2019 lib
drwxr-xr-x   2 root root      4096 Feb  9  2019 lib64
drwx------   2 root root     16384 Sep 15  2019 lost+found
drwxr-xr-x   4 root root      4096 Sep 19  2019 media
drwxr-xr-x   2 root root      4096 Feb  9  2019 mnt
drwxr-xr-x   2 root root      4096 Sep 15  2019 opt
dr-xr-xr-x 319 root root         0 Mar 29 10:47 proc
drwx------   4 root root      4096 Mar 24 18:24 root
drwxr-xr-x  28 root root       820 Mar 29 20:11 run
drwxr-xr-x   2 root root     12288 Mar 24 12:12 sbin
drwxr-xr-x  12 root root      4096 Sep 15  2019 snap
drwxr-xr-x   2 root root      4096 Feb  9  2019 srv
-rw-------   1 root root 993244160 Sep 15  2019 swapfile
dr-xr-xr-x  13 root root         0 Mar 29 20:12 sys
drwxrwxrwt  16 root root      4096 Mar 29 19:55 tmp
drwxr-xr-x  10 root root      4096 Feb  9  2019 usr
drwxr-xr-x  14 root root      4096 Feb  9  2019 var
lrwxrwxrwx   1 root root        29 Mar 24 12:17 vmlinuz -> boot/vmlinuz-5.0.0-29-generic
lrwxrwxrwx   1 root root        30 Mar 24 12:17 vmlinuz.old -> boot/vmlinuz-4.18.0-15-generic

4. Apresente somente as pastas dentro da pasta 'root'.

	$ cd /
	$ ls -d */
bin/    dev/   lib/         media/  proc/  sbin/  sys/  var/
boot/   etc/   lib64/       mnt/    root/  snap/  tmp/
cdrom/  home/  lost+found/  opt/    run/   srv/   usr/

5. Descubra em que dia da semana caiu o seu aniversário nos últimos dez anos.

	$ date +"%d de %B de %Y, %A" -d "05/03 10 years ago";date 	+"%d de %B de %Y, %A" -d "05/03 9 years ago";date +"%d de %B 	de %Y, %A" -d "05/03 8 years ago";date +"%d de %B de %Y, %	A" -d "05/03 7 years ago";date +"%d de %B de %Y, %A" -d 	"05/03 6 years ago";date +"%d de %B de %Y, %A" -d "05/03 5 	years ago";date +"%d de %B de %Y, %A" -d "05/03 4 years 	ago";date +"%d de %B de %Y, %A" -d "05/03 3 years ago";date 	+"%d de %B de %Y, %A" -d "05/03 2 years ago";date +"%d de %B 	de %Y, %A" -d "05/03 last-year";date +"%d de %B de %Y, %A" -	d "05/03 this year"

	03 de May de 2010, Monday
	03 de May de 2011, Tuesday
	03 de May de 2012, Thursday
	03 de May de 2013, Friday
	03 de May de 2014, Saturday
	03 de May de 2015, Sunday
	03 de May de 2016, Tuesday
	03 de May de 2017, Wednesday
	03 de May de 2018, Thursday
	03 de May de 2019, Friday
	03 de May de 2020, Sunday

6. Para as questões a seguir, use a pasta no endereço https://github.com/DiogoCaetanoGarcia/Sistemas_Embarcados/raw/master/Questoes/02_Intro_Linux_arqs.zip

7. Liste somente os arquivos com extensão .txt.

$ ls *.txt
arquivo.txt   cal_1996.txt  cal_2003.txt  cal_2010.txt  cal_2017.txt
cal_1990.txt  cal_1997.txt  cal_2004.txt  cal_2011.txt  cal_2018.txt
cal_1991.txt  cal_1998.txt  cal_2005.txt  cal_2012.txt  cal_2019.txt
cal_1992.txt  cal_1999.txt  cal_2006.txt  cal_2013.txt  cal_2020.txt
cal_1993.txt  cal_2000.txt  cal_2007.txt  cal_2014.txt  cal.txt
cal_1994.txt  cal_2001.txt  cal_2008.txt  cal_2015.txt  cal_types.txt
cal_1995.txt  cal_2002.txt  cal_2009.txt  cal_2016.txt

8. Liste somente os arquivos com extensão .png.

$ ls *.png
BusinessTux.png               linux.png
linux1.png                    Tux-in-a-suit.png
linux2.png                    tux-linux-professional_0-100520358-orig.png
linux3.png                    TUX.png
linux_inside.png              xanderrun-tux-construction-8454.png
linux-penguin-icon-39742.png

9. Liste somente os arquivos com extensão .jpg.

$ ls *.jpg
d36f1a2be6a927ac3e2e1e4eacdedded.jpg  oRva1OGD.jpg
oRva1OGD_400x400.jpg                  zz39112bb5.jpg

10. Liste somente os arquivos com extensão .gif.

	$ ls *.gif
	1086970.gif

11. Liste somente os arquivos que contenham o nome 'cal'.

$ ls *cal*
cal_1990.txt  cal_1997.txt  cal_2004.txt  cal_2011.txt  cal_2018.txt
cal_1991.txt  cal_1998.txt  cal_2005.txt  cal_2012.txt  cal_2019.txt
cal_1992.txt  cal_1999.txt  cal_2006.txt  cal_2013.txt  cal_2020.txt
cal_1993.txt  cal_2000.txt  cal_2007.txt  cal_2014.txt  cal.txt
cal_1994.txt  cal_2001.txt  cal_2008.txt  cal_2015.txt  cal_types.txt
cal_1995.txt  cal_2002.txt  cal_2009.txt  cal_2016.txt
cal_1996.txt  cal_2003.txt  cal_2010.txt  cal_2017.txt

12. Liste somente os arquivos que contenham o nome 'tux'.

	$ ls *tux*
	tux-linux-professional_0-100520358-orig.png
	xanderrun-tux-construction-8454.png

13. Liste somente os arquivos que comecem com o nome 'tux'.
	$ ls tux*
tux-linux-professional_0-100520358-orig.png