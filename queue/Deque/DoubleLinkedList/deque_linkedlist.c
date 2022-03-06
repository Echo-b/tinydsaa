#include "define.h"

/**
 * @brief
 *
 * @param deque
 * @return int
 */
int initDeQueue(DeQueue_t *deque)
{
  deque->front = (ptr_deQueueNode)malloc(sizeof(DeQueueNode_t));
  if (!deque->front)
  {
    printf("malloc failed!\n");
    return ERROR;
  }
  deque->front->next = nullptr;
  deque->front->pre = nullptr;
  deque->front->data = 0;
  deque->rear = deque->front;
  deque->size = 0;
  printf("init the deque successful!\n");
  return OK;
}

/**
 * @brief
 *
 * @param deque
 * @param e
 * @return int
 */
int push_front(DeQueue_t *deque, ElementType e)
{
  ptr_deQueueNode push_node =
      (ptr_deQueueNode)malloc(sizeof(struct DeQueueNode));
  if (!push_node)
  {
    printf("malloc failed!\n");
    return ERROR;
  }
  push_node->data = e;
  push_node->next = deque->front;
  deque->front->pre = push_node;
  deque->front = push_node;
  ++deque->size;
  printf("push element in the front of the deque successful!\n");
  return OK;
}

/**
 * @brief
 *
 * @param deque
 * @param e
 * @return int
 */
int pop_front(DeQueue_t *deque, ElementType *e)
{
  if (is_empty(*deque))
  {
    printf("the queue is empty!\n");
    return ERROR;
  }
  *e = deque->front->data;
  deque->front = deque->front->next;
  deque->front->pre = nullptr;
  --deque->size;
  printf("pop the element from the front successful!\n");
  return OK;
}

/**
 * @brief
 *
 * @param deque
 * @param e
 * @return int
 */
int push_back(DeQueue_t *deque, ElementType e)
{
  ptr_deQueueNode push_node =
      (ptr_deQueueNode)malloc(sizeof(struct DeQueueNode));
  if (!push_node)
  {
    printf("malloc failed!\n");
    return ERROR;
  }
  push_node->data = e;
  push_node->next = deque->rear;
  deque->rear->pre = push_node;
  deque->rear = push_node;
  ++deque->size;
  printf("push element at the back of the deque successful!\n");
  return OK;
}

/**
 * @brief
 *
 * @param deque
 * @param e
 * @return int
 */
int pop_back(DeQueue_t *deque, ElementType *e)
{
  if (is_empty(*deque))
  {
    printf("the queue is empty!\n");
    return ERROR;
  }
  *e = deque->rear->data;
  deque->rear = deque->rear->next;
  deque->rear->pre = nullptr;
  --deque->size;
  printf("pop the element from the front successful!\n");
  return OK;
}

/**
 * @brief
 *
 * @param deque
 * @param e
 * @return int
 */
int front(DeQueue_t deque, ElementType *e)
{
  if (is_empty(deque))
  {
    printf("the deque is empty!\n");
    return ERROR;
  }
  printf("get the front value successful!\n");
  *e = deque.front->data;
  return OK;
}

/**
 * @brief
 *
 * @param deque
 * @param e
 * @return int
 */
int back(DeQueue_t deque, ElementType *e)
{
  if (is_empty(deque))
  {
    printf("the deque is empty!\n");
    return ERROR;
  }
  printf("get the front value successful!\n");
  *e = deque.rear->data;
  return OK;
}

/**
 * @brief
 *
 * @param deque
 * @return int
 */
int clear_queue(DeQueue_t *deque)
{
  deque->front = deque->rear = nullptr;
  deque->size = 0;
  printf("clear the deque successful!\n");
  return OK;
}

/**
 * @brief
 *
 * @param deque
 * @return int
 */
int destory_queue(DeQueue_t *deque)
{
  // free the front part
  while (deque->front->next)
  {
    DeQueueNode_t *tmp = deque->front->next;
    free(deque->front);
    deque->front = tmp;
  }
  // free the rear part
  while (deque->rear->next)
  {
    DeQueueNode_t *tmp = deque->rear->next;
    free(deque->rear);
    deque->rear = tmp;
  }
  printf("destory the deque successful!\n");
  return OK;
}

/**
 * @brief Get the size object
 *
 * @param deque
 * @return int
 */
int get_size(DeQueue_t deque)
{
  return deque.size;
}

/**
 * @brief
 *
 * @param deque
 * @return true
 * @return false
 */
bool is_empty(DeQueue_t deque)
{
  return deque.size == 0;
}
