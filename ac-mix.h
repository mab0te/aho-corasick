#ifndef _AC_LIST
#define _AC_LIST

#include "trie/trie-mix.h"

/**
 * Une super structure augmentant la structure standar des tries.
 * Cette structure ajoute un tableau de suppléant ainsi qu'un 
 * tableau de noeud de sortie.
 */
struct _ac_trie {
  Trie trie; // Le trie  
  char * sortie;// Indique les noeuds dont les suppléants sont des états finaux
  int * sup;// Suppléants
};

typedef struct _ac_trie * AcTrie;


/*
 * Initialise la structure d'un AcTrie.
 */
AcTrie initAcTrie();

/*
 * Créé le Trie, 
 * insère tous les mots de x (via entrer (char * w, Trie e)),
 * ajoute la boucle à la racine pour toutes les lettre non utilisées de l'alphabet
 * puis complète le Trie (via completer (Trie e)).
 * Renvoie le Trie.
 */
AcTrie preAC (char ** x, int k);

/*
 * Insère un mot w dans le Trie et donne sa sortie pour le calcul des suppléants.
 */
void entrer (char * w, AcTrie acTrie);

/*
 * Ajoute au Trie les suppléants pour chaque états.
 */
void completer (AcTrie acTrie);

/*
 * Algorithme d'Aho-Corasick.
 * Localise toutes les occurences d'un ensemble fini x de k mots dans un texte y 
 * de longueur n.
 */
void ac (char ** x, int k, char * y, int n);

#endif
