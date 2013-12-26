#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <string.h>
#include <time.h>

#include "../alpha.h"

#define BUFF_SIZE 128

void usage(char *exec) {
  printf("Usage : %s wordNb minLen maxLen alphaSize", exec);
  printf("\n");
  exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]) {
  if (argc != 5) {
    usage(argv[0]);
  }
  int wordNb = atoi(argv[1]);
  int minLen = atoi(argv[2]);
  int maxLen = atoi(argv[3]);
  int alphaSize = atoi(argv[4]);

  char alpha[BUFF_SIZE];
  
  if (wordNb < 0) {
    printf("Nombre de mots invalides.\n");
    exit(EXIT_FAILURE);
  }
  if (maxLen < minLen || minLen < 0) {
    printf("Tailles de mots invalides.\n");
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
  
  FILE *file = fopen("mots.txt", "w");
  if (file == NULL) {
    fprintf(stderr, "Probleme lors de l'ouverture du fichier.\n");
    exit(EXIT_FAILURE);
  }
  
  srand(time(NULL));
  for (int i = 0; i < wordNb; i++) {
    int size = 
      minLen + (maxLen - minLen + 1) * ((float) rand()) / ((float) RAND_MAX);
    for (int j = 0; j < size; j++) {
      int alea 
	= alphaSize * ((float) rand()) / ((float) RAND_MAX);
      fputc(alpha[alea], file);
    }
    fputc('\n', file);
  }

  fclose(file);
  exit(EXIT_SUCCESS);
}
