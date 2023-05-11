//Implementare una struttura dati con politica di accesso Coda con relative funzioni di accesso utilizzando come struttura una lista concatenata.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//struttura dati
struct nodo {
	int valore;
	
	struct nodo *prossimo;
};

//FUNZIONE DI INSERIMENTO
void insert(struct nodo **head);
//FUNZIONE DI STAMPA
void print(struct nodo **head);
//FUNZIONE DI RIMOZIONE
void pop(struct nodo **head);

int main () {
	struct nodo *inizio = NULL;
	int scelta;
	
	while (true) {
		printf("---------------------------------------------------\n");
		printf("Cosa vuoi fare?\n0 - Esci\n1 - Inserisci\n2 - Rimuovi elemento dalla coda\n3 - Stampa\n");
		scanf("%d", &scelta);
		
		switch(scelta){
			case 0:
				return 0;
				break;
			case 1:
				insert(&inizio);
				break;
			case 2:
				pop(&inizio);
				break;
			case 3:
				print(&inizio);
				break;
		}
	}
	return 0;
}

//FUNZIONE DI INSERIMENTO
void insert(struct nodo **head) {
	struct nodo *punt = *head;
	struct nodo *precedente = NULL;
	struct nodo *nuovo;
	
	printf("------------------------------------------------------\n");
	
	//creo il nuovo nodo
	nuovo = malloc(sizeof(struct nodo));
	nuovo -> prossimo = NULL;
	
	printf("Inserisci un numero: ");
	scanf("%d", &nuovo -> valore);
	
	//scorro tutta la lista
	while (punt != NULL) {
		precedente = punt;
		punt = punt -> prossimo;
	}
	
	//controllo se si tratta del primo inserimento
	if (precedente == NULL) {
		*head = nuovo;
	} else {
		precedente -> prossimo = nuovo;
	}
}

//FUNZIONE DI STAMPA
void print(struct nodo **head) {
	struct nodo *punt = *head;
	
	printf("---------------------------------------------\n");
	
	while (punt != NULL) {
		printf("%d\n", punt -> valore);
		punt = punt -> prossimo;
	}
}

//FUNZIONE DI RIMOZIONE
void pop(struct nodo **head) {
	struct nodo *todel = *head;
	
	printf("---------------------------------------------------\n");
	
	//controllo se la lista è vuota
	if (*head == NULL) {
		printf("La lista e' vuota\n");
		return;
	} else {
		*head = todel -> prossimo;
		free(todel);
	}
}
