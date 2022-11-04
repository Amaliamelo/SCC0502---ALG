CC=gcc
CFLAGS=-Wall
objects = main.o pila_filha.o

run: main
	./main
	
all: main

main: pila_filha.o main.c
	$(CC) -o main pila_filha.o main.c
	
Lista.o: pila_filha.c pila_filha.h
	$(CC) -c pila_filha.c
	
clean:
	rm main $(objects)