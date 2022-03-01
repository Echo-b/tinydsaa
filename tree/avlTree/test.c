#include "avl_tree.c"

int main()
{
  ptr_avltree tree;
  tree = insert(tree, 10);
  tree = insert(tree, 8);
  tree = insert(tree, 2);
  tree = insert(tree, 3);
  tree = insert(tree, 1);
  tree = insert(tree, 4);
  tree = insert(tree, 9);
  tree = insert(tree, 11);
  printf("inordre travle\n");
  inorder(tree);
  printf("\n");
  ptr_avltree tmp = del(tree, 2);
  printf("inordre travle\n");
  inorder(tmp);
  printf("\n");
  return 0;
}