//dato un vettore, calcolare i valori assoluti di tutti gli elementi contenuti al suo interno e inserirli in un altro vettore nelle posizioni
//corrispondenti. Esempio: dato A = -1,3,-5,-2,9 allora RIS = 1,3,5,2,9

#include <stdio.h>
#include <stdlib.h>

int main () {
	int A[] = {-1,3,-5,-2,9};
	int RIS[5];

	for (int i = 0; i < 5; i++) {
		RIS[i] = abs(A[i]);

		printf("%d\t", RIS[i]);
	}
}


