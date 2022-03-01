#include "define.h"

/**
 * @brief
 *
 * @param t
 * @return int
 */
ptr_max_heap init()
{
  ptr_max_heap h = (ptr_max_heap)malloc(sizeof(maxHeapStruct_t));
  if (!h)
  {
    printf("malloc failed!\n");
    return ERROR;
  }
  h->data = (ElementType *)malloc(sizeof(ElementType) * (CAPACITY + 1));
  if (!h->data)
  {
    printf("malloc failed!\n");
    return ERROR;
  }
  h->capacity = CAPACITY;
  h->size = 0;
  h->data[0] = FlagData;
  printf("init max heap successful!\n");
  return h;
}

/**
 * @brief
 *
 * @param t
 * @param e
 * @return int
 */
int insert(ptr_max_heap h, ElementType e)
{
  if (is_full(h))
  {
    printf("the heap is full!\n");
    return ERROR;
  }
  int i;
  for (i = ++h->size; h->data[i / 2] < e; i /= 2)
    h->data[i] = h->data[i / 2];
  h->data[i] = e;
  printf("insert the node successful!\n");
  return OK;
}

/**
 * @brief
 *
 * @param t
 * @param e
 * @return int
 */
int delmax(ptr_max_heap h)
{
  if (is_empty(h))
  {
    printf("the heap is empty!\n");
    return ERROR;
  }
  ElementType max_data, last_data;
  max_data = h->data[1];
  last_data = h->data[h->size--];
  int parent, child;
  for (parent = 1; parent * 2 <= h->size; parent = child)
  {
    child = parent * 2;
    if (child != h->size && h->data[child] < h->data[child + 1])
      ++child;
    if (last_data < h->data[child])
      h->data[parent] = h->data[child];
    else
      break;
  }
  h->data[parent] = last_data;
  printf("del the max successful!\n");
  return OK;
}

/**
 * @brief
 *
 * @param h
 */
void destory(ptr_max_heap h)
{
  h->capacity = 0;
  h->size = 0;
  free(h->data);
  free(h);
  printf("make empty successful!\n");
}

/**
 * @brief
 *
 * @param h
 */
void make_empty(ptr_max_heap h)
{
  h->capacity = 0;
  h->size = 0;
  h->data = nullptr;
  printf("make empty successful!\n");
}

/**
 * @brief
 *
 * @param h
 * @return ElementType
 */
ElementType findmax(ptr_max_heap h)
{
  if (is_empty(h))
  {
    printf("the heap is empty!\n");
    return ERROR;
  }
  return h->data[1];
}

/**
 * @brief
 *
 * @param h
 * @return true
 * @return false
 */
bool is_empty(ptr_max_heap h)
{
  if (h->size == 0)
    return true;
  else
    return false;
}

/**
 * @brief
 *
 * @param h
 * @return true
 * @return false
 */
bool is_full(ptr_max_heap h)
{
  if (h->size == h->capacity)
    return true;
  else
    return false;
}

/**
 * @brief
 *
 * @param h
 */
void display(ptr_max_heap h)
{
  for (int i = 1; i <= h->size; ++i)
    printf("%3d", h->data[i]);
  printf("\n");
}