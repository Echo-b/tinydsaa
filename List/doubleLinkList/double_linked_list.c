#include "define.h"

/**
 * @brief
 * init the double linked list
 * @return ptr_double_linkedList
 */
ptr_double_linkedList initDoubleLinkedList() {
  ptr_double_linkedList double_linked_list = (ptr_double_linkedList)malloc(sizeof(doublelinkNode_t));
  if (!double_linked_list) {
    printf("malloc failed!\n");
    return nullptr;
  }
  double_linked_list->data = 0;
  double_linked_list->pre = nullptr;
  double_linked_list->next = nullptr;
  printf("init successful!\n");
  return double_linked_list;
}

/**
 * @brief
 *
 * @param double_linked_list
 * @param e
 * @param loc
 * @return int
 */
int add(ptr_double_linkedList double_linked_list, ElementType e, int loc) {
  int cur_loc = 0;
  ptr_double_linkedList tmp = double_linked_list;
  while (tmp && cur_loc < loc - 1) {
    ++cur_loc;
    tmp = tmp->next;
  }
  if (tmp == nullptr || cur_loc > loc - 1) {
    printf("error location!\n");
    return ERROR;
  }
  ptr_double_linkedList insert_node = (ptr_double_linkedList)malloc(sizeof(doublelinkNode_t));
  if (!insert_node) {
    printf("malloc failed!\n");
    return ERROR;
  }
  insert_node->data = e;
  insert_node->next = tmp->next;
  insert_node->pre = tmp;
  if (tmp->next)
    tmp->next->pre = insert_node;
  tmp->next = insert_node;
  printf("add the element successful!\n");
  return OK;
}

/**
 * @brief
 *
 * @param double_linked_list
 * @param loc
 * @return int
 */
int del(ptr_double_linkedList double_linked_list, int loc, ElementType* e) {
  if (!double_linked_list->next) {
    printf("the double linked list is empty!\n");
    return ERROR;
  }
  int cur_loc = 0;
  ptr_double_linkedList tmp = double_linked_list;
  while (tmp->next && cur_loc < loc - 1) {
    ++cur_loc;
    tmp = tmp->next;
  }
  if (tmp == nullptr || cur_loc > loc - 1) {
    printf("error location!\n");
    return ERROR;
  }
  *e = tmp->next->data;
  tmp->next = tmp->next->next;
  tmp->next->pre = tmp;
  printf("del the element successful!\n");
  return OK;
}

/**
 * @brief Get the location elem object
 *
 * @param double_linked_list
 * @param loc
 * @param e
 * @return int
 */
int get_location_elem(doublelinkNode_t double_linked_list, int loc, ElementType* e) {
  ptr_double_linkedList res;
  res = &double_linked_list;
  int cur_loc = 1;
  res = res->next;
  while (res && cur_loc < loc) {
    ++cur_loc;
    res = res->next;
  }
  if (res == nullptr || cur_loc > loc) {
    printf("not find the appoint location!\n");
    return ERROR;
  }

  printf("find the appoint location\n");
  *e = res->data;
  return OK;
}

/**
 * @brief Get the value elem object
 *
 * @param linked_list
 * @param e
 * @return doublelinkNode_t
 */
int get_value_elem(doublelinkNode_t double_linked_list, ElementType e, int* loc) {
  ptr_double_linkedList res = &double_linked_list;
  int cur_loc = 1;
  res = res->next;
  while (res && res->data != e) {
    ++cur_loc;
    res = res->next;
  }
  if (res == nullptr) {
    printf("not find the appoint value node!\n");
    *loc = -1;
    return ERROR;
  }
  *loc = cur_loc;
  printf("find the appoint value node\n");
  return OK;
}

/**
 * @brief
 *
 * @param linked_list
 * @param e
 * @param loc
 * @return int
 */
int modify(ptr_double_linkedList double_linked_list, ElementType e, int loc) {
  ptr_double_linkedList tmp = double_linked_list->next;
  int cur_loc = 1;
  while (tmp && cur_loc < loc) {
    ++cur_loc;
    tmp = tmp->next;
  }
  if (tmp == nullptr) {
    printf("not find the modify value\n");
    return ERROR;
  }
  tmp->data = e;
  printf("modify successful!\n");
  return OK;
}

/**
 * @brief Get the linked list length object
 *
 * @param linked_list
 * @return int
 */
int get_double_linked_list_length(doublelinkNode_t double_linked_list) {
  ptr_double_linkedList tmp = &double_linked_list;
  int len = 0;
  tmp = tmp->next;  // pass by the head node
  while (tmp) {
    printf("%3d\n", tmp->data);
    ++len;
    tmp = tmp->next;
  }
  return len;
}
