CC=gcc
CFLAGS=-Wall
objects = main.o ListaEstatica.o

lista1 : $(objects)
	$(CC) -o lista2 $(objects)

main.o : ListaEstatica.h
ListaEstatica.o : ListaEstatica.h

clean :
	rm lista2 $(objects)