#include <stdio.h>
#define MAX 20

int main () {

	int r, q, c; //dimensioni dei vettori
	int cont = 0; //serve solo per la stampa

	//inserimento dati
	printf("Inserisci il numero di righe di M: ");
	do {
		scanf("%d", &r);

		if (r < 0 || r > MAX)
			printf("Inserimento non valido, riprovare: ");
	} while (r < 0 || r > MAX);

	printf("Inserisci il numero di colonne di M e righe di W: ");
	do {
		scanf("%d", &q);

		if (q < 0 || q > MAX)
			printf("Inserimento non valido, riprovare: ");

	} while (q < 0 || q > MAX);

	printf("Inserisci il numero di colonne di W: ");
	do {
		scanf("%d", &c);

		if (c < 0 || c > MAX)
			printf("Inserimento non valido, riprovare: ");

	} while (c < 0 || c > MAX);

	int m[r][q], w[q][c], p[r][c]; //dichiarazione dei vettori principali

	//inserimento degli elementi nelle matrici
	printf("Inserisci gli elementi nella matrice M\n");
	for (int i = 0; i < r; i++) {
		for (int k = 0; k < q; k++) {
			printf("Cella %d: ", cont);
			cont++;

			scanf("%d", &m[i][k]);
		}
	}

	cont = 0; //azzero il contatore per la stampa
	printf("Inserisci gli elementi nella matrice W\n");
	for (int k = 0; k < q; k++) {
		for (int j = 0; j < c; j++) {
			printf("Cella %d: ", cont);
			cont++;

			scanf("%d", &w[k][j]);
		}
	}

	//calcolo della somma dei prodotti
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			p[i][j] = 0;
			for (int k = 0; k < q; k++) {
				p[i][j] += m[i][k]*w[k][j];
			}
		}
	}

	//stampa del risultato
	printf("Risultato: ");
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%d ", p[i][j]);
		}
	}

	return 0;
}
