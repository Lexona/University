#include <stdio.h>
#include "functions.h"

int main () {
  //alloco in memoria la struttura dell'array
  struct Elenco l;
  //inizializzo il generatore di numeri casuali
  srand(time(NULL));

  //richiamo la funzione di lettura dei dati dal file
  load (&l, "personaggi.txt");

  //stampo l'array
  printf("-----------ELENCO GIOCATORI------------\n");
  print(l);

  //genero due nomi casuali
  struct Personaggio p1, p2;
  random_player (l, &p1, &p2);

  //faccio iniziare la sfida
  printf("Il primo sfidante e': %s\n", p1.nome);
  printf("Il secondo sfidante e': %s\n", p2.nome);

  printf("Bene! Che la sfida abbia inizio!\n");
  sfida(&p1, &p2);

  if (p1.hp > 0) {
    printf("%s ha vinto!\n", p1.nome);
    l = remove_player(l, p2.nome);
  } else {
    printf("%s ha vinto!\n", p2.nome);
    l = remove_player(l, p1.nome);
  }

  //faccio la funzione di scrittura sul nuovo file
  printf("Scrivo nel file...\n");
  write (l, "elenco_aggiornato.txt");

  //alla fine del programma dealloco l'array
  free(l.vettore);

  return 0;
}