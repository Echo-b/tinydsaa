#include "double_linked_list.c"

int main()
{
  doublelinkNode_t head;
  head = *initDoubleLinkedList();
  add(&head, 1, 1);
  add(&head, 2, 2);
  add(&head, 3, 1);
  add(&head, 4, 2);
  add(&head, 5, 1);
  add(&head, 6, 2);
  ElementType e;
  printf("the size is:%d\n", get_double_linked_list_length(head));
  get_location_elem(head, 5, &e);
  printf("the 5th node value is:%d\n", e);
  int loc;
  get_value_elem(head, 4, &loc);
  printf("the node value equal 4 location is:%d\n", loc);
  modify(&head, 7, 3);
  del(&head, 3, &e);
  printf("the del node value is %d\n", e);
  printf("the size is:%d\n", get_double_linked_list_length(head));
  return 0;
}