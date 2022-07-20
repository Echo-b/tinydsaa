#if !defined(_SEARCH_)
#define _SEARCH_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR 0
#define OK 1
typedef int ElementType;

int sequential_search(ElementType* arr, ElementType key, int size);
int sequential_search2(ElementType* arr, ElementType key, int size);
int binary_search(ElementType* arr, ElementType key, int size);
int interpolation_search(ElementType* arr, ElementType key, int size);
int fibonacci_search(ElementType* arr, ElementType key, int size);

#endif  // _SEARCH_
