#include "laden.h"
#include <stdio.h>


void printCake(void){
	printf("                ,^,\n");
	printf("               /° °\\~~.\n");
	printf("          .~~^(° ° °)~ ~.\n");
	printf("       .~~^ ~  ^^^^^    ~.\n");
	printf("    .~~^~    ~     ~ ~   ~.\n");
	printf(".~*^   ~ ~        ~    ~  *~\n");
	printf("|^^^^^^^^^^^^^^^^^^^^^^^^^^|\n");
	printf("|__________________________|\n");
	printf("|==========================|\n");
	printf("|           Cake           |\n");
	printf("|__________________________|\n");
	printf("|==========================|\n");
	printf("'--------------------------'\n");
	printf("\n");
}

void printMuffin(void){
	printf("         (\n");
	printf("        (.)\n");
	printf("         |\n");
	printf("        l8l\n");
	printf("        | |\n");
	printf("     _.-| |-._\n");
	printf("  .-'   '-'   '-.\n");
	printf(" (-.   Muffin  .-)\n");
	printf("  \\ '-.     .-' /\n");
	printf("   | | '-.-' | |\n");
	printf("   | | | | | | |\n");
	printf("   \\_| | | | |_/\n");
	printf("     '-I_I_I-'\n");
	printf("\n");
}


void cakeOrder(int *cakes, int *muffins, int quantity){
	int order = *cakes;
	if (order < quantity) {
		printf("Es sind %d Kuchen und %d Muffins vorhanden.\n", *cakes, *muffins);
		printf("Bitte bestellen Sie erneut.\n");
	} else {
		*cakes -= quantity;
		int cost_cake = 3;
		int cost_order = cost_cake * quantity;

		printf("Das macht dann %d Euro bitte.\n", cost_order);
		printf("Hier ist Ihre Bestellung, ich wünsche Ihnen einen schönen Tag!\n");
		while (order > 0 && quantity > 0)
		{
			order -= 1;
			quantity--;
			printCake();
		}
		printf("Es sind noch %d Kuchen und %d Muffins im Laden!\n", *cakes, *muffins);
	}
}


void muffinOrder(int *muffins, int *cakes, int quantity){
	int order = *muffins;
	if (order < quantity){
		printf("Es sind %d Kuchen und %d Muffins vorhanden.\n", *cakes, *muffins);
		printf("Bitte bestellen Sie erneut.\n");
	} else {
		*muffins -= quantity;
		int cost_muffin = 2;
		int cost_order = cost_muffin * quantity;

		printf("Das macht dann %d Euro bitte.\n", cost_order);
		printf("Hier ist Ihre Bestellung, ich wünsche Ihnen einen schönen Tag!\n");
		while (order > 0 && quantity > 0)
		{
			order -= 1;
			quantity--;
			printMuffin();
		}
		printf("Es sind noch %d Kuchen und %d Muffins im Laden!\n", *cakes, *muffins);
	}    
}


int main(void) {
	int cakes = 30;
	int muffins = 25;
	printf("Der Laden ist nun geöffnet!\n");
	while (cakes > 0 || muffins > 0) {
		int quantity, type;
		
		printf("Ihre Bestellung bitte.\n");
		if (scanf("%d %d", &quantity, &type) != 2) {
			break;
		}
		if (quantity > 0 && (type == 1 ||  type == 2)) {
			if (type == 1){
				cakeOrder(&cakes, &muffins, quantity);
			}
			else{
				muffinOrder(&muffins, &cakes, quantity);
			}
		} else {
			printf("Entschuldigung, diese Sorte haben wir leider nicht.\n");
		}
	}
	
	printf("Wir sind nun ausverkauft! Der Laden ist nun geschlossen!\n");
	return 0;
}

//Schreiben Sie bitte hier Ihre Unterfunk