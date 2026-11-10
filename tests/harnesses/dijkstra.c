#define main lab_demo_main
#include "../../lab08-dijkstra/main.c"
#undef main
#include <assert.h>

int main(void)
{
    int graph[5][5], distances[5];
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            graph[i][j] = INF;
    ShortestPath(graph, 0, distances);
    assert(distances[0] == 0);
    for (int i = 1; i < 5; ++i)
        assert(distances[i] == INT_MAX);
    graph[0][1] = 0;
    graph[1][2] = 7;
    graph[0][2] = 20;
    graph[2][3] = 2;
    ShortestPath(graph, 0, distances);
    assert(distances[1] == 0 && distances[2] == 7 && distances[3] == 9);
    assert(distances[4] == INT_MAX);
    graph[0][1] = INT_MAX - 5;
    graph[0][2] = INF;
    graph[1][2] = 10;
    ShortestPath(graph, 0, distances);
    assert(distances[1] == INT_MAX - 5 && distances[2] == INT_MAX);
    ShortestPath(graph, 4, distances);
    assert(distances[4] == 0 && distances[0] == INT_MAX);
    return 0;
}
