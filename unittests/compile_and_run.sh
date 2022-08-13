# Generate file "add_tests.c" from "add_tests.ts"

checkmk add_tests.ts > add_tests.c

# Compiler flags to use the check unit testing framework

BUILDFLAGS=$(pkg-config --libs --cflags check)

# Compiler flags for gcc to activate many warnings

CFLAGS="-Wall -Wextra -Werror -std=c99 -g -fsanitize=address -fsanitize=undefined"

# Print flags

printf "The compiler flags are:\n\t$CFLAGS\n\n"
printf "The build flags for check are:\n\t$BUILDFLAGS\n\n"

# Compile tests

gcc $CFLAGS add.c add_tests.c -o tests $BUILDFLAGS

# Compile main file to try out functions yourself (without tests)

gcc $CFLAGS add.c main.c -o main

# Run tests

printf "Running tests\n\n"

./tests

# Run main example program

printf "\nRunning main program\n\n"

./main
