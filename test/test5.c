/**
 * sorting an array of string
 */

#include "bsort.h"
#include "printVector.h"
#include <string.h>

int main() {

  char *names[] = {"Frederico", "Bia", "Gui", "Ana", "Sonia", "Bruna", NULL};

  printVectors(stdout, names);
  bsort(names, 6, sizeof(names[0]), bsort_compare_string);

  printVectors(stdout, names);

  return 0;
}
