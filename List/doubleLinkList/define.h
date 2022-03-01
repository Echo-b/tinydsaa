#if !defined(DOUBLE_LINKED_LIST)
#define DOUBLE_LINKED_LIST

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define NOT_FOUND -1
#define nullptr NULL

typedef int ElementType;
typedef struct doubleLinkNode
{
  ElementType data;
  struct doubleLinkNode *pre;
  struct doubleLinkNode *next;
} doublelinkNode_t, *ptr_double_linkedList;

ptr_double_linkedList initDoubleLinkedList();
int add(ptr_double_linkedList double_linked_list, ElementType e, int loc);
int del(ptr_double_linkedList double_linked_list, int loc, ElementType *e);
int get_location_elem(doublelinkNode_t double_linked_list, int loc, ElementType *e);
int get_value_elem(doublelinkNode_t double_linked_list, ElementType e, int *loc);
int modify(ptr_double_linkedList double_linked_list, ElementType e, int loc);
int get_double_linked_list_length(doublelinkNode_t double_linked_list);

#endif // DOUBLE_LINKED_LIST
