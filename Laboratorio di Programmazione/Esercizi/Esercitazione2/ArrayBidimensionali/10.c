//data una matrice, inserire gli indici di riga e di colonna di tutti gli elementi negativi in due vettori distinti, il primo contenente le posizioni di riga ed il secondo le posizioni di colonna

#include <stdio.h>

int main () {
	int A[][3] = {{1,2,-4}, {-1,6,7}, {3,4,-7}};
	int r = 0, c = 0;
	int riga[9], colonna[9];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (A[i][j] < 0) {
				riga[r] = i+1;
				colonna[c] = j+1;

				r++;
				c++;
			}
		}

	}

	//stampa
	for (int i = 0; i < 3; i++){
		printf("Riga: %d \n", riga[i]);
		printf("Colonna: %d \n", colonna[i]);
	}

	return 0;
}
