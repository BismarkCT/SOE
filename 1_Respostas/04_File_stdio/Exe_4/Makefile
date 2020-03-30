Exe_6: Exe_6.o bib_arqs.o
	gcc $(CFLAGS)-o Exe_6 Exe_6.o bib_arqs.o
Exe_6.o: Exe_6.c bib_arqs.h
	gcc $(CFLAGS)-c Exe_6.c
bib_arqs.o: bib_arqs.c bib_arqs.h
	gcc $(CFLAGS)-c bib_arqs.c 
clean:
	rm -f*.o Exe_6
