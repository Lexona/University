//Dato un vettore, costruire un nuovo vettore uguale al primo rovesciato

#include <stdio.h>

int main () {

	int A[] = {1,3,5,-2,4,0,6};
	int RES[7], j = 0;

	for (int i = 6; i >= 0; i--) {
		RES[j] = A[i];
		j++;
	}

	//stampa del risultato
	for (int i = 0; i < 7; i++) {
		printf("%d\t", RES[i]);
	}

	return 0;
}
