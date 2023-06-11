#include "structures.h"
#include <stdio.h>

//inizializzazione dello stack
void init_stack(struct Elenco *);

//lettura dati dal file
int load_next_student_from_file(FILE *, struct Studente *);

//push degli elementi nella pila
int push (struct Elenco *, struct Studente);

//funzione intermedia per il salvataggio dei dati nell'elenco
int load_students_from_file(struct Elenco *, char []);

//funzione di pop dalla pila
int pop(struct Elenco *, struct Studente *);

//funzione di stampa
void print(struct Studente);

//funzione di scrittura nel file
int write_student_on_file(FILE *, struct Studente);

//funzione intermedia per prendere i dati dall'elenco
int write_students_on_file(struct Elenco *, char[], char, char);
