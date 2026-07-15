//copiare gli elementi nelle posizioni pari e dispari di un vettore in 2 vettori differenti

#include <stdio.h>

int main () {

	int A[] = {1,3,5,-2,4,0,6};
	int PAR[4];
	int DIS[3];

	int j = 0, k = 0;
	for (int i = 0; i < 7; i++) {
		if (i % 2 == 0) {
			PAR[j] = A[i];
			j++;
		} else {
			DIS[k] = A[i];
			k++;
		}
	}

	//stampa
	printf("Pari\n");
	for (int i = 0; i < 4; i++) {
		printf("%d\t", PAR[i]);
	}

	printf("Dispari\n");
	for (int i = 0; i < 3; i++) {
		printf("%d\t", DIS[i]);
	}

	return 0;
}
