#include "define.h"
/**
 * @brief
 * find the u's location in the graph vertex
 * @param G
 * @param u
 * @return int
 */
int locate_vex(MGraph G, VertexType u)
{
  int loc = -1;
  for (int i = 0; i < G.vexnum; ++i)
  {
    if (!strcmp(u, G.vexs[i]))
    {
      loc = i;
      break;
    }
  }
  return loc;
}

/**
 * @brief Create a graph object
 *
 * @param G
 * @return int
 */
int create_graph(MGraph *G)
{
  VertexType va, vb;
  int weight;
  printf("please input the graph G vexnum arcnum\n");
  scanf("%d", &G->vexnum);
  scanf("%d", &G->arcnum);
  edges = (EdgeNode *)malloc(sizeof(EdgeNode) * G->arcnum);
  if (!edges)
  {
    printf("malloc failed!\n");
    return ERROR;
  }
  printf("please input the %d vertex num value\n", G->vexnum);
  for (int i = 0; i < G->vexnum; ++i)
    scanf("%s", G->vexs[i]);
  /* initilization the G->arcs */
  for (int i = 0; i < G->vexnum; ++i)
    for (int j = 0; j < G->vexnum; ++j)
      G->arcs[i][j] = INFINITY;
  // printf("please input %d nums's vertex1 vertex2\n", G->arcnum);
  printf("please input the arc [va] => [vb] and the info [weight]\n");
  for (int k = 0; k < G->arcnum; ++k)
  {
    scanf("%s%s%d", va, vb, &weight);
    int va_loc = locate_vex(*G, va);
    int vb_loc = locate_vex(*G, vb);
    edges[k].begin = va_loc;
    edges[k].end = vb_loc;
    edges[k].weight = weight;
    G->arcs[va_loc][vb_loc] = G->arcs[vb_loc][va_loc] = weight;
  }
  G->kind = AG;
  printf("create the undirect graph matrix successful!\n");
  return OK;
}

/**
 * @brief
 *
 * @param G
 */
void destory_graph(MGraph *G)
{
  if (!G)
  {
    printf("the graph is not exist!\n");
    return;
  }
  G->arcnum = 0;
  G->vexnum = 0;
}

/**
 * @brief
 *
 * @param G
 * @return int
 */
int put_vex(MGraph *G, VertexType v, VertexType value)
{
  if (!G)
  {
    printf("the graph is not exist!\n");
    return ERROR;
  }
  int loc = locate_vex(*G, v);
  if (loc < 0)
  {
    printf("can not find the vertex v location!\n");
    return ERROR;
  }
  strcpy(G->vexs[loc], value);
  printf("put the vex v successful!\n");
  return OK;
}

/**
 * @brief
 *
 * @param G
 * @param v
 * @return int
 */
int first_adjvex(MGraph G, VertexType v)
{
  int loc = -1;
  loc = locate_vex(G, v);
  if (loc < 0)
  {
    printf("can not find the vertex v location!\n");
    return ERROR;
  }
  for (int i = 0; i < G.vexnum; ++i)
  {
    if (G.arcs[loc][i])
    {
      loc = i;
      break;
    }
  }
  printf("find the first adjvex\n");
  return loc;
}

/**
 * @brief
 *
 * @param G
 * @param v
 * @param w
 * @return int
 */
int next_adjvex(MGraph G, VertexType v, VertexType w)
{
  int res_loc = -1;
  int loc_v = locate_vex(G, v);
  int loc_w = locate_vex(G, w);
  if (loc_v < 0 || loc_w < 0)
  {
    printf("can not find the vertex v or w location!\n");
    return ERROR;
  }
  for (int i = loc_w + 1; i < G.vexnum; ++i)
  {
    if (G.arcs[i][loc_v])
    {
      res_loc = i;
      break;
    }
  }
  printf("find the next adjvex\n");
  return res_loc;
}

/**
 * @brief
 *
 * @param G
 * @param v
 */
void insert_vex(MGraph *G, VertexType v)
{
  if (G->vexnum == MAX_VERTEX_NUM)
  {
    printf("the vertex num is arrival the max!\n");
    return;
  }
  int loc_v = locate_vex(*G, v);
  if (loc_v != -1)
  {
    printf("have the same vertex!\n");
    return;
  }
  strcpy(G->vexs[G->vexnum], v);
  for (int i = 0; i <= G->vexnum; ++i)
  {
    G->arcs[G->vexnum][i] = 0;
    G->arcs[i][G->vexnum] = 0;
  }
  printf("insert the vex successful!\n");
  ++G->vexnum;
}

/**
 * @brief
 *
 * @param G
 * @param v
 * @return int
 */
int delete_vex(MGraph *G, VertexType v)
{
  int loc_v = locate_vex(*G, v);
  if (loc_v < 0)
  {
    printf("the delete vertex is not exist!\n");
    return ERROR;
  }
  // move the vertex location
  for (int i = loc_v + 1; i < G->vexnum; ++i)
    strcpy(G->vexs[i - 1], G->vexs[i]);

  // decrease the arcnum
  for (int i = 0; i < G->vexnum; ++i)
    if (G->arcs[i][loc_v])
      --G->arcnum;
  // move the matrix element value
  for (int i = loc_v + 1; i < G->vexnum; ++i)
    for (int j = 0; j < G->vexnum; ++j)
      G->arcs[i - 1][j] = G->arcs[i][j];

  for (int i = 0; i < G->vexnum; ++i)
    for (int j = loc_v + 1; j < G->vexnum; ++j)
      G->arcs[i][j - 1] = G->arcs[i][j];

  // decrease the vexnum
  --G->vexnum;
  printf("delete the vertex v successful!\n");
  return OK;
}

/**
 * @brief
 * add the arc <v,w>
 * @param G
 * @param v
 * @param w
 * @return int
 */
int insert_arc(MGraph *G, VertexType v, VertexType w)
{
  int loc_v = locate_vex(*G, v);
  int loc_w = locate_vex(*G, w);
  if (loc_v < 0 || loc_w < 0)
  {
    printf("can not find the vertex v or w location!\n");
    return ERROR;
  }
  ++G->arcnum;
  G->arcs[loc_v][loc_w] = 1, G->arcs[loc_w][loc_v] = 1;
  printf("add the arc <v,w> successful!\n");
  return OK;
}

/**
 * @brief
 *
 * @param G
 * @param v
 * @param w
 * @return int
 */
int delete_arc(MGraph *G, VertexType v, VertexType w)
{
  int loc_v = locate_vex(*G, v);
  int loc_w = locate_vex(*G, w);
  if (loc_v < 0 || loc_w < 0)
  {
    printf("can not find the vertex v or w location!\n");
    return ERROR;
  }
  --G->arcnum;
  G->arcs[loc_v][loc_w] = 0, G->arcs[loc_w][loc_v] = 0;
  printf("delete the arc <v,w> successful!\n");
  return OK;
}

bool visited[MAX_VERTEX_NUM];

/**
 * @brief
 *
 * @param G
 * @param i
 */

void dfs(MGraph G, int i)
{
  visited[i] = true;
  printf("%s ", G.vexs[i]);
  for (int j = 0; j < G.vexnum; ++j)
  {
    if (G.arcs[i][j] >= 1 && !visited[j])
      dfs(G, j);
  }
}

/**
 * @brief
 *
 * @param G
 */
void dfs_traverse(MGraph G)
{
  for (int i = 0; i < G.vexnum; ++i)
    visited[i] = false;
  for (int i = 0; i < G.vexnum; ++i)
  {
    if (!visited[i])
      dfs(G, i);
  }
}

/**
 * @brief
 *
 * @param G
 */
void bfs_traverse(MGraph G)
{
  SqQueue Q;
  initQueue(&Q);
  for (int i = 0; i < G.vexnum; ++i)
    visited[i] = false;
  for (int i = 0; i < G.vexnum; ++i)
  {
    if (!visited[i])
    {
      visited[i] = true;
      printf("%s ", G.vexs[i]);
      push(&Q, i);
      while (!is_empty(Q))
      {
        pop(&Q, &i);
        for (int j = 0; j < G.vexnum; ++j)
        {
          if (!visited[j] && G.arcs[i][j] >= 1)
          {
            visited[j] = true;
            printf("%s ", G.vexs[j]);
            push(&Q, j);
          }
        }
      }
    }
  }
}

/**
 * @brief
 *
 * @param G
 */
void mini_span_tree(MGraph G)
{
  int min;
  int cur_min_index = 0;
  int adjvex[MAX_VERTEX_NUM];
  int lowcost[MAX_VERTEX_NUM];
  lowcost[0] = 0;
  adjvex[0] = 0;
  for (int i = 1; i < G.vexnum; ++i)
  {
    lowcost[i] = G.arcs[0][i];
    adjvex[i] = 0;
  }
  for (int i = 1; i < G.vexnum; ++i)
  {
    min = INFINITY;
    int j = 1;
    cur_min_index = 0;
    while (j < G.vexnum)
    {
      if (lowcost[j] != 0 && lowcost[j] < min)
      {
        min = lowcost[j];
        cur_min_index = j;
      }
      ++j;
    }
    printf("[%d]->[%d]\n", adjvex[cur_min_index], cur_min_index);
    lowcost[cur_min_index] = 0;
    for (j = 1; j < G.vexnum; ++j)
    {
      if (lowcost[j] != 0 && G.arcs[cur_min_index][j] < lowcost[j])
      {
        lowcost[j] = G.arcs[cur_min_index][j];
        adjvex[j] = cur_min_index;
      }
    }
  }
}

/**
 * @brief
 *
 * @param arg1
 * @param arg2
 * @return int
 */
int compare(const void *arg1, const void *arg2)
{
  return (((EdgeNode *)arg1)->weight - ((EdgeNode *)arg2)->weight);
}

/**
 * @brief
 *
 * @param edges
 * @return int
 */
void sort(MGraph G)
{
  qsort(edges, G.arcnum, sizeof(EdgeNode), compare);
}

/**
 * @brief
 *
 * @param parent
 * @param f
 * @return int
 */
int find(int *parent, int f)
{
  while (parent[f] > 0)
    f = parent[f];
  return f;
}

/**
 * @brief
 *
 * @param G
 */
void mini_span_tree_kruskal(MGraph G)
{
  int n, m;
  int parent[MAX_VERTEX_NUM];
  // todo
  sort(G);
  for (int i = 0; i < G.vexnum; ++i)
    parent[i] = 0;
  for (int j = 0; j < G.arcnum; ++j)
  {
    n = find(parent, edges[j].begin);
    m = find(parent, edges[j].end);
    if (m != n)
    {
      parent[n] = m;
      printf("[%d] => [%d] weigth =>[%d]\n", edges[j].begin, edges[j].end, edges[j].weight);
    }
  }
}

/**
 * @brief
 *
 * @param P
 * @param D
 */
void show_shortest_path(MGraph G, Pathmartix P, ShortPathTable D, int vi)
{
  int cur_vi;
  for (int i = G.vexnum - 1; i >= 0; --i)
  {
    cur_vi = i;
    printf("the [v%d] => [v%d] path is:\n", i, vi);
    printf("[v%d]<=", i);
    while (P[cur_vi] > 0)
    {
      printf("[v%d]<=", P[cur_vi]);
      cur_vi = P[cur_vi];
    }
    printf("[v%d]\n", vi);
    printf("+-----------------------------+\n");
    printf("the weight is [%d]\n", D[i]);
    printf("+-----------------------------+\n");
  }
}

/**
 * @brief
 *
 * @param G
 * @param v0
 * @param p
 * @param D
 */
void shortest_path_dijkstra(MGraph G, int v0, Pathmartix *P, ShortPathTable *D)
{
  int min, cur_min_index;
  int final[MAX_VERTEX_NUM];
  for (int v = 0; v < G.vexnum; ++v)
  {
    final[v] = 0;
    (*D)[v] = G.arcs[v0][v];
    (*P)[v] = 0;
  }
  (*D)[v0] = 0;
  final[v0] = 1;
  for (int i = 1; i < G.vexnum; ++i)
  {
    min = INFINITY;
    for (int w = 0; w < G.vexnum; ++w)
    {
      if (!final[w] && (*D)[w] < min)
      {
        cur_min_index = w;
        min = (*D)[w];
      }
    }
    // printf("the min is:[%d]\n", min);
    final[cur_min_index] = 1;
    for (int w = 0; w < G.vexnum; ++w)
    {
      if (!final[w] && (min + G.arcs[cur_min_index][w]) < (*D)[w])
      {
        (*D)[w] = min + G.arcs[cur_min_index][w];
        (*P)[w] = cur_min_index;
      }
    }
  }
}

/**
 * @brief
 *
 * @param G
 * @param P
 * @param D
 */
void shortest_path_floyd(MGraph G, Pathmartix_floyd *P, ShortPathTable_floyd *D)
{
  for (int v = 0; v < G.vexnum; ++v)
  {
    for (int w = 0; w < G.vexnum; ++w)
    {
      (*D)[v][w] = G.arcs[v][w];
      (*P)[v][w] = w;
    }
  }
  for (int i = 0; i < G.vexnum; ++i)
  {
    for (int j = 0; j < G.vexnum; ++j)
    {
      for (int k = 0; k < G.vexnum; ++k)
      {
        if ((*D)[i][j] > ((*D)[i][k] + (*D)[k][j]))
        {
          (*D)[i][j] = (*D)[i][k] + (*D)[k][j];
          (*P)[i][j] = (*P)[i][k];
        }
      }
    }
  }
}

/**
 * @brief
 *
 * @param G
 * @param P
 * @param D
 */
void display_floyd_path(MGraph G, Pathmartix_floyd P, ShortPathTable_floyd D)
{
  int cur_vi;
  for (int i = 0; i < G.vexnum; ++i)
  {
    for (int j = i + 1; j < G.vexnum; ++j)
    {
      printf("[v%d]=>[v%d] weight [%d]", i, j, D[i][j]);
      int k = P[i][j];
      printf("  the path is: [v%d]", i);
      while (k != j)
      {
        printf("=>[v%d]", k);
        k = P[k][j];
      }
      printf("=>[v%d]\n", j);
    }
    printf("\n");
  }
}

/**
 * @brief
 *
 * @param G
 */
void display(MGraph G)
{
  printf("+-----------------------------+\n");
  for (int i = 0; i < G.vexnum; ++i)
    printf("%s ", G.vexs[i]);
  printf("\n");

  printf("+-----------------------------+\n");
  for (int i = 0; i < G.vexnum; ++i)
  {
    for (int j = 0; j < G.vexnum; ++j)
      printf("%2d", G.arcs[i][j]);
    printf("\n");
  }
  printf("+-----------------------------+\n");
}
