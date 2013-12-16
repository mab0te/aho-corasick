#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ac-matrice.h"
#include "trie/trie-mtx.h"
#include "alpha.h"

#define TRIE_SIZE 256

char * alpha = TWO_CHAR_ALPHA;

trie preAC (char ** x, int k) {
	Trie e = createTrie (TRIE_SIZE);

	for (int i = 0; i < k; i++) {
		insertInTrie (e, x[i]);
	}

	for (int i = 0; i < alpha.size; i++) {
		if (e.transition[0][alpha[i]] != 0) {
			e.transition[0][alpha[i]] = 0
		}
	}
}

void entrer (char * w, Trie e) {

}

void completer (Trie e) {

}

void ac (char ** x, int k, char * y, int n) {

}