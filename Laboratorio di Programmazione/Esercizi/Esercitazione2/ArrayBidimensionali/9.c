//copiare il perimetro di una matrice in un vettore

#include <stdio.h>

int main () {

	int A[][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
	int vettore[8], k = 0;
	//dim = (colonne*20) * [(righe-2)*2]

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 0 || i == 2) {
				vettore[k] = A[i][j];
				k++;
			} else if (j == 0 || j == 2) {
				vettore[k] = A[i][j];
				k++;
			}
		}
	}

	//stampa
	for (int i = 0; i < 8; i++) {
		printf("%d ", vettore[i]);
	}

	return 0;
}
