#include <stdio.h>
#define MAX 10

int graph[MAX][MAX], colors[MAX], n;

int isSafe(int node, int color) {
    for (int i = 0; i < n; i++) {
        if (graph[node][i] && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

int graphColoring(int node, int m) {
    if (node == n) {
        return 1;
    }
    for (int color = 1; color <= m; color++) {
        //vertices=3, matrix: 011 101 110, colors=3.
        if (isSafe(node, color)) {
            colors[node] = color;
            if (graphColoring(node + 1, m)) {
                return 1;
            }
            colors[node] = 0;
        }
    }
    return 0;
}

int main() {
    int m;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the number of colors: ");
    scanf("%d", &m);

    if (graphColoring(0, m)) {
        printf("Solution exists with the following coloring:\n");
        for (int i = 0; i < n; i++) {
            printf("Vertex %d -> Color %d\n", i, colors[i]);
        }
    } else {
        printf("No solution exists with %d colors.\n", m);
    }
    return 0;
}

