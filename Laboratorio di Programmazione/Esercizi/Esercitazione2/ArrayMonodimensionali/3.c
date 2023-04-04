//dato un vettore ed un valore k, ricerca di k all'interno di un vettore (versione NON ottimizzata, usare un for (o while)
//che scorre il vettore fino alla fine)

#include <stdio.h>
int main () {
	int A[] = {1,3,5,-2,4,0,6};
	int k = 9;

	if (A[k]){
		printf("True\n");
	} else {
		printf("False\n");
	}

	return 0;
}
