#Makefile general.
CC=gcc
CFLAGS=-Wall -pedantic -std=c99 -Werror -g

all: tries ac-mixte ac-liste ac-matrice

ac-mixte: mainMIX.o ac-mix.o queue.o trie/trie-mix.o trie/list.o
	$(CC) -o $@ $^

ac-liste: mainLST.o ac-list.o queue.o trie/trie-lst.o trie/list.o
	$(CC) -o $@ $^

ac-matrice: mainMTX.o ac-matrice.o queue.o trie/trie-mtx.o trie/list.o
	$(CC) -o $@ $^ 

mainMIX.o: mainMIX.c
	$(CC) -c $< $(CFLAGS)

mainMTX.o: mainMTX.c
	$(CC) -c $< $(CFLAGS)

mainLST.o: mainLST.c
	$(CC) -c $< $(CFLAGS)

ac-mix.o: ac-mix.c ac-mix.h queue.h
	$(CC) -c $< $(CFLAGS)

ac-matrice.o: ac-matrice.c ac-matrice.h queue.h
	$(CC) -c $< $(CFLAGS)

ac-list.o: ac-list.c ac-list.h queue.h
	$(CC) -c $< $(CFLAGS)

queue.o: queue.c queue.h
	$(CC) -c $< $(CFLAGS)

tries:
	cd trie/; make all;

clean:
	$(RM) *.o *~;
	cd trie/; make clean;
