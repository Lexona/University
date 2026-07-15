//contare quanti caratteri maiuscoli sono presenti in una stringa

#include <stdio.h>
#include <string.h>
#define MAX 20

int main () {
	char string[MAX];
	int i = 0, cont = 0;

	printf("Inserisci una parola: ");
	scanf("%s", string);

	while (string[i]) {
		if (string[i] >= 65 && string[i] <= 90)
			cont++;

		i++;
	}

	printf("Ci sono %d lettere maiuscole\n", cont);

	return 0;
}
