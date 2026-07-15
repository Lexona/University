//dato un vettore ed un indice di posizione idx, eliminazione dell'elemento in posizione idx tramite shift a destra

#include <stdio.h>

void inserimento(int vet[], int dim, int val);
void stampa(int vet[], int dim);

int main () {

	int A[] = {1,2,3,4,5,6};
	int idx = 3;

	inserimento(A, 6, idx);
	stampa(A, 6);

	return 0;
}

void inserimento (int vet[], int dim, int val) {
	int i = 0;

	while (i < dim && vet[i] < val) {
		i++;
	}

	for (int j = i; j > 0; j--) {
		vet[j] = vet[j-1];
	}
}

void stampa (int vet[], int dim) {
	for (int i = 0; i < dim; i++) {
		printf("%d ", vet[i]);
	}
}
