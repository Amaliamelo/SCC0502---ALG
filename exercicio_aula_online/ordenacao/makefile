CC=gcc
CFLAGS=-Wall
objects = main.o ListaDinamica.o

executa: main
	./main
	
main: ListaDinamica.o main.c
	$(CC) -o main ListaDinamica.o main.c
	
Lista.o: ListaDinamica.c ListaDinamica.h
	$(CC) -c ListaDinamica.c
	
clean:
	rm main $(objects)