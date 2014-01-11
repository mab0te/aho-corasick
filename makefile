#Makefile general.
CC=gcc
CFLAGS=-Wall -pedantic -std=c99 -Werror -g

all: mainMTX mainMTX2

mainMTX2: main2.o ac-matrice.o queue.o trie/trie-mtx.o trie/list.o
	$(CC) -o $@ $^ 

mainMTX: main.o ac-matrice.o queue.o trie/trie-mtx.o trie/list.o
	$(CC) -o $@ $^ 

main.o: main.c
	$(CC) -c $< $(CFLAGS)

main2.o: main2.c
	$(CC) -c $< $(CFLAGS)

ac-matrice.o: ac-matrice.c ac-matrice.h queue.h
	$(CC) -c $< $(CFLAGS)

queue.o: queue.c queue.h
	$(CC) -c $< $(CFLAGS)

clean:
	$(RM) *.o *~
