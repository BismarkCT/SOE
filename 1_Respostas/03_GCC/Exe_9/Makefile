Exe_9: Exe_9.o num_caracs.o
	gcc $(CFLAGS)-o Exe_9 Exe_9.o num_caracs.o
Exe_9.o: Exe_9.c num_caracs.h
	gcc $(CFLAGS)-c Exe_9.c
num_caracs.o: num_caracs.c num_caracs.h
	gcc $(CFLAGS)-c num_caracs.c 
clean:
	rm -f*.o Exe_9
