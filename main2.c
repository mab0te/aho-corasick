#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#include "ac-matrice.h"

#define BUFF_SIZE 1024

int main(int argc, char const *argv[]) {
  if (argc != 3) {
    printf("Usage : %s wordsFile textFile\n", argv[0]);
    exit(EXIT_SUCCESS);
  }
  char **words = NULL;
  char *text = NULL;
  int wordNb = 0;
  FILE *wordsFile = fopen(argv[1], "r");
  if (wordsFile == NULL) {
    fprintf(stderr, "Error while opening %s", argv[1]);
  }

  // Récupération des mots du fichier.
  while (!feof(wordsFile)) {
    wordNb += 1;
    if (words != NULL) {
      words = (char **) realloc(words, wordNb * sizeof(char*));
    } else {
      words = (char **) malloc(wordNb * sizeof(char*));
    }
    words[wordNb - 1] = (char *) malloc(BUFF_SIZE * sizeof(char));
    words[wordNb - 1] = fgets(words[wordNb - 1], BUFF_SIZE, wordsFile);
    if (words[wordNb - 1] != NULL) {
      words[wordNb - 1][strlen(words[wordNb - 1]) - 1] = 0;
    } else {
      wordNb -= 1;
    }
  }
  fclose(wordsFile);
  
  FILE *textFile = fopen(argv[2], "r");
  char *buff = (char *) malloc(BUFF_SIZE * sizeof(char));
  // Récupération du fichier
  if (textFile == NULL) {
    fprintf(stderr, "Error while opening %s", argv[1]);
  }
  text = (char *) malloc(BUFF_SIZE * sizeof(char));
  size_t length = 0;
  int blockNb = 1;
  while (!feof(textFile)) {
    fread(buff, sizeof(char), BUFF_SIZE, textFile);
    strncat(text, buff, BUFF_SIZE);
    length += strlen(buff);
    if (!feof(textFile)) {
      blockNb += 1;
      printf("%d\n", blockNb);
      text = realloc(text, blockNb * BUFF_SIZE);
    }
  }
  fclose(textFile);
  
  ac(words, wordNb, text, strlen(text));

  exit(EXIT_SUCCESS);
}
