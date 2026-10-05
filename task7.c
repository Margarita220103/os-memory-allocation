#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void *aligned_malloc(size_t size, size_t alignment) {
    /* Require a nonzero power of two. */
    if (alignment == 0 || (alignment & (alignment - 1)) != 0) {
        return NULL;
    }

    /* Check that the allocation size will not overflow. */
    if (alignment - 1 > SIZE_MAX - sizeof(void *)) {
        return NULL;
    }

    size_t overhead = sizeof(void *) + alignment - 1;

    if (size == 0 || size > SIZE_MAX - overhead) {
        return NULL;
    }

    void *original = malloc(size + overhead);

    if (original == NULL) {
        return NULL;
    }

    uintptr_t start = (uintptr_t)original + sizeof(void *);
    size_t padding = (alignment - start % alignment) % alignment;
    unsigned char *aligned =
        (unsigned char *)original + sizeof(void *) + padding;

    /* Save the original address before the aligned block. */
    memcpy(aligned - sizeof(void *), &original, sizeof(original));

    return aligned;
}

void aligned_free(void *ptr) {
    if (ptr == NULL) {
        return;
    }

    void *original;
    memcpy(&original,
           (unsigned char *)ptr - sizeof(void *),
           sizeof(original));

    free(original);
}

int main(void) {
    size_t alignment = 32;
    int *array = aligned_malloc(5 * sizeof(*array), alignment);

    if (array == NULL) {
        printf("Aligned memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        array[i] = (i + 1) * 10;
    }

    printf("Requested alignment: %zu bytes\n", alignment);
    printf("Memory address: %p\n", (void *)array);
    printf("Address remainder: %zu\n",
           (size_t)((uintptr_t)array % alignment));

    printf("Array:");
    for (int i = 0; i < 5; i++) {
        printf(" %d", array[i]);
    }
    printf("\n");

    aligned_free(array);
    return 0;
}
