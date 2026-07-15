//calcolare la lunghezza di una stringa senza utilizzare la funzione string length (strlen)

#include <stdio.h>
#include <string.h>
#define MAX 30

int main () {

	int cont = 0, i = 0;
	char stringa[MAX];

	printf("Scrivi una parola: ");
	scanf("%s", stringa);

	//conteggio
	while (stringa[i] != '\0') {
		i++;
	}

	printf("Lunghezza stringa: %d\n", i);

	return 0;
}
