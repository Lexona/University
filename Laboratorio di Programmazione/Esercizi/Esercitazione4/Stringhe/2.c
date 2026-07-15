//effettuare la copia di una stringa in un'altra senza utilizzare funzione string copy (strcpy)

#include <stdio.h>
#include <string.h>
#define MAX 30

int main () {
	char string[MAX], copia[MAX];
	int i = 0;

	printf("Scrivi una parola: ");
	scanf("%s", string);

	while (string[i] != '\0') {
		copia[i] = string[i];
		i++;
	}

	printf("Copia della parola: %s\n", copia);

	return 0;
}
