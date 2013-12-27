#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

Queue pushQueue (Queue q, int elm) {
	Queue ptr1 = q;
	if (q->next != NULL) {
		Queue ptr2 = ptr1->next;
	
		while (ptr2 != NULL){
			ptr1 = ptr1->next;
			ptr2 = ptr1->next;
		}
	
	}

	Queue tmp = (Queue) malloc (sizeof (struct _queue));
	tmp->elm = elm;
	tmp->next = NULL;

	ptr1->next = tmp;

	return q;	
}

Queue popQueue (Queue q) {
	Queue ptr1 = q;
	Queue ptr2 = q->next;

	free (ptr1);

	return ptr2;
}

int topQueue (Queue q) {
	return q->elm;
}