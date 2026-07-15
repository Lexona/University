#include <stdio.h>
#define MAX 10

void trova_trasposta (int m[][MAX], int r, int c);

int main () {
	int righe, colonne, matrice[MAX][MAX];

	printf("Inserisci il numero di righe: ");
	do {
		scanf("%d", &righe);

		if (righe < 0 || righe > MAX)
			printf("Inserimento non valido, riprovare: ");
	} while (righe <0 || righe > MAX);

	printf("Inserisci il numero di colonne: ");
	do {
		scanf("%d", &colonne);

		if (colonne < 0 || colonne > MAX)
			printf("Inserimento non valido, riprovare: ");
	} while (colonne < 0 || colonne > MAX);

	//inserimento nella matrice
	printf("Inserisci i numeri nella matrice\n");
	for (int i = 0; i < righe; i++) {
		for (int j = 0; j < colonne; j++){
			printf("Inserisci: ");
			scanf("%d", &matrice[i][j]);
		}
	}

	trova_trasposta(matrice, righe, colonne);

	return 0;
}

void trova_trasposta (int m[][MAX], int r, int c){
	int risultato [MAX][MAX];

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			risultato[i][j] = m[j][i];

			printf("%d ", risultato[i][j]);
		}
	}

}















