#include <stdio.h>
#define MAX 20

void creazione_matrice (int matA[][MAX], int matB[][MAX], int prod[][MAX], int dim);
void stampa (int prod[][MAX], int dim);

int main () {
	int dimensione, a[MAX][MAX], b[MAX][MAX];

	printf("Inserisci il numero di righe e colonne delle matrici: ");
	do {
		scanf("%d", &dimensione);
		
		if (dimensione < 0 || dimensione > MAX)
			printf("Inserimento non valido, riprovare: ");
	} while (dimensione < 0 || dimensione > MAX);
	
	for (int i = 0; i < dimensione; i++){
		for (int j = 0; j < dimensione; j++){
			printf("Riga %d, colonna %d di A: ", i, j);
			scanf("%d", &a[i][j]);
			printf("Riga %d, colonna %d di B: ", i, j);
			scanf("%d", &b[i][j]);
		}
	}
	
	int matrice_prodotto[MAX][MAX];
	
	creazione_matrice (a, b, matrice_prodotto, dimensione);
	stampa(matrice_prodotto, dimensione);
}

void creazione_matrice (int matA[][MAX], int matB[][MAX], int prod[][MAX], int dim){

	int cont = 0;
	
	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++) {
			for (int k = 0; k < dim; k++){
				prod[cont][k] = matA[i][k];
			}
			
			for (int k = 0; k < dim; k++){
				prod[cont][dim + k] = matB[j][k];
			}
			
			cont++;
		}
	}
}

void stampa (int prod[][MAX], int dim){
	for (int i = 0; i < dim*dim; i++) {
		for (int j = 0; j < dim*dim; j++) {
			printf("%d ", prod[i][j]);
		}
	}
}






