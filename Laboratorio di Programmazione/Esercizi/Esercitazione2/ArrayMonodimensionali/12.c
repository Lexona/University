//dato un vettore e date due variabili contenenti due indici di posizione,scambiare gli elementi nelle posizioni date

#include <stdio.h>

	int main () {

	int A[] = {1,3,5,-2,4,0,6};
	int c = 2, x = 5, temp;

	temp = A[c];
	A[c] = A[x];
	A[x] = temp;

	for (int i = 0; i < 7; i++) {
		printf("%d\t", A[i]);
	}
	return 0;

}
