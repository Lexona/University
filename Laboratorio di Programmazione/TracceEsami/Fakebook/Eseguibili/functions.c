#include "functions.h"

//funzione di inizializzazione della coda
void init_queue (struct Bacheca *b) {
	b->deposito = (struct Post**)malloc(MAX * sizeof(struct Post*));
	b->first_in = 0;
	b->first_out = 0;
	b->n_occupati = 0;
}

//funzione restituisce il numero di elementi contenuti in bacheca
int len (struct Bacheca *b) {
	return b->n_occupati;
}

//funzione di controllo se la coda è vuota
int is_empty (struct Bacheca *b) {
	if (len(b) == 0)
		return 1;
	else
		return 0;
}

//funzione di inserimento dati nella coda
int append (struct Bacheca *b, struct Post p) {
	//controllo se la coda è vuota
	if (len(b) >= MAX)
		return 1;

	//negli altri casi
	b->deposito[b->first_in] = malloc(sizeof(struct Post));

	*b->deposito[b->first_in] = p;
	b->first_in = (b->first_in + 1) % MAX;
	b->n_occupati++;

	return 0;
}

//funzione di caricamento dati dal file
void load_user_from_file (struct Bacheca *b, char nomeFile[]) {
	//apro il file in modalità lettura
	FILE *file = fopen(nomeFile, "r");
	//controllo che il file sia stato aperto correttamente
	if (file == NULL) {
		printf("Qualcosa e' andato storto con l'apertura del file\n");
		return;
	}

	//inizializzo la coda
	init_queue (b);

	char c; //variabile di appoggio per la lettura
	struct Post p;

	while (!feof(file)) {
		fscanf(file, "%c", &c); //faccio una lettura a vuoto
		fgets(p.msg, sizeof(p.msg), file);
		fscanf(file, "%d", &p.n_like);

		//aggiungo i dati nella coda
		append(b, p);
	}

	//chiudo il file
	fclose(file);
}

//funzione di pop dalla coda
struct Post *pop (struct Bacheca *b) {
	//controllo se la coda è vuota
	if (is_empty(b) == 1)
		return NULL;

	//negli altri casi
	struct Post *p = b->deposito[b->first_out];
	b->first_out = (b->first_out + 1) % MAX;
	b->n_occupati--;
	return p;
}

//funzione di stampa
void print(struct Post *p) {
	printf("--------------------------\n");
	printf("%s\n", p->msg);
	printf("%d\n", p->n_like);
	printf("--------------------------\n");
}

//funzione di deeallocazione
void deallocate (struct Bacheca *b) {
	//controllo se è vuota
	if (is_empty(b) != 1) {
		for (int i = b->first_out; i < len(b); i++) {
			free(b->deposito[i]);
		}
	}

	free(b->deposito);
}

//funzione di scrittura nel nuovo file
void write_post_on_file (struct Post *p, char nomeFile[]) {
	//apro il file in modalità scrittura
	FILE *file = fopen(nomeFile, "a");
	//controllo che il file sia stato aperto correttamente
	if (file == NULL) {
		printf("Qualcosa e' andato storto con l'apertura del file\n");
		return;
	}

	//scrivo nel file
	fprintf(file, "%s\n", p->msg);
	fprintf(file, "%d\n", p->n_like);

	//chiudo il file
	fclose(file);
}


















