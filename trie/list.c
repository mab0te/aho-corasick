#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

int getFromList(List list, char label) {
  List tmp = list;
  while (tmp != NULL) {
    if (tmp->letter == label) {
      return tmp->targetNode;
    }
    tmp = tmp->next;
  }
  return -1;
}

List addToList(List list, int targetNode, char label) {
  List cell = (List) malloc(sizeof(struct _list));
  cell->targetNode = targetNode;
  cell->letter = label;
  cell->next = list;
  return cell;
}

void printList(List list) {
  while (list != NULL) {
    printf("|node : %i; label : %c|", list->targetNode, list->letter);
    list = list->next;
  }
  printf("X\n");
}
