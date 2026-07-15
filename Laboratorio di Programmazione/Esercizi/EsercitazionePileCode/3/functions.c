#include "functions.h"
#include <stdlib.h>

//inserimento dell'elemento nella pila
int push (struct Lista **start, int val) {
	//creo il nuovo nodo
	struct Lista *nuovo = malloc(sizeof(struct Lista));
	nuovo -> valore = val;
	nuovo -> prossimo = NULL;

	//scorro la lista
	struct Lista *punt = *start;
	struct Lista *precedente = NULL;

	while (punt != NULL) {
		precedente = punt;
		punt = punt -> prossimo;
	}

	//controllo dove si deve aggiungere l'elemento
	if (precedente == NULL) {
		*start = nuovo;
	} else {
		precedente -> prossimo = nuovo;
	}

	return 0;
}

//eliminazione elemento dalla pila
int pop (struct Lista **start, int *val) {
	//controllo se la pila è vuota
	if (*start == NULL)
		return 1;

	struct Lista *punt = *start;
	struct Lista *precedente = NULL;

	//scorro la lista fino all'ultimo elemento
	while (punt -> prossimo != NULL) {
		precedente = punt;
		punt = punt -> prossimo;
	}

	//controllo se l'elemento da eliminare sta all'inizio della pila
	if(punt == *start){
		*val = punt -> valore;
		*start = NULL;
		free(punt);
	} else {
        	*val = punt -> valore;
        	precedente -> prossimo = NULL;
        	free(punt);
	}

	return 0;
}
