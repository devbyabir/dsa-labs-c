/* DSA Lab 8: dijkstra. Reviewed in 2026. */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 9999999

int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < 5; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void ShortestPath(int graph[5][5], int src, int length[5]) {
    int dist[5];
    int sptSet[5];
    for (int i = 0; i < 5; i++)
        dist[i] = INT_MAX, sptSet[i] = 0;
    dist[src] = 0;
    for (int count = 0; count < 5 - 1; count++) {
        int u = minDistance(dist, sptSet);
        if (u < 0 || dist[u] == INT_MAX) break;
        sptSet[u] = 1;
        for (int v = 0; v < 5; v++)
            if (!sptSet[v] && graph[u][v] != INF && dist[u] != INT_MAX && graph[u][v] <= INT_MAX - dist[u] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    for (int i = 0; i < 5; i++)
        length[i] = dist[i];
}

int main(void) {
    int graph[5][5] = {
        {INF, 10, 5, INF, INF},
        {INF, INF, INF, 1, INF},
        {INF, 3, INF, 9, 2},
        {INF, INF, INF, INF, 4},
        {3, INF, 6, INF, INF}
    };

    int length[5];
    ShortestPath(graph, 0, length);

    for (int i = 0; i < 5; i++)
        printf("The shortest path between V0 and V%d is %d\n", i, length[i]);

    return 0;
}
