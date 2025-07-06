#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <stdlib.h>

void bsort(void *vector, size_t num_elements, size_t size,
           int (*compare)(const void *, const void *));

void bsort_swap(void *a, void *b, size_t size);

int bsort_compare_int(const void *a, const void *b);

int bsort_compare_float(const void *a, const void *b);

int bsort_compare_double(const void *a, const void *b);

int bsort_compare_string(const void *a, const void *b);

#endif // !BUBBLESORT_H
