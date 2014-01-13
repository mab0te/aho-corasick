#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trie-mix.h"
#include "list.h"

Trie createTrie(int maxNode) {
  Trie newTrie = (Trie) malloc(sizeof(struct _trie));
  newTrie->maxNode = maxNode;
  newTrie->nextNode = 1;
  newTrie->transitionRoot = (int *) malloc(ALPHA_SIZE * sizeof(int));
  newTrie->transitionOther = (List *) malloc(maxNode * sizeof(List));
  newTrie->finite = (char *) malloc(maxNode * sizeof(char));
  for (int i = 0; i < ALPHA_SIZE; i++) {
    newTrie->transitionRoot[i] = -1;
  }
  for (int i = 0; i <= maxNode; i++) {
    newTrie->transitionOther[i] = NULL;
    newTrie->finite[i] = 0;
  }

  return newTrie;
}

int insertInTrie(Trie trie, char *w) {
  if (strcmp((char *) w, "") == 0) {
    trie->finite[0] = 1;
    return 0;
  } else {
    int curState = trie->transitionRoot[(int) w[0]];
    if (curState == -1) {
      trie->transitionRoot[(int) w[0]] = trie->nextNode;
      curState = trie->nextNode;
      trie->nextNode = trie->nextNode + 1;
    }
    size_t length = strlen((char *) w);
    for (int i = 1; i < length; i++) {
      int next = getFromList(trie->transitionOther[curState], w[i]);
      if (next >- 1) {
	curState = next;
      } else {
	trie->transitionOther[curState] =
	  addToList(trie->transitionOther[curState], trie->nextNode, w[i]);
	curState = trie->nextNode;
	trie->nextNode = trie->nextNode + 1;
      }
    }
    trie->finite[curState] = 1;
    return curState;
  }
}

int isInTrie(Trie trie, char *w) {
  if (strcmp((char *) w, "") == 0) {
    return trie->finite[0];
  }
  size_t length = strlen((char *) w);
  int curState = trie->transitionRoot[(int) w[0]];
  if (curState < 0) {
    return 0;
  }
  else {
    for (int i = 1; i < length; i++) {
      int next = getFromList(trie->transitionOther[curState], w[i]);
      if (next < 0) {
	return 0;
      } else {
	curState = next;
      }
    }
    return trie->finite[curState];
  }
}
