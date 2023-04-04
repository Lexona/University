//stampare la somma di tutti gli elementi in un vettore

#include <stdio.h>
int main () {
	int A[] = {1,3,5,-2,4,0,6};
	int somma = 0;

	for (int i = 0; i < 7; i++) {
		somma += A[i];
	}

	printf("Somma: %d\n", somma);

	return 0;
}
