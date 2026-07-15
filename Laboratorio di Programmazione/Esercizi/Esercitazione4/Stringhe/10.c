//data una stringa e due variabili carattere C1 e C2, sostituire nella stringa tutte le occorrenze di C1 con C2

#include <stdio.h>
#include <string.h>
#define MAX 20

int main () {
	char string[MAX], c1, c2;
	int i = 0;

	printf("Inserisci una parola: ");
	scanf("%s", string);

	printf("Inserisci una lettera: ");
	scanf(" %c", &c1);
	printf("Inserisci un'altra lettera: ");
	scanf(" %c", &c2);

	while (string[i]) {
		if (string[i] == c1){
			string[i] = c2;
		}
		i++;
	}

	printf("%s", string);

	return 0;
}
