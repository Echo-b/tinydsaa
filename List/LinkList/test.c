#include "linked_list.c"

int main()
{
  linkNode_t linked_list;
  linked_list = *initLinkedList();
  add(&linked_list, 1, 1);
  add(&linked_list, 2, 2);
  add(&linked_list, 3, 2);
  add(&linked_list, 4, 4);
  add(&linked_list, 5, 3);

  // insert_elem_from_head(&linked_list, 1);
  // insert_elem_from_head(&linked_list, 2);
  // insert_elem_from_head(&linked_list, 3);
  // insert_elem_from_head(&linked_list, 4);
  // insert_elem_from_head(&linked_list, 5);

  int len = get_linked_list_length(linked_list);
  printf("the size is:%d\n", len);
  ElementType e;
  get_location_elem(linked_list, 2, &e);
  printf("the 2th value is:%d\n", e);
  int loc;
  get_value_elem(linked_list, 2, &loc);
  printf("the loc is :%d\n", loc);
  modify(&linked_list, 5, 2);
  get_location_elem(linked_list, 2, &e);
  printf("the 2th value is:%d\n", e);
  del(&linked_list, &e, 2);
  printf("the del element value is:%d\n", e);
  get_location_elem(linked_list, 3, &e);
  printf("the 4th value is:%d\n", e);
  return 0;
}