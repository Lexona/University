//dato un vettore v=(v1,v2,…,vn), fornire una soluzione ricorsiva per stamparne i valori partendo dall'ultimo al primo. Si consideri come caso base la stampa di un singolo elemento.

#include <stdio.h>
#define MAX 20

void stampa (int vet[], int dim) {
	//caso base
	if (dim == 1) {
		printf("%d\n", vet[0]);
		return;
	}

	//casi successivi
	stampa(vet+1, dim-1);
	printf("%d\n", vet[0]);
}

int main () {
	int v[MAX], dimensione;

	printf("Quanti elementi vuoi inserire? ");
	do {
		scanf("%d", &dimensione);
	} while (dimensione < 0 || dimensione > MAX);

	for (int i = 0; i < dimensione; i++) {
		printf("Valore %d: ", i+1);
		scanf("%d", &v[i]);
	}

	stampa(v, dimensione);

	return 0;
}
