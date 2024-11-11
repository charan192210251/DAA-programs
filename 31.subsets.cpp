#include <stdio.h>

int total = 0;

void subsetSum(int set[], int subset[], int n, int subsetSize, int sum, int targetSum, int index) {
    if (sum == targetSum) {
        for (int i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }

    for (int i = index; i < n; i++) {
        if (sum + set[i] <= targetSum) {
            subset[subsetSize] = set[i];
            subsetSum(set, subset, n, subsetSize + 1, sum + set[i], targetSum, i + 1);
        }
    }
}

int main() {
    int n, targetSum;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int set[n], subset[n];
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);
    printf("Subsets with the given sum:\n");
    subsetSum(set, subset, n, 0, 0, targetSum, 0);
    return 0;
}

