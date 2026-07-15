//dato un vettore ed un valore k, ricerca di k all'interno di un vettore (ottimizzato, ossia il ciclo si deve fermare quando l'elemento è stato trovato, USARE UN WHILE NON UN FOR)

#include <stdio.h>

void trova(int vet[], int dim, int val);

int main () {

	int A[] = {1,2,3,4,5,6,7,3,9};
	int k;

	printf("Inserisci il numero che vuoi cercare: \n");
	scanf("%d", &k);

	trova(A, 9, k);

	return 0;
}


void trova(int vet[], int dim, int val) {
	int i = 0;

	while (i < dim) {
		if (vet[i] == val) {
			printf("Il valore ricercato esiste\n");
			break;
		}

		i++;
	}
}
