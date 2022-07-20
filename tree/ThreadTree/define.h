#ifndef _THREADTREE_
#define _THREADTREE_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define nullptr NULL
#define ERROR 0
#define OK 1

typedef int DataType;
typedef enum PointTag {
  lINK,
  THREAD
} PointTag;

struct ThreadNode;
typedef struct ThreadNode* ptr_thread_tree;

typedef struct ThreadNode {
  DataType data;
  struct ThreadNode* lchild;
  struct ThreadNode* rchild;
  PointTag ltag;
  PointTag rtag;
} ThreadTree_t;

ptr_thread_tree pre = nullptr;  // global node ,point to the pre visit node

ptr_thread_tree insert(ptr_thread_tree t, DataType e);
void postorder(ptr_thread_tree t);
void inthreading(ptr_thread_tree t);
void prethreading(ptr_thread_tree t);
void postthreading(ptr_thread_tree t);
void preorder(ptr_thread_tree t);
void levelorder(ptr_thread_tree t);
void inorder(ptr_thread_tree t);
void visit(ptr_thread_tree t);
ptr_thread_tree findmin(ptr_thread_tree t);
ptr_thread_tree findmax(ptr_thread_tree t);
ptr_thread_tree find(ptr_thread_tree t, DataType e);
ptr_thread_tree del(ptr_thread_tree t, DataType e);
int destory_tree(ptr_thread_tree t);
#endif