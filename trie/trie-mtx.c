#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trie-mtx.h"

Trie createTrie(int maxNode, int alphaSize) {
  Trie newTrie;
  //Allocation de la structure
  newTrie = (Trie) malloc(sizeof(struct _trie));
  if (newTrie == NULL) {
    return NULL;
  }

  //Allocation de la matrice
  newTrie->transition = (int **) malloc(maxNode * sizeof(int *));
  if (newTrie->transition == NULL) {
    return NULL;
  }
  for (int i = 0; i <= maxNode; i++) {
    newTrie->transition[i] = (int *) malloc(alphaSize * sizeof(int));
    if (newTrie->transition[i] == NULL) {
      return NULL;
    }
  }
  
  //Allocation du tableau des états finaux
  newTrie->finite = (char *) malloc(maxNode * sizeof(char));
  if (newTrie->finite == NULL) {
    return NULL;
  }
  newTrie->maxNode = maxNode;
  newTrie->nextNode = 1;
  for (int i = 0; i <= maxNode; i++) {
    for (int j = 0; j < alphaSize; j++) {
      newTrie->transition[i][j] = -1;
    }
    newTrie->finite[i] = 0;
  }
  return newTrie; //Retour du pointeur sur la structure.
}

int insertInTrie(Trie trie, char *w) {
  size_t length = strlen((char *) w);
  int curState = 0;
  for (int i = 0; i < length; i++) {
    int next = trie->transition[curState][w[i]];
    if (next > -1) {
      curState = next;
    } else {
      trie->transition[curState][w[i]] = trie->nextNode;
      curState = trie->nextNode;
      if (i == length - 1) {
        trie->finite[trie->nextNode] = 1;
      }
      trie->nextNode++;
    }
  }

  return curState;
}

int isInTrie(Trie trie, char *w) {
  size_t length = strlen((char *) w);
  int curState = 0;
  for (int i = 0; i < length; i++) {
    int next = trie->transition[curState][w[i]];
    if (next < 0) {
      return 0;
    } else {
      curState = next;
    }
  }
  return trie->finite[curState];
}
