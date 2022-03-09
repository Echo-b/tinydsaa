#include "adjacency_matrix.c"

int main() {
  int i, j, k, n;
  VertexType v1, v2;
  MGraph g;
  create_graph(&g);
  printf("bfs_traverse\n");
  bfs_traverse(g);
  printf("\n");
  printf("dfs_traverse\n");
  dfs_traverse(g);
  printf("\n+-----------------------------+\n");
  printf("prime result\n");
  printf("+-----------------------------+\n");
  mini_span_tree(g);
  printf("+-----------------------------+\n");
  printf("kruskal result:\n");
  printf("+-----------------------------+\n");
  mini_span_tree_kruskal(g);
  printf("+-----------------------------+\n");
  Pathmartix P;
  ShortPathTable D;
  shortest_path_dijkstra(g, 5, &P, &D);
  show_shortest_path(g, P, D, 5);
  Pathmartix_floyd P_floyd;
  ShortPathTable_floyd D_floyd;
  shortest_path_floyd(g, &P_floyd, &D_floyd);
  display_floyd_path(g, P_floyd, D_floyd);
  // display(g);
  // printf("修改顶点的值，请输入原值 新值: \n");
  // scanf("%s%s", v1, v2);
  // put_vex(&g, v1, v2);
  // printf("删除一条边或弧，请输入待删除边或弧的弧尾 弧头:\n");
  // scanf("%s%s", v1, v2);
  // delete_arc(&g, v1, v2);
  // display(g);
  // printf("插入新顶点，请输入顶点的值: ");
  // scanf("%s", v1);
  // insert_vex(&g, v1);
  // printf("\n插入与新顶点有关的边，请输入边数: ");
  // scanf("%d", &n);
  // for (k = 0; k < n; k++)
  // {
  //   printf("\n请输入另一顶点的值: ");
  //   scanf("%s", v2);
  //   insert_arc(&g, v1, v2);
  // }
  // printf("\n");
  // display(g);
  // printf("删除顶点及相关边，请输入顶点的值: ");
  // scanf("%s", v1);
  // printf("\n");
  // delete_vex(&g, v1);
  // display(g);
  destory_graph(&g);
  return 0;
}