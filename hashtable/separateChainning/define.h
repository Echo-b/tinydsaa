#ifndef _HASH_TABLE_
#define _HASH_TABLE_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ERROR 0
#define OK 1
#define nullptr NULL

typedef int ElementType;

struct listNode;
typedef struct listNode *list;
struct hashTbl;
typedef struct hashTbl *hashTable;

#define minTableSize 10

struct listNode
{
  ElementType data;
  list next;
};

struct hashTbl
{
  int tablesize;
  list *theLists;
};

hashTable init(unsigned int table_size);
void destory(hashTable h);
list find(hashTable h, ElementType key);
void insert(hashTable h, ElementType key);
ElementType retrive(list p);
int hashfun(ElementType key, unsigned int tabel_size);
bool isprime(int x);
int next_prime(int x);
void display(hashTable h);
#endif