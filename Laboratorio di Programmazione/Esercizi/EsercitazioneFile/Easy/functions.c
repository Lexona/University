#include "functions.h"
#include <stdio.h>

//inizializzazione della pila
void init_stack(struct Elenco *e) {
	e -> first_in = 0;
}

//inserimento dei dati dello studente
void acquisisci (struct Studente *s) {
	printf("Matricola: ");
	scanf("%s", s -> matricola);
	printf("Nome: ");
	scanf("%s", s -> nome);
	printf("Cognome: ");
	scanf("%s", s -> cognome);
}

//inserimento dei dati nella pila
int push (struct Elenco *e, struct Studente val) {
	//controllo se la pila è piena
	if (e -> first_in >= MAX) {
		printf("La pila e' piena!\n");
		return 1;
	}

	e -> deposito[e -> first_in] = val;
	e -> first_in++;

	return 0;
}

//funzione di pop dalla pila
int pop (struct Elenco *e, struct Studente *val) {
	//controllo se la pila è vuota
	if (e -> first_in <= 0) {
		printf("La pila e' vuota!\n");
		return 1;
	}

	*val = e -> deposito[e -> first_in - 1];
	e -> first_in--;

	return 0;
}

//funzione di acquisizione del valore della pila
void stampa (struct Studente s) {
	printf("------------------------------\n");
	printf("Matricola: %s\n", s.matricola);
	printf("Nome: %s\n", s.nome);
	printf("Cognome: %s\n", s.cognome);
	printf("------------------------------\n");
}












