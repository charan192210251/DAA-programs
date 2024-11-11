#include <stdio.h>
#define INF 9999999
#define MAX 10
void floydWarshall(int graph[MAX][MAX], int n) {
    int dist[MAX][MAX], i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) dist[i][j] = 0;
            else if (graph[i][j] == 0) dist[i][j] = INF;
            else dist[i][j] = graph[i][j];
        }
    }
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    //vertices=4, matrix: 0300 3015 0102 0520.
    printf("The shortest distances between every pair of vertices are:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dist[i][j] == INF) printf("INF ");
            else printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int n, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int graph[MAX][MAX];
    printf("Enter the adjacency matrix (use 0 for no edge and a positive integer for edge weights):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    floydWarshall(graph, n);
    return 0;
}

