#include <stdio.h>
#include <stdlib.h>

#include "define.h"

/**
 * @brief
 * init the dynamic sequential list
 * @param dynamic_sqlist
 * @return error or ok
 */
int init(dynamic_sqlist_t *dynamic_sqlist)
{
  dynamic_sqlist->data = (ElementType *)malloc(sizeof(ElementType) * initSize);
  if (!dynamic_sqlist->data)
  {
    printf("malloc failed!");
    return ERROR;
  }
  dynamic_sqlist->cur_len = 0;
  dynamic_sqlist->max_size = maxSize;
  printf("init successful!\n");
  return OK;
}

/**
 * @brief
 * add element in the apoint location
 * @param dynamic_sqlist
 * @param e
 * @param loc
 * @return error or ok
 */
int add(dynamic_sqlist_t *dynamic_sqlist, ElementType e, int loc)
{
  if (dynamic_sqlist->cur_len >= maxSize)
  {
    // realloc more space to storage more element
    ElementType *newbase = (ElementType *)realloc(dynamic_sqlist->data, (size_t)(maxSize + addSize) * sizeof(ElementType));
    if (!dynamic_sqlist)
    {
      printf("realloc failed!\n");
      return ERROR;
    }
    dynamic_sqlist->data = newbase;
    dynamic_sqlist->max_size += addSize;
    printf("realloc successful!\n");
  }
  if (loc < 1 && loc > dynamic_sqlist->cur_len + 1)
  {
    printf("the location error!\n");
    return ERROR;
  }
  for (int i = dynamic_sqlist->cur_len - 1; i >= loc; --i)
  {
    dynamic_sqlist->data[i + 1] = dynamic_sqlist->data[i];
  }
  dynamic_sqlist->data[loc - 1] = e;
  ++dynamic_sqlist->cur_len;
  printf("add function successful!\n");
  return OK;
}

/**
 * @brief
 * delete appoint location element
 * @param dynamic_sqlist
 * @param loc
 * @return int
 */

int del(dynamic_sqlist_t *dynamic_sqlist, int loc)
{
  if (loc > dynamic_sqlist->cur_len + 1 && loc < 1)
  {
    printf("location error!\n");
    return ERROR;
  }
  else
  {
    for (int i = loc; i <= dynamic_sqlist->cur_len; ++i)
    {
      dynamic_sqlist->data[i - 1] = dynamic_sqlist->data[i];
    }
    --dynamic_sqlist->cur_len;
  }
  printf("delete element successful!\n");
  return OK;
}

/**
 * @brief
 * modify appoint location element value
 * @param dynamic_sqlist
 * @param e
 * @param loc
 * @return int
 */
int modify(dynamic_sqlist_t *dynamic_sqlist, ElementType e, int loc)
{
  if (loc < 1 && loc > dynamic_sqlist->cur_len + 1)
  {
    printf("error location!\n");
    return ERROR;
  }
  dynamic_sqlist->data[loc - 1] = e;
  printf("modify success!\n");
  return OK;
}

/**
 * @brief
 * find the element first location
 * @param dynamic_sqlist
 * @param e
 * @return int
 */
int find(dynamic_sqlist_t dynamic_sqlist, ElementType e)
{
  int res_index = -1;
  for (int i = 0; i < dynamic_sqlist.max_size; ++i)
  {
    if (dynamic_sqlist.data[i] == e)
    {
      res_index = i;
      break;
    }
  }
  if (res_index != -1)
  {
    printf("find the element location!\n");
    return res_index + 1;
  }
  printf("not find the element location!\n");
  return NOT_FOUND;
}

/**
 * @brief
 *
 * @param dynamic_sqlist_t
 * @return int
 */
int clear_sqlist(dynamic_sqlist_t *dynamic_sqlist)
{
  dynamic_sqlist->cur_len = 0;
  printf("clear the sqlist successful!\n");
  return OK;
}

/**
 * @brief
 *
 * @param dynamic_sqlist_t
 * @return int
 */
int destory_sqlist(dynamic_sqlist_t *dynamic_sqlist)
{
  dynamic_sqlist->cur_len = 0;
  dynamic_sqlist->data = nullptr;
  dynamic_sqlist->max_size = 0;
  printf("destory the sqlist successful!\n");
  return OK;
}

/**
 * @brief
 *
 * @param dynamic_sqlist
 */
void display(dynamic_sqlist_t dynamic_sqlist)
{
  for (int i = 0; i < dynamic_sqlist.cur_len; ++i)
    printf("%3d", dynamic_sqlist.data[i]);
  printf("\n");
}

/**
 * @brief
 *
 * @param first
 * @param second
 * @param com_sqlist
 * @return int
 */
int merge_sqlist(dynamic_sqlist_t first, dynamic_sqlist_t second, dynamic_sqlist_t *com_sqlist)
{
  com_sqlist->cur_len = first.cur_len + second.cur_len;
  com_sqlist->data = (ElementType *)malloc(sizeof(ElementType) *
                                           (first.cur_len + second.cur_len));
  if (!com_sqlist->data)
  {
    printf("malloc failed!\n");
    return -1;
  }

  int i = 0, j = 0;
  int index = 0;
  while (i < first.cur_len || j < second.cur_len)
  {
    if (i >= first.cur_len)
    {
      com_sqlist->data[index] = second.data[j];
      ++j;
      ++index;
    }
    else if (j >= second.cur_len)
    {
      com_sqlist->data[index] = first.data[i];
      ++i;
      ++index;
    }
    else if (first.data[i] >= second.data[j])
    {
      com_sqlist->data[index] = second.data[j];
      ++j;
      ++index;
    }
    else
    {
      com_sqlist->data[index] = first.data[i];
      ++i;
      ++index;
    }
  }
  printf("merge the sqlist successful!\n");
  return OK;
}

