#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

//funzione di assegnazione dei valori nella struttura dell'array
void init_array (struct Elenco *);

//funzione di inserimento dati nel vettore
void insert (struct Elenco *, struct Personaggio *);

//funzione di lettura dati dal file
void load (struct Elenco *, char []);

//funzione di stampa dell'array
void print (struct Elenco);

//funzione di ricerca di un giocatore
void trova_personaggio (struct Elenco l, struct Personaggio *, struct Personaggio *);

//funzione per far colpire i due personaggi
void colpisci (struct Personaggio *, struct Personaggio *);

//funzione di inizio della sfida
void sfida (struct Personaggio *, struct Personaggio *);

//funzione di swap a sinistra
void spostamento_a_sinistra (struct Elenco *, int);

//funzione di rimozione di un giocatore dall'array
int remove_player (struct Elenco, char[]);

//funzione di scrittura nel nuovo file
void write (struct Elenco, char[]);
