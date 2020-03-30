Exe_11: Exe_11.o num_caracs.o
	gcc $(CFLAGS)-o Exe_11 Exe_11.o num_caracs.o
Exe_11.o: Exe_11.c num_caracs.h
	gcc $(CFLAGS)-c Exe_11.c
num_caracs.o: num_caracs.c num_caracs.h
	gcc $(CFLAGS)-c num_caracs.c 
clean:
	rm -f*.o Exe_11
