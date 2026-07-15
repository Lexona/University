//Data una lista concatenata L, proporre una soluzione ricorsiva che ne stampi tutti i valori

#include <stdio.h>
#include <stdlib.h>

struct Lista {
	int valore;
	struct Lista *prossimo;
};

//INSERIMENTO NELLA LISTA
void insert(struct Lista **start, int num) {
	//creo il nuovo nodo
	struct Lista *nuovo = malloc(sizeof(struct Lista));
	nuovo -> prossimo = NULL;
	nuovo -> valore = num;

	//scorro la lista
	struct Lista *punt = *start;
	struct Lista *precedente = NULL;

	while(punt != NULL) {
		precedente = punt;
		punt = punt -> prossimo;
	}

	//controllo in che posizione inserire il nuovo nodo
	if (precedente == NULL)
		*start = nuovo;
	else
		precedente -> prossimo = nuovo;
}

void print_list(struct Lista *start) {
	//caso base
	if (start == NULL) {
		printf("\n");
		return;
	}

	printf("%d\n", start->valore);
	print_list(start->prossimo);
}

int main () {
	//dichiarazione delle variabili
	int scelta = -1, numero;
	struct Lista *head = NULL;

	//menu
	while (scelta != 0) {
		printf("------------------------------------\n");
		printf("Cosa vuoi fare?\n");
		printf("0 - Esci\n1 - Inserisci\n2 - Stampa\n");
		scanf("%d", &scelta);

		switch(scelta) {
			case 0:
				printf("Ciao!\n");
				break;
			case 1:
				printf("Inserisci un numero: ");
				scanf("%d", &numero);
				insert(&head, numero);
				break;
			case 2:
				printf("-------------------------------------\n");
				print_list(head);
				break;
		}
	}

	return 0;
}
