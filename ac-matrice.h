#ifndef _AC_MATRICE
#define _AC_MATRICE

#include "trie/trie-mtx.h"

/*
 * Créé le Trie, 
 * insère tous les mots de x (via entrer (char * w, Trie e)),
 * ajoute la boucle à la racine pour toutes les lettre non utilisées de l'alphabet
 * puis complète le Trie (via completer (Trie e)).
 * Renvoie le Trie.
 */
Trie preAC (char ** x, int k);

/*
 * Insère un mot w dans le Trie et donne sa sortie pour le calcul des suppléants.
 */
void entrer (char * w, Trie e);

/*
 * Ajoute au Trie les suppléants pour chaque états.
 */
void completer (Trie e);

/*
 * Algorithme d'Aho-Corasick.
 * Localise toutes les occurences d'un ensemble fini x de k mots dans un texte y de longueur n.
 */
void ac (char ** x, int k, char * y, int n);