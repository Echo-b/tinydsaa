#include "define.h"

/**
 * @brief
 *
 * @param Q
 * @return int
 */
int initQueue(SqQueue *Q)
{
  Q->base = (ElementType *)malloc(MAXQSIZE * sizeof(ElementType));
  if (!Q->base)
  {
    printf("malloc failed!\n");
    return ERROR;
  }
  Q->front = 0;
  Q->rear = 0;
  printf("init the queue successful!\n");
  return OK;
}

/**
 * @brief Get the queue length object
 *
 * @param Q
 * @return int
 */
int get_queue_length(SqQueue Q)
{
  return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

/**
 * @brief
 * push the element from the queue rear
 * @param Q
 * @param e
 * @return int
 */
int push(SqQueue *Q, ElementType e)
{
  if ((Q->rear + 1) % MAXQSIZE == Q->front)
  {
    printf("the queue is full!\n");
    return ERROR;
  }
  Q->base[Q->rear] = e;
  Q->rear = (Q->rear + 1) % MAXQSIZE;
  printf("push the element successful!\n");
  return OK;
}

/**
 * @brief
 * pop the element from the queue front
 * @param Q
 * @param e
 * @return int
 */
int pop(SqQueue *Q, ElementType *e)
{
  if (is_empty(*Q))
  {
    printf("the queue is empty!\n");
    return ERROR;
  }
  *e = Q->base[Q->front];
  Q->front = (Q->front + 1) % MAXQSIZE;
  printf("pop the element successful!\n");
  return OK;
}

/**
 * @brief
 *
 * @param Q
 * @return int
 */
bool is_empty(SqQueue Q)
{
  if (Q.rear == Q.front)
    return true;
  else
    return false;
}

