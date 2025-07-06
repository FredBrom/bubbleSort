# Bubble sort

### An generic (type independent) implementation of bubble sort algorithm in C

## Sorting Function

```c
void bsort(void *vector, size_t num_elements, size_t size,
           int (*compare)(const void *, const void *))
```

## Compare Functions

To make the sorting algorithm type independent, it was necessary to implement a type dependent comparative function for array elements.
It must:

- return 0 if a = b
- return 1 if a > b
- return -1 if a < b

```c
int bsort_compare_int(const void *a, const void *b);

int bsort_compare_float(const void *a, const void *b);

int bsort_compare_double(const void *a, const void *b);

int bsort_compare_string(const void *a, const void *b);
```

The function `bsort_compare_string` is implemented using the `strcmp` function defined in string.h of clib.
