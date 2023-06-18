#include "functions.h"

//funzione di inizializzazione dello stack
void init_stack(struct Report *r) {
	r->deposito = (struct Veicolo*)malloc(MAX*sizeof(struct Veicolo));
	r->first_in = 0;
}

//funzione di inserimento dati nella pila
int push (struct Report *r, struct Veicolo v) {
	//controllo se la pila è piena
	if (r->first_in > MAX)
		return 1;

	//inserisco i dati nella pila
	r->deposito[r->first_in] = v;
	r->first_in++;

	return 0;
}

//funzione di caricamento dati dal file
int load_vehicles_from_file(struct Report *r, char nomeFile[]) {
	//apro il file in modalità lettura
	FILE *file = fopen(nomeFile, "r");
	//controllo che il file sia stato aperto correttamente
	if (file == NULL) {
		printf("Qualcosa e' andato storto con l'apertura del file\n");
		return 1;
	}

	//dichiaro le variabili che mi servono
	struct Veicolo v;

	//leggo il file
	while (fscanf(file, "%s %f %f", v.targa, &v.velocita, &v.limite) == 3)
		push(r, v);

	//chiudo il file
	fclose(file);
	return 0;
}

//funzione di controllo se il veicolo deve essere sanzionato o meno
int is_crime(struct Veicolo v) {
	float limite_con_tolleranza = v.limite + (5*(v.limite/100));

	//controllo se il veicolo è sanzionabile
	if (v.velocita > limite_con_tolleranza)
		return 1;

	return 0;
}

//funzione di pop dalla pila
int pop (struct Report *r, struct Veicolo *v) {
	//controllos se la pila è vuota
	if (r->first_in <= 0)
		return 1;

	//negli altri casi
	*v = r->deposito[r->first_in - 1];
	r->first_in--;

	return 0;
}

//funziona di scrittura nel nuovo file
void write_crimes_on_file(struct Report *r, char nomeFile[]) {
	//apro il file in modalità scrittura
	FILE *file = fopen(nomeFile, "w");
	//controllo se il file è stato aperto correttamente
	if (file == NULL) {
		printf("Qualcosa e' andato storto con l'apertura del file\n");
		return;
	}

	//dichiarazione delle variabili
	struct Veicolo v;
	float limite_superato, sanzione;

	while (pop(r, &v) == 0) {
		if (is_crime(v) == 1) {
			limite_superato = v.velocita - v.limite;

			//calcolo il valore della sanzione
			if (limite_superato > 0 && limite_superato <= 10)
				sanzione = 173.0;
			else if (limite_superato > 10 && limite_superato <= 40)
				sanzione = 695.0;
			else if (limite_superato > 40 && limite_superato <= 60)
				sanzione = 2170.0;
			else if (limite_superato > 60)
				sanzione = 3382.0;

			//scrivo nel file i valori trovati
                	fprintf(file, "%s %.1f %.1f\n", v.targa, limite_superato, sanzione);
		}
	}

	//chiudo il file
	fclose(file);
}

//funzione di deallocazione
void deallocate (struct Report *r) {
	free(r->deposito);
}

















