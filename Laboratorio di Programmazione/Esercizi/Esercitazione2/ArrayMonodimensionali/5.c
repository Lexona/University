//dato un vettore, calcolare e stampare i valori assoluti di tutti gli elementi contenuti al suo interno

#include <stdio.h>

int main () {
	int A[] = {1,-3,5,-2,4,0,-6};

	for (int i = 0; i < 7; i++) {
		if (A[i] < 0) {
			printf("%d",(A[i])*(-1));
		} else {
			printf("%d", A[i]);
		}
	}
	return 0;
}
