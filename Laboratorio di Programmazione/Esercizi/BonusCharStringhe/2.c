//effettuare la copia di una stringa in un'altra senza utilizzare funzione string copy (strcpy)

#include <stdio.h>
#include <string.h>
#define MAX 20

int main () {
	char stringa[MAX], copia[MAX];
	int i = 0;
	
	printf("Scrivi una parola: ");
	scanf("%s", stringa);
	
	while (stringa[i] != '\0') {
		copia[i] = stringa[i];
		i++;
	}
	
	copia[i] = '\0';
	
	printf("La stringa copiata: %s\n", copia);

	return 0;
}
