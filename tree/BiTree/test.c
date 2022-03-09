#include "bin_tree.c"
#include "define.h"
int main() {
  ptr_binary_tree tree = nullptr;
  tree = insert(tree, 8);
  tree = insert(tree, 2);
  tree = insert(tree, 3);
  tree = insert(tree, 1);
  tree = insert(tree, 4);
  tree = insert(tree, 9);
  tree = insert(tree, 10);
  printf("the depth is:%d\n", depth(tree));
  printf("preorder result:\n");
  preorder(tree);
  printf("\n");
  printf("inorder result:\n");
  inorder(tree);
  printf("\n");
  printf("postorder result\n");
  postorder(tree);
  printf("\n");
  printf("levelorder result\n");
  levelorder(tree);
  printf("\n");
  ptr_binary_tree tmp = findmax(tree);
  printf("the max ele value is:%d\n", tmp->elm);
  tmp = findmin(tree);
  printf("the min ele value is:%d\n", tmp->elm);
  tmp = find(tree, 7);
  printf("the find node value is:%p\n", tmp);
  // tree = del(tree, 7);
  tree = del(tree, 2);
  printf("lever order result\n");
  levelorder(tree);
  printf("\n");
  // destory_tree(t);
  return 0;
}
