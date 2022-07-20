#if !defined(LINKLIST)
#define LINKLIST

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define NOT_FOUND -1
#define nullptr NULL

typedef int ElementType;
typedef struct linkNode {
  ElementType data;
  struct linkNode* next;
} linkNode_t, *ptr_linkedList;

ptr_linkedList initLinkedList();
int insert_elem_from_head(ptr_linkedList linked_list, ElementType e);
int add(ptr_linkedList linked_list, ElementType e, int loc);
int del(ptr_linkedList linked_list, ElementType* e, int loc);
int get_location_elem(linkNode_t linked_list, int loc, ElementType* e);
int get_value_elem(linkNode_t linked_list, ElementType e, ElementType* loc);
int modify(ptr_linkedList linked_list, ElementType e, int loc);
int get_linked_list_length(linkNode_t linked_list);
#endif