#include <stdio.h>

int main() {
    int n, i;

    // Get the value of n from the user
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Factors of %d are: ", n);

    // Loop from 1 to n to find the factors
    for(i = 1; i <= n; i++) {
        if(n % i == 0) { // Check if i is a factor of n
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}

