CC=gcc
CFLAGS=-Wall
objects = main.o ListaEstatica.o

executa: main
	./main
	
main: ListaEstatica.o main_estatica.c
	$(CC) -o main ListaEstatica.o main_estatica.c
	
Lista.o: ListaEstatica.c ListaEstatica.h
	$(CC) -c ListaEstatica.c
	
clean:
	rm main $(objects)