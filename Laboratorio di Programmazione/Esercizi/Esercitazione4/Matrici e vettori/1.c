#include <stdio.h>
#define MAX 10

void creazione_matrice(int vet1[], int vet2[], int dim);

int main () {
	int dimensione_vettore, a[MAX], b[MAX];

	printf("Inserisci la dimensione dei vettori: ");
	do {
		scanf("%d", &dimensione_vettore);

		if (dimensione_vettore < 0 || dimensione_vettore > MAX)
			printf("Inserimento non valido, riprovare: ");
	} while (dimensione_vettore < 0 || dimensione_vettore > MAX);

	printf("Inserisci gli elementi nei vettori:\n");
	for (int i = 0; i < dimensione_vettore; i++) {
		printf("Cella A: ");
		scanf("%d", &a[i]);
		printf("Cella B: ");
		scanf("%d", &b[i]);
	}

	creazione_matrice(a, b, dimensione_vettore);

	return 0;
}

void creazione_matrice(int vet1[], int vet2[], int dim){

	int matrice[dim*dim][2], cont = 0;

	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			matrice[cont][0] = vet1[i];
			matrice[cont][1] = vet2[j];
			cont ++;
		}
	}

	//stampa matrice
	for (int i = 0; i < dim*dim; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d ", matrice[i][j]);
		}
	}
}
