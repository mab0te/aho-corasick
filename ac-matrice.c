#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ac-matrice.h"
#include "trie/trie-mtx.h"
#include "alpha.h"
#include "queue.h"

#define TRIE_SIZE 10000

char * alpha = TWO_CHAR_ALPHA;
size_t alphaSize = 2;

AcTrie initAcTrie () {
  AcTrie acTrie; //Le nouveau trie
  //Allocation de la structure de l'ac-trie
  acTrie = (AcTrie) malloc (sizeof (struct _ac_trie));
  //Création du trie interne
  acTrie->trie = createTrie (TRIE_SIZE, 256);
  //Inititalisation du tableau des sortie.
  acTrie->sortie = (char *) malloc (TRIE_SIZE * sizeof (char));
  memset (acTrie->sortie, 0, TRIE_SIZE);
  //Initialisation des suppléants (aucun suppléants)
  acTrie->sup = (int *) malloc (TRIE_SIZE * sizeof (int));
  memset (acTrie->sup, -1, TRIE_SIZE);

  return acTrie;
}

AcTrie preAC (char ** x, int k) {
  //printf("[DEBUG] Entering preAC\n");
  // Création du trie
  AcTrie acTrie = initAcTrie();
  printf("[DEBUG] trie initialisé\n");
  // Insertion de tous les mots de x au trie
  for (int i = 0; i < k; i++) {
    entrer (x[i], acTrie);
  }/*
  if (!isInTrie(acTrie->trie, x[1])) {
    exit(0);
  } else {
    printf("0 -> a -> %d\n", acTrie->trie->transition[0][(int) 'a']);
    printf("1 -> b -> %d\n", acTrie->trie->transition[1][(int) 'b']);
    printf("1 -> a -> %d\n", acTrie->trie->transition[1][(int) 'a']);
    exit(0);
    }*/
  // Ajout de la boucle à la racine
  for (int i = 0; i < alphaSize; i++) {
    if (acTrie->trie->transition[0][(int) alpha[i]] == -1) {
      acTrie->trie->transition[0][(int) alpha[i]] = 0;
    }
    //printf("[DEBUG] d(0, %c) = %d\n", 
    //alpha[i], 
    //acTrie->trie->transition[0][(int) alpha[i]]
    //);
  }

  // Complétion du acTrie
  completer (acTrie);

  // Renvoie du acTrie
  return acTrie;
}

void entrer (char * w, AcTrie acTrie) {
  //printf("[DEBUG] Entering entrer\n");
  int e = insertInTrie (acTrie->trie, w);
  acTrie->sortie[e] = 1;
  if (!isInTrie(acTrie->trie, w)) {
    //fprintf(stderr, "[DEBUG][ERROR] in entrer no word inserted\n");
  }
}

void completer (AcTrie acTrie) {
  // File
  //printf("[DEBUG] entering completer\n");
  Queue q = NULL;
  // Liste des transitions depuis la racine (longueur de l = alphaSize)
  int * l = acTrie->trie->transition[0];
	
  /* Remplissage de la file avec les premiers noeuds suivant la racine 
   * + ajout des suppléants (les suppléants des successeurs de la racine 
   * sont la racine elle même)
   */
  for (int i = 0; i < alphaSize; i++) {
    // On ne prend pas en compte les transitions du type (0, i, 0)
    if (l[(int) alpha[i]] != 0 && l[(int) alpha[i]] != -1) {
      //printf("[DEBUG] %d\n", l[(int) alpha[i]]);
      q = pushQueue (q, l[(int) alpha[i]]);
      //printf("*\n");
      acTrie->sup[l[(int) alpha[i]]] = 0;
    }
  }

  // Ajout des suppléants des tous les autres états
  while (q != NULL) {
    //printQueue(q);
    //printf("\n");
    //printf("[DEBUG] begin loop body for suppleants\n");
    // On prend le noeud en tête de file
    int h = topQueue (q);
    q = popQueue(q);

    // Ainsi que ses successeurs
    l = acTrie->trie->transition[h];

    // Pour chacunes de ses transitions
    for (int i = 0; i < alphaSize; i++) {
      int p = l[(int) alpha[i]];
      //printf("[DEBUG] Etat %d - %c -> %d\n", h, alpha[i], p);
      if (p != -1) {
	// On enfile les successeurs
	q = pushQueue (q, p);
	
	// On prend le suppléants du noeud actuel
	int s = acTrie->sup[h];	
	//printf("%d\n", s);
	// Recherche du suppléant
	while (acTrie->trie->transition[s][(int) alpha[i]] == -1) {
	  s = acTrie->sup[s];
	  //printf("**\n");
	}
	
	// Affectation du suppléant
	acTrie->sup[p] = acTrie->trie->transition[s][(int) alpha[i]];

	// sortie(0) <- sortie(0) U sortie(sup(p))
	if (acTrie->sortie[acTrie->sup[p]] == 1) {
	  acTrie->sortie[p] = 1;
	}
      }
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
  //printf("[DEBUG] entering main aho-corasick function\n");
  AcTrie acTrie = preAC (x, k);
  printf("Debut de la recherche\n");
  int curState = 0;

  for (int j = 0; j < n; j++)	{ //parcours du texte
    printf("%d\n", curState);
    while (acTrie->trie->transition[curState][(int) y[j]] == -1) {
      printf("%d %c X\n", curState, y[j]);
      curState = acTrie->sup[curState];
      printf("=> %d\n", curState);
    }
    curState = acTrie->trie->transition[curState][(int) y[j]];
    printf("= %c => %d\n", y[j], curState);
    if (acTrie->sortie[curState] == 1) {
      printf("Found on character %d\n", j);
    }
  }
  printf("*\n");
}
