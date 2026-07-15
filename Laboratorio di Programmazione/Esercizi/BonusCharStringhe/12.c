//scrivere un programma che stampi video la domanda cos'è un file .h? e, se l'utente risponde con una stringa contenente la parola libreria, il programma stampa bocciato, altrimenti Ok. Andiamo avanti.

#include <stdio.h>
#include <string.h>
#define MAX 20

int main () {
	char risposta[MAX];

	printf("Cos'e' un file .h?\n");
	scanf("%s", risposta);

	if (strstr(risposta, "libreria")) {
		printf("Bocciato");
	} else {
		printf("Ok. Andiamo avanti.");
	}

	return 0;
}
