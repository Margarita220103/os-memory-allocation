#include <stdio.h>
#include <stdlib.h>

void free_strings(char **strings, int count) {
    for (int i = 0; i < count; i++) {
        free(strings[i]);
    }
    free(strings);
}

int main(void) {
    char **strings = malloc(3 * sizeof(*strings));

    if (strings == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter 3 strings (up to 50 characters each, no spaces):\n");

    for (int i = 0; i < 3; i++) {
        strings[i] = malloc(51 * sizeof(char));

        if (strings[i] == NULL) {
            printf("Memory allocation failed.\n");
            free_strings(strings, i);
            return 1;
        }

        if (scanf("%50s", strings[i]) != 1) {
            printf("Invalid input.\n");
            free_strings(strings, i + 1);
            return 1;
        }
    }

    printf("First 3 strings:");
    for (int i = 0; i < 3; i++) {
        printf(" %s", strings[i]);
    }
    printf("\n");

    char **temp = realloc(strings, 5 * sizeof(*strings));

    if (temp == NULL) {
        printf("Memory resizing failed.\n");
        free_strings(strings, 3);
        return 1;
    }

    strings = temp;

    printf("Enter 2 more strings:\n");

    for (int i = 3; i < 5; i++) {
        strings[i] = malloc(51 * sizeof(char));

        if (strings[i] == NULL) {
            printf("Memory allocation failed.\n");
            free_strings(strings, i);
            return 1;
        }

        if (scanf("%50s", strings[i]) != 1) {
            printf("Invalid input.\n");
            free_strings(strings, i + 1);
            return 1;
        }
    }

    printf("All strings:");
    for (int i = 0; i < 5; i++) {
        printf(" %s", strings[i]);
    }
    printf("\n");

    free_strings(strings, 5);
    return 0;
}
