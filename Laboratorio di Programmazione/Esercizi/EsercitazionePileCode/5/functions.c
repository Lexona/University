#include "functions.h"
#include <stdlib.h>

//funzione di deallocazione
void deallocate (struct Lista *start) {
	while (start != NULL) {
		struct Lista *punt = start -> prossimo;
		free(start);
		start = punt;
	}

}

//funzione di inserimento nella coda
int insert_queue (struct Lista **start, int val) {
	//creo un nuovo nodo
	struct Lista *nuovo = malloc(sizeof(struct Lista));
	nuovo -> prossimo = NULL;
	nuovo -> valore = val;

	//scorro la lista
	struct Lista *punt = *start;
	struct Lista *precedente = NULL;

	while (punt != NULL) {
		precedente = punt;
		punt = punt -> prossimo;
	}

	//controllo se si tratta del primo inserimento oppure no
	if (precedente == NULL)
		*start = nuovo;
	else
		precedente -> prossimo = nuovo;

	return 0;
}

//funzione di eliminazione dell'elemento dalla coda
int get_from_queue(struct Lista **start, int *val) {

	//controllo se la pila è vuota
	if (*start == NULL)
		return 1;

	struct Lista *punt = *start;
	*val = punt -> valore;

	//controllo se c'è un solo elemento nella lista
	if (punt -> prossimo  == NULL) {
		*start = NULL;
		free(punt);
		return 0;
	}

	*start = punt -> prossimo;
	punt -> prossimo = NULL;
	free(punt);
	return 0;
}
