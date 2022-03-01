#include "define.h"

/**
 * @brief
 *
 * @param l
 * @return int
 */
ptr_cyclinklist init()
{
  ptr_cyclinklist l = (ptr_cyclinklist)malloc(sizeof(CycLNode_t));
  if (!l)
    return nullptr;
  l->next = l;
  printf("init the cyclic list successful!\n");
  return l;
}

/**
 * @brief
 *
 * @param l
 * @return int
 */
int destory(ptr_cyclinklist l)
{
  ptr_cyclinklist p, q;
  p = l->next;
  while (p != l)
  {
    q = p->next;
    free(p);
    p = q;
  }
  free(l);
  printf("destory the cyclic list successful!\n");
  return OK;
}

/**
 * @brief
 *
 * @param l
 * @return true
 * @return false
 */
bool list_empty(ptr_cyclinklist l)
{
  if (l->next == l)
    return true;
  else
    return false;
}

/**
 * @brief Get the elem object
 *
 * @param l
 * @param loc
 * @param e
 * @return int
 */
int get_elem(ptr_cyclinklist l, int loc, ElementType *e)
{
  ptr_cyclinklist p;
  int cur_loc = 1;
  p = l->next;
  while (p != l && cur_loc < loc)
  {
    p = p->next;
    ++cur_loc;
  }
  if (cur_loc < loc || cur_loc > loc)
    return ERROR;
  *e = p->data;
  printf("get the elem successful!\n");
  return OK;
}

/**
 * @brief
 *
 * @param l
 * @param loc
 * @param e
 * @return int
 */
int insert(ptr_cyclinklist l, int loc, ElementType e)
{
  ptr_cyclinklist p, s;
  int cur_loc = 0;
  p = l;
  while (p->next != l && cur_loc < loc - 1)
  {
    p = p->next;
    ++cur_loc;
  }
  if (cur_loc > loc - 1 || cur_loc < loc - 1)
    return ERROR;
  s = (ptr_cyclinklist)malloc(sizeof(CycLNode_t));
  if (!s)
    return ERROR;
  s->data = e;
  s->next = p->next;
  p->next = s;
  printf("insert the node successful!\n");
  return OK;
}

/**
 * @brief
 *
 * @param l
 * @param loc
 * @param e
 * @return int
 */
int del(ptr_cyclinklist l, int loc, ElementType *e)
{
  int cur_loc = 0;
  ptr_cyclinklist p, q;
  p = l;
  while (p->next != l && cur_loc < loc - 1)
  {
    p = p->next;
    ++cur_loc;
  }
  if (cur_loc < loc - 1 || cur_loc > loc - 1)
    return ERROR;
  q = p->next;
  p->next = q->next;
  *e = q->data;
  free(q);
  printf("del the node successful!\n");
  return OK;
}

/**
 * @brief
 *
 * @param l
 * @return int
 */
int len(CycLNode_t l)
{
  ptr_cyclinklist tmp = &l;
  int len = 0;
  while (tmp->next != &l)
  {
    ++len;
    tmp = tmp->next;
  }
  return len;
}