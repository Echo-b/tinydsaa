#ifndef _BIN_HEAP_
#define _BIN_HEAP_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define ERROR 0
#define OK 1
#define nullptr NULL

#define CAPACITY 100
#define FlagData INT_MIN

typedef int ElementType;
struct HeapStruct;
typedef struct HeapStruct HeapStruct_t;
typedef struct HeapStruct *ptr_priority_queue;

struct HeapStruct
{
  ElementType *data;
  int capacity;
  int size;
};

ptr_priority_queue init();
void destory(ptr_priority_queue h);
void make_empty(ptr_priority_queue h);
int insert(ptr_priority_queue h, ElementType e);
ElementType delmin(ptr_priority_queue h);
ElementType findmin(ptr_priority_queue h);
bool is_empty(ptr_priority_queue h);
bool is_full(ptr_priority_queue h);
void display(ptr_priority_queue h);
#endif