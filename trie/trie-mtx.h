#ifndef _TRIE_MTX
#define _TRIE_MTX

struct _trie {
  int maxNode; //Nombre maximale de noeud du trie
  int nextNode; //Indice du prochain noeud disponible
  int **transition; //Matrice de transition
  char *finite; //Etats terminaux
};

typedef struct _trie *Trie;

/**
 * Créé un trie vide de maxNode noeuds au maximum.
 * @args maxNode le nombre de noeud maximal.
 *       maxNode >= 0
 * @return un Trie initialisé ou NULL en cas d'erreur.
 */
Trie createTrie(int maxNode, int alphaSize);

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
