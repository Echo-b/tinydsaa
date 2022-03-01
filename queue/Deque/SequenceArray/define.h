#if !defined(SEQUENCEARRAYDEQUE)
#define SEQUENCEARRAYDEQUE

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define nullptr NULL
#define MAXSIZE 200
#define HALFMAXSIZE (MAXSIZE / 2)

typedef int ElementType;
typedef struct DeQueue
{
  int front;
  int rear;
  ElementType *base;
} DeQueue_t;

int initDeQueue(DeQueue_t *deque);
int push_front(DeQueue_t *deque, ElementType e);
int pop_front(DeQueue_t *deque, ElementType *e);
int push_back(DeQueue_t *deque, ElementType e);
int pop_back(DeQueue_t *deque, ElementType *e);
int front(DeQueue_t deque, ElementType *e);
int back(DeQueue_t deque, ElementType *e);
int clear_queue(DeQueue_t *deque);
int destory_queue(DeQueue_t *deque);
int get_size(DeQueue_t deque);
bool is_empty(DeQueue_t deque);

#endif // SEQUENCEARRAYDEQUE
