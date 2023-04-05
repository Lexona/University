//implementare una funzione che accetta un vettore, restituire due variabili, la prima contenente il numero di elementi pari presenti
//nel vettore e la seconda il numero di elementi dispari (utilizzare il passaggio di parametri tramite puntatore per restituire i risultati)

#include <stdio.h>
#define MAX 20

void func(int vet[], int dim, int *p, int *d);

int main () {

	int dim; //dimensione vettore
	int cont = 0; //serve per la stampa

	//inserimento dimensione
	printf("Inserisci la dimensione del vettore: ");
	do {
		scanf("%d", &dim);

		if (dim < 0 || dim > MAX)
			printf("Valore non valido, riprovare: ");

	} while (dim < 0 || dim > MAX);

	int vettore[dim]; //vettore principale

	printf("Inserisci gli elementi nel vettore\n");
	for (int i = 0; i < dim; i++) {
		printf("Cella %d: ", cont);
		cont++;

		scanf("%d", &vettore[i]);
	}

	int pari = 0, dispari = 0;

	func(vettore, dim, &pari, &dispari);

	return 0;
}

void func(int vet[], int dim, int *p, int *d){

	for (int i = 0; i < dim; i++) {
		if (vet[i] % 2 == 0) {
			*p += 1;
		} else {
			*d += 1;
		}
	}

	printf("Pari: %d\n", *p);
	printf("Dispari: %d", *d);
}
