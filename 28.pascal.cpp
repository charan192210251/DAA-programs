#include <stdio.h>
int main() {
    int n, i, j, val, space;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (space = 0; space < n - i - 1; space++) {
            printf("  ");
        }
        val = 1;
        for (j = 0; j <= i; j++) {
            printf("%4d", val);
            val = val * (i - j) / (j + 1);
        }
        printf("\n");
    }
    return 0;
}

