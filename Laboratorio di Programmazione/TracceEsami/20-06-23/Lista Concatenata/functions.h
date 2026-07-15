#include "structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//funzione di inserimento dati nella lista (inserimento in coda semplice)
void insert (struct Personaggio **, struct Personaggio *);

//funzione di lettura dati dal file
int load (struct Personaggio **, char []);

//funzione di stampa della lista
void print (struct Personaggio *);

//funzione di eliminazione di un nodo dalla lista
int remove_node (struct Personaggio **, char[]);

//funzione per far colpire due personaggi
void colpisci (struct Personaggio *, struct Personaggio *);

//funzione della sfida effettiva
void sfida (struct Personaggio *, struct Personaggio *);

//funzione di scrittura dati nel file (Facoltativo A)
void write (struct Personaggio *, char []);

//funzione di deallocazione della lista
void deallocate (struct Personaggio *);

//funzione per cercare gli sfidanti nella lista
void trova_personaggio (struct Personaggio *, struct Personaggio *, struct Personaggio *);

//funzione che mi trova due personaggio randomici all'interno della lista (Facoltativo B)
void rand_players(struct Personaggio *, struct Personaggio *, struct Personaggio *);


