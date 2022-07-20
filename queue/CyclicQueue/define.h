#if !defined(QUEUE)
#define QUEUE

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXQSIZE 3
#define OK 1
#define ERROR 0

typedef int ElementType;

typedef struct Queue {
  ElementType* base;
  int front;
  int rear;
} SqQueue;

int initQueue(SqQueue* Q);
int get_queue_length(SqQueue Q);
int push(SqQueue* Q, ElementType e);
int pop(SqQueue* Q, ElementType* e);
bool is_empty(SqQueue Q);

#endif  // QUEUE
