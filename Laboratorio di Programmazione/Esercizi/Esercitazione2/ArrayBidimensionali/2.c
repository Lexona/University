//memorizzare e stamapre le somme di ogni riga di una matrice in un vettore

#include <stdio.h>

int main () {

	int A[][3] = {{1,2,3}, {1,2,3}, {1,2,3}};
	int somma[3];
	int k = 0;

	for (int i = 0; i < 3; i++) {
		somma[k] = 0;
		for (int j = 0; j < 3; j++) {
			somma[k] += A[i][j];
		}
		k++;
	}

	printf("Somma:\n");

	for (int i = 0; i < k; i++) {
		printf("%d ", somma[i]);
	}

	return 0;
}
