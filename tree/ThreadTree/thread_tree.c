#include "define.h"
/**
 * @brief
 *
 * @param t
 * @param e
 * @return ptr_thread_tree
 */
ptr_thread_tree insert(ptr_thread_tree t, DataType e) {
  if (!t) {
    t = (ptr_thread_tree)malloc(sizeof(ThreadTree_t));
    if (!t) {
      printf("malloc failed");
      return ERROR;
    }
    t->data = e;
    t->lchild = t->rchild = nullptr;
    printf("insert node successful!\n");
  } else if (e < t->data)
    t->lchild = insert(t->lchild, e);
  else if (e > t->data)
    t->rchild = insert(t->rchild, e);
  return t;
}

/**
 * @brief
 *
 * @param t
 */
void preorder(ptr_thread_tree t) {
  while (t) {
    while (t->ltag == lINK && t->lchild) {
      visit(t);
      t = t->lchild;
    }
    while (t->rtag == THREAD && t->rchild) {
      t = t->rchild;
      visit(t);
    }
    t = t->rchild;
  }
}

/**
 * @brief
 *
 * @param t
 */
void prethreading(ptr_thread_tree t) {
  if (t) {
    if (!t->lchild) {
      t->ltag = THREAD;
      t->lchild = pre;
    }
    if (!pre->rchild && pre) {
      pre->rtag = THREAD;
      pre->rchild = t;
    }
    pre = t;
    prethreading(t->lchild);
    prethreading(t->rchild);
  }
}

/**
 * @brief
 *
 * @param t
 */
void inthreading(ptr_thread_tree t) {
  if (t) {
    inthreading(t->lchild);
    if (!t->lchild) {
      t->ltag = THREAD;
      t->lchild = pre;
    }
    if (!pre->rchild && pre) {
      pre->rtag = THREAD;
      pre->rchild = t;
    }
    pre = t;
    inthreading(t->rchild);
  }
}

/**
 * @brief
 *
 * @param t
 */
void inorder(ptr_thread_tree t) {
  while (t) {
    while (t->ltag == lINK && t->lchild) {
      t = t->lchild;
    }
    visit(t);
    while (t->rtag == THREAD && t->rchild) {
      t = t->rchild;
      visit(t);
    }
    t = t->rchild;
  }
}

/**
 * @brief
 *
 * @param t
 */
void postorder(ptr_thread_tree t) {
}

/**
 * @brief
 *
 * @param t
 */
void postthreading(ptr_thread_tree t) {
  if (t) {
    postthreading(t->lchild);
    postthreading(t->rchild);
    if (!t->lchild) {
      t->ltag = THREAD;
      t->lchild = pre;
    }
    if (!pre->rchild && pre) {
      pre->rtag = THREAD;
      pre->rchild = t;
    }
    pre = t;
  }
}

/**
 * @brief
 *
 * @param t
 */
void levelorder(ptr_thread_tree t) {
}

/**
 * @brief
 *
 * @param t
 */
void visit(ptr_thread_tree t) {
  printf("%d ", t->data);
}

/**
 * @brief
 *
 * @param t
 * @return ptr_thread_tree
 */
ptr_thread_tree findmin(ptr_thread_tree t) {
  if (t)
    while (t->ltag == lINK && t->lchild)
      t = t->lchild;
  return t;
}

/**
 * @brief
 *
 * @param t
 * @return ptr_thread_tree
 */
ptr_thread_tree findmax(ptr_thread_tree t) {
  if (t)
    while (t->rtag == lINK && t->rchild)
      t = t->rchild;
  return t;
}

/**
 * @brief
 *
 * @param t
 * @param e
 * @return ptr_thread_tree
 */
ptr_thread_tree find(ptr_thread_tree t, DataType e) {
  if (!t)
    return nullptr;
  if (t->data == e)
    return t;
  else if (e < t->data && t->ltag == lINK)
    return find(t->lchild, e);
  else if (e > t->data && t->rtag == lINK)
    return find(t->rchild, e);
}

/**
 * @brief
 *
 * @param t
 * @param e
 * @return ptr_thread_tree
 */
ptr_thread_tree del(ptr_thread_tree t, DataType e) {
}

/**
 * @brief
 *
 * @param t
 * @return int
 */
int destory_tree(ptr_thread_tree t) {
  if (t) {
    if (t->ltag == lINK && t->lchild)
      destory_tree(t->lchild);
    if (t->rtag == lINK && t->rchild)
      destory_tree(t->rchild);
    free(t);
  }
  printf("free the node successful!\n");
}
