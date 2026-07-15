//determinare il minimo (massimo) presente in un vettore e stamparne a video sia valore che la posizione in cui si trova.

#include <stdio.h>

int main() {
	int A[] = {1,3,5,-2,4,0,6};
	int min = 10, max = 0, posMin, posMax;

	//minimo elemento dell'array
	for (int i = 0; i < 7; i++) {
		if (A[i] < min) {
			min = A[i];
			posMin = i+1;
		}
	}

	//massimo elemento dell'array
	for (int i = 0; i < 7; i++) {
		if (A[i] > max) {
			max = A[i];
			posMax = i+1;
		}
	}

	printf("Minimo: %d, Posizione: %d\n", min, posMin);
	printf("Massimo: %d, Posizione: %d\n", max, posMax);

	return 0;
}
