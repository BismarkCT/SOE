hello: ola.o main.o
	gcc $(CFLAGS)-o hello ola.o main.o
ola.o: ola.c ola.h
	gcc $(CFLAGS)-c ola.c
main.o: main.c 
	gcc $(CFLAGS)-c main.c 
clean:
	rm -f *.o Exe_1