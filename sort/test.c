#include "sort.c"

int main() {
  ElementType arr[10] = {12, 34, 23, 9, 10, 28, 2, -12, 8, 17};
  // bubble_sort(arr, 10);
  //  insertion_sort(arr, 10);
  //  selection_sort(arr, 10);
  hill_sort(arr, 10);
  // merge_sort(arr, 10);
  dispaly(arr, 10);

  return 0;
}
