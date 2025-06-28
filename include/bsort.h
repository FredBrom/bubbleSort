#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <stdlib.h>

void bsort(void *vector, size_t num_elements, size_t size,
           int (*compare)(const void *, const void *));

void swap(void *a, void *b, size_t size);

int compareInt(const void *a, const void *b);

int compareFloat(const void *a, const void *b);

int compareDouble(const void *a, const void *b);

int compareStrint(const void *a, const void *b);

#endif // !BUBBLESORT_H
