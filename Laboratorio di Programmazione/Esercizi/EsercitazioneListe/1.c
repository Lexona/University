#include <stdio.h>
#include <stdlib.h>

struct nodo {
	int valore;
	
	struct nodo *prossimo;
};

//FUNZIONE DI INSERIMENTO
int inserimento(struct nodo **start);
//FUNZIONE DI STAMPA
void stampa(struct nodo **start);
//FUNZIONE DI RIMOZIONE
void remove_at(struct nodo **start, int dim, int idx);
//FUNZIONE INSERIMENTO IN UN PUNTO SPECIFICO
void insert_at(struct nodo **start, int dim, int idx, int val);

int main () {
	struct nodo *inizio = NULL;
	int posizioneRimozione, posizioneInserimento, val;

	int dimensione = inserimento(&inizio);
	stampa(&inizio);
	
	printf("Inserisci la posizione dell'elemento che vuoi eliminare: ");
	scanf("%d", &posizioneRimozione);
	
	remove_at(&inizio, dimensione, posizioneRimozione);
	
	stampa(&inizio);
	
	printf("Dove vuoi inserire il nuovo elemento? ");
	scanf("%d", &posizioneInserimento);
	printf("Che valore vuoi inserire? ");
	scanf("%d", &val);
	
	insert_at(&inizio, dimensione, posizioneInserimento, val);
	
	stampa(&inizio);

	return 0;
}

//FUNZIONE DI INSERIMENTO
int inserimento(struct nodo **start){
	int dim = 0;
	char risposta;
	
	//dichiaro i puntatori
	struct nodo *nuovo;
	struct nodo *punt;
	struct nodo *precedente;
	
	do {
		//creo il nuovo nodo
		nuovo = malloc(sizeof(struct nodo));
		nuovo -> prossimo = NULL;
		
		//faccio inserire il numero all'utente
		printf("Inserisci un numero: ");
		scanf("%d", &nuovo -> valore);
		
		//scorro tutta la lista
		punt = *start;
		precedente = NULL;
		
		while (punt != NULL) {
			precedente = punt;
			punt = punt -> prossimo;
		}
		
		//controllo se si tratta del primo inserimento
		if (precedente == NULL) {
			*start = nuovo;
		} else {
			precedente -> prossimo = nuovo;
		}
		
		getchar();
		
		//chiedo all'utente se vuole fare un nuovo inserimento
		printf("Vuoi inserire un altro numero? ");
		scanf("%c", &risposta);
		
		if (risposta == 's' || risposta == 'S') {
			dim++;
		}
	
	} while (risposta == 's' || risposta == 'S');
	
	return dim;
}

//FUNZIONE DI STAMPA
void stampa(struct nodo **start) {
	struct nodo *punt = *start;
	
	while (punt	!= NULL) {
		printf("%d \n", punt -> valore);
		punt = punt -> prossimo;
	}
}

//FUNZIONE DI RIMOZIONE
void remove_at(struct nodo **start, int dim, int idx){
	//dichiaro la variabile che mi serve per contatare quanti passi devo fare
	int contatore = 0;
	//dichiaro i puntatori che mi servono per eliminare l'elemento
	struct nodo *punt = *start;
	struct nodo *precedente = NULL;
	struct nodo *todel = *start;

	//controllo se l'elemento ricercato esiste
	if (idx < 0 || idx > dim) {
		printf("L'elemento non esiste\n");
	}
	
	//in caso contrario, controllo quale tipo di eliminazione devo fare (se in testa, in coda o in mezzo)
	else if (idx == 0) { //caso in cui la rimozione avviene in testa
		todel = *start;
		*start = (*start)-> prossimo;
		printf("Indirizzo dell'elemento eliminato: %p\n", todel);
		free(todel);
		dim--;
	
	} else if (idx > 0 && idx < dim) { //caso in cui la rimozione avviene in mezzo
		//scorro la lista fino ad arrivare al punto desiderato
		while (contatore <= idx) { 
			precedente = todel;
			todel = punt;
			punt = punt -> prossimo;
			
			contatore++;
		}
		
		precedente -> prossimo = punt;
		printf("Indirizzo dell'elemento eliminato: %p\n", todel);
		free(todel);
		
		dim--;
		
	} else if (idx == dim) {
		while (punt -> prossimo != NULL) {
			todel = punt;
			punt = punt -> prossimo;
		}
		
		printf("Indirizzo dell'elemento eliminato: %p\n", todel);
		free(todel);
		
		dim--;
	}
}

void insert_at(struct nodo **start, int dim, int idx, int val){

	//dichiaro la variabile che mi serve per contatare quanti passi devo fare
	int contatore = 0;
	
	//dichiaro i puntatori che mi servono
	struct nodo *punt = *start;
	struct nodo *precedente = NULL;

	//creo il nuovo nodo
	struct nodo *nuovo = malloc(sizeof(struct nodo));
	nuovo -> valore = val;
	nuovo -> prossimo = NULL;
	
	//controllo in che posto vuole inserire il valore
	if (idx == 0) { //se vuole fare l'inserimento in testa
		nuovo -> prossimo = *start;
		*start = nuovo;	
	} else if (idx > 0 && idx < dim) { //se vuole fare l'inserimento in mezzo
		while (contatore < idx) {
			precedente = punt;
			punt = punt -> prossimo;
			
			contatore++;
		}
		
		precedente -> prossimo = nuovo;
		nuovo -> prossimo = punt;
	} else if (idx == dim) {
		while (punt -> prossimo != NULL) {
			punt = punt -> prossimo;
		}
		
		punt -> prossimo = nuovo;
	}
}
























