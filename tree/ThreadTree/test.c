#include "define.h"
#include "thread_tree.c"

int main() {
  ptr_thread_tree tree;
  tree = insert(tree, 8);
  tree = insert(tree, 2);
  tree = insert(tree, 3);
  tree = insert(tree, 1);
  tree = insert(tree, 4);
  tree = insert(tree, 9);
  tree = insert(tree, 10);
  pre = tree;
  inthreading(tree);
  printf("inorder result\n");
  inorder(tree);
  printf("\n");
  ptr_thread_tree tmp = findmin(tree);
  printf("the min node value is:%d\n", tmp->data);
  tmp = findmax(tree);
  printf("the max node value is:%d\n", tmp->data);
  destory_tree(tree);
  return 0;
}