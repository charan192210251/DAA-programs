#include <stdio.h>

int main() {
    int numItems, i;
    float capacity, totalWeight = 0.0, itemWeight;

    // Get container capacity from user
    printf("Enter the container capacity (in kg): ");
    scanf("%f", &capacity);

    // Get the number of items to load
    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    float itemWeights[numItems];

    // Get the weights of all items from user
    for(i = 0; i < numItems; i++) {
        printf("Enter the weight of item %d (in kg): ", i + 1);
        scanf("%f", &itemWeights[i]);
    }

    // Try to load items into the container
    for(i = 0; i < numItems; i++) {
        itemWeight = itemWeights[i];

        // Check if adding the item exceeds the container capacity
        if(totalWeight + itemWeight > capacity) {
            printf("Container is full, cannot load more items.\n");
            break;
        } else {
            totalWeight += itemWeight;
            printf("Item %d (weight: %.2f kg) loaded successfully. Total weight: %.2f kg\n", i + 1, itemWeight, totalWeight);
        }
    }

    if(totalWeight == capacity) {
        printf("Container is now full.\n");
    } else {
        printf("Total weight loaded into the container: %.2f kg\n", totalWeight);
    }

    return 0;
}

