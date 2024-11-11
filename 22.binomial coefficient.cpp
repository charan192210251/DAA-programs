#include <stdio.h>

// Function to calculate Binomial Coefficient using dynamic programming
int binomialCoeff(int n, int k) {
    int C[n+1][k+1];

    // Calculate value of Binomial Coefficient in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= (i < k ? i : k); j++) {
            // Base Case: C(i, 0) = 1 and C(i, i) = 1
            if (j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                // Recursive Case: C(i, j) = C(i-1, j-1) + C(i-1, j)
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
    }

    return C[n][k]; // Return the binomial coefficient C(n, k)
}

int main() {
    int n, k;
    
    // Input values for n and k
    printf("Enter values of n and k: ");
    scanf("%d %d", &n, &k);

    // Output the binomial coefficient
    printf("Binomial Coefficient C(%d, %d) = %d\n", n, k, binomialCoeff(n, k));

    return 0;
}

