#include <stdlib.h>
#include "bsort.h"

void bsort(int *vector, size_t size) {

  size_t i = size - 1;
  size_t j;

  while(i > 0) {
    
    j = 0;
    while(j < i) {
      
      if (vector[j] > vector[j+1]) {
        swap(&vector[j], &vector[j+1]);
      }

      j++;
    }
    i--;
  }

}

void swap(int *a, int *b) {

  int t;
  t = *a;
  *a = *b;
  *b = t;
}


