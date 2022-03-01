#ifndef _OPEN_ADDR_HASH_TABLE_
#define _OPEN_ADDR_HASH_TABLE_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ERROR 0
#define OK 1
#define nullptr NULL

typedef unsigned int Index;
typedef Index position;
typedef int ElementType;

struct hashTbl;
typedef struct hashTbl *hashTable;

#define minTableSize 100

enum KindofEntry
{
  Legitimate,
  Empty,
  Delete
};

struct hashEntry
{
  ElementType data;
  enum KindofEntry info;
};

typedef struct hashEntry Cell;

struct hashTbl
{
  int tablesize;
  Cell *theCells;
};

hashTable init(unsigned int table_size);
void destory(hashTable h);
position find(hashTable h, ElementType key);
void insert(hashTable h, ElementType key);
ElementType retrive(position p, hashTable h);
int hashfun(ElementType key, unsigned int tabel_size);
bool isprime(int x);
int next_prime(int x);
hashTable rehash(hashTable h);
double compute_load_factor(hashTable h);
void display(hashTable h);
#endif