//verificare se un dato vettore è uguale ad una o più righe di una matrice; se sì, stampare in quali posizioni si trovano tali righe

#include <stdio.h>
#define MAX 20

int main () {

	int r, c, conteggio = 1, vero; //numero di righe e di colonne

	//inserimento del numero di righe e di colonne
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

	int vet[c], a[r][c];

	//faccio inseririre gli elementi nel vettore
	printf("Inserisci gli elementi nel vettore: ");
	for (int i = 0; i < c; i++) {
		scanf("%d", &vet[i]);
	}

	//faccio inserire gli elementi nella matrice
	printf("Inserisci gli elementi nella matrice\n");
	for (int i = 0; i < r; i++) {

		vero = 0;

		for (int j = 0; j < c; j++) {
			printf("Casella %d: ", conteggio);
			conteggio++;

			scanf("%d", &a[i][j]);

			if (a[i][j] == vet[j]) {
				vero++;
			}
		}

		if (vero == c) {
			printf("Il vettore e la riga %d sono uguali\n", i);
		}

	}

	if (vero != c) {
		printf("Il vettore e le righe della matrice NON sono uguali\n");
	}

	return 0;
}
