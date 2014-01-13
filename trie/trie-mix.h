#ifndef _TRIE_MIX
#define _TRIE_MIX

#include "list.h"

#define ALPHA_SIZE 256

struct _trie {
  int maxNode; //Nombre maximal de noeud du trie.
  int nextNode; //Indice du prochain noeud disponible.
  int *transitionRoot; //Transition de la racine.
  List *transitionOther; //Transitions des autres noeuds.
  char *finite; //Les etats terminaux.
};

typedef struct _trie *Trie;

/**
 * Créé un trie vide de maxNode noeuds au maximum.
 * @args maxNode le nombre de noeud maximal.
 *       maxNode >= 0
 * @return un Trie initialisé ou NULL en cas d'erreur.
 */
Trie createTrie(int maxNode);

/**
 * Insert un mot dans un Trie
 * @param trie : le trie dans lequel insérer.
 * @param w : le mot à insérer dans le trie.
 */
int insertInTrie(Trie trie, char *w);

/**
 * Recherche si un mot est présent dans un trie.
 * @param trie : Le Trie dasn lequel chercher.
 * @param w : Le mot à chercher dans le trie.
 *
 * @return : 1 si le mot est trouvé, 0 sinon.
 */
int isInTrie(Trie trie, char *w);

#endif
