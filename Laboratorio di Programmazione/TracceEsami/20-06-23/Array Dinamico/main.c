#include <stdio.h>
#include "functions.h"

int main () {
  //alloco in memoria la struttura dell'array
  struct Elenco l;

  //richiamo la funzione di lettura dei dati dal file
  load (&l, "personaggi.txt");

  //stampo l'array
  printf("-----------ELENCO GIOCATORI------------\n");
  print(l);

  //faccio insrire all'utente il nome di due sfidanti
  struct Personaggio p1, p2;

  printf("Inserisci il nome del primo sfidante: ");
  scanf("%s", p1.nome);
  printf("Inserisci il nome del secondo sfidante: ");
  scanf("%s", p2.nome);

  //cerco i due personaggi nell'array e salvo i dati
  trova_personaggio(l, &p1, &p2);

  //faccio iniziare la sfida
  printf("Bene! Che la sfida abbia inizio!\n");
  sfida(&p1, &p2);

  if (p1.hp > 0) {
    printf("%s ha vinto!\n", p1.nome);
    remove_player(l, p2.nome);
  } else {
    printf("%s ha vinto!\n", p2.nome);
    remove_player(l, p1.nome);
  }

  //faccio la funzione di scrittura sul nuovo file
  printf("Scrivo nel file...\n");
  write (l, "elenco_aggiornato.txt");

  //alla fine del programma dealloco l'array
  free(l.vettore);

  return 0;
}