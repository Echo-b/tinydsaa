#if !defined(DEQUE)
#define DEQUE

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define nullptr NULL

typedef int ElementType;
typedef struct DeQueueNode
{
  ElementType data;
  struct DeQueueNode *next;
  struct DeQueueNode *pre;
} DeQueueNode_t, *ptr_deQueueNode;

typedef struct DeQueue
{
  ptr_deQueueNode front;
  ptr_deQueueNode rear;
  int size;
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

#endif // DEQUE
