#include "swap.h"
#include "reverse.h"

void reverse(int array[], size_t length, size_t index, size_t count){
    // Do not swap anything if count is too small or index is invalid
    if (count > 1 && index < length && count <= length - index){
        // Swap recursively
        reverse(array, length, index + 1, count - 2);

        size_t reverse_index = index + count - 1;

        // Swap two elements
        swap(array, index, reverse_index);
    }
}
