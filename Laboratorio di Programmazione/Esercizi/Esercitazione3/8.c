//implementare una funzione che, data in input una stringa, restituisca due variabili, la prima contenente la prima consonante presente nell stringa,
//la seconda variabile contenente l'ultima vocale.

#include <stdio.h>
#include <string.h>
#define MAX 20

void lettera (char s[], int dim, char *v, char *c);

int main () {

	char stringa[MAX], vocale, consonante;

	//caricamento vettore
	printf("Scrivi una prola: ");
	do {
		scanf("%s", stringa);

		if (strlen(stringa) >= MAX)
			printf("Inserimento non valido, riprovare: ");

	} while (strlen(stringa) >= MAX);

	lettera (stringa, MAX, &vocale, &consonante);

	return 0;
}

void lettera (char s[], int dim, char *v, char *c) {
	int check = 0;

	for (int i = 0; i < dim; i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
			*v = s[i];
		}

		else if ((s[i] != 'a' || s[i] != 'e' || s[i] != 'i' || s[i] != 'o' || s[i] != 'u') && check == 0) {
			*c = s[i];
			check++;
		}

	}

	//stampa risultato
	printf("Vocale: %c\n", *v);
	printf("Consonante: %c\n", *c);

}
