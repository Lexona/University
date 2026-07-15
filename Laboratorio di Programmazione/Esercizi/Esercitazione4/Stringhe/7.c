//dire in che posizione si trova il primo carattere maiuscolo

#include <stdio.h>
#include <string.h>
#define MAX 20

int main () {
	char string[MAX];
	int i = 0, posizione = 0;

	printf("Scrivi una parola: ");
	scanf("%s", string);

	while (string[i]) {
		if (string[i] >= 65 && string[i] <= 90)
			posizione = i;

		i++;
	}

	if (posizione == 0) {
		printf("Non ci sono lettere maiuscole");
	} else {
		printf("La lettera maiuscola sta nella posizione %d\n", posizione);
	}

	return 0;
}
