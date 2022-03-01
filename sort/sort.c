#include "define.h"
#define swap(x, y)         \
  {                        \
    ElementType __tmp = x; \
    x = y;                 \
    y = __tmp;             \
  }

/**
 * @brief
 *
 * @param arr
 * @param size
 * @return int
 */
int bubble_sort(ElementType *arr, int size)
{
  int change_enable = 0;
  for (int i = 0; i < size - 1; ++i)
  {
    for (int j = 0; j < size - 1 - i; ++j)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
        change_enable = 1;
      }
    }
    if (!change_enable)
      break;
  }
  printf("bubble sort complete!\n");
  return OK;
}

/**
 * @brief
 *
 * @param arr
 * @param size
 * @return int
 */
int selection_sort(ElementType *arr, int size)
{
  for (int i = 0; i < size - 1; ++i)
  {
    int minindex = i;
    for (int j = i + 1; j < size; ++j)
    {
      if (arr[j] < arr[minindex])
        minindex = j;
    }
    if (i != minindex)
      swap(arr[i], arr[minindex]);
  }
  printf("selection sort complete!\n");
  return OK;
}

/**
 * @brief
 *
 * @param arr
 * @param size
 * @return int
 */
int insertion_sort(ElementType *arr, int size)
{
  for (int i = 1; i < size; ++i)
  {
    int key = arr[i];
    int j = i - 1;
    while ((j >= 0) && (arr[j] > key))
    {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
  printf("insertion sort complete!\n");
  return OK;
}

/**
 * @brief
 *
 * @param arr
 * @param size
 * @return int
 */
int hill_sort(ElementType *arr, int size)
{
  int hill_increment = size;
  int i, j;
  do
  {
    hill_increment >>= 1;
    for (i = hill_increment + 1; i < size; ++i)
    {
      int tmp = arr[i];
      for (j = i - hill_increment; (j >= 0) && (tmp < arr[j]); j -= hill_increment)
        arr[j + hill_increment] = arr[j];
      arr[j + hill_increment] = tmp;
    }

  } while (hill_increment > 0);
  printf("hill sort complete!\n");
  return OK;
}

/**
 * @brief
 *
 * @param arr
 * @param size
 * @return int
 */
int merge_sort(ElementType *arr, int size)
{
  ElementType *tmp = (ElementType *)malloc(sizeof(ElementType) * size);
  if (!tmp)
  {
    printf("malloc failed!\n");
    return ERROR;
  }

  int increment ;
  for(increment = 1; increment < size; increment += increment){
    // for(int i = 0)
  }

  // internal_merge_sort(arr, tmp, 0, size - 1);
  printf("merge sort complete!\n");
  return OK;
}

/**
 * @brief
 *
 * @param arr
 * @param tmp
 * @param left
 * @param right
 * @return int
 */
void internal_merge_sort(ElementType *arr, ElementType *tmp, int left, int right)
{
  if (left >= right)
    return;
  int middle = left + (right - left) >> 1;
  internal_merge_sort(arr, tmp, left, middle);
  internal_merge_sort(arr, tmp, middle + 1, right);
  merge_sorted_array(arr, tmp, left, middle, right);
}

/**
 * @brief
 *
 * @param arr
 * @param tmp
 * @param left
 * @param middle
 * @param right
 * @return int
 */
void merge_sorted_array(ElementType *arr, ElementType *tmp, int left, int middle, int right)
{
  int index = 0;
  int i = left;
  int j = middle + 1;
  while (i <= middle && j <= right)
    tmp[index++] = (arr[i] > arr[j]) ? arr[i++] : arr[j++];
  while (i <= middle)
    tmp[index++] = arr[i++];
  while (j <= right)
    tmp[index++] = arr[j++];
  for (int k = 0; k < index; ++k)
    arr[left + k] = tmp[k];
}

int quick_sort(ElementType *arr, int size)
{
}

int heap_sort(ElementType *arr, int size)
{
}

int count_sort(ElementType *arr, int size)
{
}

int bucket_sort(ElementType *arr, int size)
{
}

int radix_sort(ElementType *arr, int size)
{
}

void dispaly(ElementType *arr, int size)
{
  for (int i = 0; i < size; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}