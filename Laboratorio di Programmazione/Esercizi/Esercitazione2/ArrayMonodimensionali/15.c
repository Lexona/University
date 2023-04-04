//dato un vettore A di numeri interi, creare un secondo vettore B contenente:
//1, se il valore nella rispettiva posizione è multiplo di 3 o maggiore di 100,
//2, altrimenti

#include <stdio.h>

int main () {

	int A[] = {1,3,5,-2,4,0,6};
	int B[7];

	int j = 0;
	for (int i = 0; i < 7; i++) {
		if (A[i] % 3 == 0 || A[i] > 100) {
			B[j] = 1;
			j++;
		} else {
			B[j] = 2;
			j++;
		}
	}

	//stampa
	for (int i = 0; i < 7; i++) {
		printf("%d\t", B[i]);
	}

	return 0;
}
