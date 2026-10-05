#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_realloc(void *ptr, size_t old_size, size_t new_size) {
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }

    void *new_ptr = malloc(new_size);

    if (new_ptr == NULL) {
        return NULL;
    }

    if (ptr != NULL) {
        size_t copy_size = old_size < new_size ? old_size : new_size;
        memcpy(new_ptr, ptr, copy_size);
        free(ptr);
    }

    return new_ptr;
}

int main(void) {
    int *array = malloc(3 * sizeof(*array));

    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    array[0] = 10;
    array[1] = 20;
    array[2] = 30;

    printf("Original array:");
    for (int i = 0; i < 3; i++) {
        printf(" %d", array[i]);
    }
    printf("\n");

    int *temp = my_realloc(array,
                          3 * sizeof(*array),
                          5 * sizeof(*array));

    if (temp == NULL) {
        printf("Memory resizing failed.\n");
        free(array);
        return 1;
    }

    array = temp;
    array[3] = 40;
    array[4] = 50;

    printf("Array after growing:");
    for (int i = 0; i < 5; i++) {
        printf(" %d", array[i]);
    }
    printf("\n");

    temp = my_realloc(array,
                      5 * sizeof(*array),
                      2 * sizeof(*array));

    if (temp == NULL) {
        printf("Memory resizing failed.\n");
        free(array);
        return 1;
    }

    array = temp;

    printf("Array after shrinking:");
    for (int i = 0; i < 2; i++) {
        printf(" %d", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}
