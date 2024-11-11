#include <stdio.h>
#include <limits.h>

#define N 4  // Size of the matrix (number of tasks and workers)

int cost[N][N];
int finalAssignment[N];
int minCost = INT_MAX;

void printSolution(int assignment[], int costMatrix[N][N]) {
    printf("Optimal Assignment:\n");
    for (int i = 0; i < N; i++) {
        printf("Task %d -> Worker %d\n", i + 1, assignment[i] + 1);
    }
    printf("Minimum Cost: %d\n", minCost);
}

int calculateCost(int assignment[], int costMatrix[N][N]) {
    int totalCost = 0;
    //matrix: 12 7 9 7, 8 6 10 9, 10 4 3 8, 7 5 8 6.
    for (int i = 0; i < N; i++) {
        totalCost += costMatrix[i][assignment[i]];
    }
    return totalCost;
}

void boundAndBranch(int costMatrix[N][N], int assignment[], int n, int level, int currentCost, int visited[]) {
    if (level == n) {
        // Base case: all tasks assigned
        if (currentCost < minCost) {
            minCost = currentCost;
            for (int i = 0; i < n; i++) {
                finalAssignment[i] = assignment[i];
            }
        }
        return;
    }

    // Loop through all workers to try assigning tasks
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            assignment[level] = i;
            int newCost = currentCost + costMatrix[level][i];
            if (newCost < minCost) {
                boundAndBranch(costMatrix, assignment, n, level + 1, newCost, visited);
            }
            visited[i] = 0;  // Backtrack
        }
    }
}

int main() {
    int assignment[N] = {-1, -1, -1, -1};  // Holds the final assignment
    int visited[N] = {0, 0, 0, 0};  // Keeps track of assigned workers

    // Input the entire cost matrix at once
    printf("Enter the cost matrix for the assignment problem (size %dx%d), space-separated values:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    boundAndBranch(cost, assignment, N, 0, 0, visited);
    printSolution(finalAssignment, cost);
    
    return 0;
}

