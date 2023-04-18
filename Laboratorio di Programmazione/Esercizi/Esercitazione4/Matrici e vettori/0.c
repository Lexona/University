#include <stdio.h>
#define MAX 20

int exists_row_same_elements(int mat[][MAX], int dim);
int exists_col_same_elements(int mat[][MAX], int dim);
int exists_diag_same_elements(int mat[][MAX], int dim);
int exists_something_same_elements(int mat[][MAX], int dim);

int main () {
	int dimensione, matrice[MAX][MAX];

	printf("Inserisci la grandezza della matrice: ");
	do {
		scanf("%d", &dimensione);

		if (dimensione < 0 || dimensione > MAX)
			printf("Inserimento non valido, riprovare: ");
	} while(dimensione < 0 || dimensione > MAX);

	for (int i = 0; i < dimensione; i++) {
		for (int j = 0; j < dimensione; j++) {
			printf("Inserisci: ");
			scanf("%d", &matrice[i][j]);
		}
	}

	int ris1 = exists_row_same_elements(matrice, dimensione);
	printf("Esiste una riga con elementi uguali: %d\n", ris1);

	int ris2 = exists_col_same_elements(matrice, dimensione);
	printf("Esiste una colonna con elementi uguali: %d\n", ris2);

	int ris3 = exists_diag_same_elements(matrice, dimensione);
	printf("La diagonale principale o secondaria ha elementi uguali: %d\n", ris3);

	int ris4 = exists_something_same_elements(matrice, dimensione);
	printf("Esiste una riga, o una colonna, o la diagonale principale, o la diagonale secondaria con tutti gli elementi uguali: %d\n", ris4);

	return 0;
}

int exists_row_same_elements(int mat[][MAX], int dim) {
	int check = -1;

	for (int i = 0; i < dim && check != 1; i++) {
		check = 1;
		for (int j = 0; j < dim && check != 0; j++) {
			if (mat[i][0] != mat[i][j])
				check = 0;
		}
	}
	return check;
}

int exists_col_same_elements (int mat[][MAX], int dim) {
	int check = -1;

	for (int j = 0; j < dim && check != 1; j++){
		check = 1;
		for (int i = 0; i < dim && check != 0; i++) {
			if (mat[0][j] != mat[i][j])
				check = 0;
		}
	}
	return check;
}

int exists_diag_same_elements(int mat[][MAX], int dim) {
	int check1 = 1, check2 = 1, j = dim-2;

	for (int i = 1; i < dim && check1 != 0; i++) {
		if (mat[i][i] != mat[i-1][i-1])
			check1 = 0;
	}

	for (int i = 1; i < dim && check2 != 0; i++) {
		if (mat[i][j] != mat[i-1][j+1])
			check2 = 0;

		j--;
	}

	return check1 + check2;
}

int exists_something_same_elements(int mat[][MAX], int dim) {

	int check = 0;

	if ((exists_row_same_elements(mat, dim) + exists_col_same_elements(mat, dim) + exists_diag_same_elements(mat, dim)) >= 1) {
		check = 1;
	}

	return check;

}













