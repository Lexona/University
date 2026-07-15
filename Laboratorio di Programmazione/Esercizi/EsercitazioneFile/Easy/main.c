#include <stdio.h>
#include "functions.h"
#define MAX 50

int main () {
	struct Elenco e;
	struct Studente s;
	int scelta;

	//inizializzazione della pila
	init_stack(&e);

	//inserimento nella pila
	for (int i = 0; i < 3; i++) {
		acquisisci(&s);
		push(&e, s);
	}

	//stampa degli elementi
	for (int i = 0; i < 3; i++) {
		struct Studente s;
		pop(&e, &s);
		stampa(s);
	}

	return 0;
}
