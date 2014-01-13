CC=gcc
CFLAGS= -Wall -pedantic -std=c99 -Werror
RM= rm

all: genere-texte genere-mots

genere-texte: genere-texte.o
	$(CC) -o $@ $(CFLAGS) $^

genere-texte.o: genere-texte.c 
	$(CC) -c $< $(CFLAGS)

genere-mots: genere-mots.o
	$(CC) -o $@ $(CFLAGS) $^

genere-mots.o: genere-mots.c
	$(CC) -c $(CFLAGS) $<

clean:
	$(RM) *.o *~
