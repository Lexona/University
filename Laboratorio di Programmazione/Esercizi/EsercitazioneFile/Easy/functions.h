#include "structures.h"

//inizializzazione della pila
void init_stack(struct Elenco *);

//inserimento dei dati dello studente
void acquisisci(struct Studente *);

//funzione di inserimento nella pila
int push (struct Elenco *, struct Studente);

//funzione di pop dalla pila
int pop (struct Elenco *, struct Studente *);

//funzione di stampa dell'elemento della pila
void stampa (struct Studente);
