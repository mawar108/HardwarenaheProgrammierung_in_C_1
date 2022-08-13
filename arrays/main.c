#include "arrays.h"

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int main(void) {
    size_t length;
    int *array;

    printf("Wie viele Zahlen sollen eingelesen werden? ");
    if (scanf("%zu", &length) != 1) {
        printf("Die Eingabe ist ungueltig!\n");
        return EXIT_FAILURE;
    }
    array = malloc(sizeof(int) * length);

    printf("Bitte geben Sie %zu Zahlen ein:\n", length);
    read_numbers(array, length);

    print_max_of_thirds(array, length);

    free(array);
    return EXIT_SUCCESS;
}
