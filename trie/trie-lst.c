#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "trie-lst.h"
#include "list.h"

Trie createTrie(int maxNode) {
  if (maxNode < 1) {
    return NULL;
  }
  Trie newTrie = (Trie) malloc(sizeof(struct _trie));
  if (newTrie == NULL) {
    return NULL;
  }
  newTrie->maxNode = maxNode;
  newTrie->nextNode = 1;
  newTrie->transition = NULL;
  newTrie->finite = (char *) malloc(maxNode * sizeof(char));
  newTrie->transition = (List *) malloc(maxNode * sizeof(List));
  for (int i = 0; i <= maxNode; i++) {
    newTrie->transition[i] = NULL;
    newTrie->finite[i] = 0;
  }
  return newTrie;
}

int insertInTrie(Trie trie, char *w) {
  size_t length = strlen(w);
  int curState = 0;
  for (int i = 0; i < length; i++) {
    int next = getFromList(trie->transition[curState], w[i]);
    if (next > -1) {
      curState = next;
    } else {
      trie->transition[curState] = 
	addToList(trie->transition[curState], trie->nextNode, w[i]);
      curState = trie->nextNode;
      trie->nextNode = trie->nextNode + 1;
    }
  }
  trie->finite[curState] = 1;
  return curState;
}

int isInTrie(Trie trie, char *w) {
  size_t length = strlen(w);
  int curState = 0;
  for (int i = 0; i < length; i++) {
    int next = getFromList(trie->transition[curState], w[i]);
    if (next < 0) {
      return 0;
    } else {
      curState = next;
    }
  }
  return trie->finite[curState];
}
