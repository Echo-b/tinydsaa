#include "define.h"
/**
 * @brief
 *
 * @param t
 * @return ptr_avltree
 */
void make_empty(ptr_avltree t) {
  if (t) {
    make_empty(t->lchild);
    make_empty(t->rchild);
    free(t);
  }
  printf("make empty the tree successful!\n");
}

/**
 * @brief
 *
 * @param t
 * @return int
 */
int height(ptr_avltree t) {
  if (!t)
    return -1;
  return t->height;
}

/**
 * @brief
 * inorder travel
 * @param t
 */
void inorder(ptr_avltree t) {
  if (t) {
    inorder(t->lchild);
    printf("%d ", retrieve(t));
    inorder(t->rchild);
  }
}

/**
 * @brief
 *
 * @param t
 * @param e
 * @return Position
 */
Position find(ptr_avltree t, ElementType e) {
  if (!t)
    return nullptr;
  if (t->data == e)
    return t;
  else if (t->data < e)
    return find(t->lchild, e);
  else if (t->data > e)
    return find(t->rchild, e);
}

/**
 * @brief
 *
 * @param t
 * @return Position
 */
Position findmin(ptr_avltree t) {
  if (t)
    while (t->lchild)
      t = t->lchild;
  return t;
}

/**
 * @brief
 *
 * @param t
 * @return Position
 */
Position findmax(ptr_avltree t) {
  if (t)
    while (t->rchild)
      t = t->rchild;
  return t;
}

/**
 * @brief
 *
 * @param t
 * @param e
 * @return ptr_avltree
 */
ptr_avltree insert(ptr_avltree t, ElementType e) {
  if (!t) {
    t = (ptr_avltree)malloc(sizeof(AvlNode_t));
    if (!t) {
      printf("malloc failed!\n");
      return nullptr;
    }
    t->data = e;
    t->lchild = t->rchild = nullptr;
    t->height = 0;
    printf("insert node successful!\n");
  } else if (e < t->data) {
    t->lchild = insert(t->lchild, e);
    if (height(t->lchild) - height(t->rchild) == 2) {
      if (e < t->lchild->data)
        t = single_rotate_with_left(t);
      else
        t = double_rotate_with_left(t);
    }
  } else if (e > t->data) {
    t->rchild = insert(t->rchild, e);
    if (height(t->rchild) - height(t->lchild) == 2) {
      if (e < t->rchild->data)
        t = single_rotate_with_right(t);
      else
        t = double_rotate_with_right(t);
    }
  }
  t->height = MAX(height(t->lchild), height(t->rchild)) + 1;
  return t;
}

/**
 * @brief
 *
 * @param t
 * @param e
 * @return ptr_avltree
 */
ptr_avltree del(ptr_avltree t, ElementType e) {
  Position p;
  if (!t) {
    printf("the tree is empty!\n");
    return nullptr;
  } else if (e < t->data) {
    t->lchild = del(t->lchild, e);
    if (height(t->lchild) - height(t->rchild) == 2) {
      if (e < t->lchild->data)
        t = single_rotate_with_left(t);
      else
        t = double_rotate_with_left(t);
    }
  } else if (e > t->data) {
    t->rchild = del(t->rchild, e);
    if (height(t->rchild) - height(t->lchild) == 2) {
      if (e < t->rchild->data)
        t = single_rotate_with_right(t);
      else
        t = double_rotate_with_right(t);
    }
  } else if (t->rchild && t->lchild) {
    // find the node and the left and right child is not null
    p = findmin(t->rchild);
    t->data = p->data;
    t->rchild = del(t->rchild, t->data);
  } else {
    p = t;
    if (!t->lchild)
      t = t->rchild;
    if (!t->rchild)
      t = t->lchild;
    free(p);
  }
  if (t)
    t->height = MAX(height(t->lchild), height(t->rchild)) + 1;
  return t;
}

/**
 * @brief
 *
 * @param p
 * @return int
 */
int retrieve(Position p) {
  if (p)
    return p->data;
  printf("the tree is empty!\n");
  return ERROR;
}

/**
 * @brief
 * perform a rotate between a node and its left child
 * update the height and return new root
 * @param t
 * @return ptr_avltree
 */
ptr_avltree single_rotate_with_left(ptr_avltree t) {
  Position tl;
  tl = t->lchild;
  t->lchild = tl->rchild;
  tl->rchild = t;
  t->height = MAX(height(t->lchild), height(t->rchild)) + 1;
  tl->height = MAX(height(tl->lchild), height(t)) + 1;
  return tl;
}

/**
 * @brief
 *
 * @param t
 * @return ptr_avltree
 */
ptr_avltree double_rotate_with_left(ptr_avltree t) {
  t->lchild = single_rotate_with_right(t->lchild);
  return single_rotate_with_left(t);
}

/**
 * @brief
 *
 * @param t
 * @return ptr_avltree
 */
ptr_avltree single_rotate_with_right(ptr_avltree t) {
  Position tr;
  tr = t->rchild;
  t->rchild = tr->lchild;
  tr->lchild = t;
  t->height = MAX(height(t->lchild), height(t->rchild)) + 1;
  tr->height = MAX(height(tr->rchild), height(t)) + 1;
  return tr;
}

/**
 * @brief
 *
 * @param t
 * @return ptr_avltree
 */
ptr_avltree double_rotate_with_right(ptr_avltree t) {
  t->rchild = single_rotate_with_left(t->rchild);
  return single_rotate_with_right(t);
}
