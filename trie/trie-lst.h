#ifndef _TRIE_LST
#define _TRIE_LST

#include "list.h"

struct _trie {
  int maxNode; // Nombre maximal de noeud du trie
  int nextNode; // Indice du prochain noeud disponible
  List *transition; // Listes d'adjacence
  char *finite; // Les etats terminaux
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
 *
 * @return : le nouvel état final inséré.
 */
int insertInTrie(Trie trie, unsigned char *w);

/**
 * Recherche si un mot est présent dans un trie.
 * @param trie : Le Trie dasn lequel chercher.
 * @param w : Le mot à chercher dans le trie.
 *
 * @return : 1 si le mot est trouvé, 0 sinon.
 */
int isInTrie(Trie trie, unsigned char *w);

#endif
