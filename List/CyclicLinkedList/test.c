#include "cyc_linkedlist.c"

int main() {
  CycLNode_t l;
  l = *init();
  insert(&l, 1, 1);
  insert(&l, 2, 2);
  insert(&l, 3, 3);
  insert(&l, 4, 4);
  insert(&l, 5, 5);
  ElementType e;
  get_elem(&l, 4, &e);
  printf("the elem value is : %d\n", e);
  return 0;
}