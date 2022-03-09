#include "deque_array.c"

int main() {
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