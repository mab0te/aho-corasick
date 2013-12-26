#makefile des tries.
CC=gcc
CFLAGS=-Wall -pedantic -std=c99 -Werror

trie-mtx.o : trie-mtx.c trie-mtx.h
	gcc -c $(CFLAGS) $<

trie-lst.o : trie-lst.c list.h trie-lst.h
	gcc -c $(CFLAGS) $<

trie-mix.o : trie-mix.c trie-mix.h list.h
	gcc -c $(CFLAGS) $<

list.o : list.c list.h
	gcc -c $(CFLAGS) $<
