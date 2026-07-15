//dato un vettore A di numeri interi, creare un secondo vettore B contenente solo i valori di A che siano compresi tra 10 e 20

#include <stdio.h>

int main () {
	int A[] = {1,13,15,2,4,11,6};
	int B[7];

	int j = 0;
	for (int i = 0; i < 7; i++) {
		if (A[i] > 10 && A[i] < 20) {
			B[j] = A[i];
			j++;
		}
	}

	//stampa
	for (int i = 0; i < j; i++){
		printf("%d\t", B[i]);
	}

	return 0;
}
