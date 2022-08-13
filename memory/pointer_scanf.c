#include <stdio.h>

int main(void){
    int value;

    printf("Please enter an integer:\n");

    int result = scanf("%d", &value);

    // ERROR: if scanf fails, the variable "value" will not be initialized!
    // Always check the return value of scanf.
    printf("The entered integer was: %i\n", value);
    printf("scanf returned the value %i\n", result);
    printf("\n");

    // Read two integers, but only print them if they both have been read.
    int value1, value2;
    printf("Please enter two integers.\n");
    result = scanf("%d %d", &value1, &value2);
    if (result == 2){
        printf("The first integer was: %d\n", value1);
        printf("The second integer was: %d\n", value2);
    }else{
        printf("Did not enter two integers correctly.\n");
    }
    printf("scanf returned the value %i\n", result);

    // ERROR: The pointer has not been initialized and therefore points to an
    // undefined address in memory. The scanf function will then try to write
    // the entered integer to that memory address, which might cause a
    // segmentation fault or corrupt arbitrary memory locations.
    // Make sure that your pointers always point to valid memory locations!
    printf("Please enter an integer and prepare for crash.\n");
    int *pointer;
    if (1 == scanf("%d", pointer)){
        printf("This might crash: %d\n", *pointer);
    }

    return 0;
}
