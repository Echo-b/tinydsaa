#ifndef _AVL_TREE_
#define _AVL_TREE_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define nullptr NULL

typedef int ElementType;

struct AvlNode;
typedef struct AvlNode AvlNode_t;
typedef struct AvlNode* Position;
typedef struct AvlNode* ptr_avltree;

struct AvlNode {
  ElementType data;
  ptr_avltree lchild;
  ptr_avltree rchild;
  int height;
};

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

void make_empty(ptr_avltree t);
int height(ptr_avltree t);
void inorder(ptr_avltree t);
Position find(ptr_avltree t, ElementType e);
Position findmin(ptr_avltree t);
Position findmax(ptr_avltree t);
ptr_avltree insert(ptr_avltree t, ElementType e);
ptr_avltree del(ptr_avltree t, ElementType e);
int retrieve(Position p);
ptr_avltree single_rotate_with_left(ptr_avltree t);
ptr_avltree double_rotate_with_left(ptr_avltree t);
ptr_avltree single_rotate_with_right(ptr_avltree t);
ptr_avltree double_rotate_with_right(ptr_avltree t);

#endif
