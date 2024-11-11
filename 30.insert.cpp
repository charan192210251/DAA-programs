#include <stdio.h>
int main() {
    int arr[100], n, pos, elem, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the position to insert (1 to %d): ", n + 1);
    scanf("%d", &pos);
    printf("Enter the element to insert: ");
    scanf("%d", &elem);
    for (i = n; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos - 1] = elem;
    n++;
    printf("Array after insertion:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

