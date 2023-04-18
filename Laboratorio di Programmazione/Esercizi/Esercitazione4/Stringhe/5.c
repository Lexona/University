//trasformazione stringa minuscola in maiuscola

#include <stdio.h>
#include <string.h>
#define MAX 20

//32

int main () {
	char string[MAX];
	int i = 0;

	printf("Inserisci una parola: ");
	scanf("%s", string);

	while (string[i] != '\0') {
		string[i] = string[i] - 32;
		i++;
	}

	printf("%s\n", string);

	return 0;
}
