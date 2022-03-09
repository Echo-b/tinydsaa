#include "define.h"

/**
 * @brief
 *
 * @param linked_list_stack
 * @return int
 */
int initLinkedStack(linkedListStack_t* linked_list_stack) {
  linked_list_stack->top = (StackNode_t*)malloc(sizeof(struct StackNode));
  if (!linked_list_stack->top) {
    printf("malloc failed!\n");
    return ERROR;
  }
  linked_list_stack->size = 0;
  printf("init linked list stack successful!\n");
  return OK;
}

/**
 * @brief
 *
 * @param linked_list_stack
 * @param e
 * @return int
 */
int push(linkedListStack_t* linked_list_stack, ElementType e) {
  StackNode_t* push_node = (StackNode_t*)malloc(sizeof(struct StackNode));
  if (!push_node) {
    printf("malloc failed!\n");
    return ERROR;
  }
  push_node->data = e;
  push_node->next = linked_list_stack->top;
  linked_list_stack->top = push_node;
  ++(linked_list_stack->size);
  printf("push element successful!\n");
  return OK;
}

/**
 * @brief
 *
 * @param linked_list_stack
 * @param e
 * @return int
 */
int pop(linkedListStack_t* linked_list_stack, ElementType* e) {
  if (linked_list_stack->size == 0) {
    printf("linked list stack is empty!\n");
    return ERROR;
  }
  linked_list_stack->top = linked_list_stack->top->next;
  --(linked_list_stack->size);
  printf("pop the element successful!\n");
  return OK;
}

/**
 * @brief Get the top object
 *
 * @param linked_list_stack
 * @param e
 * @return int
 */
int get_top(linkedListStack_t linked_list_stack, ElementType* e) {
  if (linked_list_stack.size == 0) {
    printf("linked list stack is empty!\n");
    return ERROR;
  }
  *e = linked_list_stack.top->data;
  printf("get the top element successful!\n");
  return OK;
}

/**
 * @brief Get the size object
 *
 * @param linked_list_stack
 * @return int
 */
int get_size(linkedListStack_t linked_list_stack) {
  return linked_list_stack.size;
}

/**
 * @brief
 *
 * @param linked_list_stack
 * @return int
 */
int clear_stack(linkedListStack_t* linked_list_stack) {
  while (!is_empty(*linked_list_stack)) {
    pop(&linked_list_stack, nullptr);
  }
  linked_list_stack->top = nullptr;
  linked_list_stack->size = 0;
  printf("clear the stack successful!\n");
  return OK;
}

int destory_stack(linkedListStack_t* linked_list_stack) {
  while (linked_list_stack->top) {
    StackNode_t* tmp = linked_list_stack->top;
    linked_list_stack->top = tmp->next;
    free(tmp);
  }
  printf("destory the stack successful!\n");
  return OK;
}
/**
 * @brief
 *
 * @param linked_list_stack
 * @return true
 * @return false
 */
bool is_empty(linkedListStack_t linked_list_stack) {
  return linked_list_stack.size == 0;
}
