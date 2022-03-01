#include "search.h"

/**
 * @brief
 *
 * @param arr
 * @param key
 * @param size
 * @return int
 */
int sequential_search(ElementType *arr, ElementType key, int size)
{
  for (int i = 0; i < size; ++i)
  {
    if (arr[i] == key)
      return i;
  }
  printf("search successful!\n");
  return ERROR;
}

/**
 * @brief
 * if return 0 => failed!
 * arr[0] is as a sentry
 * @param arr
 * @param key
 * @param size
 * @return int
 */
int sequential_search2(ElementType *arr, ElementType key, int size)
{
  arr[0] = key;
  int i = size - 1;
  while (arr[i] != key)
    --i;
  return i;
}

/**
 * @brief
 *
 * @param array
 * @param type
 * @return int
 */
int binary_search(ElementType *arr, ElementType key, int size)
{
  int left = 0, right = size - 1;
  while (left <= right)
  {
    int mid = left + (right - left) >> 1;
    if (arr[mid] == key)
    {
      printf("search successful!\n");
      return mid;
    }
    else if (arr[mid] > key)
      right = mid - 1;
    else
      left = mid + 1;
  }
  return ERROR;
}

/**
 * @brief
 * when the table is big and datum is evenly distributed
 * the interpolation forum is [(key - arr[left]) / (arr[right] - arr[left])]
 * @param arr
 * @param key
 * @param size
 * @return int
 */
int interpolation_search(ElementType *arr, ElementType key, int size)
{
  int left = 0, right = size - 1;
  while (left <= right)
  {
    int mid = left + (right - left) * ((key - arr[left]) / (arr[right] - arr[left]));
    if (arr[mid] == key)
    {
      printf("search successful!\n");
      return mid;
    }
    else if (arr[mid] > key)
      right = mid - 1;
    else
      left = mid + 1;
  }
  return ERROR;
}

/**
 * @brief
 *
 * @param arr
 * @param key
 * @param size
 * @return int
 */
int fibonacci_search(ElementType *arr, ElementType key, int size)
{
}