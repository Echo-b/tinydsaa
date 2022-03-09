#include "hashtlb.c"

int main() {
  hashTable h = init(5);
  insert(h, 19);
  insert(h, 21);
  insert(h, 32);
  insert(h, 12);
  insert(h, 11);
  display(h);
  destory(h);
  return 0;
}