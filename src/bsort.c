#include <stdlib.h>
#include <string.h>

#include "bsort.h"

void bsort(void *vector, size_t num_elements, size_t size,
           int (*compare)(const void *, const void *)) {
  size_t i = num_elements - 1;
  size_t j;

  while (i > 0) {

    j = 0;

    while (j < i) {

      const void *elem_j = vector + j * size;
      const void *elem_j1 = vector + (j + 1) * size;

      if (compare(elem_j, elem_j1) > 0) {
        swap((char *)vector + j * size, (char *)vector + (j + 1) * size, size);
      }

      j++;
    }

    i--;
  }
}

void swap(void *a, void *b, size_t size) {
  /**
   *  Implementation of a generic swap method
   */
  char temp[size];
  memcpy(temp, a, size);
  memcpy(a, b, size);
  memcpy(b, temp, size);
}

int compareInt(const void *a, const void *b) {
  /**
   * Compare function to integers
   * return -1 if a < b
   * return  0 if a = b
   * return  1 if a > b
   */
  return (*(const int *)a > *(const int *)b) -
         (*(const int *)a < *(const int *)b);
}

int compareDouble(const void *a, const void *b) {
  return (*(const double *)a > *(const double *)b) -
         (*(const double *)a < *(const double *)b);
}

int compareFloat(const void *a, const void *b) {
  return (*(const float *)a > *(const float *)b) -
         (*(const float *)a < *(const float *)b);
}

int compareString(const void *a, const void *b) {
  const char *str1 = *(const char **)a;
  const char *str2 = *(const char **)b;
  return strcmp(str1, str2);
}