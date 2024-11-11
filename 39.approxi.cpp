#include <stdio.h>
#include <math.h>

#define MAX_CITIES 10
#define INF 99999

// Function to calculate the distance between two cities (Euclidean distance)
double distance(int city1[], int city2[]) {
    return sqrt(pow(city1[0] - city2[0], 2) + pow(city1[1] - city2[1], 2));
}

// Nearest Neighbor Approximation Algorithm for TSP
double nearestNeighbor(int cities[][2], int n) {
    int visited[n];
    int path[n];
    double totalDistance = 0.0;
    
    // Initialize visited array
    for (int i = 0; i < n; i++) {
        //cities=4, coordinates: 0 0, 1 2, 3 1, 4 4.
        visited[i] = 0;  // No cities are visited initially
    }

    visited[0] = 1;  // Start at the first city
    path[0] = 0;  // First city in the path
    int currentCity = 0;
    
    // Iterate through all cities
    for (int i = 1; i < n; i++) {
        double minDist = INF;
        int nextCity = -1;
        
        // Find the nearest unvisited city
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                double dist = distance(cities[currentCity], cities[j]);
                if (dist < minDist) {
                    minDist = dist;
                    nextCity = j;
                }
            }
        }
        
        // Mark the next city as visited and add it to the path
        visited[nextCity] = 1;
        path[i] = nextCity;
        totalDistance += minDist;
        currentCity = nextCity;
    }

    // Add the distance to return to the start city
    totalDistance += distance(cities[currentCity], cities[0]);

    // Print the path
    printf("Path: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");

    return totalDistance;
}

int main() {
    int n;

    // Input the number of cities
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    // Input the coordinates of the cities
    int cities[n][2];
    printf("Enter the coordinates of the cities (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cities[i][0], &cities[i][1]);
    }

    // Call the nearest neighbor algorithm
    double totalCost = nearestNeighbor(cities, n);

    printf("Total travel distance: %.2f\n", totalCost);

    return 0;
}

