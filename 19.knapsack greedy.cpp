
#include <stdio.h>
#include <stdlib.h>

// Structure for an item
struct Item {
    int value;
    int weight;
    float ratio; // Value-to-weight ratio
};

// Comparison function for sorting items based on value-to-weight ratio
int compare(const void *a, const void *b) {
    float ratio1 = ((struct Item*)a)->ratio;
    float ratio2 = ((struct Item*)b)->ratio;
    return (ratio2 - ratio1 > 0) - (ratio2 - ratio1 < 0);
}

// Function to solve the Fractional Knapsack problem using Greedy approach
// items=4, capacity=50, value and weight: 60 10, 100 20, 120 30, 80 20.
float knapsack(struct Item items[], int n, int capacity) {
    // Sort items by value-to-weight ratio in descending order
    qsort(items, n, sizeof(struct Item), compare);
    
    float totalValue = 0.0;
    int remainingCapacity = capacity;
    
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remainingCapacity) {
            // Take the whole item
            remainingCapacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take the fraction of the item that fits
            totalValue += items[i].value * ((float)remainingCapacity / items[i].weight);
            break;
        }
    }
    
    return totalValue;
}

int main() {
    int n, capacity;
    
    // Input number of items and knapsack capacity
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    
    struct Item items[n];
    
    // Input value, weight and calculate value-to-weight ratio for each item
    printf("Enter the value and weight for each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }
    
    // Calculate the maximum value that can be obtained
    float maxValue = knapsack(items, n, capacity);
    
    // Output the result
    printf("Maximum value that can be obtained: %.2f\n", maxValue);
    
    return 0;
}

