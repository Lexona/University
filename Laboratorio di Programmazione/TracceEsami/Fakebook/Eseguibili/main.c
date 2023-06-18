#include <stdio.h>
#include "functions.h"

int main () {
	//dichiarazione delle variabili
	struct Bacheca b;
	int scelta = -1;

	//richiamo la funzione di caricamento dati dal file
	printf("Leggo i dati dal file...\n");
	load_user_from_file(&b, "utente42.txt");

	//stampo il primo post
	struct Post *current_post = pop(&b);
	print(current_post);

	//menu
	while (scelta != 0) {
		printf("-------------------------\n");
		printf("0 - Esci\n1 - Andare al prossimo post\n2 - Aggiungere un like al prossimo post\n3 - Condividere il post attuale\n");
		scanf("%d", &scelta);

		switch (scelta) {
			case 0:
				printf("Ciao!\n");
				deallocate(&b);
				break;
			case 1:
				current_post = pop(&b);
				print(current_post);
				break;
			case 2:
				current_post->n_like++;
				printf("Like aggiunto!\n");
				break;
			case 3:
				printf("Scrivo sul file...\n");
				write_post_on_file(current_post, "condivisi.txt");
				break;
		}
	}

	return 0;
}
