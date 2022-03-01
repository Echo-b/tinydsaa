#ifndef _ADJACENCY_LIST_
#define _ADJACENCY_LIST_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../queue/define.h"
#include "../queue/queue.c"
#include "../stack/define.h"
#include "../stack/seq_stack.c"

#define ERROR 0
#define OK 1
#define nullptr NULL

#define MAX_VERTEX_NUM 30
typedef enum graphKind
{
  DG,
  DN,
  AG,
  AN
} graphKind;

typedef char VertexType[6];

struct ArcNode;
typedef struct ArcNode ArcNode;

/**
 * @brief
 * adjvex => arc tail
 * nextarc => pointer to next vertex node
 * info => vertex node value
 */
struct ArcNode
{
  int adjvex;
  ArcNode *nextarc;
  int info;
};

struct VNode;
typedef struct VNode *Adjlist;

/**
 * @brief
 * data => arc head
 * firstarc => pointer to the association vertex node
 */
struct VNode
{
  VertexType data;
  ArcNode *firstarc;
};

struct AlGraph;
typedef struct AlGraph AlGraph;

/**
 * @brief
 * vertices => array of vertex node information
 * vexnum => vertex node nums
 * arcnum => arc node nums
 * kind => the type of the graph
 */
struct AlGraph
{
  Adjlist vertices;
  int vexnum;
  int arcnum;
  graphKind kind;
};

int locate_vex(AlGraph G, VertexType u);
int create_graph(AlGraph *G);
void destory_graph(AlGraph *G);
int put_vex(AlGraph *G, VertexType v, VertexType value);
int first_adjvex(AlGraph G, VertexType v);
int next_adjvex(AlGraph G, VertexType v, VertexType w);
int insert_vex(AlGraph *G, VertexType v);
int delete_vex(AlGraph *G, VertexType v);
int insert_arc(AlGraph *G, VertexType v, VertexType w);
int delete_arc(AlGraph *G, VertexType v, VertexType w);
void dfs(AlGraph G, int i);
void dfs_traverse(AlGraph G);
void bfs_traverse(AlGraph G);
void find_indegree(AlGraph G);
void topologicalsort(AlGraph G);
void display(AlGraph G);
#endif