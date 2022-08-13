#include "add.h"

#test add_zero
    int expected = 0;
    int result = add(0, 0);
    ck_assert_int_eq(result, expected);

#test add_nonzero
    int expected = 2;
    int result = add(1, 1);
    ck_assert_int_eq(result, expected);
