#include <stdio.h>
#include <stdlib.h>

struct nodo {
	int valore;
	
	struct nodo *prossimo;
};

//FUNZIONE DI INSERIMENTO
void insert_sorted(struct nodo **start, int val);
//FUNZIONE DI STAMPA
void stampa(struct nodo **start);

int main () {

	//dichiarazione variabili
	struct nodo *inizio = NULL;
	char risposta;
	int dimensione = 0, numero;
	
	//faccio inserire il numero all'utente
	do {
		printf("Inserisci un numero: ");
		scanf("%d", &numero);
		
		insert_sorted(&inizio, numero);
		
		getchar();
		
		printf("Vuoi inserire un altro numero? ");
		scanf("%c", &risposta);
		
		if (risposta == 's' || risposta == 'S')
			dimensione++;	
	
	} while (risposta == 's' || risposta == 'S');
	
	stampa(&inizio);

	return 0;
}

//FUNZIONE DI INSERIMENTO
void insert_sorted(struct nodo **start, int val){

	//dichiaro i puntatori
	struct nodo *nuovo = malloc(sizeof(struct nodo));
	struct nodo *punt = *start;
	
	//inserisco i valori nella struttura
	nuovo -> valore = val;
	nuovo -> prossimo = NULL;
	
	//controllo se si tratta del primo inserimento
	if (*start == NULL || val < (*start) -> valore) {
		nuovo -> prossimo = *start;
		*start = nuovo;
	} else {
		//scorro la lista
		while (punt -> prossimo != NULL && punt -> prossimo -> valore < val) {
				punt = punt -> prossimo;
		}

		nuovo -> prossimo = punt -> prossimo;
		punt -> prossimo = nuovo;
	}

}

//FUNZIONE DI STAMPA
void stampa(struct nodo **start){
	struct nodo *punt = *start;
	
	while (punt != NULL) {
		printf("%d ", punt -> valore);
		punt = punt -> prossimo;
	}
}
























