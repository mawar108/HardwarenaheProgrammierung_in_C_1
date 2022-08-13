#include "swap.h"
#include "reverse.h"

void reverse(int array[], size_t length, size_t index, size_t count){
	// Diese Funktion muss von Ihnen implementiert werden.
	int counter = count;
	if (counter > 1 && index < length && count <= length - index){
		for(int i = 0; i < (int) (count/2); i++){
			swap(array, index+i, index+count-i-1);
			counter = counter - 2;
		}
	}
}
