#include <stdio.h>
#include <limits.h>

// Function to calculate the sum of frequencies from i to j
int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) {
        s += freq[k];
    }
    return s;
}

// Function to build the OBST using dynamic programming
int optimalSearchTree(int keys[], int freq[], int n) {
    int cost[n][n]; // cost[i][j] stores the minimum cost of OBST for keys[i..j]

    // Initialize the cost of single keys (single nodes)
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }

    // Build the table for subtrees of increasing size
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            cost[i][j] = INT_MAX;

            // Try making each key in keys[i..j] as the root
            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) + 
                        ((r < j) ? cost[r + 1][j] : 0) + 
                        sum(freq, i, j);

                if (c < cost[i][j]) {
                    cost[i][j] = c;
                }
            }
        }
    }

    return cost[0][n - 1]; // Minimum cost of OBST for keys[0..n-1]
}

int main() {
    int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    int keys[n], freq[n];
    printf("Enter the keys:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }

    printf("Enter the frequencies:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }

    int minCost = optimalSearchTree(keys, freq, n);
    printf("The minimum cost of the Optimal Binary Search Tree is: %d\n", minCost);

    return 0;
}

