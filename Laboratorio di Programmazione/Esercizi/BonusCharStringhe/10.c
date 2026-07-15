//data una stringa S e due variabili carattere C1 e C2, sostituire nella stringa S tutte le occorrenze di C1 con C2

#include <stdio.h>
#include <string.h>
#define MAX 20

int main () {

	char stringa[MAX], c1, c2;
	int i = 0;
	
	printf("Scrivi una parola: ");
	scanf("%s", stringa);
	
	printf("Scrivi una lettera all'interno della parola: ");
	scanf(" %c", &c1);
	
	printf("Scrivi un'altra lettera da sostituire a quella di prima: ");
	scanf(" %c", &c2);
	
	while (stringa[i] != '\0') {
		if (stringa[i] == c1) {
			stringa[i] = c2;
		}
		
		i++;
	}
	
	printf("Parola modificata: %s\n", stringa);

	return 0;
}
