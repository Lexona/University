//data una matrice, scrivere un programma che determini qual è la colonna col maggior numero di elementi pari. Stamparne quindi l'indice

#include <stdio.h>

int main () {

	int A[][3] = {{1,2,3}, {5,4,6}, {7,8,9}};
	int conteggio[3], max = 0, indice;

	for (int i = 0; i < 3; i++) {

		conteggio[i] = 0;

		for (int j = 0; j < 3; j++) {
			if (A[i][j] % 2 == 0) {
				conteggio[i]++;
			}
		}
	}

	//ricerca massimo nel vettore conteggio
	for (int i = 0; i < 3; i++) {
		if (conteggio[i] > max) {
			max = conteggio[i];
			indice = i+1;
		}
	}

	//stampa
	printf("La colonna col maggior numero di elementi pari: %d\n", indice);

	return 0;
}

