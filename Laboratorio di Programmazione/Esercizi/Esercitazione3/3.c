#include <stdio.h>
#define MAX 20

int main () {
	int r, c; //indici di riga e di colonna
	int cont = 0; //serve solo per la stampa

	//inserimento
	printf("Inserisci il numero di righe: ");
	do {
		scanf("%d", &r);

		if (r < 0 || r > MAX)
			printf("Inserimento non valido, riprovare: ");

	} while (r < 0 || r > MAX);

	printf("Inserisci il numero di colonne: ");
	do {
		scanf("%d", &c);

		if (c < 0 || c > MAX)
			printf("Inserimento non valido, riprovare: ");

	} while (c < 0 || c > MAX);

	int m[r][c], w[r][c], somma[r][c];

	//inserimento + controlli
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("Cella %d:\n", cont);
			cont++;

			scanf("%d", &m[i][j]);
			scanf("%d", &w[i][j]);

			somma[i][j] = m[i][j] + w[i][j];
		}
	}

	//stampa
	printf("Somma: ");
	for (int i = 0; i <  r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%d ", somma[i][j]);
		}
	}

	return 0;
}
