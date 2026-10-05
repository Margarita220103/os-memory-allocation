#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *array = malloc(10 * sizeof(*array));

    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter 10 integers: ");
    for (int i = 0; i < 10; i++) {
        if (scanf("%d", &array[i]) != 1) {
            printf("Invalid input.\n");
            free(array);
            return 1;
        }
    }

    int *temp = realloc(array, 5 * sizeof(*array));

    if (temp == NULL) {
        printf("Memory resizing failed.\n");
        free(array);
        return 1;
    }

    array = temp;

    printf("Array after resizing:");
    for (int i = 0; i < 5; i++) {
        printf(" %d", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}
