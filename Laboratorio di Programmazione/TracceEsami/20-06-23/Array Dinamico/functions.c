#include "functions.h"

//funzione di assegnazione dei valori nella struttura dell'array
void init_array (struct Elenco *l) {
  l -> vettore = NULL;
  l -> dimensione = 0;
}

//funzione di inserimento dati nel vettore
void insert (struct Elenco *l, struct Personaggio *p) {
  l -> dimensione++;
  l -> vettore = realloc(l -> vettore, l -> dimensione*sizeof(struct Personaggio));
  l -> vettore[l->dimensione - 1] = *p;
}

//funzione di lettura dati dal file
void load (struct Elenco *l, char nomeFile[]) {
  //apro il file in modalità lettura
  FILE *file = fopen(nomeFile, "r");
  //controllo che il file sia stato aperto correttamente
  if (file == NULL) {
    printf("Qualcosa e' andato storto con l'apertura del file\n");
    return;
  }

  //nel caso in cui è andato tutto bene, assegno i valori alla struttura dati dell'array
  init_array(l);

  //alloco memoria per la struttura dati del personaggio
  struct Personaggio p;

  //leggo i dati dal file
  while (fscanf(file, "%s%d%d%d", p.nome, &p.hp, &p.dp, &p.ap) == 4) {
    insert(l, &p);
  }

  //chiudo il file
  fclose(file);
}

//funzione di stampa dell'array
void print (struct Elenco l) {
  for (int i = 0; i < l.dimensione; i++) {
    printf("---------------\n");
    printf("Nome: %s\n", l.vettore[i].nome);
    printf("Hp: %d\n", l.vettore[i].hp);
    printf("Dp: %d\n", l.vettore[i].dp);
    printf("Ap: %d\n", l.vettore[i].ap);
  }
}

//funzione di ricerca di un giocatore
void trova_personaggio (struct Elenco l, struct Personaggio *p1, struct Personaggio *p2) {
  for (int i = 0; i < l.dimensione; i++) {
    if (strcmp(l.vettore[i].nome, p1->nome) == 0) {
      p1 -> hp = l.vettore[i].hp;
      p1 -> dp = l.vettore[i].dp;
      p1 -> ap = l.vettore[i].ap;
    }

    if (strcmp(l.vettore[i].nome, p2->nome) == 0) {
      p2 -> hp = l.vettore[i].hp;
      p2 -> dp = l.vettore[i].dp;
      p2 -> ap = l.vettore[i].ap;
    }
  }
}

//funzione per far colpire i due personaggi
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

//funzione di inizio della sfida
void sfida (struct Personaggio *p1, struct Personaggio *p2) {
  colpisci(p1, p2);
}

//funzione di swap a sinistra
void spostamento_a_sinistra (struct Elenco *l, int index) {
  //controllo se l'indice è valido
  if (index < 0 || index >= l->dimensione) {
    printf("Indice non valido\n");
    return;
  }

  //sposto gli elementi successivi di un indice verso sinistra
  for (int i = index; i < l -> dimensione; i++)
    l -> vettore[i] = l -> vettore[i + 1];

  //riduco la dimensione del vettore
  l->dimensione--;

  //dealloco dalla memoria l'elemento eliminato
  l -> vettore = realloc(l -> vettore, l -> dimensione*sizeof(struct Personaggio));
}

//funzione di rimozione di un giocatore dall'array
int remove_player (struct Elenco l, char nomePersonaggio[]) {
  int index = -1; //indice dell'elemento da eliminare

  //scorro l'array per trovare l'elemetno da eliminare
  for (int i = 0; i < l.dimensione; i++) {
    if (strcmp(l.vettore[i].nome, nomePersonaggio) == 0)
      index = i;
  }

  //controllo se l'elemento è stato trovato
  if (index == -1) {
    return 1;
  }

  //a questo punto faccio lo swap a sinistra
  spostamento_a_sinistra(&l, index);
  return 0;
}

//funzione di scrittura nel nuovo file
void write (struct Elenco l, char nomeFile[]) {
  //apro il file in modalità scrittura
  FILE *file = fopen (nomeFile, "w");
  //controllo che il file sia stato aperto correttamente
  if (file == NULL) {
    printf("Qualcosa e' andato storto con l'apertura del file\n");
    return;
  }

  //scorro l'array e scrivo nel file
  for (int i = 0; i < l.dimensione; i++) {
    fprintf(file, "%s\n", l.vettore[i].nome);
    fprintf(file, "%d\n", l.vettore[i].hp);
    fprintf(file, "%d\n", l.vettore[i].dp);
    fprintf(file, "%d\n", l.vettore[i].ap);
  }

  //chiudo il file
  fclose(file);
}


