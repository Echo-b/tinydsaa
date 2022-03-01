#include "define.h"

/**
 * @brief
 *
 * @return hashTable
 */
hashTable init(unsigned int table_size)
{
  if (table_size > minTableSize)
  {
    printf("the size is bigger!\n");
    return nullptr;
  }
  hashTable h = (hashTable)malloc(sizeof(struct hashTbl));
  if (!h)
  {
    printf("malloc failed!\n");
    return nullptr;
  }
  h->tablesize = next_prime(table_size);
  /* malloc list of array */
  h->theLists = (list *)malloc(sizeof(struct listNode) * h->tablesize);
  if (!h->theLists)
  {
    printf("malloc failed!\n");
    return nullptr;
  }
  /* malloc list head */
  for (int i = 0; i < h->tablesize; ++i)
  {
    h->theLists[i] = (list)malloc(sizeof(struct listNode));
    if (!h->theLists[i])
    {
      printf("malloc failed!\n");
      return nullptr;
    }
    h->theLists[i]->data = 0;
    h->theLists[i]->next = nullptr;
  }
  printf("init the hash table successful!\n");
  return h;
}

/**
 * @brief
 *
 * @param h
 */
void destory(hashTable h)
{
  list l;
  /* first free the list node header */
  for (int i = 0; i < h->tablesize; ++i)
  {
    l = h->theLists[i]->next;
    while (l)
    {
      list p = l->next;
      free(l);
      l = p;
    }
    free(h->theLists[i]);
  }
  /* second free the list of array */
  free(h->theLists);
  /* third free the hashtable point */
  free(h);
  printf("free the all space complete!\n");
}

/**
 * @brief
 *
 * @param h
 * @param key
 * @return list
 */
list find(hashTable h, ElementType key)
{
  list l;
  /* find the right list node header */
  l = h->theLists[hashfun(key, h->tablesize)];
  l = l->next;
  while (l && l->data != key)
    l = l->next;
  return l;
}

/**
 * @brief
 *
 * @param h
 * @param key
 */
void insert(hashTable h, ElementType key)
{
  list p = find(h, key);
  if (!p)
  {
    list node = (list)malloc(sizeof(struct listNode));
    if (!node)
    {
      printf("malloc failed!\n");
      return;
    }
    list l = h->theLists[hashfun(key, h->tablesize)];
    node->data = key;
    node->next = l->next;
    l->next = node;
    printf("insert the elem into the hashtable successful!\n");
  }
  else
  {
    printf("the hashtable has the same value node!\n");
    return;
  }
}

/**
 * @brief
 *
 * @param p
 * @return ElementType
 */
ElementType retrive(list p)
{
  if (!p)
  {
    printf("the list node is nullptr!\n");
    return ERROR;
  }
  return p->data;
}

/**
 * @brief
 *
 * @param key
 * @param tabel_size
 * @return int
 */
int hashfun(ElementType key, unsigned int tabel_size)
{
  return key % tabel_size;
}

/**
 * @brief
 *
 * @param x
 * @return true
 * @return false
 */
bool isprime(int x)
{
  if (x < 2)
    return false;
  for (int i = 2; i < (int)sqrt(x); ++i)
  {
    if (x % i == 0)
      return false;
  }
  return true;
}

/**
 * @brief
 *
 * @param x
 * @return int
 */
int next_prime(int x)
{
  while (true)
  {
    if (isprime(x))
      break;
    ++x;
  }
  return x;
}

/**
 * @brief
 *
 * @param h
 */
void display(hashTable h)
{
  for (int i = 0; i < h->tablesize; ++i)
  {
    list l = h->theLists[i]->next;
    int pos = 1;
    while (l)
    {
      printf("the header is [%d], and the node is [%d], the node value is [%d]\n", i, pos, l->data);
      ++pos;
      l = l->next;
    }
  }
}