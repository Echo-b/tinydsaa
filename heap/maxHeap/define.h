#ifndef _MAX_HEAP_
#define _MAX_HEAP_

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define nullptr NULL

#define CAPACITY 100
#define FlagData INT_MAX

typedef int ElementType;
struct maxHeapStruct;
typedef struct maxHeapStruct maxHeapStruct_t;
typedef struct maxHeapStruct* ptr_max_heap;

struct maxHeapStruct {
  ElementType* data;
  int capacity;
  int size;
};

ptr_max_heap init();
void destory(ptr_max_heap h);
void make_empty(ptr_max_heap h);
int insert(ptr_max_heap h, ElementType e);
ElementType delmax(ptr_max_heap h);
ElementType findmax(ptr_max_heap h);
bool is_empty(ptr_max_heap h);
bool is_full(ptr_max_heap h);
void display(ptr_max_heap h);
#endif