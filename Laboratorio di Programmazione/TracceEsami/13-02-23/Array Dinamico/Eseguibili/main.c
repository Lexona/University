#include <stdio.h>
#include "functions.h"

int main () {
	//dichiarazione delle variabili
	struct Report r;

	//inizializzo la struttura Report
	init_stack(&r);

	//richiamo funzione di caricamento dati dal file alla struttura Report
	printf("Lettura del file...\n");
	load_vehicles_from_file(&r, "autovelox.txt");

	//richiamo la funzione di scrittura nel nuovo file
	printf("Scrivo nel nuovo file...\n");
	write_crimes_on_file(&r, "sanzionati.txt");

	//dealloco
	deallocate(&r);

	return 0;
}
