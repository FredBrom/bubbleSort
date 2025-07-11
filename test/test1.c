/**
 * first test
 */
#include "bsort.h"
#include "printVector.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

  int vector[] = {2, 6, 3, 5, 1, 4};
  size_t n = sizeof(vector) / sizeof(vector[0]);

  print_vector_int(stdout, vector, n);
  bsort(vector, n, sizeof(int), bsort_compare_int);
  print_vector_int(stdout, vector, n);

  return 0;
}
