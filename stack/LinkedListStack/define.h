#if !defined(LINKEDLISTSTACK)
#define LINKEDLISTSTACK

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define nullptr NULL

typedef int ElementType;
typedef struct StackNode {
  ElementType data;
  struct StackNode* next;
} StackNode_t;

typedef struct linkedListStack {
  StackNode_t* top;
  int size;
} linkedListStack_t;

int initLinkedStack(linkedListStack_t* linked_list_stack);
int push(linkedListStack_t* linked_list_stack, ElementType e);
int pop(linkedListStack_t* linked_list_stack, ElementType* e);
int get_top(linkedListStack_t linked_list_stack, ElementType* e);
int get_size(linkedListStack_t linked_list_stack);
int clear_stack(linkedListStack_t* linked_list_stack);
int destory_stack(linkedListStack_t* linked_list_stack);
bool is_empty(linkedListStack_t linked_list_stack);

#endif  // LINKEDLISTSTACK
