#include "seq_stack.c"

int main() {
  SqStack s;
  initStack(&s);
  push(&s, 1);
  push(&s, 2);
  push(&s, 3);
  ElementType e;
  if (get_top(s, &e))
    printf("stack top is:%d\n", e);
  if (pop(&s, &e))
    printf("pop element is:%d\n", e);
  if (get_top(s, &e))
    printf("stack top is:%d\n", e);
  pop(&s, &e);
  if (get_top(s, &e))
    printf("stack top is:%d\n", e);
  pop(&s, &e);
  if (is_empty(s))
    printf("the stack is empty\n");
  return 0;
}