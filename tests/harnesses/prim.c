#define main lab_demo_main
#include "../../lab09-prim/main.c"
#undef main

int main(void)
{
    int graph[MAX_VERTICES][MAX_VERTICES] = {{0}};
    primMST(graph, 0); /* Invalid size must not access an array. */
    primMST(graph, MAX_VERTICES + 1);
    primMST(graph, 1);
    primMST(graph, 2); /* No connection: no uninitialized parent access. */
    graph[0][1] = graph[1][0] = 5;
    graph[0][2] = graph[2][0] = 1;
    graph[1][2] = graph[2][1] = 2;
    primMST(graph, 3);
    return 0;
}
