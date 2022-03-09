#include "define.h"

/**
 * @brief
 * init the linked_list;
 * @return ptr_linkedList
 */
ptr_linkedList initLinkedList() {
  ptr_linkedList linked_list = (ptr_linkedList)malloc(sizeof(linkNode_t));
  if (!linked_list) {
    printf("malloc failed");
    return nullptr;
  }

  linked_list->next = nullptr;
  printf("init the linked list successful!\n");
  return linked_list;
}

/**
 * @brief
 * insert element from head
 * @param linked_list
 * @param e
 * @return int
 */
int insert_elem_from_head(ptr_linkedList linked_list, ElementType e) {
  ptr_linkedList insert_node = (ptr_linkedList)malloc(sizeof(linkNode_t));
  if (!insert_node) {
    printf("malloc failed!\n");
    return ERROR;
  }
  insert_node->data = e;
  insert_node->next = linked_list->next;
  linked_list->next = insert_node;
  printf("insert element node from head successful!\n");
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
int add(ptr_linkedList linked_list, ElementType e, int loc) {
  ptr_linkedList tmp = linked_list;
  int cur_loc = 0;
  while (tmp && cur_loc < loc - 1) {
    ++cur_loc;
    tmp = tmp->next;
  }
  if (!tmp || cur_loc > loc - 1) {
    printf("error appoint location\n");
    return ERROR;
  }
  ptr_linkedList insert_node = (ptr_linkedList)malloc(sizeof(linkNode_t));
  if (!insert_node) {
    printf("malloc failed!\n");
    return ERROR;
  }
  insert_node->data = e;
  insert_node->next = tmp->next;
  tmp->next = insert_node;
  printf("add the element at the appoint location successful\n");
  return OK;
}

/**
 * @brief
 *
 * @param linked_list
 * @param loc
 * @return int
 */
int del(ptr_linkedList linked_list, ElementType* e, int loc) {
  ptr_linkedList tmp = linked_list;
  int cur_loc = 0;
  while (tmp->next && cur_loc < loc - 1) {
    ++cur_loc;
    tmp = tmp->next;
  }
  if (!(tmp->next) || cur_loc > loc - 1) {
    printf("error appoint location\n");
    return ERROR;
  }
  ptr_linkedList del_node = tmp->next;
  tmp->next = del_node->next;
  *e = del_node->data;
  free(del_node);
  printf("del the element at the appoint location successful\n");
  return OK;
}

/**
 * @brief Get the location elem object
 *
 * @param linked_list
 * @param loc
 * @return linkNode_t
 */
int get_location_elem(linkNode_t linked_list, int loc, ElementType* e) {
  ptr_linkedList res = &linked_list;
  int cur_loc = 1;
  res = res->next;  // pass by the head node
  while (res && cur_loc < loc) {
    ++cur_loc;
    res = res->next;
  }
  if (res == nullptr || cur_loc > loc) {
    printf("not find the appoint location\n");
    return ERROR;
  }
  *e = res->data;
  printf("find the right location\n");
  return OK;
}

/**
 * @brief Get the value elem object
 *
 * @param linked_list
 * @param e
 * @return linkNode_t
 */
int get_value_elem(linkNode_t linked_list, ElementType e, ElementType* loc) {
  ptr_linkedList res = &linked_list;
  int cur_loc = 1;
  res = res->next;
  while (res && res->data != e) {
    res = res->next;
    ++cur_loc;
  }
  if (res == nullptr) {
    *loc = NOT_FOUND;
    printf("not find the location can satisfy\n");
    return ERROR;
  }
  *loc = cur_loc;
  printf("get the right value node\n");
  return OK;
}

/**
 * @brief
 * modify the appoint location element value to e
 * @param linked_list
 * @param e
 * @param loc
 * @return int
 */

int modify(ptr_linkedList linked_list, ElementType e, int loc) {
  ptr_linkedList tmp = linked_list->next;
  int cur_loc = 1;
  while (tmp && cur_loc < loc) {
    ++cur_loc;
    tmp = tmp->next;
  }
  if (tmp == nullptr || cur_loc > loc) {
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

int get_linked_list_length(linkNode_t linked_list) {
  int len = 0;
  ptr_linkedList tmp = &(linked_list);
  tmp = tmp->next;
  while (tmp) {
    ++len;
    printf("%3d", tmp->data);
    tmp = tmp->next;
  }
  return len;
}
