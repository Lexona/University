//ricerca di un elemento k dato dall'utente all'interno di una matrice. Se presente, visualizzare l'indice di riga e di colonna in cui si trova

#include <stdio.h>

int main () {

	int A[][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
	int k, riga, colonna;

	printf("Quale numero vuoi ricercare?\n");
	scanf("%d", &k);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (A[i][j] == k) {
				riga = i+1;
				colonna = j+1;
			}
		}
	}

	//stampa
	printf("Riga: %d\n", riga);
	printf("Colonna: %d\n", colonna);

	return 0;
}
