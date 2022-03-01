#include "define.h"

/**
 * @brief
 *
 * @param deque
 * @return int
 */
int initDeQueue(DeQueue_t *deque)
{
  deque->base = (ElementType *)malloc(sizeof(ElementType) * MAXSIZE);
  if (!deque->base)
  {
    printf("malloc failed!\n");
    return ERROR;
  }
  deque->front = HALFMAXSIZE - 1;
  deque->rear = HALFMAXSIZE;
  printf("init the deque successful!\n");
  return OK;
}

/**
 * @brief
 * the left of array as the front
 * @param deque
 * @param e
 * @return int
 */
int push_front(DeQueue_t *deque, ElementType e)
{
  if (deque->front == -1)
  {
    printf("the deque front part is full!\n");
    return ERROR;
  }
  deque->base[deque->front--] = e;
  printf("push the element in the front of deque successful!\n");
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
  if (deque->front == (HALFMAXSIZE - 1))
  {
    printf("the front part is empty!\n");
    return ERROR;
  }
  *e = deque->base[++deque->front];
  printf("pop the front element in the front of deque successful!\n");
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
  if (deque->rear == MAXSIZE)
  {
    printf("the deque rear part is full!\n");
    return ERROR;
  }
  deque->base[deque->rear++] = e;
  printf("push the element at the back of deque successful!\n");
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
  if (deque->rear == (HALFMAXSIZE))
  {
    printf("the rear part is empty!\n");
    return ERROR;
  }
  *e = deque->base[--deque->rear];
  printf("pop the element at the back of deque successful!\n");
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
  if (deque.front == (HALFMAXSIZE - 1))
  {
    printf("the front part is empty!\n");
    return ERROR;
  }
  *e = deque.base[deque.front + 1];
  printf("get the front element succseeful!\n");
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
  if (deque.rear == (HALFMAXSIZE))
  {
    printf("the rear part is empty!\n");
    return ERROR;
  }
  *e = deque.base[deque.rear - 1];
  printf("get the rear element successful!\n");
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
  deque->base = nullptr;
  deque->front = 0;
  deque->rear = 0;
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
  free(deque->base);
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
  return deque.rear - deque.front - 1;
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
  if (deque.rear == (HALFMAXSIZE) && deque.front == (HALFMAXSIZE - 1))
    return true;
  else
    return false;
}

int main()
{
  DeQueue_t deque;
  initDeQueue(&deque);
  push_front(&deque, 2);
  push_back(&deque, 1);
  printf("the size is:%d\n", get_size(deque));
  ElementType e;
  back(deque, &e);
  printf("the back element value is:%d\n", e);
  front(deque, &e);
  printf("the front element value is:%d\n", e);
  return 0;
}