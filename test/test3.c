/**
 *  Test sorting float vector
 */

#include "bsort.h"
#include "printVector.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 10

int main() {

  float vector[NUM];

  srand(time(NULL));

  for (int i = 0; i < NUM; i++) {
    vector[i] = 5.0f - (float)(rand() % 1000) / 100.0f;
  }

  size_t n = sizeof(vector) / sizeof(vector[0]);

  printVectorf(stdout, vector, n, 2);
  bsort(vector, n, sizeof(float), bsort_compare_float);
  printVectorf(stdout, vector, n, 2);

  return 0;
}
