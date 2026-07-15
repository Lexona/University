//Dato un vettore, rovesciarlo in loco

#include <stdio.h>

int main () {

	int A[] = {1,3,5,-2,4,0,6};
	int dim = 6, temp;

	for (int i = 0; i < 3; i++){
		temp = A[i];
		A[i] = A[dim];
		A[dim] = temp;

		dim--;
	}

	//stampa
	for (int i = 0; i < 7; i++){
		printf("%d\t", A[i]);
	}
	return 0;
}
