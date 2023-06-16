#include "structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//funzione che restituisce il numero di elementi contenuti nella bacheca
int len(struct Bacheca *);

//funzione di controllo se la bacheca è vuota oppure no
int is_empty(struct Bacheca *);

//implemento una funzione per la creazione della bacheca (dato che deve trovarsi nell'heap)
struct Bacheca *create_Bacheca(int);

//funzione di caricamento dati dalla strutura Post alla strutura Bacheca
void append(struct Bacheca *, struct Post *);

//funzione di lettura dati dal file
struct Bacheca *load_posts_from_file(char[]);

//funzione di pop
struct Post *pop (struct Bacheca *);

//funzione di stampa di un elemento
void print_post (struct Post *);

//funzione di deallocazione della bacheca
void deallocate(struct Bacheca *);

//funzione di condivisione dei post sul file
void save_post_on_file(struct Post *, char[]);
