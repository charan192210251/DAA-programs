
#include <stdio.h>

#define MAX 16
#define INF 9999999   // Define a large number to represent infinity

int dp[1 << MAX][MAX];  // DP table to store the minimum cost
int dist[MAX][MAX];     // Matrix to store distances between cities

// Function to solve the Traveling Salesman Problem using Dynamic Programming and Bitmasking
int tsp(int mask, int pos, int n) {
    if (mask == (1 << n) - 1) {  // All cities have been visited
        return dist[pos][0];  // Return to the starting city
    }

    if (dp[mask][pos] != -1)  // If the result is already calculated, return it
        return dp[mask][pos];

    int ans = INF;
    //cities=4, matrix: 0 10 15 20, 10 0 35 25, 15 35 0 30, 20 25 30 0. 
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {  // If the city hasn't been visited
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city, n);
            ans = (ans < newAns) ? ans : newAns;  // Choose the minimum cost
        }
    }
    return dp[mask][pos] = ans;  // Store the result in DP table
}

int main() {
    int n;
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("The maximum number of cities supported is %d.\n", MAX);
        return -1;
    }

    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    // Initialize DP table with -1 (meaning uncalculated)
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    // Calculate the result starting from city 0, with only city 0 visited (mask = 1)
    int result = tsp(1, 0, n);  
    printf("The minimum cost of the tour is: %d\n", result);

    return 0;
}

