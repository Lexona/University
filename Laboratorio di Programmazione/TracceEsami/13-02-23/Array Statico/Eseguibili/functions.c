#include "functions.h"

//funzione di inizializzazione dello stack
void init_stack(struct Report *r) {
	r->first_in = 0;
}

//funzione di push nello stack
int push (struct Report *r, struct Veicolo val) {
	//controllo se lo stack è pieno
	if (r->first_in >= MAX)
		return 1;

	r->deposito[r->first_in] = val;
	r->first_in++;
	return 0;
}

//funzione di caricamento dati dal file di testo
int load_vehicles_from_file(struct Report *r, char nomeFile[]) {
	//dichiarazione delle variabili
	int check = 0;
	struct Veicolo v;

	//apro il file in modalità lettura
	FILE *file = fopen(nomeFile, "r");
	//controllo che il file sia stato aperto correttamente
	if (file == NULL)
		return 1;

	//richiamo la funzione di inizializzazione della pila
        init_stack(r);

	while (!feof(file)) {
		if (fscanf(file, "%s %f %d", v.targa, &v.velocita, &v.limite) == 3)
			push(r, v);
	}


	fclose(file);
	return 0;
}

//funzione di pop dallo stack
int pop (struct Report *r, struct Veicolo *val) {
	//controllo se lo stack è vuoto
	if (r->first_in <= 0)
		return 1;

	*val = r->deposito[r->first_in - 1];
	r->first_in--;
	return 0;
}

//funzione di controllo del sanzionamento
int is_crime (struct Veicolo v) {
	//dichiarazione variabile
	float limite_con_tolleranza;
	//calcolo del limite con tolleranza
	limite_con_tolleranza = v.limite + (5 * v.limite / 100.0);
	//controllo se è sanzionabile
	if (v.velocita > limite_con_tolleranza)
		return 1;

	return 0;
}

//funzione di scrittura nel nuovo file
void write_ctimes_on_file (struct Report *r, char nomeFile[]) {
	//apro il file in modalità scrittura
	FILE *file = fopen(nomeFile, "w");
	//controllo che il file sia stato aperto correttamente
	if (file == NULL)
		return;

	int check = 0, limite_superato;
	float soldi_sanzione;
	struct Veicolo v;

	while (pop(r, &v) == 0) {
		check = is_crime(v);

		//nel caso in cui trovo un veicolo da sanzionare
		if (check == 1) {
			//calcolo il limite superato
			limite_superato = v.velocita - v.limite;

			//calcolo l'ammontare della sanzione
			if (limite_superato > 0 && limite_superato <= 10)
				soldi_sanzione = 173.0;
			else if (limite_superato > 10 && limite_superato <= 40)
				soldi_sanzione = 695.0;
			else if (limite_superato > 40 && limite_superato <= 60)
				soldi_sanzione = 2170.0;
			else if (limite_superato > 60)
				soldi_sanzione = 3382.0;

			//scrivo i dati ottenuti sul file
			fprintf(file, "%s %d %f\n", v.targa, limite_superato, soldi_sanzione);
		}
	}

	//chiudo il file
	fclose(file);
}












