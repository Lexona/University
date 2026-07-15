#include <stdio.h>
#include "functions.h"

int main () {
  struct Personaggio *head = NULL;
  srand(time(NULL)); //inizializzo il generatore di numeri casuali

    //richiamo la funzione di lettura dati dal file
  if (load (&head, "personaggi.txt") == 1)
    printf("Qualcosa e' andato storto con l'apertura del file\n");

  //stampo l'elenco dei personaggi contenuti nel file
  printf("-------------ELENCO PERSONAGGI------------\n");
  print(head);

  //genero in maniera casuale due sfidanti
  struct Personaggio p1, p2;
  rand_players(head, &p1, &p2);

  //faccio iniziare la sfida
  printf("Il primo sfidante e': %s\n", p1.nome);
  printf("Il secondo sfidante e': %s\n", p2.nome);

  printf("Bene! Che la sfida abbia inizio!\n");
  sfida(&p1, &p2);

  //faccio la stampa del vincitore
  if (p1.hp > 0) {
    printf("%s ha vinto!!\n", p1.nome);
    remove_node(&head, p2.nome);
  } else {
    printf("%s ha vinto!!\n", p2.nome);
    remove_node(&head, p1.nome);
  }

  printf("Scrivo i dati nel file...");
  write (head, "elenco_aggiornato.txt");

  //al termine del programma, dealloco la lista
  deallocate(head);


  return 0;
}