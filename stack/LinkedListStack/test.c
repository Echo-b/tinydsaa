#include "linked_list_stack.c"

int main()
{
  linkedListStack_t s;
  initLinkedStack(&s);
  push(&s, 1);
  push(&s, 2);
  push(&s, 3);
  ElementType e;
  get_top(s, &e);
  printf("the top element value is:%d\n", e);
  pop(&s, &e);
  printf("the pop element value is:%d\n", e);
  get_top(s, &e);
  printf("the top element value is:%d\n", e);
  printf("the stack size is:%d\n", get_size(s));
  pop(&s, &e);
  printf("the pop element value is:%d\n", e);
  get_top(s, &e);
  printf("the top element value is:%d\n", e);
  printf("the stack size is:%d\n", get_size(s));
  pop(&s, &e);
  if (is_empty(s))
    printf("the stack is empty\n");
  return 0;
}