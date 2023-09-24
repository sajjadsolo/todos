CC = gcc 
CFLAGS = -Wall

all:final

pointer.o:pointer.c
	$(CC) $(CFLAGS) -c pointer.c

final:pointer.o
	$(CC) $(CFLAGS) pointer.o -o application

clean:
	rm pointer.o application
