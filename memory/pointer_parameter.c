#include <stdio.h>
#include <stdlib.h>

void change_value1(int *pointer, int new_value){
    *pointer = new_value;
}

// "int *pointer" and "int pointer[]" are the same in function SIGNATURES, but
// not elsewhere!
void change_value2(int pointer[], int new_value){
    // Same as change_value1
    pointer[0] = new_value;
}

int main(void){
    int value = 1;

    printf("The initial value is: %i\n", value);

    int *pointer = &value;

    // Change value to 42 using a pointer.
    change_value1(pointer, 42);

    printf("The updated value is: %i\n", value);

    // Change value to 1337 using a pointer.
    change_value2(&value, 1337);

    printf("The updated value is: %i\n", value);

    return 0;
}
