#include "reverse.h"
#include <stdint.h>

// In dieser Datei müssen weitere Tests implementiert werden.

#test  reverse_1234
	int array[4] = {1, 2, 3, 4};
	int reversed[4] = {4, 3, 2, 1};

	// Reverse the array
	reverse(array, 4, 0, 4);

	// Check if the array is now equal to the reversed array
	for (size_t i = 0; i < 4; i++){
		ck_assert_int_eq(array[i], reversed[i]);
	}

#test  reverse_12345
	int array[5] = {1, 2, 3, 4, 5};
	int reversed[5] = {4, 3, 2, 1, 5};

	// Reverse the array
	reverse(array, 5, 0, 4);

	// Check if the array is now equal to the reversed array
	for (size_t i = 0; i < 5; i++){
		ck_assert_int_eq(array[i], reversed[i]);
	}


#test  reverse_12345_All_5
	int array[5] = {1, 2, 3, 4, 5};
	int reversed[5] = {5, 4, 3, 2, 1};

	// Reverse the array
	reverse(array, 5, 0, 5);

	// Check if the array is now equal to the reversed array
	for (size_t i = 0; i < 5; i++){
		ck_assert_int_eq(array[i], reversed[i]);
	}


#test reverse_subrange2
	int array[7] = {3, 4, 8, 2, 7, 1, 5};
	int reversed[7] = {3, 4, 1, 7, 2, 8, 5};

	// Reverse 4 values starting at index 2
	reverse(array, 7, 2, 4);

	// Check if the array is now equal to the reversed array
	for (size_t i = 0; i < 7; i++){
		ck_assert_int_eq(array[i], reversed[i]);
	}


#test reverse_1221
	int array[4] = {1, 2, 2, 1};
	int reversed[4] = {1, 2, 2, 1};

	// Reverse the array
	reverse(array, 4, 0, 4);

	// Check if the array is now equal to the reversed array
	for (size_t i = 0; i < 4; i++){
		ck_assert_int_eq(array[i], reversed[i]);
	}

#test reverse_subrange
	int array[7] = {3, 4, 1, 2, 2, 1, 5};
	int reversed[7] = {3, 4, 1, 2, 2, 1, 5};

	// Reverse 4 values starting at index 2
	reverse(array, 4, 2, 4);

	// Check if the array is now equal to the reversed array
	for (size_t i = 0; i < 7; i++){
		ck_assert_int_eq(array[i], reversed[i]);
	}

#test reverse_invalid_count_too_large
	int array[4] = {1, 2, 3, 4};
	int reversed[4] = {1, 2, 3, 4};

	reverse(array, 4, 0, 5);

	for (size_t i = 0; i < 4; i++){
		ck_assert_int_eq(array[i], reversed[i]);
	}

#test reverse_length_too_small
	reverse(NULL, 0, 0, 0);

#test invalid_count_too_small
	int array[4] = {1, 2, 3, 4};
	int reversed[4] = {1, 2, 3, 4};

	reverse(array, 4, 5, 0);

	for (size_t i = 0; i < 4; i++){
		ck_assert_int_eq(array[i], reversed[i]);
	}

	reverse(array, 4, 5, 1);

	for (size_t i = 0; i < 4; i++){
		ck_assert_int_eq(array[i], reversed[i]);
	}

#test invalid_index_too_large
	int array[4] = {1, 2, 3, 4};
	int reversed[4] = {1, 2, 3, 4};

	reverse(array, 4, 5, 2);

	for (size_t i = 0; i < 4; i++){
		ck_assert_int_eq(array[i], reversed[i]);
	}

	reverse(array, 4, 99999999, 0);

	for (size_t i = 0; i < 4; i++){
		ck_assert_int_eq(array[i], reversed[i]);
	}

	reverse(array, 4, 99999999, 1);

	for (size_t i = 0; i < 4; i++){
		ck_assert_int_eq(array[i], reversed[i]);
	}

#test invalid_index_plus_count_too_large
	int array[4] = {1, 2, 3, 4};
	int reversed[4] = {1, 2, 3, 4};

	reverse(array, 4, 1, 4);

	for (size_t i = 0; i < 4; i++){
		ck_assert_int_eq(array[i], reversed[i]);
	}

	reverse(array, 4, 2, 3);

	for (size_t i = 0; i < 4; i++){
		ck_assert_int_eq(array[i], reversed[i]);
	}

	reverse(array, 4, 3, 2);

	for (size_t i = 0; i < 4; i++){
		ck_assert_int_eq(array[i], reversed[i]);
	}

	reverse(array, 4, 4, 1);

	for (size_t i = 0; i < 4; i++){
		ck_assert_int_eq(array[i], reversed[i]);
	}

	// Might trigger integer overflow for size_t if not careful
	reverse(array, 4, SIZE_MAX / 2, SIZE_MAX / 2);

	for (size_t i = 0; i < 4; i++){
		ck_assert_int_eq(array[i], reversed[i]);
	}

	reverse(array, 4, SIZE_MAX / 2, SIZE_MAX / 2 + 1);

	for (size_t i = 0; i < 4; i++){
		ck_assert_int_eq(array[i], reversed[i]);
	}

	reverse(array, 4, SIZE_MAX / 2 + 1, SIZE_MAX / 2);

	for (size_t i = 0; i < 4; i++){
		ck_assert_int_eq(array[i], reversed[i]);
	}

	reverse(array, 4, SIZE_MAX / 2 + 1, SIZE_MAX / 2 + 1);

	for (size_t i = 0; i < 4; i++){
		ck_assert_int_eq(array[i], reversed[i]);
	}
