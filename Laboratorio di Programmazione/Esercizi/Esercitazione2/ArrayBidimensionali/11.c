//data una matrice quadrata, dire se la diagonale principale è uguale alla diagonale secondaria

#include <stdio.h>
#define MAX 20

int main () {

	int r, c; //numero di righe e di colonne
	int vet1[MAX], vet2[MAX]; //vettori d'appoggio
	int k = 0, h = 0, conteggio = 1;

	//inserimento numero di righe (e di colonne di conseguenza)
	printf("Inserisci il numero di righe e di colonne: ");
	do {
		scanf("%d", &r);

		if (r < 0 || r > MAX)
			printf("Inserimento non valido: ");

	} while (r < 0 || r > MAX);

	c = r; //stabilisco il numero di colonne

	int a[r][c]; //dichiarazione del vettore principale

	//inserimento dei valori nel vettore principale
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {

			printf("Inserisci il valore nella cella %d: ", conteggio);

			scanf("%d", &a[i][j]);

			if (i == j) { //inserimento nel vettore della diagonale principale
				vet1[k] = a[i][j];
				k++;
			} else if (i + j == r - 1) { //inserimento nel vettore della diagonale secondaria
				vet2[h] = a[i][j];
				h++;
			}
			conteggio++;
		}
	}

	int vero; //variabile per vedere se i due vettori sono uguali o no

	//confronto dei due vettori
	for (int i = 0; i < k; i++) { //metto k ma potrebbe essere anche h

		vero = 0;

		if (vet1[i] == vet2[i]) //controllo se i due vettori sono uguali
			vero = 1;
	}

	if (vero == 1) {
		printf("Le due diagonali sono uguali\n");
	} else {
		printf("Le due diagonali NON sono uguali\n");
	}

	return 0;
}
