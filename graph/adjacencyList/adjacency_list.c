#include "define.h"

/**
 * @brief
 *
 * @param G
 * @param u
 * @return int
 */
int locate_vex(AlGraph G, VertexType u)
{
  int loc = -1;
  for (int i = 0; i < G.vexnum; ++i)
  {
    if (!strcmp(G.vertices[i].data, u))
    {
      loc = i;
      break;
    }
  }
  // printf("find the location!\n");
  return loc;
}

int create_graph(AlGraph *G)
{
  VertexType va, vb;
  ArcNode *p;
  int weight;
  G->kind = DN;
  G->vertices = (Adjlist)malloc(sizeof(struct VNode) * MAX_VERTEX_NUM);
  if (!G->vertices)
  {
    printf("malloc failed!\n");
    return ERROR;
  }
  printf("please input the vexnum!\n");
  scanf("%d", &G->vexnum);
  printf("please input the arcnum!\n");
  scanf("%d", &G->arcnum);
  printf("please input the %d vertex num value\n", G->vexnum);
  for (int i = 0; i < G->vexnum; ++i)
  {
    scanf("%s", G->vertices[i].data);
    G->vertices[i].firstarc = nullptr;
  }
  printf("please input the every arc head tail weight!\n");
  for (int j = 0; j < G->arcnum; ++j)
  {
    scanf("%s%s%d", va, vb, &weight);
    int i = locate_vex(*G, va);
    int j = locate_vex(*G, vb);
    p = (ArcNode *)malloc(sizeof(ArcNode));
    p->adjvex = j;
    p->info = weight;
    p->nextarc = G->vertices[i].firstarc;
    G->vertices[i].firstarc = p;
  }
  printf("create the graph successful!\n");
  return OK;
}

/**
 * @brief
 *
 * @param G
 */
void destory_graph(AlGraph *G)
{
  for (int i = 0; i < G->vexnum; ++i)
  {
    ArcNode *p = G->vertices[i].firstarc;
    while (p)
    {
      ArcNode *tmp = p->nextarc;
      free(p);
      p = tmp;
    }
  }
  free(G->vertices);
  G->arcnum = 0;
  G->vexnum = 0;
  printf("free all space complete!\n");
}

/**
 * @brief
 *
 * @param G
 * @param v
 * @param value
 * @return int
 */
int put_vex(AlGraph *G, VertexType v, VertexType value)
{
  int loc_v = locate_vex(*G, v);
  if (loc_v < 0)
  {
    printf("can't find the vertex node location!\n");
    return ERROR;
  }
  strcpy(G->vertices[loc_v].data, value);
  printf("put the vex complete!\n");
  return OK;
}

/**
 * @brief
 *
 * @param G
 * @param v
 * @return int
 */
int first_adjvex(AlGraph G, VertexType v)
{
  int loc_v = locate_vex(G, v);
  if (loc_v < 0)
  {
    printf("can't find the vertex node location!\n");
    return ERROR;
  }
  ArcNode *p = G.vertices[loc_v].firstarc;
  int res = -1;
  if (p)
    res = p->adjvex;
  printf("first adjvex function complete!\n");
  return res;
}

/**
 * @brief
 *
 * @param G
 * @param v
 * @param w
 * @return int
 */
int next_adjvex(AlGraph G, VertexType v, VertexType w)
{
  int loc_v = locate_vex(G, v);
  int loc_w = locate_vex(G, w);
  if (loc_v < 0 || loc_w < 0)
  {
    printf("can't find the vertex node location!\n");
    return ERROR;
  }
  int res;
  ArcNode *p = G.vertices[loc_v].firstarc;
  while (p && p->adjvex != loc_w)
    p = p->nextarc;
  if (!p || !p->nextarc)
    res = -1;
  else
    res = p->adjvex;
  printf("next adjvex function successful!\n");
  return res;
}

/**
 * @brief
 *
 * @param G
 * @param v
 */
int insert_vex(AlGraph *G, VertexType v)
{
  int loc_v = locate_vex(*G, v);
  if (loc_v != -1)
  {
    printf("have the same node\n");
    return ERROR;
  }
  strcpy(G->vertices[G->vexnum].data, v);
  G->vertices[G->vexnum].firstarc = nullptr;
  ++G->vexnum;
  printf("insert the vex successful!\n");
  return OK;
}

int delete_vex(AlGraph *G, VertexType v)
{
  int loc_v = locate_vex(*G, v);
  if (loc_v < 0)
  {
    printf("can't find the vertex node location!\n");
    return ERROR;
  }
  ArcNode *p = G->vertices[loc_v].firstarc;
  ArcNode *tmp = nullptr;
  while (p)
  {
    tmp = p;
    p = p->nextarc;
    free(tmp);
    --G->arcnum;
  }
  --G->vexnum;
  for (int i = loc_v; i < G->vexnum; ++i)
    G->vertices[i] = G->vertices[i + 1];

  for (int i = 0; i < G->vexnum; ++i)
  {
    p = G->vertices[i].firstarc;
    while (p)
    {
      if (p->adjvex == loc_v)
      {
        if (p == G->vertices[i].firstarc)
        {
          G->vertices[i].firstarc = p->nextarc;
          free(p);
          p = G->vertices[i].firstarc;
          --G->arcnum;
        }
        else
        {
          tmp->nextarc = p->nextarc;
          free(p);
          p = tmp->nextarc;
          --G->arcnum;
        }
      }
      else
      {
        if (p->adjvex > loc_v)
        {
          --p->adjvex;
        }
        tmp = p;
        p = p->nextarc;
      }
    }
  }
  printf("delete the vex function complete!\n");
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
int insert_arc(AlGraph *G, VertexType v, VertexType w)
{
  int loc_v = locate_vex(*G, v);
  int loc_w = locate_vex(*G, w);
  if (loc_v < 0 || loc_w < 0)
  {
    printf("can't find the vertex node location!\n");
    return ERROR;
  }
  ++G->arcnum;
  printf("please input the arc v->w's weight\n");
  int weight;
  scanf("%d", &weight);
  ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
  if (!p)
  {
    printf("malloc failed!\n");
    return ERROR;
  }
  p->adjvex = loc_w;
  p->info = weight;
  p->nextarc = G->vertices[loc_v].firstarc;
  G->vertices[loc_v].firstarc = p;
  printf("insert arc function complete!\n");
  return OK;
}

/**
 * @brief
 * delete the arc <v,w>
 * @param G
 * @param v
 * @param w
 * @return int
 */
int delete_arc(AlGraph *G, VertexType v, VertexType w)
{
  int loc_v = locate_vex(*G, v);
  int loc_w = locate_vex(*G, w);
  if (loc_v < 0 || loc_w < 0)
  {
    printf("can't find the vertex node location!\n");
    return ERROR;
  }
  ArcNode *p = G->vertices[loc_v].firstarc;
  ArcNode *tmp;
  while (p && p->adjvex != loc_w)
  {
    tmp = p;
    p = p->nextarc;
  }
  if (p && p->adjvex == loc_w)
  {
    if (p == G->vertices[loc_v].firstarc)
      G->vertices[loc_v].firstarc = p->nextarc;
    else
      tmp->nextarc = p->nextarc;
    free(p);
    --G->arcnum;
  }
  printf("delete the arc function complete!\n");
  return OK;
}

bool visited[MAX_VERTEX_NUM];
/**
 * @brief
 *
 * @param G
 * @param i
 */
void dfs(AlGraph G, int i)
{
  visited[i] = true;
  printf("%s ", G.vertices[i].data);
  ArcNode *p = G.vertices[i].firstarc;
  while (p)
  {
    if (!visited[p->adjvex])
      dfs(G, p->adjvex);
    p = p->nextarc;
  }
}

/**
 * @brief
 *
 * @param G
 */
void dfs_traverse(AlGraph G)
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
void bfs_traverse(AlGraph G)
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
      printf("%s ", G.vertices[i].data);
      push(&Q, i);
      while (!is_empty(Q))
      {
        pop(&Q, &i);
        ArcNode *p = G.vertices[i].firstarc;
        while (p)
        {
          if (!visited[p->adjvex])
          {
            visited[p->adjvex] = true;
            printf("%s ", G.vertices[p->adjvex].data);
            push(&Q, p->adjvex);
          }
          p = p->nextarc;
        }
      }
    }
  }
}

int indegree[MAX_VERTEX_NUM] = {0};

/**
 * @brief
 *
 * @param G
 */
void find_indegree(AlGraph G)
{
  ArcNode *p;
  for (int i = 0; i < G.vexnum; ++i)
  {
    p = G.vertices[i].firstarc;
    while (p)
    {
      indegree[p->adjvex]++;
      p = p->nextarc;
    }
  }
}

/**
 * @brief
 *
 * @param G
 */
void topologicalsort(AlGraph G)
{
  find_indegree(G);
  SqStack s;
  ElementType pop_index;
  initStack(&s);
  int count = 0;
  ArcNode *p;
  for (int i = 0; i < G.vexnum; ++i)
  {
    if (!indegree[i])
      push_s(&s, i);
  }
  while (!is_empty_stack(s))
  {
    pop_s(&s, &pop_index);
    printf("%s ", G.vertices[pop_index].data);
    ++count;
    for (p = G.vertices[pop_index].firstarc; p; p = p->nextarc)
    {
      int push_index = p->adjvex;
      if (!(--indegree[push_index]))
        push_s(&s, push_index);
    }
  }
  if (count < G.vexnum)
    printf("the graph has a loop\n");
}

/**
 * @brief
 *
 * @param G
 */
void display(AlGraph G)
{
  printf("the vertex and the node is as follow!\n");
  for (int i = 0; i < G.vexnum; ++i)
  {
    printf("the [%d] vertex is [%s] the arc is =>\n", i + 1, G.vertices[i].data);
    ArcNode *p = G.vertices[i].firstarc;
    while (p)
    {
      printf("=> the vertex node name is [%s] , the weight is [%d]\n",
             G.vertices[p->adjvex].data, p->info);
      p = p->nextarc;
    }
    printf("=====================>\n");
  }
}
