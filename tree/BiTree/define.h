#ifndef _BINTREE_
#define _BINTREE_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define nullptr NULL
#define ERROR 0
#define OK 1

typedef int DataType;
struct BinTreeNode;
typedef struct BinTreeNode* ptr_binary_tree;
typedef struct BinTreeNode* position;

typedef struct BinTreeNode {
  DataType elm;
  struct BinTreeNode* lchild;
  struct BinTreeNode* rchild;
} BinTreeNode_t;

ptr_binary_tree insert(ptr_binary_tree bin_tree, DataType e);
void postorder(ptr_binary_tree bin_tree);
void inorder(ptr_binary_tree bin_tree);
void preorder(ptr_binary_tree bin_tree);
void levelorder(ptr_binary_tree bin_tree);
ptr_binary_tree findmin(ptr_binary_tree bin_tree);
ptr_binary_tree findmax(ptr_binary_tree bin_tree);
ptr_binary_tree find(ptr_binary_tree bin_tree, DataType e);
ptr_binary_tree del(ptr_binary_tree bin_tree, DataType e);
void visit(ptr_binary_tree bin_tree);
int depth(ptr_binary_tree bin_tree);
int destory_tree(ptr_binary_tree bin_tree);
#endif