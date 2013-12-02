/**
 * Définit les liste d'adjacence pour les tries.
 */

#ifndef _LIST
#define _LIST

struct _list {
  int targetNode; // Cible de la transition 
  unsigned char letter; // Etiquette de la transition
  struct _list *next; // Maillon suivant
};

typedef struct _list *List;

/**
 * Récupère le noeud cible dans la liste par label.
 */
int getFromList(List list, unsigned char label);

/**
 * Créer une nouvelle liste et la retourne.
 * La nouvelle liste est list à laquelle on ajoute en tete un nouveau
 * targetNode accessible via label.
 */
List addToList(List list, int targetNode, char label);

/**
 * Affiche sur la sortie standard une représentation de la liste.
 */
void printList(List list);

#endif
