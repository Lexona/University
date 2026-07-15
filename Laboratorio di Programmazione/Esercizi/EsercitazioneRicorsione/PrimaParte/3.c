//Stampare una matrice di dimensioni nr×nc di interi utilizzando una soluzione ricorsiva. Si consideri come caso base la stampa di una singola riga della matrice.

#include <stdio.h>
#define MAX 20

void stampa_vettore(int *vet, int dim) {
	//caso base
	if (dim == 1) {
		printf("%d ", vet[0]);
		return;
	}

	printf("%d ", vet[0]);
	stampa_vettore(vet+1, dim-1);
}

void stampa (int mat[][MAX], int r, int c) {
	//caso base
	if (r == 1) {
		stampa_vettore(*mat, c);
		return;
	}

	//casi successivi
	stampa_vettore(*mat, c);
	stampa(mat+1, r-1, c);
}


int main () {
	int righe, colonne, matrice[MAX][MAX];

	printf("Righe: ");
	do {
		scanf("%d", &righe);
	} while (righe < 0 || righe > MAX);

	printf("Colonne: ");
	do {
		scanf("%d", &colonne);
	} while (colonne < 0 || colonne > MAX);

	//inserimento nella matrice
	for (int i = 0; i < righe; i++) {
		for (int j = 0; j < colonne; j++) {
				printf("Riga %d, colonna %d: ", i+1, j+1);
				scanf("%d", &matrice[i][j]);
		}
	}

	stampa(matrice, righe, colonne);

	return 0;
}
