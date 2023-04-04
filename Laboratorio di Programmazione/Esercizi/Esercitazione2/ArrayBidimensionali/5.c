//copiare la diagonale secondaria di una matrice in un vettore

#include <stdio.h>

int main () {

	int A[][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
	int RIS[5], k = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i + j == 3-1) {
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
