#include "max_heap.c"

int main() {
  ptr_max_heap h = init();
  insert(h, 21);
  insert(h, 19);
  insert(h, 68);
  insert(h, 65);
  insert(h, 13);
  insert(h, 14);
  insert(h, 16);
  insert(h, 24);
  insert(h, 26);
  display(h);
  delmax(h);
  display(h);
  printf("the queue top value is:%d\n", findmax(h));
  return 0;
}