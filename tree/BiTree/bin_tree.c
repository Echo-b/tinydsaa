#include "../queue/define.h"
#include "../queue/queue.c"
#include "define.h"

/**
 * @brief
 *
 * @param bin_tree
 * @param e
 * @return ptr_binary_tree
 */
ptr_binary_tree insert(ptr_binary_tree bin_tree, DataType e)
{
  if (!bin_tree)
  {
    bin_tree = malloc(sizeof(struct BinTreeNode));
    if (!bin_tree)
    {
      printf("malloc failed!\n");
      return nullptr;
    }
    bin_tree->elm = e;
    bin_tree->lchild = bin_tree->rchild = nullptr;
  }
  else if (e < bin_tree->elm)
    bin_tree->lchild = insert(bin_tree->lchild, e);
  else
    bin_tree->rchild = insert(bin_tree->rchild, e);
  return bin_tree;
}

/**
 * @brief
 *
 * @param bin_tree
 */
void postorder(ptr_binary_tree bin_tree)
{
  if (bin_tree)
  {
    preorder(bin_tree->lchild);
    preorder(bin_tree->rchild);
    visit(bin_tree);
  }
}

/**
 * @brief
 *
 * @param bin_tree
 */
void inorder(ptr_binary_tree bin_tree)
{
  if (bin_tree)
  {
    preorder(bin_tree->lchild);
    visit(bin_tree);
    preorder(bin_tree->rchild);
  }
}

/**
 * @brief
 *
 * @param bin_tree
 */
void preorder(ptr_binary_tree bin_tree)
{
  if (bin_tree)
  {
    visit(bin_tree);
    preorder(bin_tree->lchild);
    preorder(bin_tree->rchild);
  }
}

/**
 * @brief
 *
 * @param bin_tree
 */
void levelorder(ptr_binary_tree bin_tree)
{
  if (!bin_tree)
  {
    printf("the tree is empty!\n");
    return;
  }
  SqQueue Q;
  ptr_binary_tree e;
  initQueue(&Q);
  push(&Q, bin_tree);
  while (!is_empty(Q))
  {
    pop(&Q, &e);
    visit(e);
    if (e->lchild)
      push(&Q, e->lchild);
    if (e->rchild)
      push(&Q, e->rchild);
  }
}

/**
 * @brief
 *
 * @param bin_tree
 */
void visit(ptr_binary_tree bin_tree) { printf("%3d", bin_tree->elm); }

/**
 * @brief
 *
 * @param bin_tree
 * @return int
 */
int destory_tree(ptr_binary_tree bin_tree)
{
  if (bin_tree)
  {
    destory_tree(bin_tree->lchild);
    destory_tree(bin_tree->rchild);
    free(bin_tree);
    printf("destory tree successful!\n");
  }
  return OK;
}

/**
 * @brief
 *
 * @param bin_tree
 * @return int
 */
int depth(ptr_binary_tree bin_tree)
{
  if (!bin_tree)
    return 0;
  else
  {
    int rdepth = depth(bin_tree->rchild);
    int ldepth = depth(bin_tree->lchild);
    return rdepth > ldepth ? rdepth + 1 : ldepth + 1;
  }
}

/**
 * @brief
 *
 * @param bin_tree
 * @return ptr_binary_tree
 */
ptr_binary_tree findmin(ptr_binary_tree bin_tree)
{
  /*******  recursive code ******
   *if (!bin_tree)
   *  return nullptr;
   *ptr_binary_tree t = bin_tree;
   *if (t->lchild == nullptr)
   *  return t;
   *else
   *  return findmin(t->lchild);
   *******************************/
  if (bin_tree)
    while (bin_tree->lchild)
      bin_tree = bin_tree->lchild;
  return bin_tree;
}

/**
 * @brief
 *
 * @param bin_tree
 * @return ptr_binary_tree
 */
ptr_binary_tree findmax(ptr_binary_tree bin_tree)
{
  /*******  recursive code ******
   *if (!bin_tree)
   *  return nullptr;
   *ptr_binary_tree t = bin_tree;
   *if (t->rchild == nullptr)
   *  return t;
   *else
   *  return findmax(t->rchild);
   *******************************/
  if (bin_tree)
    while (bin_tree->rchild)
      bin_tree = bin_tree->rchild;
  return bin_tree;
}

/**
 * @brief
 *
 * @param bin_tree
 * @param e
 * @return ptr_binary_tree
 */
ptr_binary_tree find(ptr_binary_tree bin_tree, DataType e)
{
  if (!bin_tree)
    return nullptr;
  if (bin_tree->elm == e)
    return bin_tree;
  else if (bin_tree->elm > e)
    return find(bin_tree->lchild, e);
  else
    return find(bin_tree->rchild, e);
}

/**
 * @brief
 *
 * @param bin_tree
 * @param e
 * @return int
 */
ptr_binary_tree del(ptr_binary_tree bin_tree, DataType e)
{
  ptr_binary_tree tmp;
  if (!(bin_tree))
    printf("the tree is empty!\n");
  else if (e < bin_tree->elm)
    bin_tree->lchild = del(bin_tree->lchild, e);
  else if (e > bin_tree->elm)
    bin_tree->rchild = del(bin_tree->rchild, e);
  else if (bin_tree->lchild && bin_tree->rchild)
  {
    tmp = findmin(bin_tree->rchild);
    bin_tree->elm = tmp->elm;
    bin_tree->rchild = del(bin_tree->rchild, bin_tree->elm);
  }
  else
  {
    tmp = bin_tree;
    if (!bin_tree->lchild)
      bin_tree = bin_tree->rchild;
    if (!bin_tree->rchild)
      bin_tree = bin_tree->lchild;
    free(tmp);
  }
  return bin_tree;
}
