#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ac-matrice.h"
#include "trie/trie-mtx.h"
#include "alpha.h"
#include "queue.h"

#define TRIE_SIZE 256

char * alpha = TWO_CHAR_ALPHA;
size_t alphaSize = 2;

AcTrie initAcTrie () {
	AcTrie acTrie;
	acTrie = (AcTrie) malloc (sizeof (struct _ac_trie));

	acTrie->trie = createTrie (TRIE_SIZE, alphaSize);

	acTrie->sortie = (char *) malloc (TRIE_SIZE * sizeof (char));
	memset (acTrie->sortie, 0, TRIE_SIZE);

	acTrie->sup = (int *) malloc (TRIE_SIZE * sizeof (int));
	memset (acTrie->sup, -1, TRIE_SIZE);

	return acTrie;
}

AcTrie preAC (char ** x, int k) {
	// Création du trie
	AcTrie acTrie = initAcTrie();
	
	// Insertion de tous les mots de x au trie
	for (int i = 0; i < k; i++) {
		entrer (x[i], acTrie);
	}

	// Ajout de la boucle à la racine
	for (int i = 0; i < alphaSize; i++) {
		if (acTrie->trie->transition[0][(unsigned char) i] == -1) {
			acTrie->trie->transition[0][(unsigned char) i] = 0;
		}
		printf("d(0, %c) = %d\n", alpha[i], acTrie->trie->transition[0][i]);
	}

	// Complétion du acTrie
	completer (acTrie);

	// Renvoie du acTrie
	return acTrie;
}

void entrer (char * w, AcTrie acTrie) {
	int e = insertInTrie (acTrie->trie, ((unsigned char *) w));
	acTrie->sortie[e] = 1;
}

void completer (AcTrie acTrie) {
	// File
	Queue q = (Queue) malloc (sizeof (struct _queue));

	// Liste des transitions depuis la racine (longueur de l = alphaSize)
	int * l = acTrie->trie->transition[0];
	
	/* Remplissage de la file avec les premiers noeuds suivant la racine 
	 * + ajout des suppléants (les suppléants des successeurs de la racine sont la racine elle même)
	 */
	for (int i = 0; i < alphaSize; i++) {
		// On ne prend pas en compte les transitions du type (0, i, 0)
		if (l[i] != 0 && l[i] != -1) {
			pushQueue (q, l[i]);
			acTrie->sup[i] = 0;
		}
	}

	// Ajout des suppléants des tous les autres états
	while (q != NULL) {
		// On prend le noeud en tête de file
		int h = topQueue (q);
		q = popQueue(q);

		// Ainsi que ses successeurs
		l = acTrie->trie->transition[h];

		// Pour chacunes de ces transitions
		for (int i = 0; i < alphaSize; i++) {
			int p = l[i];
			if (p != -1) {
				// On enfile les successeurs
				pushQueue (q, p);

				// On prend le suppléants du noeud actuel
				int s = acTrie->sup[h];

				// Recherche du suppléant
				while (acTrie->trie->transition[s][i] == -1) {
					s = acTrie->sup[s];
				}

				// Affectation du suppléant
				acTrie->sup[p] = acTrie->trie->transition[s][i];

				// sortie(0) <- sortie(0) U sortie(sup(p))
				if (acTrie->sortie[acTrie->sup[p]] == 1) {
					acTrie->sortie[0] = 1;
				}
			}
		}

	}
}

void ac (char ** x, int k, char * y, int n) {
	AcTrie acTrie = preAC (x, k);
	int curState = 0;

	printf("*\n");
	for (int j = 0; j < n; j++)	{
		for (int i = 0; i < alphaSize; i++)	{
			printf("**\n");
			while (acTrie->trie->transition[curState][(unsigned char) alpha[i]] == -1) {
				printf("%d\n", curState);
				curState = acTrie->sup[curState];
				printf("%d\n", curState);
			}
			printf("**\n");
		}
		curState = acTrie->trie->transition[curState][(unsigned char) y[j]];
		if (acTrie->sortie[curState] == 1) {
			printf("Found on character %d\n", j);
		}
	}
	printf("*\n");
}