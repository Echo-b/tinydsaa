#include "define.h"

/**
 * @brief
 *
 * @param s
 * @return int
 */
int initStack(SqStack *s)
{
  s->base = (ElementType *)malloc(STACK_INIT_SIZE * sizeof(ElementType));
  if (s->base == nullptr)
  {
    printf("malloc failed!\n");
    return ERROR;
  }
  s->top = s->base;
  s->stack_size = STACK_INIT_SIZE;
  printf("init stack successful!\n");
  return OK;
}

/**
 * @brief Get the top object
 *
 * @param s
 * @param e
 * @return int
 */
int get_top(SqStack s, ElementType *e)
{
  if (is_empty(s))
  {
    printf("the stack is empty!\n");
    return ERROR;
  }
  else
  {
    *e = *(s.top - 1);
    printf("get top element successful!\n");
    return OK;
  }
}

/**
 * @brief
 *
 * @param s
 * @param e
 * @return int
 */
int push(SqStack *s, ElementType e)
{
  /*
   *stack full; increase the space
   */
  if (s->top - s->base >= s->stack_size)
  {
    s->base = (ElementType *)malloc((s->stack_size + STACKINCREMENT) * sizeof(ElementType));
    if (!s->base)
    {
      printf("malloc failed!\n");
      return ERROR;
    }
    s->top = s->base + s->stack_size;
    s->stack_size += STACKINCREMENT;
  }
  *(s->top++) = e;
  printf("add element successful!\n");
  return OK;
}

/**
 * @brief
 *
 * @param s
 * @param e
 * @return int
 */
int pop(SqStack *s, ElementType *e)
{
  if (is_empty(*s))
  {
    printf("the stack is empty!");
    return ERROR;
  }
  *e = *(--s->top);
  printf("pop the element successful!\n");
  return OK;
}

/**
 * @brief
 *
 * @param s
 * @return int
 */
int is_empty(SqStack s)
{
  if (s.base == s.top)
    return OK;
  else
    return ERROR;
}
