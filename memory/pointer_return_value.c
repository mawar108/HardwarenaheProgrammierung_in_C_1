#include <stdio.h>
#include <stdlib.h>

int* create_array_correct(void){
    // Allocate memory dynamically on the heap. It will not be released until
    // we call free(...).
    int *array = malloc(3 * sizeof(int));
    array[0] = 100;
    array[1] = 200;
    array[2] = 300;
    return array;
}

int* array_pass_through(int *array){
    // This is ok because the array lives outside of this function.
    return array;
}

int* create_array_incorrect(void){
    // This array is created on the stack and stops existing as soon as the
    // function returns. Returning a pointer to it is a mistake!
    int array[3] = {100, 200, 300};
    return array;
}

int main(void){
    int *array1 = create_array_correct();

    printf("The first value is %i.\n", array1[0]);

    // Remember to release memory once we are done with it.
    free(array1);

    int array2[3] = {100, 200, 300};

    int *pointer2 = array_pass_through(array2);

    // The pointer points to array2, which lives in main, so it is ok to use it.
    printf("The first value is %i.\n", pointer2[0]);

    int *array3 = create_array_incorrect();

    printf("The first value is %i or maybe the program crashes first.\n",
        array3[0]);

    return 0;
}
