CC =gcc
CFLAGS = -Wall
OBJ = learn.o
all:final

%.o:%.c
	$(CC) $(CFLAGS) -c $@ $<

final:$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o application

clean:
	rm $(OBJ) application
