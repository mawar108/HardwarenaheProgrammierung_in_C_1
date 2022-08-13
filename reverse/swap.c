#include "swap.h"

void swap(int array[], size_t index1, size_t index2){
	// Swap two values
	int index = array[index1];
	array[index1] = array[index2];
	array[index2] = index;
}


