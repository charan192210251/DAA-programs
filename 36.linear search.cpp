#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return index if element is found
        }
    }
    return -1;  // Return -1 if element is not found
}

int main() {
    int size, target;

    // Input array size
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];  // Declare the array with the given size

    // Input array elements
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the target element to search
    printf("Enter the element to search for: ");
    scanf("%d", &target);

    int result = linearSearch(arr, size, target);

    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}

