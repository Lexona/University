//date due matrici M1 e M2, dire, per ogni riga di M2, se ne esiste soltanto una uguale in M1

#include <stdio.h>
#define MAX 20

int main () {

	int r, c; //valori per le righe e le colonne
	int cont = 1; //serve solo per la stampa

	//inserimento di tali valori
	printf("Inserisci il numero di righe: ");
	do {
		scanf("%d", &r);

		if (r < 0 || r > MAX)
			printf("Valore non valido, riprovare: ");
	} while(r < 0 || r > MAX);

	printf("Inserisci il numero di colonne: ");
	do {
		scanf("%d", &c);

		if (c < 0 || c > MAX)
			printf("Valore non valido, riprovare: ");
	} while (c < 0 || c > MAX);

	int M1[r][c], M2[r][c]; //dichiaro le due matrici
	int vero = 0; //serve per vedere il numero di elemento uguali

	//faccio l'inserimento dei valori nelle matrici e faccio il controllo
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("Cella %d:\n", cont);
			cont++;

			scanf("%d", &M1[i][j]);
			scanf("%d", &M2[i][j]);

			if (M1[i][j] == M2[i][j])
				vero++;
		}
	}

	if (vero == c || vero % c != 0) {
		printf("Esiste solo una riga uguale\n");
	} else {
		printf("NON esiste solo una riga uguale\n");
	}

	return 0;
}
