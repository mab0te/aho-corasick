#ifndef _AC_FILE
#define _AC_FILE

struct _queue {
	int elm;
	struct _queue * next;
};

typedef struct _queue * Queue;

/*
 * Insertion en queue d'un élément dans la file.
 */
Queue pushQueue (Queue q, int elm);

/*
 * Retire le premier élément.
 */
Queue popQueue (Queue q);

/*
 * Récupère l'élément en tête de file.
 */
int topQueue (Queue q);

#endif