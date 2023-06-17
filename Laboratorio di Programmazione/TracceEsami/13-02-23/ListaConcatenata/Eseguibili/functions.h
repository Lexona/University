#include "structures.h"
#include <stdio.h>
#include <stdlib.h>

//funzione di inserimento nella lista
void push (struct Report **, struct Veicolo);

//funzione di caricamento dati dal file
int load_vehicles_from_file(struct Report **, char[]);

//funzione di calcolo del sanzionamento
int is_crime(struct Veicolo);

//funzione di pop
int pop(struct Report **, struct Veicolo *);

//funzione di scrittura nel nuovo file
void write_crimes_on_file(struct Report *, char[]);
