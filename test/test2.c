#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bsort.h"
#include "printVector.h"

#define N 25

int main() {

  int vector[N];
  srand(time(NULL));

  for (int i=0; i<N; i++) {
    vector[i] = rand() % 100;
  }

  size_t n = sizeof(vector) / sizeof(vector[0]);

  printf("%d\n", n);

  printVectori(stdout, vector, n);
  bsort(vector, n);
  printVectori(stdout, vector, n);

  return 0;
}
