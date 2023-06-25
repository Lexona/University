#include "functions.h"

//funzione di inserimento dati nella lista (inserimento in coda semplice)
void insert (struct Personaggio **start, struct Personaggio *p) {
  //creo il nuovo nodo
  struct Personaggio *nuovo = malloc(sizeof(struct Personaggio));
  nuovo -> prossimo = NULL;
  strcpy(nuovo->nome, p->nome);
  nuovo -> hp = p -> hp;
  nuovo -> dp = p -> dp;
  nuovo -> ap = p -> ap;

  //controllo se si tratta del primo inserimento
  if (*start == NULL) {
    *start = nuovo;
    return;
  }

  //in caso contrario, scorro la lista
  struct Personaggio *punt = *start;
  while (punt -> prossimo != NULL)
    punt = punt -> prossimo;

  punt -> prossimo = nuovo;
}

//funzione di lettura dati dal file
int load (struct Personaggio **start, char nomeFile[]) {
  //apro il file in modalità lettura
  FILE *file = fopen(nomeFile, "r");
  //controllo che il file sia stato aperto correttamente
  if (file == NULL)
    return 1;

  //alloco la struttura dati
  struct Personaggio p; //di appoggio per l'inserimento dei dati nella lista

  //leggo i dati dal file e li metto nella struttura
  while (fscanf(file, "%s%d%d%d", p.nome, &p.hp, &p.dp, &p.ap) == 4)
    insert(start, &p);

  //chiudo il file
  fclose(file);

  return 0;
}

//funzione di stampa della lista
void print (struct Personaggio *start) {
  struct Personaggio *punt = start;

  if (punt != NULL) {
    printf("---------------------\n");
    printf("Nome: %s\n", start -> nome);
    printf("Hp: %d\n", start -> hp);
    printf("Dp: %d\n", start -> dp);
    printf("Ap: %d\n", start -> ap);
    printf("---------------------\n");

    print(start -> prossimo);
  }
}

//funzione di eliminazione di un nodo dalla lista
int remove_node (struct Personaggio **start, char nomePersonaggio[]) {
  //scorro la lista fino a quando trovo il nodo da eliminare
  struct Personaggio *punt = *start;
  struct Personaggio *precedente = NULL;
  struct Personaggio *toDel = NULL;

  while (punt != NULL) {
    if (strcmp(punt -> nome, nomePersonaggio) == 0) {
      toDel = punt;

      //controllo in che posizione si trova il nodo da eliminare e gestisco l'eliminazione
      if (precedente == NULL)
        *start = toDel -> prossimo;
      else
        precedente -> prossimo = toDel -> prossimo;
    }

    precedente = punt;
    punt = punt -> prossimo;
  }

  //controllo se è stato trovato il valore da eliminare
  if (toDel == NULL) //significa che non è stato trovato il valore
    return 0;

  return 1;
}

//funzione per far colpire due personaggi
void colpisci (struct Personaggio *p1, struct Personaggio *p2) {
  while (p1 -> hp > 0 && p2 -> hp > 0) {
    if (p1 -> hp > 0) {
      printf("%s colpisce %s\n", p1 -> nome, p2 -> nome);
      p2 -> hp = p2 -> hp - (((int)(p1 -> ap/p2 -> dp)) * p2 -> hp);
    }

    if (p2 -> hp > 0) {
      printf("%s colpisce %s\n", p2 -> nome, p1 -> nome);
      p1 -> hp = p1 -> hp - (((int)(p2 -> ap/p1 -> dp)) * p1 -> hp);
    }
  }
}

//funzione della sfida effettiva
void sfida (struct Personaggio *p1, struct Personaggio *p2) {
  colpisci(p1, p2);
}

//funzione di scrittura dati nel file
void write (struct Personaggio *start, char nomeFile[]) {
  //apro il file in modalità scrittura
  FILE *file = fopen(nomeFile, "w");
  //controllo che il file sia stato aperto correttamente
  if (file == NULL) {
    printf("Qualcosa e' andato storto con l'apertura del file!\n");
    return;
  }

  //in caso contrario, scorro la lista e scrivo i nodi nel file
  struct Personaggio *punt = start;

  while (punt != NULL) {
    fprintf(file, "%s\n", punt -> nome);
    fprintf(file, "%d\n", punt -> hp);
    fprintf(file, "%d\n", punt -> dp);
    fprintf(file, "%d\n", punt -> ap);

    punt = punt -> prossimo;
  }

  //chiud il file
  fclose(file);
}

//funzione di deallocazione della lista
void deallocate (struct Personaggio *start) {
  while (start != NULL) {
    struct Personaggio *temp = start -> prossimo;
    free(start);
    start = temp;
  }

  start = NULL;
}

//funzione per cercare gli sfidanti nella lista
void trova_personaggio (struct Personaggio *start, struct Personaggio *p1, struct Personaggio *p2) {
  struct Personaggio *punt = start;

  //scorro la lista e salvo i parametri
  while (punt != NULL) {
    if (strcmp(punt -> nome, p1 -> nome) == 0) {
      p1 -> hp = punt -> hp;
      p1 -> dp = punt -> dp;
      p1 -> ap = punt -> ap;
    }

    if (strcmp(punt -> nome, p2 -> nome) == 0) {
      p2 -> hp = punt -> hp;
      p2 -> dp = punt -> dp;
      p2 -> ap = punt -> ap;
    }

    punt = punt -> prossimo;
  }
}
