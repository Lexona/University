#include <stdio.h>
#include "functions.h"

int main () {
	struct Report *head = NULL;

	//richiamo la funzione di caricamento dati dal file
	printf("Sto caricando il file...\n");
	load_vehicles_from_file(&head, "autovelox.txt");

	//richiamo la funzione di scrittura nel file
	printf("Scrivo i sanzionati nel file...\n");
	write_crimes_on_file(head, "sanzionati.txt");

	return 0;
}
