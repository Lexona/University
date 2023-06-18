#include "structures.h"
#include <stdio.h>
#include <stdlib.h>

//funzione di inizializzazione della coda
void init_queue (struct Bacheca *);

//funzione restituisce il numero di elementi contenuti in bacheca
int len (struct Bacheca *);

//funzione di controllo se la coda è vuota
int is_empty (struct Bacheca *);

//funzione di inserimento dati nella coda
int append (struct Bacheca *, struct Post *);

//funzione di caricamento dati dal file
void load_user_from_file (struct Bacheca *, char[]);

//funzione di pop dalla coda
struct Post *pop (struct Bacheca *);

//funzione di stampa
void print(struct Post *);

//funzione di deeallocazione
void deallocate (struct Bacheca *);

//funzione di scrittura nel nuovo file
void write_post_on_file (struct Post *, char []);
