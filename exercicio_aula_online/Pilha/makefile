CC=gcc
CFLAGS=-Wall
objects = main.o PilhaDinamica.o

executa: main
	./main
	
main: PilhaDinamica.o main.c
	$(CC) -o main PilhaDinamica.o main.c
	
Pilha.o: PilhaDinamica.c PilhaDinamica.h
	$(CC) -c PilhaDinamica.c
	
clean:
	rm main $(objects)