#include "openadr_hash.c"

int main() {
  hashTable h = init(17);
  insert(h, 23);
  insert(h, 19);
  insert(h, 76);
  insert(h, 45);
  insert(h, 10);
  insert(h, 32);
  insert(h, 123);
  insert(h, 79);
  insert(h, 81);
  insert(h, 7);
  display(h);
  return 0;
}