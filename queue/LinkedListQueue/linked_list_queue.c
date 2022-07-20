#include "define.h"

/**
 * @brief
 * the init node is not the first aviliable node, instead of the
 * linked_list_queue->front->next is aviliable
 * @param linked_list_queue
 * @return int
 */
int initLinkedQueue(linkedListQueue_t* linked_list_queue) {
  linked_list_queue->front = (ptr_queueNode)malloc(sizeof(struct QueueNode));
  if (!linked_list_queue->front) {
    printf("malloc failed!\n");
    return ERROR;
  }
  linked_list_queue->front->next = nullptr;
  linked_list_queue->rear = linked_list_queue->front;
  linked_list_queue->size = 0;
  printf("init the linked list queue successful!\n");
  return OK;
}

/**
 * @brief
 *
 * @param linked_list_queue
 * @param e
 * @return int
 */
int push(linkedListQueue_t* linked_list_queue, ElementType e) {
  ptr_queueNode push_node = (ptr_queueNode)malloc(sizeof(struct QueueNode));
  if (!push_node) {
    printf("malloc failed!\n");
    return ERROR;
  }
  push_node->data = e;
  push_node->next = nullptr;
  linked_list_queue->rear->next = push_node;
  linked_list_queue->rear = push_node;
  ++(linked_list_queue->size);
  printf("push the element successful!\n");
}

/**
 * @brief
 *
 * @param linked_list_queue
 * @param e
 * @return int
 */
int pop(linkedListQueue_t* linked_list_queue, ElementType* e) {
  if (is_empty(*linked_list_queue)) {
    printf("the queue is empty!\n");
    return ERROR;
  }
  QueueNode_t* pop_node = linked_list_queue->front->next;
  *e = pop_node->data;
  linked_list_queue->front->next = pop_node->next;
  if (linked_list_queue->rear == pop_node)
    linked_list_queue->rear = linked_list_queue->front;
  --linked_list_queue->size;
  free(pop_node);
  printf("pop the element successful!\n");
  return OK;
}

/**
 * @brief
 * let the queue value equal zero
 * @param linke_list_queue
 * @return int
 */
int clear_queue(linkedListQueue_t* linked_list_queue) {
  linked_list_queue->front = linked_list_queue->rear = nullptr;
  linked_list_queue->size = 0;
  printf("clear the queue is successful!\n");
  return OK;
}

int destory_queue(linkedListQueue_t* linked_list_queue) {
  while (linked_list_queue->front) {
    linked_list_queue->rear = linked_list_queue->front;
    free(linked_list_queue->front);
    linked_list_queue->front = linked_list_queue->rear->next;
  }
  printf("destory the queue successful!\n");
  return OK;
}

int get_size(linkedListQueue_t linked_list_queue) {
  return linked_list_queue.size;
}

bool is_empty(linkedListQueue_t linked_list_queue) {
  return linked_list_queue.size == 0;
}
