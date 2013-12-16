#include <stdio.h>
#include <stdlib.h>

#include "file.h"

Queue pushQueue (Queue q, int elm) {
	int * ptr1 = q->elm;
	int * ptr2 = ptr1->next;

	while (ptr2 != NULL){
		ptr1 = ptr1->next;
		ptr2 = ptr1->next;		
	}

	Queue tmp = (Queue) malloc (sizeof (struct _queue));
	tmp->elm = elm;
	tmp->next = NULL;

	ptr1->next = tmp;

	return q;
}

Queue popQueue (Queue q) {
	return q->next;
}

int topQueue (Queue q) {
	return q->elm;
}