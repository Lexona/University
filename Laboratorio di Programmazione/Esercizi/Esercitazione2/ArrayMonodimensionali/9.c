//concatenare due vettori in un terzo vettore. Esempio: dati A = 1,2,5,3, B = 2,4,1,2 allora RIS = 1,2,5,3,2,4,1,2

#include <stdio.h>

int main () {
	int A[] = {1,2,5,3};
	int B[] = {2,4,1,2};
	int RIS[8];

	int j = 0;
	for (int i = 0; i < 4; i++) {
		RIS[j] = A[i];
		j++;
	}

	for (int i = 0; i < 4; i++) {
		RIS[j] = B[i];
		j++;
	}

	for (int i = 0; i < 8; i++) {
		printf("%d\t", RIS[i]);
	}

	return 0;
}
