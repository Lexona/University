#include <stdio.h>
#include "functions.h"

int main () {
	int scelta = -1, val, errore;
	struct Lista *head = NULL;

	while (scelta != 0) {
		printf("-------------------------------------------------\n");
		printf("0 - Esci\n1 - Inserisci\n2 - Elimina\n");
		scanf("%d", &scelta);

		switch(scelta) {
			case 0:
				deallocate(head);
				head = NULL;
				break;
			case 1:
				printf("----------------------------------------------\n");
				printf("Inserisci un numero: ");
				scanf("%d", &val);

				errore = insert_queue(&head, val);
				if (errore == 1)
					printf("Qualcosa e' andato storto!\n");
				else
					printf("Inserimento avvenuto con successo\n");
				break;
			case 2:
				printf("----------------------------------------------\n");
				errore = get_from_queue(&head, &val);
				if (errore == 1)
					printf("La coda e' vuota!\n");
				else
					printf("Il valore eliminato e' : %d\n", val);
		}
	}

	return 0;
}
