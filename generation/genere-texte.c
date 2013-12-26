#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <string.h>
#include <time.h>

#include "../alpha.h"

#define BUFF_SIZE 128

void usage(char *exec) {
  printf("Usage : %s texte-size alapha-size", exec);
  printf("\n");
  exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    usage(argv[0]);
  }
  long long int textSize = atoll(argv[1]);
  int alphaSize = atoi(argv[2]);
  char alpha[BUFF_SIZE];

  if (textSize < 0) {
    printf("Taille de texte invalide.\n");
    exit(EXIT_FAILURE);
  }
  switch(alphaSize) {
  case 2: 
    strncpy(alpha, TWO_CHAR_ALPHA, BUFF_SIZE);
    break;
  case 4:
    strncpy(alpha, FOUR_CHAR_ALPHA, BUFF_SIZE);
    break;
  case 20:
    strncpy(alpha, TWENTY_CHAR_ALPHA, BUFF_SIZE);
    break;
  case 70:
    strncpy(alpha, SEVENTY_CHAR_ALPHA, BUFF_SIZE);
    break;
  default :
    printf("%d est une taille d'alphabet invalide.\n", alphaSize);
    exit(EXIT_FAILURE);
    break;
  }
  
  FILE *file = fopen("texte.txt", "w");
  if (file == NULL) {
    fprintf(stderr, "Probleme lors de l'ouverture du fichier.\n");
    exit(EXIT_FAILURE);
  }
  srand(time(NULL));
  for (long long int i = 0; i < textSize; i++) {
    int alea 
      = alphaSize * ((float) rand()) / ((float) RAND_MAX);
    fputc(alpha[alea], file);
  }
  
  fclose(file);
  exit(EXIT_SUCCESS);
}
