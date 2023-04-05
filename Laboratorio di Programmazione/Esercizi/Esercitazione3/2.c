#include <stdio.h>
#define MAX 20

int main () {

	int dim, somma = 0; //dichiaro la dimensione dei vettori + la somma finale degli elementi
	int cont = 0; //serve solo per la stampa

	//faccio inserire la dimensione
	printf("Inserisci la dimensione dei vettori: ");
	do {
		scanf("%d", &dim);

		if (dim < 0 || dim > MAX)
			printf("Valore non valido riprovare");

	} while (dim < 0 || dim > MAX);

	int v[dim], w[dim], prodotto[dim];

	//inserimento degli elementi
	for (int i = 0; i < dim; i++) {
		printf("Cella %d:\n", cont);
		cont++;

		scanf("%d", &v[i]);
		scanf("%d", &w[i]);

		prodotto[i] = v[i]*w[i];
		somma += prodotto[i];
	}

	//stampa del risultato
	printf("Prodotto scalare: %d", somma);

	return 0;
}
