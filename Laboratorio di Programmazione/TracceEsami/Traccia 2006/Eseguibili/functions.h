#include "structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//funzione di inizializzazione della struttura
void init_partita(struct Partita *);

//funzione di calcolo delle posizioni libere
int free_positions(char *, int);

//funzione di calcolo del punteggio
int match_score(struct Partita);

//funzione di inserimento nella lista
void append_in_list(struct Partita **, struct Partita);

//funzione per determinare il vincitore
char the_winner_is(char [3][3]);

//funzione di caricamento dal file
int load_matches_from_file (struct Partita **, char[]);

//funzione di stampa di una singola configurazione
void print_match(struct Partita);

//funzione di stampa di tutti gli elementi della lista
void print_list(struct Partita *);

//funzione di rimozione delle configurazioni di pareggio
void remove_tied(struct Partita **);

//funzione di deallocazzione della lista
void free_list(struct Partita *);

//funzione per scrivere sui file
int write_winners_on_file(char [], struct Partita *, char);
