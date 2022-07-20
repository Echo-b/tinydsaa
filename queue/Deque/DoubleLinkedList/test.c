#include "deque_linkedlist.c"

int main() {
  DeQueue_t deque;
  initDeQueue(&deque);
  push_front(&deque, 1);
  push_front(&deque, 2);
  push_front(&deque, 3);
  push_back(&deque, 4);
  push_back(&deque, 5);
  push_back(&deque, 6);
  ElementType e;
  printf("the size is :%d\n", get_size(deque));
  front(deque, &e);
  printf("the front element is:%d\n", e);
  pop_front(&deque, &e);
  printf("the size is :%d\n", get_size(deque));
  printf("the pop front element is:%d\n", e);
  back(deque, &e);
  printf("the back element is:%d\n", e);
  destory_queue(&deque);
  return 0;
}