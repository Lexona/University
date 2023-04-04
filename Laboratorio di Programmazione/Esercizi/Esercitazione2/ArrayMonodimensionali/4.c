//dato un vettore stampare UGUALI se tutti gli elementi contenuti al suo interno sono tra loro uguali, NO se ne esiste anche soltanto uno diverso
//(versione NON ottimizzata, ossia attraverso un ciclo for (o while) che scorre il vettore fino alla fine)

#include <stdio.h>

int is_all_equal(int vet[], int dim);

int main () {
	int A[] = {1,1,1,4,1,1,1};

	if (is_all_equal(A, 7)){
		printf("UGUALI\n");
	} else {
		printf("NO\n");
	}
}

int is_all_equal(int vet[], int dim) {
	if (dim == 1) {
		return 1;
	} else {
		return (vet[0] == vet[dim-1]) && is_all_equal(vet, dim-1);
	}
}
