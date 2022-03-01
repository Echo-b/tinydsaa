#ifndef _SORT_
#define _SORT_

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

#define ERROR 0
#define OK 1

int bubble_sort(ElementType *arr, int size);
int selection_sort(ElementType *arr, int size);
int insertion_sort(ElementType *arr, int size);
int hill_sort(ElementType *arr, int size);

int merge_sort(ElementType *arr, int size);
void internal_merge_sort(ElementType *arr, ElementType *tmp, int left, int right);
void merge_sorted_array(ElementType *arr, ElementType *tmp, int left, int middle, int right);

int quick_sort(ElementType *arr, int size);
int heap_sort(ElementType *arr, int size);
int count_sort(ElementType *arr, int size);
int bucket_sort(ElementType *arr, int size);
int radix_sort(ElementType *arr, int size);
void dispaly(ElementType *arr, int size);

#endif