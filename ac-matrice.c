#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ac-matrice.h"
#include "trie/trie-mtx.h"
#include "alpha.h"
#include "file.h"

#define TRIE_SIZE 256

char * alpha = TWO_CHAR_ALPHA;

AcTrie initAcTrie () {
	AcTrie acTrie;
	acTrie = (AcTrie) malloc (sizeof (struct _ac_trie));

	acTrie->trie = createTrie (TRIE_SIZE);

	acTrie->sortie = (char *) malloc (TRIE_SIZE * sizeof (char));
	memset (acTrie->sortie, 0, TRIE_SIZE);

	return acTrie;
}

Trie preAC (char ** x, int k) {
	// Création du trie
	AcTrie acTrie = initAcTrie();

	// Insertion de tous les mots de x au trie
	for (int i = 0; i < k; i++) {
		entrer (x[i], acTrie);
	}

	// Ajout de la boucle à la racine
	t_size size = strlen (alpha);
	for (int i = 0; i < size; i++) {
		if (acTrie->trie->transition[0][(unsigned char) alpha[i]] != 0) {
			acTrie->trie->transition[0][(unsigned char) alpha[i]] = 0
		}
	}

	// Complétion du acTrie
	completer (acTrie);

	// Renvoie du acTrie
	return acTrie;
}

void entrer (char * w, AcTrie acTrie) {
	int e = insertInTrie (acTrie, w);
	acTrie->sortie[e] = 1;
}

void completer (AcTrie acTrie) {
	Queue q = (Queue) malloc (sizeof (struct _queue));
	
}

void ac (char ** x, int k, char * y, int n) {

}