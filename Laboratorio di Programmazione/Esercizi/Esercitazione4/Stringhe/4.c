//verificare se una stringa è composta da soli caratteri maiuscoli

#include <stdio.h>
#include <string.h>
#define MAX 20

int main () {
	char string[MAX];
	int i = 0, check = 0;

	printf("Inserisci una parola: ");
	scanf("%s", string);

	while (string[i] != '\0') {
		if (string[i] < 97 || string[i] > 122)
			check = 1;

		i++;
	}

	printf("Ci sono lettere maiuscole (1 si, 0 no): %d\n", check);

	return 0;
}
