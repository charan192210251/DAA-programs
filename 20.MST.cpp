#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 100 // Maximum number of vertices

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[], int vertices) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < vertices; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

//vertices=4, matrix: 0206, 2038, 0300, 6800.
// Function to print the constructed MST and calculate the total weight
void printMST(int parent[], int graph[V][V], int vertices) {
    int totalWeight = 0;
    printf("Edge \tWeight\n");
    for (int i = 1; i < vertices; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]]; // Sum the weights
    }
    printf("Total Minimum Weight of MST: %d\n", totalWeight);
}

// Function to construct and print the MST using Prim's algorithm
void primMST(int graph[V][V], int vertices) {
    int parent[V]; // Array to store the constructed MST
    int key[V];    // Key values used to pick the minimum weight edge
    bool mstSet[V]; // To represent the set of vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Include the first vertex in MST
    key[0] = 0;
    parent[0] = -1; // First node is always the root of the MST

    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet, vertices);
        mstSet[u] = true;

        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, vertices);
}

int main() {
    int vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[V][V];
    printf("Enter the adjacency matrix (use 0 for no connection):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, vertices);

    return 0;
}

