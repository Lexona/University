//Data una lista concatenata contenente valori interi, scrivere una funzione ricorsiva che ne elimini tutti i nodi avente valore pari a k, con k fornito dall'utente

#include <stdio.h>
#include <stdlib.h>

//DICHIARAZIONE DELLA STRUTTURA
struct Lista {
	int valore;
	struct Lista *prossimo;
};

//INSERIMENTO
void insert(struct Lista **start, int num) {
	//creo il nuovo nodo
	struct Lista *nuovo = malloc(sizeof(struct Lista));
	nuovo -> prossimo = NULL;
	nuovo -> valore = num;

	//scorro la lista
	struct Lista *punt = *start;
	struct Lista *precedente = NULL;
	while (punt != NULL) {
		precedente = punt;
		punt = punt -> prossimo;
	}

	//controllo in che posto mettere
	if (precedente == NULL)
		*start = nuovo;
	else
		precedente -> prossimo = nuovo;
}

//STAMPA
void print(struct Lista *start) {
	//caso base
	if (start == NULL) {
		printf("\n");
		return;
	}

	printf("%d\n", start -> valore);
	print(start->prossimo);
}

//ELIMINAZIONE
struct Lista *remove_val (struct Lista *start, int val) {
	//caso base
	if (start == NULL) {
		return NULL;
	}

	if (start -> valore == val) {
		struct Lista *punt = start -> prossimo;
		free(start);
		return remove_val(punt, val);
	}

	start -> prossimo = remove_val(start -> prossimo, val); //serve per mantere il collegamento dei vari nodi della lista
	return start;
}

int main () {
	//dichiarazione delle variabili
	int scelta = -1, numero, trovato;
	struct Lista *head = NULL;

	//menu
	while (scelta != 0) {
		printf("--------------------------------\n");
		printf("0 - Esci\n1 - Inserisci un valore\n2 - Stampa\n");
		scanf("%d", &scelta);

		switch (scelta) {
			case 0:
				printf("Ciao!\n");
				break;
			case 1:
				printf("--------------------\n");
				printf("Inserisci un numero: ");
				scanf("%d", &numero);
				insert(&head, numero);
				break;
			case 2:
				printf("--------------------\n");
				printf("Inserisci un numero: ");
				scanf("%d", &trovato);
				head = remove_val(head, trovato);
				print(head);
				break;
		}
	}

	return 0;
}
