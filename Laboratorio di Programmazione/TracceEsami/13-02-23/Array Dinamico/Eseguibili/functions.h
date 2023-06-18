#include "structures.h"
#include <stdio.h>
#include <stdlib.h>

//funzione di inizializzazione dello stack
void init_stack(struct Report *);

//funzione di inserimento dati nella pila
int push (struct Report *, struct Veicolo);

//funzione di caricamento dati dal file
int load_vehicles_from_file(struct Report *, char[]);

//funzione di controllo se il veicolo deve essere sanzionato o meno
int is_crime(struct Veicolo);

//funzione di pop dalla pila
int pop (struct Report *, struct Veicolo *);

//funziona di scrittura nel nuovo file
void write_crimes_on_file(struct Report *, char[]);

//funzione di deallocazione
void deallocate (struct Report *);
