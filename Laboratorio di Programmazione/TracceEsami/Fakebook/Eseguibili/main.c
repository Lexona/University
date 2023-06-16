#include <stdio.h>
#include "functions.h"

int main () {
	//dichiaro il puntatore alla struttura Bacheca
	printf("Leggo i dati dal file...\n");
	struct Bacheca *b = load_posts_from_file("utente42.txt");

	//dichiaro le variabili che servono per il menu
	int scelta = -1;

	//stampo il primo post
	struct Post *current_post = pop(b);
	print_post(current_post);

	//menu
	while (scelta != 0) {
		printf("-------------------------------------\n");
		printf("0 - Fermati\n1 - Vai al prossimo post\n2 - Aggiungi un like al post attuale\n3 - Condividi il post attuale\n");
		scanf("%d", &scelta);

		switch(scelta) {
			case 0:
				deallocate(b);
				break;
			case 1:
				current_post = pop(b);
				print_post(current_post);
				break;
			case 2:
				current_post->n_like++;
				break;
			case 3:
				save_post_on_file(current_post, "condivisi.txt");
				break;
		}
	}

	return 0;
}
