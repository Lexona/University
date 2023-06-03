#include <stdio.h>
#include "functions.h"

int main () {
	int scelta = -1, val, errore;
	struct Lista *head = NULL;

	while (scelta != 0) {
		printf("---------------------------------------------------\n");
		printf("0 - Esci\n1 - Inserisci\n2 - Elimina\n");
		scanf("%d", &scelta);

		switch(scelta){
			case 0:
				break;
			case 1:
				printf("-------------------------------------------------\n");
				printf("Inserisci un valore: ");
				scanf("%d", &val);

				errore = push(&head, val);
				if (errore == 0)
					printf("Inserimento avvenuto con successo\n");
				else
					printf("Qualcosa e' andato storto\n");
				break;

			case 2:
				printf("---------------------------------\n");
				errore = pop(&head, &val);

				if (errore == 1)
					printf("La pila e' vuota!\n");
				else
					printf("Il valore eliminato e' : %d\n", val);
				break;
		}
	}


	return 0;
}
