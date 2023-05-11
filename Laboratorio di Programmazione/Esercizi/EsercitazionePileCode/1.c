//Definire una struttura dati contenente interi avente una politica di accesso del tipo minimum first out, in cui il valore più piccolo contenuto è sempre il primo ad uscire. Provarla con un apposito main(...).

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
//FUNZIONE DI RIMOZIONE DEL MINIMO
void get(struct nodo **head);

int main () {

	struct nodo *inizio = NULL;
	int scelta;
	
	while (true) {
	
		printf("-----------------------------------------------------------\n");
		printf("Cosa vuoi fare?\n0 - Esci\n1 - Inserimento\n2 - Rimozione del minimo\n3 - Stampa della lista\n");
		scanf("%d", &scelta);
	
		switch(scelta) {
			case 1:
				insert(&inizio);
				break;
			case 2:
				get(&inizio);
				break;
			case 0:
				return 0;
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
	struct nodo *nuovo = malloc(sizeof(struct nodo));
	
	printf("--------------------------------------------\n");
	printf("Inserisci un numero: ");
	scanf("%d", &nuovo -> valore);
	
	nuovo -> prossimo = NULL;
	
	//scorro tutta la lista
	while (punt != NULL) {
		precedente = punt;
		punt = punt -> prossimo;
	}
	
	//controllo se è il primo inserimento
	if (precedente == NULL) {
		*head = nuovo;
	} else {
		precedente -> prossimo = nuovo;
	}
}

//FUNZIONE DI STAMPA
void print(struct nodo **head) {
	struct nodo *punt = *head;
	
	printf("------------------------------------------------\n");
	while (punt != NULL) {
		printf("%d\n", punt -> valore);
		punt = punt -> prossimo;
	}
}

//FUNZIONE DI RIMOZIONE DEL MINIMO
void get(struct nodo **head) {
	struct nodo *save = *head;
	struct nodo *punt = (*head) -> prossimo;
	struct nodo *precedente = *head;
	
	int minimo;
	
	printf("-------------------------------------------------\n");
	
	if (*head == NULL) {
		printf("LISTA VUOTA\n");
		return;
	
	} else if (punt == NULL) {
		free(save);
		*head = NULL;
	
	} else {
		minimo = punt -> valore;
		
		//trovo il minimo
		while (punt != NULL) {
			
			if (minimo > punt -> valore) {
				minimo = punt -> valore;
				save = punt;
			}
			
			punt = punt -> prossimo;	
		}
	
		//scorro precedente
		while (precedente -> prossimo != save && precedente != save) {
			precedente = precedente -> prossimo;
		}
		
		//controllo in che posizione si trova l'elemento da elimianare
		if (save == *head) {
			*head = save -> prossimo;
			free(save);
		
		} else if (save -> prossimo == NULL) {
			precedente -> prossimo = NULL;
			free(save);
		
		} else {
			precedente -> prossimo = save -> prossimo;
			free(save);
		}
	}
}
