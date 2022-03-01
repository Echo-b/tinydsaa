#if !defined(STACK)
#define STACK

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define nullptr NULL

typedef int ElementType;

typedef struct Stack
{
  ElementType *base;
  ElementType *top;
  int stack_size;
} SqStack;

int initStack(SqStack *s);
int get_top(SqStack s, ElementType *e);
int push(SqStack *s, ElementType e);
int pop(SqStack *s, ElementType *e);
int is_empty(SqStack s);

#endif // STACK
