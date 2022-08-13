#include <stdio.h> // For printf
#include <stdlib.h> // For malloc and free

int main(void){
    int x = 42;
    printf("x has the value %i.\n", x);
    printf("x lives on the stack and has the address %p.\n", &x);
    printf("x occupies %zu byte on the stack.\n", sizeof(x));
    printf("\n");

    int y;
    // ERROR: The variable y has not been initialized. Its initial value is
    // undefined (it could be any value). The variable should not be read.
    printf("y has the value %d.\n", y);
    printf("y has the address %p.\n", &y);
    printf("\n");

    // A pointer saves the address of x.
    int *pointer_to_x = &x;
    printf("The address of x is still %p.\n", pointer_to_x);

    // We can change the value of x using the pointer on x.
    *pointer_to_x = 123;

    printf("x now has the value %i\n", x);
    printf("\n");

    int a[3];
    printf("The array 'a' occupies %zu byte on the stack.\n", sizeof(a));
    printf("The address of 'a' is                      %p.\n", a);
    printf("The address of the first integer in 'a' is %p, too!\n", &a[0]);
    printf("The address of the second integer is       %p.\n", &a[1]);
    printf("The address of the third integer is        %p.\n", a + 2);
    // Alternatively, "&a[2]" can be written as "a + 2".
    printf("\n");

    // ERROR:
    // The following statements could print any value, because the array 'a'
    // has not been initialized.
    printf("The first  integer has the value: %i\n", a[0]);
    printf("The second integer has the value: %i\n", a[1]);
    printf("The third  integer has the value: %i\n", *(a + 2));
    // Alternatively, "a[2]" can be written as "*(a + 2)"

    // ERROR:
    // a[3] is out of bounds for the array. Only 0, 1 and 2 are valid.
    printf("The fourth integer has the value %i or maybe we crash.\n", a[3]);
    printf("\n");

    // The malloc function can be used to allocate a certain number of bytes on
    // the heap. It will return an address to the allocated memory region. We
    // may use the memory to store any type of data.

    // You will not have to use malloc for this or the next exercise sheet yet.
    // Its reappearance will have to wait until exercise sheet 3.

    // Note:
    // In this lecture, you may assume that sizeof(int) is 4, but it might be
    // only 2 instead on different systems, e.g. microcontrollers.
    // The C99 standard only guarantees that an int can store values between
    // -32767 and +32767.

    // Now reserving 3 * sizeof(int) = 3 * 4 = 12 bytes on the heap.
    int *q = malloc(3 * sizeof(int));
    printf("Pointer q lives on the stack and has the address     %p.\n", &q);
    printf("Pointer q points to memory on the heap with address  %p.\n", q);
    printf("The address of the second integer pointed to by q is %p.\n", &q[1]);
    printf("\n");

    // malloc does not initialize the reserved memory. It could have any value!
    // Remember to initialize the memory that you are pointing to.
    *q = 100;
    *(q + 1) = 101;
    q[2] = 102;

    printf("q[1] has the value %i\n\n", q[1]);
    q[1]++;
    printf("q[1] has been incremented and now has the value %i\n", q[1]);

    // Release the allocated memory, so other processes may use it.
    // Many operating systems automatically release all memory once a program
    // exits, but if your program runs longer, it will become necessary to
    // release memory so it does not run out. Remember to release all your
    // memory once you are done with it!
    free(q);

    return 0;
}
