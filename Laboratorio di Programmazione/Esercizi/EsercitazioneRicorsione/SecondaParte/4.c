//Data una lista concatenata in cui ogni nodo contiene un numero di telefono codificato in forma di vettore di interi, scrivere una funzione ricorsiva che elimini dalla lista tutti i numeri di telefono che non iniziano con prefisso 081.

#include <stdio.h>
#include <stdlib.h>

//dichiarazione della struttura
struct Lista {
	int telefono[10];
	struct Lista *prossimo;
};

//FUNZIONE DI INSERIMENTO NELLA LISTA
void insert(struct Lista **start, int num[]) {
	//creo il nuovo nodo
	struct Lista *nuovo = malloc(sizeof(struct Lista));
	nuovo -> prossimo = NULL;

	for (int i = 0; i < 10; i++) {
		nuovo -> telefono[i] = num[i];
	}

	//scorro la lista
	struct Lista *punt = *start;
	struct Lista *precedente = NULL;
	while (punt != NULL) {
		precedente = punt;
		punt = punt -> prossimo;
	}

	//controllo in che posizione inserire il nuovo nodo
	if (precedente == NULL)
		*start = nuovo;
	else
		precedente -> prossimo = nuovo;
}

struct Lista *remove_val(struct Lista *start) {
	//caso base
	if (start == NULL) {
		return NULL;
	}

	//altri casi
	if (start -> telefono[0] == 0 && start -> telefono[1] == 8 && start -> telefono[2] == 1) {
		struct Lista *punt = start -> prossimo;
		free(start);
		return remove_val(punt);
	}

	start -> prossimo = remove_val(start -> prossimo);
	return start;
}

void print_list (struct Lista *start) {
	//caso base
	if (start == NULL) {
		printf("\n");
		return;
	}

	for (int i = 0; i < 10; i++) {
		printf("%d", start -> telefono[i]);
	}

	printf("\n");
	print_list(start -> prossimo);
}

int main () {
	//dichiarazione variabili
	int scelta = -1, numero[10];
	struct Lista *head = NULL;

	//menu
	while (scelta != 0){
		printf("---------------------\n");
		printf("0 - Esci\n1 - Inserisci un numero di telefono\n2 - Elimina e stampa\n");
		scanf("%d", &scelta);

		switch (scelta) {
			case 0:
				printf("Ciao!\n");
				break;
			case 1:
				printf("------------------\n");
				printf("Inserisci un numero di telefono: ");
				for (int i = 0; i < 10; i++) {
					scanf("%d", &numero[i]);
				}

				insert(&head, numero);
				break;
			case 2:
				printf("---------------------------\n");
				head = remove_val(head);
				print_list(head);
				break;
		}
	}

	return 0;
}
