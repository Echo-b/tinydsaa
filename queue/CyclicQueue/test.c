#include "queue.c"
int main() {
  SqQueue Q;
  initQueue(&Q);
  push(&Q, 1);
  push(&Q, 2);
  push(&Q, 3);
  printf("the queue length is: %d\n", get_queue_length(Q));
  ElementType e;
  if (pop(&Q, &e))
    printf("the queue length is: %d\n", get_queue_length(Q));
  if (pop(&Q, &e))
    printf("the queue length is: %d\n", get_queue_length(Q));
  if (pop(&Q, &e))
    printf("the queue length is: %d\n", get_queue_length(Q));
  if (is_empty(Q))
    printf("the queue is empty!\n");
  return 0;
}
