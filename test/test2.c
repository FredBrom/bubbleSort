/**
 *  test sorting double vector
 */

#include "bsort.h"
#include "printVector.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 10

int main() {

  double vector[NUM];

  srand(time(NULL));

  for (int i = 0; i < NUM; i++) {
    vector[i] = 5.0 - (double)(rand() % 1000) / 100.0;
  }

  size_t n = sizeof(vector) / sizeof(vector[0]);

  print_vector_double(stdout, vector, n, 2);
  bsort(vector, n, sizeof(double), bsort_compare_double);
  print_vector_double(stdout, vector, n, 2);

  return 0;
}
