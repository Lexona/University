#include "functions.h"

//funzione di inizializzazione della struttura
void init_partita(struct Partita *p) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			p->campo[i][j] = 0;
		}
	}

	p -> punteggio = 0;
	p -> prossimo = NULL;
}

//funzione di calcolo delle posizioni libere
int free_positions(char *campo, int dim) {
	//caso base
	if (dim == 0)
		return 0;

	//altri casi
	if (*campo == '@')
		return 1 + free_positions(campo + 1, dim - 1);
	else
		return free_positions(campo + 1, dim - 1);
}

//funzione di calcolo del punteggio
int match_score(struct Partita p) {
	if (p.vincitore == 'P')
		return 0;
	else
		return 3 + free_positions(p.campo[0], 9);
}

//funzione di inserimento nella lista
void append_in_list(struct Partita **start, struct Partita p) {
	if (*start == NULL) {
		//creo il nuovo nodo
		struct Partita *nuovo = malloc(sizeof(struct Partita));
		*nuovo = p; //metto tutti i valori nella nuova struct
		nuovo -> prossimo = NULL;
		*start = nuovo;
		return;
	}

	append_in_list(&((*start) -> prossimo), p);
}

//funzione per determinare il vincitore
char the_winner_is(char campo[][3]) {
	//controllo sulle righe
	for (int i = 0; i < 3; i++) {
		if (campo[i][0] == campo[i][1] && campo[i][0] == campo[i][2]) {
			if (campo[i][0] == 'O' || campo[i][0] == 'X')
				return campo[i][0];
		}
	}

	//controllo sulle colonne
	for (int i = 0; i < 3; i++) {
		if (campo[0][i] == campo[1][i] && campo[0][i] == campo[2][i]) {
			if (campo[0][i] == 'O' || campo[0][i] == 'X')
				return campo[0][i];
		}
	}

	//controllo la diagonale principale
	if (campo[0][0] == campo[1][1] && campo[0][0] == campo[2][2]) {
		if (campo[0][0] == 'O' || campo[0][0] == 'X')
			return campo[0][0];
	}

	//controllo la diagonale secondaria
	if (campo[0][2] == campo[1][1] && campo[0][2] == campo[2][0]) {
		if (campo[0][2] == 'O' || campo[0][2] == 'X')
			return campo[0][2];
	}

	//nel caso in cui non c'è un vincitore
	return 'P';
}

//funzione di caricamento dal file
int load_matches_from_file (struct Partita **start, char nomeFile[]) {
	//dichiarazione delle variabili
	struct Partita p;
	char line[10]; // per leggere le righe del file

	//apro il file in modalità lettura
	FILE *file = fopen(nomeFile, "r");
	//controllo se il file sia stato aperto correttamente
	if (file == NULL)
		return 1;

	//richiamo della funzione di inizializzazione della struttura
	init_partita(&p);

	//leggo una riga dal file
	while (fscanf(file, "%s", line) == 1) {
		strncpy(p.campo[0], line, 9);
		//calcolo il vincitore
		p.vincitore = the_winner_is(p.campo);
		//calcolo il punteggio
		p.punteggio = match_score(p);
		//inserimento nella lista
		append_in_list(start, p);
	}

	//chiudo il file
	fclose(file);

	return 0;
}

//funzione di stampa di una singola configurazione
void print_match(struct Partita p) {
	printf("----------------------\n");
	printf("Vittoria: %c\n", p.vincitore);
	printf("Punteggio: %d\n", p.punteggio);
	printf("Campo: ");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%c ", p.campo[i][j]);
		}
	}

	printf("\n");
	printf("-----------------------\n");
}

//funzione di stampa di tutti gli elementi della lista
void print_list(struct Partita *start) {
	//controllo se la lista è vuota
	if (start == NULL)
		return;

	print_match(*start);
	print_list(start -> prossimo);
}

//funzione di rimozione delle configurazioni di pareggio
void remove_tied(struct Partita **start) {
	//dichiaro le variabili
	struct Partita *punt = *start;
	struct Partita *precedente = NULL;
	//scorro la lista fino a quando non trovo una situazione di pareggio
	while (punt != NULL) {
		if (punt -> vincitore == 'P') {
			struct Partita *toDel = punt;
			//controllo in che posizione mi trovo
			if (precedente == NULL)
				*start = toDel -> prossimo;
			else
				precedente -> prossimo = toDel -> prossimo;

			punt = toDel -> prossimo;
			free(toDel);
		}

		precedente = punt;
		punt = punt -> prossimo;
	}
}

//funzione di deallocazzione della lista
void free_list(struct Partita *start) {
	struct Partita *temp;

	while (start != NULL) {
		temp = start -> prossimo;
		free(start);
		start = temp;
	}
}

//funzione per scrivere sui file
int write_winners_on_file(char nomeFile[], struct Partita *start, char giocatore) {
	//apro il file in scrittura
	FILE *file = fopen(nomeFile, "w");
	//controllo che il file sia stato aperto correttamente
	if (file == NULL)
		return 1;

	struct Partita *punt = start;
	//scorro la lista
	while (punt != NULL) {
		if (punt -> vincitore == giocatore) {
			char line[10];
			line[9] = '\0';
			strncpy(line, punt -> campo[0], 9);
			fprintf(file, "%s\n", line);
		}

		punt = punt -> prossimo;
	}

	//chiudo il file
	fclose(file);
	return 0;
}
