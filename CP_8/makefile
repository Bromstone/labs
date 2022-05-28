CC = gcc
CFLAGS= -c -Wall -std=c99 -pedantic

lin:	main.o lin.o
	$(CC) -o lin main.o lin.o

main.o:	main.c
	$(CC) $(CFLAGS) main.c

lin.o:	lin.c
	$(CC) $(CFLAGS) lin.c

clean:
	rm lin main.o lin.o
