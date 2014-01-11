#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

Queue pushQueue (Queue q, int elm) {
  if (q != NULL) {
    Queue ptr1 = q;
    Queue ptr2 = ptr1->next;
    while (ptr2 != NULL){
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
    }
    Queue tmp = (Queue) malloc (sizeof (struct _queue));
    tmp->elm = elm;
    tmp->next = NULL;
    
    ptr1->next = tmp;

    return q;
  } else {
    Queue tmp = (Queue) malloc (sizeof (struct _queue));
    tmp->elm = elm;
    tmp->next = NULL;

    return tmp;
  }	
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

void printQueue (Queue q) {
  Queue ptr = q;
  if (ptr != NULL) {
    printf("%d ", ptr->elm);
    ptr = ptr->next;
  }
  while (ptr != NULL) {
    printf("| %d ", ptr->elm);
    ptr = ptr->next;
  }
}
