 #include "functions.h"
#include <stdlib.h>

int push (struct Lista **start, int val){
	//creo il nuovo nodo
	struct Lista *nuovo = malloc(sizeof(struct Lista));
	nuovo -> prossimo = NULL;
	nuovo -> valore = val;

	//dichiaro i puntatori che mi servono
	struct Lista *punt = *start;
	struct Lista *precedente = NULL;

	//mi scorro tutta la lista
	while (punt != NULL) {
		precedente = punt;
		punt = punt -> prossimo;
	}

	//controllo se la lista è vuota
	if (precedente == NULL) {
		*start = nuovo;
	} else {
		precedente -> prossimo = nuovo;
	}

	return 0;
}

int pop (struct Lista **start, int *min) {
	//controllo se la lista è vuota
	if (*start == NULL)
		return 1;

	//dichiarazioni variabili
	struct Lista *punt = (*start) -> prossimo;
	struct Lista *precedente = *start;
	struct Lista *toDel = *start;

	if (punt == NULL){ //controllo se ci sta un solo elemento nella lista
		*min = toDel -> valore;
		free(toDel);
		*start = NULL;
		return 0;
	}

	//in caso contrario mi scorro la lista per trovare il minimo
	while (punt != NULL) {
		if (punt -> valore < toDel -> valore) {
			toDel = punt;
		}
		punt = punt -> prossimo;
	}

	//mi salvo il valore del minimo
	*min = toDel -> valore;

	//faccio scorrere precedente
	while (precedente -> prossimo != toDel && precedente != toDel) {
		precedente = precedente -> prossimo;
	}

	//controllo in che posizione si trova l'elemento da eliminare
	if (toDel == *start) {
		*start = toDel -> prossimo;
		toDel -> prossimo = NULL;
		free(toDel);
	} else {
		precedente -> prossimo = toDel -> prossimo;
		toDel -> prossimo = NULL;
		free(toDel);
	}

	return 0;
}
