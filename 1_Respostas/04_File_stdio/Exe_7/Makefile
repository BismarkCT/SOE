Exe_7: Exe_7.o bib_arqs.o
	gcc $(CFLAGS)-o Exe_7 Exe_7.o bib_arqs.o
Exe_7.o: Exe_7.c bib_arqs.h
	gcc $(CFLAGS)-c Exe_7.c
bib_arqs.o: bib_arqs.c bib_arqs.h
	gcc $(CFLAGS)-c bib_arqs.c 
clean:
	rm -f*.o Exe_7
