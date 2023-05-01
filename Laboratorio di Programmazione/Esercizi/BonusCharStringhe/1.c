//calcolare la lunghezza di una stringa senza utilizzare la funzione string length (strlen)

#include <stdio.h>
#include <string.h>
#define MAX 20

int main () {
	
	char stringa[MAX];
	int cont = 0, i = 0;
	
	printf("Scrivi una parola: ");
	scanf("%s", stringa);
	
	while (stringa[i] != '\0') {
		cont++;
		i++;
	}
	
	printf("Lunghezza: %d\n", cont);
	
	return 0;
}
