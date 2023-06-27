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

//funzione di stampa di un singolo elemento
void print_elem (struct Personaggio vet[], int dim) {
  //caso base
  if (dim == 0)
    return;

  //negli altri casi
  printf("------------------\n");
  printf("Nome: %s\n", vet[0].nome);
  printf("Hp: %d\n", vet[0].hp);
  printf("Dp: %d\n", vet[0].dp);
  printf("Ap: %d\n", vet[0].ap);

  print_elem(vet+1, dim-1);
}

//funzione di stampa dell'array (ricorsiva)
void print (struct Elenco l) {
  print_elem(l.vettore, l.dimensione);
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
void shift_left (struct Elenco *l, int index) {
  //controllo se l'indice è valido
  if (index < 0 || index >= l->dimensione) {
    printf("Indice non valido\n");
    return;
  }

  //sposto gli elementi successivi di un indice verso sinistra
  for (int i = index; i < l -> dimensione - 1; i++)
    l -> vettore[i] = l -> vettore[i + 1];

  //riduco la dimensione del vettore
  l->dimensione--;

  //dealloco dalla memoria l'elemento eliminato
  l -> vettore = realloc(l -> vettore, l -> dimensione*sizeof(struct Personaggio));
}

//funzione di rimozione di un giocatore dall'array
struct Elenco remove_player (struct Elenco l, char nomePersonaggio[]) {
  int index = -1; //indice dell'elemento da eliminare

  //scorro l'array per trovare l'elemetno da eliminare
  for (int i = 0; i < l.dimensione; i++) {
    if (strcmp(l.vettore[i].nome, nomePersonaggio) == 0)
      index = i;
  }

  //a questo punto faccio lo swap a sinistra
  shift_left(&l, index);
  return l;
}

//funzione di scrittura nel nuovo file (Facoltativo A)
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

//funzione di generazione casuale di due personaggi
void random_player (struct Elenco l, struct Personaggio *p1, struct Personaggio *p2) {
  //genero due indici e controllo che siano distinti
  int index1 = rand() % l.dimensione, index2;
  do {
    index2 = rand() % l.dimensione;
  } while (index1 == index2);

  //cerco i personaggi agli indici specificati
  int current_index = 0;

  for (int i = 0; i < l.dimensione; i++) {
    if (current_index == index1) {
      strcpy(p1->nome, l.vettore[i].nome);
      p1 -> hp = l.vettore[i].hp;
      p1 -> dp = l.vettore[i].dp;
      p1 -> ap = l.vettore[i].ap;
    }

    if (current_index == index2) {
      strcpy(p2->nome, l.vettore[i].nome);
      p2 -> hp = l.vettore[i].hp;
      p2 -> dp = l.vettore[i].dp;
      p2 -> ap = l.vettore[i].ap;
    }

    current_index++;
  }
}

