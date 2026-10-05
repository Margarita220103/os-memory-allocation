#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    long long sum = 0;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    int *array = calloc((size_t)n, sizeof(*array));

    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Array after calloc:");
    for (int i = 0; i < n; i++) {
        printf(" %d", array[i]);
    }
    printf("\n");

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &array[i]) != 1) {
            printf("Invalid input.\n");
            free(array);
            return 1;
        }
        sum += array[i];
    }

    printf("Updated array:");
    for (int i = 0; i < n; i++) {
        printf(" %d", array[i]);
    }
    printf("\n");

    double average = (double)sum / n;
    printf("Average of the array: %.2f\n", average);

    free(array);
    return 0;
}
