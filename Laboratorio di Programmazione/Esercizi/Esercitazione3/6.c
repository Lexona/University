#include <stdio.h>
#define MAX 20

int main () {
	int dim; //dimensione della matrice
	int cont = 0; //serve per la stampa

	//inserimento dei dati
	printf("Inserisci la dimensione della matrice quadrata: ");
	do {
		scanf("%d", &dim);

		if (dim < 0 || dim > MAX)
			printf("Inserimento non valido, riprovare: ");

	} while (dim < 0 || dim > MAX);

	int m[dim][dim], vet1[dim], vet2[dim]; //dichiarazione della matrice e vettori principali

	//inserimento nella matrice
	printf("Inserisci i valori nella matrice\n");
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			printf("Cella %d: ", cont);
			cont++;

			scanf("%d", &m[i][j]);

			if (i == j) {
				vet1[i] = m[i][j];
			}

			if (i + j == dim - 1) {
				vet2[i] = m[i][j];
			}
		}
	}

	//stampa del risultato
	for (int i = 0; i < dim; i++) {
		printf("%d ", vet1[i]);
	}

	for (int i = 0; i < dim; i++) {
		printf("%d ", vet2[i]);
	}

	return 0;
}
