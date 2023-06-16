#include "functions.h"

//funzione che restituisce il numero di elementi contenuti nella bacheca
int len(struct Bacheca *b) {
	return b->n_occupati;
}

//funzione di controllo se la bacheca è vuota oppure no
int is_empty(struct Bacheca *b) {
	if (b->n_occupati == 0)
		return 1;

	return 0;
}

//implemento una funzione per la creazione della bacheca (dato che deve trovarsi nell'heap)
struct Bacheca *create_Bacheca(int totale) {
	struct Bacheca *b = (struct Bacheca*)malloc(sizeof(struct Bacheca)); //necessario il cast esplicito (Bacheca*) per assegnare il puntatore di tipo generico restituito da malloc() al puntatore specifico di tipo Bacheca*.
	b->deposito = (struct Post**)malloc(totale*sizeof(struct Post*));

	b->first_in = 0;
	b->first_out = 0;
	b->n_occupati = 0;

	return b;
}

//funzione di caricamento dati dalla strutura Post alla strutura Bacheca
void append(struct Bacheca *b, struct Post *p) {
	//controllo se la coda e' piena
	if (b->n_occupati >= MAX) {
		printf("La coda e' piena!\n");
		return;
	}

	b->deposito[b->first_in] = p;
	b->first_in = (b->first_in + 1) % MAX;
	b->n_occupati++;
}

//funzione di lettura dati dal file
struct Bacheca *load_posts_from_file(char nomeFile[]) {
	//apro il file in modalità lettura
	FILE *file = fopen(nomeFile, "r");
	//controllo che il file sia stato aperto correttamente
	if (file == NULL) {
		printf("Qualcosa e' andato storto!\n");
		return NULL;
	}

	//creo la bacheca
	struct Bacheca *b = create_Bacheca(MAX);
	char c;

	//dichiaro le variabili che mi servono per la lettura del file
	while (!feof(file)) {
		struct Post *p = (struct Post*)malloc(sizeof(struct Post));
		  //devo fare una lettura a vuoto perchè poi mi legge il nline
 		fscanf(file, "%c", &c);
		fgets(p->msg, sizeof(p->msg), file);
		fscanf(file, "%d", &p->n_like);

		//richiamo la funzione di inserimento dei dati dalla struttura Post alla struttura Bacheca
		append(b, p);
	}

	//chiudo il file
	fclose(file);
	return b;
}

//funzione di pop
struct Post *pop (struct Bacheca *b) {
	//controllo se la coda è vuota
	if (is_empty(b) == 1)
		return NULL;

	struct Post *p = b->deposito[b->first_out];
	b->first_out = (b->first_out + 1) % MAX;
	b->n_occupati--;

	return p;
}

//funzione di stampa di un elemento
void print_post (struct Post *p) {
	printf("--------------------------------------\n");
	printf("%s\n", p->msg);
	printf("%d\n", p->n_like);
	printf("--------------------------------------\n");
}

//funzione di deallocazione della bacheca
void deallocate(struct Bacheca *b) {
	for (int i = 0; i < b->n_occupati; i++) {
		free(b->deposito[i]);
	}

	free(b->deposito);
	free(b);
}

//funzione di condivisione dei post sul file
void save_post_on_file(struct Post *p, char nomeFile[]) {
	//apro il file in modalità scrittura
	FILE *file = fopen(nomeFile, "a");
	//controllo che il file sia stato aperto correttamente
	if (file == NULL) {
		printf("Qualcosa e' andato storto!\n");
		return;
	}

	//scrivo sul file
	fprintf(file, "%s\n", p->msg);
	fprintf(file, "%d\n", p->n_like);

	//chiudo il file
	fclose(file);
}

