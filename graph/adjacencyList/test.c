#include "adjacency_list.c"

int main() {
  VertexType v1, v2;
  AlGraph g;
  create_graph(&g);
  printf("bfs_traverse\n");
  bfs_traverse(g);
  printf("\n");
  printf("dfs_traverse\n");
  dfs_traverse(g);
  printf("\n");
  display(g);
  printf("the topologiscalsort\n");
  topologicalsort(g);
  printf("\n");
  printf("删除一条弧，请输入待删除弧的弧尾 弧头:");
  scanf(" %s%s", v1, v2);
  delete_arc(&g, v1, v2);
  printf("\n修改顶点的值，请输入原值 新值: ");
  scanf(" %s%s", v1, v2);
  put_vex(&g, v1, v2);
  printf("\n插入新顶点，请输入顶点的值: ");
  scanf("%s", v1);
  insert_vex(&g, v1);
  printf("\n插入与新顶点有关的弧，请输入弧数: ");
  int n;
  scanf("%d", &n);
  for (int k = 0; k < n; k++) {
    printf("\n请输入另一顶点的值: ");
    scanf("%s", v2);
    insert_arc(&g, v2, v1);
  }
  printf("\n");
  display(g);
  printf("删除顶点及相关的弧，请输入顶点的值: ");
  scanf("%s", v1);
  delete_vex(&g, v1);
  printf("\n");
  display(g);
  destory_graph(&g);
  return 0;
}