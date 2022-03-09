#ifndef _ADJACENCY_MATRIX_
#define _ADJACENCY_MATRIX_

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../queue/define.h"
#include "../queue/queue.c"

#define ERROR 0
#define OK 1
#define INFINITY 65536

#define MAX_VERTEX_NUM 30
typedef enum graphKind {
  DG,
  DN,
  AG,
  AN
} graphKind;

typedef char VertexType[6];
typedef int ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

struct MGraph;
typedef struct MGraph MGraph;

struct MGraph {
  VertexType vexs[MAX_VERTEX_NUM];
  AdjMatrix arcs;
  int vexnum, arcnum;
  graphKind kind;
};

/***************************/
struct EdgeNode;
typedef struct EdgeNode EdgeNode;

struct EdgeNode {
  int begin;
  int end;
  int weight;
};

struct EdgeNode* edges;
/**************************/

/*****************************************/
typedef int Pathmartix[MAX_VERTEX_NUM];
typedef int ShortPathTable[MAX_VERTEX_NUM];
/****************************************/

/*****************************************/
typedef int Pathmartix_floyd[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef int ShortPathTable_floyd[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
/****************************************/

int locate_vex(MGraph G, VertexType u);
int create_graph(MGraph* G);
void destory_graph(MGraph* G);
int put_vex(MGraph* G, VertexType v, VertexType value);
int first_adjvex(MGraph G, VertexType v);
int next_adjvex(MGraph G, VertexType v, VertexType w);
void insert_vex(MGraph* G, VertexType v);
int delete_vex(MGraph* G, VertexType v);
int insert_arc(MGraph* G, VertexType v, VertexType w);
int delete_arc(MGraph* G, VertexType v, VertexType w);
void dfs(MGraph G, int i);
void dfs_traverse(MGraph G);
void bfs_traverse(MGraph G);
void mini_span_tree(MGraph G);
int compare(const void* arg1, const void* arg2);
int find(int* parent, int f);
void sort(MGraph G);
void mini_span_tree_kruskal(MGraph G);
void shortest_path_dijkstra(MGraph G, int v0, Pathmartix* P, ShortPathTable* D);
void show_shortest_path(MGraph G, Pathmartix P, ShortPathTable D, int vi);
void shortest_path_floyd(MGraph G, Pathmartix_floyd* P, ShortPathTable_floyd* D);
void display_floyd_path(MGraph G, Pathmartix_floyd P, ShortPathTable_floyd D);
void display(MGraph G);
#endif