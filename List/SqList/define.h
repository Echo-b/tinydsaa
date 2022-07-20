#if !defined(SQLIST)
#define SQLIST

#define maxSize 100
#define addSize 50
#define ERROR 0
#define OK 1
#define NOT_FOUND -1
#define nullptr NULL
typedef int ElementType;

/**
 * @brief
 * static sequential list
 */

typedef struct
{
  ElementType data[maxSize];
  int cur_len;
} static_sqList_t;

/**
 * @brief
 * dynamic sequential sqlist
 */

#define initSize 100
typedef struct
{
  ElementType* data;
  int max_size;
  int cur_len;
} dynamic_sqlist_t;

int init(dynamic_sqlist_t* dynamic_sqlist);
int add(dynamic_sqlist_t* dynamic_sqlist, ElementType e, int loc);
int del(dynamic_sqlist_t* dynamic_sqlist, int loc);
int modify(dynamic_sqlist_t* dynamic_sqlist, ElementType e, int loc);
int find(dynamic_sqlist_t dynamic_sqlist, ElementType e);
int clear_sqlist(dynamic_sqlist_t* dynamic_sqlist_t);
int destory_sqlist(dynamic_sqlist_t* dynamic_sqlist_t);
void display(dynamic_sqlist_t dynamic_sqlist);
int merge_sqlist(dynamic_sqlist_t first, dynamic_sqlist_t second, dynamic_sqlist_t* com_sqlist);

#endif
