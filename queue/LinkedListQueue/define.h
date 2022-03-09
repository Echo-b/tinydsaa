#if !defined(LINKLISTQUEUE)
#define LINKLISTQUEUE

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define nullptr NULL

typedef int ElementType;
typedef struct QueueNode {
  ElementType data;
  struct QueueNode* next;
} QueueNode_t, *ptr_queueNode;

typedef struct linkedListQueue {
  ptr_queueNode front;
  ptr_queueNode rear;
  int size;
} linkedListQueue_t;

int initLinkedQueue(linkedListQueue_t* linked_list_queue);
int push(linkedListQueue_t* linked_list_queue, ElementType e);
int pop(linkedListQueue_t* linked_list_queue, ElementType* e);
int clear_queue(linkedListQueue_t* linked_list_queue);
int destory_queue(linkedListQueue_t* linked_list_queue);
int get_size(linkedListQueue_t linked_list_queue);
bool is_empty(linkedListQueue_t linked_list_queue);

#endif  // LINKLISTQUEUE
