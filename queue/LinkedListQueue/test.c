#include "linked_list_queue.c"
int main() {
  linkedListQueue_t que;
  initLinkedQueue(&que);
  push(&que, 1);
  push(&que, 2);
  push(&que, 3);
  printf("the size is:%d\n", get_size(que));
  ElementType e;
  pop(&que, &e);
  printf("the pop element value is:%d\n", e);
  printf("the size is:%d\n", get_size(que));
  return 0;
}