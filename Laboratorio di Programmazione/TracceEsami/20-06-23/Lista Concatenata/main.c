#include <stdio.h>
#include "functions.h"

int main () {
  struct Personaggio *head = NULL;

  //richiamo la funzione di lettura dati dal file
  if (load (&head, "personaggi.txt") == 1)
    printf("Qualcosa e' andato storto con l'apertura del file\n");

  //stampo l'elenco dei personaggi contenuti nel file
  printf("-------------ELENCO PERSONAGGI------------\n");
  print(head);

  //dichiaro le due strutture in cui mettere i nomi dei personaggi da far sfidare
  struct Personaggio p1, p2;

  //faccio inserire i nomi all'utente
  printf("Inserisci il nome del primo sfidante: ");
  scanf("%s", p1.nome);
  printf("Inserisci il nome del secondo sfidante: ");
  scanf("%s", p2.nome);

  //cerco i personaggi nella lista
  trova_personaggio(head, &p1, &p2);

  //faccio iniziare la sfida
  printf("Bene! Che la sfida abbia inizio!\n");
  sfida (&p1, &p2);

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