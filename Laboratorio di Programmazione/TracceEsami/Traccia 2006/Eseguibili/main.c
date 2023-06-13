#include <stdio.h>
#include "functions.h"

int main () {
	//dichiarazione delle variabili
	struct Partita *head = NULL;
	int check = 0;

	//richiamo della funzione di caricamento dal file nella lista
	printf("Calcolo dei dati...\n");
	load_matches_from_file (&head, "configurazioni.txt");

	printf("Prima dell'eliminazione\n");
	print_list(head);

	//richiamo la funzione di eliminazione
	remove_tied(&head);
	printf("Dopo la rimozione\n");
	print_list(head);

	check = write_winners_on_file("vittorie_X.txt", head, 'X');
	if (check != 0)
		printf("Qualcosa e' andato storto!\n");

	check = write_winners_on_file("vittorie_O.txt", head, 'O');
	if (check != 0)
		printf("Qualcosa e' andato storto!\n");

	free_list(head);
	head = NULL;

	return 0;
}
