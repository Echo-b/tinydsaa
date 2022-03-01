#ifndef _CYCLIC_LINKED_LIST
#define _CYCLIC_LINKED_LIST

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define nullptr NULL

struct CycLNode;
typedef struct CycLNode *ptr_cyclinklist;
typedef struct CycLNode CycLNode_t;
typedef int ElementType;

struct CycLNode
{
  ElementType data;
  struct CycLNode *next;
};

ptr_cyclinklist init();
int destory(ptr_cyclinklist l);
bool list_empty(ptr_cyclinklist l);
int get_elem(ptr_cyclinklist l, int loc, ElementType *e);
int insert(ptr_cyclinklist l, int loc, ElementType e);
int del(ptr_cyclinklist l, int loc, ElementType *e);
int len(CycLNode_t l);
#endif