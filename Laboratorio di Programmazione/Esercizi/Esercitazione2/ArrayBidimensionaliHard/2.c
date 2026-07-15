//date due matrici M1 e M2, dire, per ogni riga di M2, se ne esiste almeno una uguale in M1

#include <stdio.h>
#define MAX 20

int main () {
	int r, c; //valori per le righe e le colonne
	int cont = 0; //contatore per la stampa

	//faccio inserire i valori delle righe e delle colonne
	printf("Inserisci il numero di righe: ");
	do {
		scanf("%d", &r);

		if (r < 0 || r > MAX)
			printf("Inserimento non valido, riprovare: ");
	} while(r < 0 || r > MAX);

	printf("Inserisci il numero di colonne: ");
	do {
		scanf("%d", &c);

		if (c < 0 || c > MAX)
			printf("Inserimento non valido, riprovare: ");

	} while(c < 0 || c > MAX);

	int M1[r][c], M2[r][c]; //dichiaro le due matrici
	int vero = 0; //serve per vedere se le righe sono uguali

	//inserimento dei valori nelle matrici
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("Cella numero %d: \n", cont);
			cont++;

			scanf("%d\n", &M1[i][j]);
			scanf("%d", &M2[i][j]);

			if (M1[i][j] == M2[i][j]) {
				vero++;
			}
		}
	}

	//stampo il risultato
	if (vero >= c) {
		printf("Le due matrici hanno almeno un elemento in comune");
	} else {
		printf("Le due matrici non hanno righe in comune");
	}

	return 0;
}
