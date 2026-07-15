#include "functions.h"
#include <stdio.h>

int main () {
	//dichiarazione delle variabili
	struct Veicolo v;
	struct Report r;
	int check = 0, check_sanzionamento = 0;

	//richiamo della funzione di caricamento dati
	printf("Sto caricando i dati...\n");
	if (load_vehicles_from_file(&r, "autovelox.txt") == 0)
		printf("Inserimento avvenuto con successo\n");
	else
		printf("Qualcosa e' andato storto\n");

	//funzione di scrittura nel nuovo file
	printf("Scrivo sul file...\n");
	write_ctimes_on_file(&r, "sanzionati.txt");

	return 0;
}
