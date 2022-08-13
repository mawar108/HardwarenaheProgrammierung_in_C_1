#include <stdio.h>

void stackoverflow(void){
    // Create an array with 10 million bytes on the stack.
    // On many systems, the stack size is limited to 8 MB, so this should crash.
    // This probably would have worked if malloc was used instead.
    // Another way to trigger stackoverflows are recursive functions, since
    // function parameters and return addresses are often stored on the stack.
    char array[10 * 1024 * 1024];

    for (int i = 0; i < 10 * 1024 * 1024; i++){
        array[i] = 0;
    }

    printf("%c\n", array[0]);
}

int main(void){
    stackoverflow();

    return 0;
}
