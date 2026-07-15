//costruire un vettore che sia l'unione di 2 vettori dati (ossia mettere gli elementi dei due vettori in un terzo vettore senza ripetizioni)

#include <stdio.h>

int main () {
	int A[] = {1,2,3,4};
	int B[] = {4,5,6,7};
	int RES[8], dim_res = 0, cont;

	//primo vettore
	for (int i = 0; i < 4; i++) {
		cont = 0;
		for (int j = 0; j < dim_res; j++) {
			if (A[i] == RES[j]) {
				cont = 1;
				break;
			}
		}

		if (! cont) {
			RES[dim_res] = A[i];
			dim_res++;
		}
	}

	//secondo vettor
	for (int i = 0; i < 4; i++) {
		cont = 0;
		for (int j = 0; j < dim_res; j++) {
			if (B[i] == RES[j]) {
				cont = 1;
				break;
			}
		}

		if (!cont) {
			RES[dim_res] = B[i];
			dim_res++;
		}
	}

	//stamapa
	for (int i = 0; i < dim_res; i++) {
		printf("%d\t", RES[i]);
	}

	return 0;
}
