//sommare due matrici elemento per elemento memorizzandone i valori in una terza matrice

#include <stdio.h>

int main () {

	int A[][3] = {{1,2,3}, {1,2,3}};
	int B[][3] = {{4,5,6}, {4,5,6}};
	int C[2][3];

	for (int i = 0; i < 2; i++) {

		for (int j = 0; j < 3; j++) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}

	//stampa
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", C[i][j]);
		}
	}

	return 0;
}
