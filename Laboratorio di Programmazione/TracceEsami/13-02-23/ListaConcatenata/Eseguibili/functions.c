#include "functions.h"

//funzione di inserimento nella lista
void push (struct Report **start, struct Veicolo v) {
	//creo il nuovo nodo
	struct Report *nuovo = malloc(sizeof(struct Report));
	nuovo -> prossimo = NULL;
	nuovo->deposito = v;

	//scorro la lista
	struct Report *punt = *start;
	struct Report *precedente = NULL;

	while (punt != NULL) {
		precedente = punt;
		punt = punt -> prossimo;
	}

	//controllo dove bisogna collocare il nuovo nodo
	if (precedente == NULL)
		*start = nuovo;
	else
		precedente->prossimo = nuovo;
}

//funzione di caricamento dati dal file
int load_vehicles_from_file(struct Report **start, char nomeFile[]) {
	//apro il file in modalità lettura
	FILE *file = fopen(nomeFile, "r");
	//controllo che l'apertura sia avvenuta con successo
	if (file == NULL) {
		printf("Qualcosa e' andato storto con l'apertura del file\n");
		return 1;
	}

	//dichiarazione delle variabili
	int check = 0;
	struct Veicolo v;

	while (!feof(file)) {
		if (fscanf(file, "%s %f %d", v.targa, &v.velocita, &v.limite) == 3)
			push(start, v);
	}

	fclose(file);
}

//funzione di calcolo del sanzionamento
int is_crime(struct Veicolo v) {
	int limite_con_tolleranza = v.limite + (5*(v.limite/100));

	if (v.velocita > limite_con_tolleranza)
		return 1;

	return 0;
}

//funzione di pop
int pop(struct Report **start, struct Veicolo *v) {
	//dichiarazione delle variabili
	struct Report *punt = *start;
	struct Report *toDel = NULL;
	struct Report *precedente = NULL;

	//controllo se la lista è vuota
	if (*start == NULL)
		return 1;

	//scorro la lista fino ad arrivare all'ultimo elemento
	while (punt->prossimo != NULL) {
		precedente = punt;
		punt = punt -> prossimo;
	}

	*v = punt->deposito;
	toDel = punt;

	if ((*start) -> prossimo != NULL)
		precedente -> prossimo = NULL;
	else
		*start = NULL;

	free(toDel);

	return 0;
}

//funzione di scrittura nel nuovo file
void write_crimes_on_file(struct Report *start, char nomeFile[]) {
	//dichiarazione delle variabili
	struct Veicolo v;
	int check = 0, limite_superato, sanzione;

	//apro il file in modalità scrittura
	FILE *file = fopen(nomeFile, "w");
	//controllo che il file si sia aperto correttamente
	if (file == NULL) {
		printf("Qualcosa e' andato storto con l'apertura del file\n");
		return;
	}

	while (check == 0) {
		check = pop(&start, &v);

		if (check == 0)
			if (is_crime(v) == 1) {
				limite_superato = v.velocita - v.limite;

				if (limite_superato > 0 && limite_superato <= 10)
					sanzione = 173;
				else if (limite_superato > 10 && limite_superato <= 40)
					sanzione = 695;
				else if (limite_superato > 40 && limite_superato <= 60)
					sanzione = 2170;
				else if (limite_superato > 60)
					sanzione = 3382;

				fprintf(file, "%s %d %d\n", v.targa, limite_superato, sanzione);
			}
	}

	fclose(file);
}

















