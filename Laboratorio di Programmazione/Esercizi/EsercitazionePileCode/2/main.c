#include <stdio.h>
#include <string.h>
#include "functions.h"
#define MAX 20

int main () {
	char parola[MAX], pila[MAX];
	int errore;

	printf("Scrivi una parola: ");
	do {
		scanf("%s", parola);
	} while(strlen(parola) > MAX);

	int dimensione = strlen(parola);

	//richiamo la funzione di inserimento della stringa nella pila
	push(parola, pila, dimensione);
	//richiamo la funzione di controllo
	errore = check(parola, pila, dimensione);

	if (errore == 1)
		printf("NO palindrona\n");
	else
		printf("Palindroma\n");

	return 0;
}
