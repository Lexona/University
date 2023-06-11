//Dati due vettori v,w ∈  Rn, fornire una soluzione ricorsiva per il calcolo del loro prodotto scalare

#include <stdio.h>
#define MAX 20

void prodotto_scalare(int v[], int w[], int dim, int *prodotto) {
	//caso base
	if (dim == 0) {
		printf("\n");
		return;
	}

	*prodotto += v[0]*w[0];
	prodotto_scalare(v+1, w+1, dim-1, prodotto);
	return;
}

int main () {
	int v[MAX], w[MAX], dimensione, risultato = 0;

	printf("Dimensione vettori: ");
	do {
		scanf("%d", &dimensione);
	} while (dimensione < 0 || dimensione > MAX);

	for (int i = 0; i < dimensione; i++) {
		printf("Elemento %d vettore 1: ", i+1);
		scanf("%d", &v[i]);
		printf("Elemento %d vettore 2: ", i+1);
		scanf("%d", &w[i]);
	}

	prodotto_scalare(v, w, dimensione, &risultato);

	printf("Prodotto scalare: %d", risultato);

	return 0;
}
