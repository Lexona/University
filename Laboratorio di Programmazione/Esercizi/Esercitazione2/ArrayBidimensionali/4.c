//copiare la diagonale principale di una matrice in un vettore

#include <stdio.h>

int main () {

	int A[][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
	int RIS[5];
	int k = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) {
				RIS[k] = A[i][j];
				k++;
			}
		}
	}

	//stampa
	for (int i = 0; i < k; i++) {
		printf("%d ", RIS[i]);
	}

	return 0;
}
