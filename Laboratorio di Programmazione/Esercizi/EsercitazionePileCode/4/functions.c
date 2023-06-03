#include "functions.h"
#include <stdio.h>

//funzione di inizializzazione dello stack
void init_stack(struct Pila *p) {
	p -> first_in = 0;
}

//funzione di conversione in binario e inserimento nella pila
void push (struct Pila *p, int num) {
	int resto;

	while (num != 0) {
		resto = num % 2;
		num = num/2;
		p -> binario[p -> first_in] = resto;

		p -> first_in++;
	}
}
//funzione di stampa degli elementi nella pila

void pop (struct Pila *p) {
	int valore;

	for (int i = p -> first_in - 1; i >= 0; i--) {
		valore = p -> binario[i];
		printf("%d", valore);
	}
}
