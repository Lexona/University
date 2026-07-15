//dato un vettore, eliminarne i duplicati tramite shift

#include <stdio.h>

void elimina (int vet[], int dim);
void stampa (int vet[], int dim);

int main () {

	int A[] = {1,2,3,3,4,5,6,6,7};

	elimina(A, 9);
	stampa(A, 9);

	return 0;
}

void elimina (int vet[], int dim) {

	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			if (vet[i] == vet[j] && i != j) {
				for (int k = j; k < dim-1; k++) {
					vet[k] = vet[k+1];
				}
			}
		}
	}
}

void stampa (int vet[], int dim) {
	for (int i = 0; i < dim; i++) {
		printf("%d ", vet[i]);
	}
}
