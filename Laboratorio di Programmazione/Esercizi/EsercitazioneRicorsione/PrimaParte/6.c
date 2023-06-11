//Data una matrice quadrata, proporre una soluzione ricorsiva per stamparne la diagonale principale

#include <stdio.h>
#define MAX 20

void stampa_diagonale(int *mat, int dim) {
	//caso base
	printf("%d ", *mat);
	//altri casi
	if (dim > 1)
		stampa_diagonale((mat+MAX)+1, dim-1); //l'offset è MAX perché bisogna anche considerare le celle in cui non è stato messo un valore
}

int main () {
	//dichiarazione delle variabili
	int matrice[MAX][MAX], dimensione;

	//inserimento della dimensione
	printf("Inserisci la dimensione della matrice: ");
	do {
		scanf("%d", &dimensione);
	} while (dimensione < 0 || dimensione > MAX);

	//inserimento degli elementi nella matrice
	for (int i = 0; i < dimensione; i++) {
		for (int j = 0; j < dimensione; j++) {
			printf("Riga %d, colonna %d: ", i+1, j+1);
			scanf("%d", &matrice[i][j]);
		}
	}

	//richiamo della funzione
	stampa_diagonale(*matrice, dimensione);

	return 0;
}
