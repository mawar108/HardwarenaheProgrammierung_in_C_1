#include "reverse.h"
#include <stdlib.h>

#test reverse_long
    size_t count = 10000000;
    // Allocate memory for 10 million integers
    int *array = malloc(sizeof(int) * count);
    int *reversed = malloc(sizeof(int) * count);

    for (size_t i = 0; i < count; i++){
        array[i] = i;
        reversed[i] = count - 1 - i;
    }

    // Reverse 10 million values
    reverse(array, count, 0, count);

    // Check if arrays are equal
    for (size_t i = 0; i < count; i++){
        if (array[i] != reversed[i]){
            ck_assert_int_eq(array[i], reversed[i]);
        }
    }

    // Free memory
    free(array);
    free(reversed);
