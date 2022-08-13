// This file contains some examples for different data types in C.
//
// See the C99-Standard for more details:
// https://port70.net/~nsz/c/c99/n1256.html#5.2.4.2.1
//
#include <stdio.h> // for printf
#include <limits.h> // for INT_MAX
#include <stdint.h> // for SIZE_MAX
#include <float.h> // for DBL_MAX

void example_int(void){
    int value = 123;

    printf("This is an int with value %i.\n", value);

    printf("The largest possible integer (on this machine) is %i.\n", INT_MAX);
    printf("The smallest possible integer (on this machine) is %i.\n", INT_MIN);
    printf("\n");

    // ERROR: Overflow for *signed* integer types is undefined.
    //value = INT_MAX + 1;
}

void example_unsigned(void){
    unsigned int value = 123u;

    printf("This is an unsigned int with value %u.\n", value);

    printf("The largest possible value (on this machine) is %u.\n", UINT_MAX);
    printf("The smallest possible value is 0.\n");

    value = UINT_MAX + 1;

    printf("UINT_MAX + 1 is %u.\n", value);
    printf("Overflow for *unsigned* integer types will wrap around to 0.\n");
    printf("This is fine and not an error, unlike for signed integers.\n");
    printf("\n");
}

void example_char(void){
    char value = 'A';

    printf("This is the character '%c'.\n", value);
    printf("In C, characters are stored as integers.\n");
    printf("The ASCII code of '%c' is %i.\n", value, value);
    printf("The data type \"char\" can be signed or unsigned (not defined).\n");

    printf("The largest possible value (on this machine) is %i.\n", CHAR_MAX);
    printf("The smallest possible value (on this machine) is %i.\n", CHAR_MIN);
    printf("\n");

}

void example_size_t(void){
    size_t value = SIZE_MAX;

    printf("The largest value for the type size_t (on this machine) is %zu.\n", value);
    printf("The smallest possible value is 0.\n");
    printf("This data type is often used for sizes and array indices.\n");
    printf("\n");
}

void example_double(void){
    double value = 1.0 / 3.0;

    printf("This is a value of type double: %.30f\n", value);
    printf("The largest possible value is %.20e.\n", DBL_MAX);
    printf("The smallest possible value is %e.\n", DBL_MIN);
    printf("Doubles are usually stored as base 2 floating point values.\n");
    printf("Therefore, they can not represent values such as 1/3 exactly.\n");
    printf("However, integers up to 2^53 can be stored exactly.\n");
    printf("Sums of fractions of powers of 2 can be stored exactly as well,\n");
    printf("for example 0.5 or 7.125.\n");
    printf("For more details, see the IEEE 754 standard.\n");
    printf("https://en.wikipedia.org/wiki/IEEE_754\n");
    printf("\n");
}

void sizes_in_bytes(void){
    printf("On this machine, these data types have these sizes in bytes:\n");
    printf("              char: %zu\n", sizeof(char));
    printf("       signed char: %zu\n", sizeof(signed char));
    printf("     unsigned char: %zu\n", sizeof(unsigned char));
    printf("             short: %zu\n", sizeof(short));
    printf("    unsigned short: %zu\n", sizeof(unsigned short));
    printf("               int: %zu\n", sizeof(int));
    printf("      unsigned int: %zu\n", sizeof(unsigned int));
    printf("              long: %zu\n", sizeof(long));
    printf("     unsigned long: %zu\n", sizeof(unsigned long));
    printf("         long long: %zu\n", sizeof(long long));
    printf("unsigned long long: %zu\n", sizeof(unsigned long long));
    printf("            size_t: %zu\n", sizeof(size_t));
    printf("             float: %zu\n", sizeof(float));
    printf("            double: %zu\n", sizeof(double));
    printf("              int*: %zu\n", sizeof(int*));
    printf("(All pointer types have the same size.)\n");
}

int main(void){
    example_int();
    example_unsigned();
    example_char();
    example_size_t();
    example_double();
    sizes_in_bytes();
    return 0;
}
