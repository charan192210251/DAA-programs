#include <stdio.h>
#include <stdbool.h>
#define MAX_NODES 100
void generateCompleteGraph(int graph[MAX_NODES][MAX_NODES], int nodes) {
    for (int i = 0; i < nodes; i++)
        for (int j = 0; j < nodes; j++)
            graph[i][j] = (i != j);
}
bool isSafe(int v, int graph[MAX_NODES][MAX_NODES], int path[], int pos) {
    if (!graph[path[pos - 1]][v]) return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v) return false;
    return true;
}
bool hamiltonianCycleUtil(int graph[MAX_NODES][MAX_NODES], int path[], int pos, int nodes) {
    if (pos == nodes) return graph[path[pos - 1]][path[0]];
    for (int v = 1; v < nodes; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamiltonianCycleUtil(graph, path, pos + 1, nodes)) return true;
            path[pos] = -1;
        }
    }
    return false;
}
void findHamiltonianCycle(int graph[MAX_NODES][MAX_NODES], int nodes) {
    int path[MAX_NODES];
    for (int i = 0; i < nodes; i++) path[i] = -1;
    path[0] = 0;
    if (hamiltonianCycleUtil(graph, path, 1, nodes)) {
        printf("Hamiltonian Cycle found: ");
        for (int i = 0; i < nodes; i++) printf("%d ", path[i]);
        printf("%d\n", path[0]);
    } else {
        printf("No Hamiltonian Cycle found.\n");
    }
}
int main() {
    int nodes, graph[MAX_NODES][MAX_NODES];
    printf("Enter number of nodes (max %d): ", MAX_NODES);
    scanf("%d", &nodes);
    if (nodes < 3 || nodes > MAX_NODES) {
        printf("Invalid number of nodes.\n");
        return 1;
    }
    generateCompleteGraph(graph, nodes);
    findHamiltonianCycle(graph, nodes);
    return 0;
}

