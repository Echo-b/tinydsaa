#include "define.h"

/**
 * @brief
 *
 * @param table_size
 * @return hashTable
 */
hashTable init(unsigned int table_size) {
  if (table_size > minTableSize) {
    printf("the table size is bigger than the min table size!\n");
    return nullptr;
  }
  hashTable h = (hashTable)malloc(sizeof(struct hashTbl));
  if (!h) {
    printf("malloc failed!\n");
    return nullptr;
  }
  h->tablesize = next_prime(table_size);
  h->theCells = (Cell*)malloc(sizeof(Cell) * h->tablesize);
  if (!h->theCells) {
    printf("malloc failed!\n");
    return nullptr;
  }
  for (int i = 0; i < h->tablesize; ++i) {
    h->theCells[i].info = Empty;
  }
  return h;
}

/**
 * @brief
 * two times hash the solve function is F(i) = F(i -1) + 2*i - 1
 * may be we can also to use the liner function to elicit the free space
 * just use the solve function F(i) = F(i-1) + 1
 * @param h
 */
void destory(hashTable h) {
  free(h->theCells);
  free(h);
  printf("free all space complete!\n");
}

/**
 * @brief
 *
 * @param h
 * @param key
 * @return position
 */
position find(hashTable h, ElementType key) {
  position cur_pos;
  int collision_num = 0;
  cur_pos = hashfun(key, h->tablesize);
  while (h->theCells[cur_pos].info != Empty && h->theCells[cur_pos].data != key) {
    cur_pos += (++collision_num) << 1 - 1;
    if (cur_pos > h->tablesize)
      cur_pos -= h->tablesize;
  }
  return cur_pos;
}

/**
 * @brief
 *
 * @param h
 * @param key
 */
void insert(hashTable h, ElementType key) {
  position cur_pos = find(h, key);
  if (h->theCells[cur_pos].info != Legitimate) {
    h->theCells[cur_pos].info = Legitimate;
    h->theCells[cur_pos].data = key;
  }
  if (compute_load_factor(h) > 0.7) {
    printf("load factor > 0.7,call the rehash\n");
    rehash(h);
  }
}

ElementType retrive(position p, hashTable h) {
  return h->theCells[p].data;
}

/**
 * @brief
 *
 * @param key
 * @param tabel_size
 * @return int
 */
int hashfun(ElementType key, unsigned int tabel_size) {
  return key % tabel_size;
}

/**
 * @brief
 *
 * @param x
 * @return true
 * @return false
 */
bool isprime(int x) {
  if (x < 2)
    return false;
  for (int i = 2; i < (int)sqrt(x); ++i) {
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
int next_prime(int x) {
  while (true) {
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
 * @return double
 */
double compute_load_factor(hashTable h) {
  int cur_num = 0;
  double load_factor = 0;
  for (int i = 0; i < h->tablesize; ++i) {
    if (h->theCells[i].info == Legitimate)
      ++cur_num;
  }
  load_factor = (double)cur_num / h->tablesize;
  return load_factor;
}

/**
 * @brief
 * when the load factor > 0.6 ,we should realloc a bigger hashtable and rehash pre table element
 * @param h
 * @return hashTable
 */
hashTable rehash(hashTable h) {
  Cell* oldCell;
  int i, oldsize;
  oldCell = h->theCells;
  oldsize = h->tablesize;
  h = init(2 * oldsize);
  for (int i = 0; i < oldsize; ++i) {
    if (oldCell[i].info == Legitimate)
      insert(h, oldCell[i].data);
  }
  free(oldCell);
  return h;
}

void display(hashTable h) {
  for (int i = 0; i < h->tablesize; ++i) {
    if (h->theCells[i].info == Legitimate)
      printf("the location is [%d], the value is [%d]\n", i, h->theCells[i].data);
  }
}