#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "ac-list.h"
#include "trie/trie-lst.h"

#include "alpha.h"
#include "queue.h"
 
#define TRIE_SIZE 100000

char * alpha = SEVENTY_CHAR_ALPHA;
size_t alphaSize = 20;

AcTrie initAcTrie () {
  AcTrie acTrie; //Le nouveau trie
  //Allocation de la structure de l'ac-trie
  acTrie = (AcTrie) malloc (sizeof (struct _ac_trie));
  //Création du trie interne
  acTrie->trie = createTrie (TRIE_SIZE);
  //Inititalisation du tableau des sortie.
  acTrie->sortie = (char *) malloc (TRIE_SIZE * sizeof (char));
  memset (acTrie->sortie, 0, TRIE_SIZE);
  //Initialisation des suppléants (aucun suppléants)
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
    if (getFromList(acTrie->trie->transition[0], (int) alpha[i]) == -1) {
      addToList(acTrie->trie->transition[0], 0, (int) alpha[i]);
    }
  }
  // Complétion du acTrie
  completer (acTrie);

  // Renvoie du acTrie
  return acTrie;
}

void entrer (char * w, AcTrie acTrie) {
  int e = insertInTrie (acTrie->trie, w);
  acTrie->sortie[e] = 1;
}

void completer (AcTrie acTrie) {
  // File
  Queue q = NULL;
  // Liste des transitions depuis la racine (longueur de l = alphaSize)
  List l = acTrie->trie->transition[0];
	
  /* Remplissage de la file avec les premiers noeuds suivant la racine 
   * + ajout des suppléants (les suppléants des successeurs de la racine 
   * sont la racine elle même)
   */
  while (l != NULL) {
    if (l->targetNode != 0) {
      q = pushQueue(q, l->targetNode);
      acTrie->sup[l->targetNode] = 0;
    }
    l = l->next;
  }
  
  // Ajout des suppléants des tous les autres états
  while (q != NULL) {
    // On prend le noeud en tête de file
    int h = topQueue (q);
    q = popQueue(q);

    // Ainsi que ses successeurs
    l = acTrie->trie->transition[h];
    
    // Pour chacunes de ses transitions
    while (l != NULL) {
      int p = l->targetNode;
      if (p != -1) {
	// On enfile les successeurs
	q = pushQueue (q, p);
	
	// On prend le suppléants du noeud actuel
	int s = acTrie->sup[h];	
	// Recherche du suppléant
	while (getFromList(acTrie->trie->transition[s], l->letter) == -1) {
	  s = acTrie->sup[s];
	}
	// Affectation du suppléant
	acTrie->sup[p] = getFromList(acTrie->trie->transition[s], l->letter);

	// sortie(0) <- sortie(0) U sortie(sup(p))
	if (acTrie->sortie[acTrie->sup[p]] == 1) {
	  acTrie->sortie[p] = 1;
	}
      }
      l = l->next;
    }

  }
}
/**
 * Fonction principale d'aho Corasick
 * @param x l'ensemble des mots à chercher
 * @param k le nombre de mots à chercher
 * @param y le text dans lequel chercher
 * @param n la longueur du texte dans lequel chercher
 */
void ac (char ** x, int k, char * y, int n) {
  AcTrie acTrie = preAC (x, k);
  int curState = 0;
  for (int j = 0; j < n; j++)	{ //parcours du texte
    while (getFromList(acTrie->trie->transition[curState], (int) y[j]) == -1) {
      curState = acTrie->sup[curState];
    }
    curState = getFromList(acTrie->trie->transition[curState], (int) y[j]);
    if (acTrie->sortie[curState] == 1) {
      //printf("%d\n", j);
    }
  }
}
