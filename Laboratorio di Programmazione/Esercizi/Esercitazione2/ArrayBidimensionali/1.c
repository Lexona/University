//effettuare somma di tutti gli elementi di una matrice

#include <stdio.h>

int main () {

	int A[][3] = {{1,2,3}, {1,2,3}};
	int somma = 0;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			somma += A[i][j];
		}
	}

	printf("Somma: %d ", somma);

	return 0;
}
