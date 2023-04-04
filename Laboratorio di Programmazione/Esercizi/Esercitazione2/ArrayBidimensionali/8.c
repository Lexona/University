
// data una matrice e due interi pos1 e pos2, scambiare le due righe nelle posizioni corrispondenti

#include <stdio.h>

int main () {
	int A[][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
	int appoggio[3];
	int pos1, pos2;

	printf("Inserisci pos1:\n");
	do {
		scanf("%d", &pos1);

		if (pos1 < 0 || pos1 > 3) {
			printf("Inserimento non valido\n");
		}

	} while (pos1 < 0 || pos1 > 3);


	printf("Inserisci pos2:\n");
	do {
		scanf("%d", &pos2);

		if (pos2 < 0 || pos2 > 3) {
			printf("Inserimento non valido\n");
		}

	} while (pos2 < 0 || pos2 > 3);

	//scambio
	for (int i = 0; i < 3; i++) {
		appoggio[i] = A[pos1-1][i];
		A[pos1-1][i] = A[pos2-1][i];
		A[pos2-1][i] = appoggio[i];
	}

	//stampa
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", A[i][j]);
		}
	}

	return 0;
}
