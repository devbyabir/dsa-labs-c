/* DSA Lab 9: prim. Reviewed in 2026. */
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int minimum_key(int key[], bool mstSet[], int n) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < n; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int n, int graph[MAX_VERTICES][MAX_VERTICES]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int n) {
    if (n < 1 || n > MAX_VERTICES) return;
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    bool mstSet[MAX_VERTICES];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n; count++) {
        int u = minimum_key(key, mstSet, n);
        if (u < 0) { puts("Graph is disconnected."); return; }
        mstSet[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, n, graph);
}

int main(void) {
    int n = 5;
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 0, 3, 0, 0},
        {0, 0, 10, 4, 0},
        {3, 10, 0, 2, 6},
        {0, 4, 2, 0, 1},
        {0, 0, 6, 1, 0}
    };

    primMST(graph, n);

    return 0;
}
