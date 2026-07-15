//Data una matrice contenente, in ogni riga, una stringa, copiare in un vettore la prima lettera presente in ogni riga dopo averla convertita in maiuscolo

#include <stdio.h>
#include <string.h>
#define MAX 20

int main () {

	int n;
	char matrice[MAX][MAX], vettore[MAX];

	printf("Inserisci il numero di parole che vuoi scrivere: ");
	do {
		scanf("%d", &n);

		if (n < 0 || n > MAX)
			printf("Inserimento non valido, riprovare: ");
	} while (n < 0 || n > MAX);

	for (int i = 0; i < n; i++) {
		printf("Inserisci la %d parola: ", i+1);
		scanf("%s", matrice[i]);

		vettore[i] = matrice[i][0];
		vettore[i] = vettore[i] - 32;
	}

	//stampa
	for (int i = 0; i < n; i++) {
		printf("%c ", vettore[i]);
	}

	return 0;
}
