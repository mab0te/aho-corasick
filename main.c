#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ac-matrice.h"

int main(int argc, char const * argv[]) {
  char ** x = (char **) malloc (2 * sizeof (char *));
  x[0] = (char *) malloc (7 * sizeof (char));
  strncpy (x[0], "bababa", 7);
  x[1] = (char *) malloc (3 * sizeof (char));
  strncpy (x[1], "b", 2);
  printf("words to insert : %s |  %s\n", x[0], x[1]);
  int k = 2;
  char * y = "baabababaaba";
  int n = 12;
  printf("text to search in : %s\n", y);

  ac (x, k, y, n);

  return EXIT_SUCCESS;
}