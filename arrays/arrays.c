#include "arrays.h"

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void read_numbers(int *array, size_t length){
	int index = 0;
	int zahl;
	while (length != 0){
		scanf("%d", &zahl);
		*(array+index) = zahl;
		index++;
		length--;
	}   
}

int max(int *array, size_t length){
	if(length == 0){
		return EXIT_FAILURE;
	}
	int ergebnis = *(array + 0);
	for (int i = 0; i < (int) length; i++){
		if (*(array + i) > ergebnis){
			ergebnis = *(array + i);
		}
	}
	return ergebnis;
}

void print_max_of_thirds(int *array, size_t length){
	int anzahlAnZahlen = length / 3;
   
	for(int i = 0; i < 3; i++){
		int *drittelArray = malloc(anzahlAnZahlen * sizeof(int));
		memcpy(drittelArray, array + (i*anzahlAnZahlen), anzahlAnZahlen * sizeof(int));
		int maximum = max(drittelArray, (length/3));
		printf("Maximum %d. Drittel: %d \n", (i+1),  maximum);
		free(drittelArray);
	}
}