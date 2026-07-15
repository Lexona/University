#include "structures.h"
#include <stdio.h>

//funzione di inizializzazione dello stack
void init_stack(struct Report *);

//funzione di push nello stack
int push (struct Report *, struct Veicolo);

//funzione di caricamento dati dal file di testo
int load_vehicles_from_file(struct Report *, char[]);

//funzione di pop dallo stack
int pop (struct Report *, struct Veicolo *);

//funzione di controllo del sanzionamento
int is_crime (struct Veicolo);

//funzione di scrittura nel nuovo file
void write_ctimes_on_file (struct Report *, char[]);
