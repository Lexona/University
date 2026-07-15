#include <stdio.h>
#define MAX 20

int main () {

	int dim; //dichiaro la grandezza dei vettori
	int cont = 0; //serve solo per la stampa

	//faccio inserire la grandezza dei vettori
	printf("Inserisci la dimensione dei vettori: ");
	do {
		scanf("%d", &dim);

		if (dim < 0 || dim > MAX)
			printf("Inserimento non valido, riprovare: ");

	} while (dim < 0 || dim > MAX);

	int v[dim], w[dim], somma[dim]; //dichiaro i due vettori

	//faccio inserire i valori nei due vettori
	for (int i = 0; i < dim; i++) {
		printf("Cella %d:\n", cont);
		cont++;

		scanf("%d", &v[i]);
		scanf("%d", &w[i]);

		somma[i] = v[i] + w[i];
	}

	//stampa
	for (int i = 0; i < dim; i++) {
		printf("%d ", somma[i]);
	}

	return 0;
}
