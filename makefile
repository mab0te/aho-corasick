#Makefile general.
CC=gcc
CFLAGS=-Wall -pedantic -std=c99 -Werror

ac-matrice.o: ac-matrice.c ac-matrice.h
  $(CC) -c $< $(CFLAGS)
  
queue.o: queue.c queue.h
  $(CC) -c $< $(CFLAGS)
  
