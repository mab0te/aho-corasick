CC=gcc
CFLAGS=-Wall -pedantic -std=c99 -Werror

test : test.o trie-mix.o list.o
	gcc -o $@ $^

test.o : test.c trie-mtx.h trie-lst.h
	gcc -c $(CFLAGS) $<

trie-mtx.o : trie-mtx.c trie-mtx.h
	gcc -c $(CFLAGS) $<

trie-lst.o : trie-lst.c list.h trie-lst.h
	gcc -c $(CFLAGS) $<

trie-mix.o : trie-mix.c trie-mix.h list.h
	gcc -c $(CFLAGS) $<

list.o : list.c list.h
	gcc -c $(CFLAGS) $<
