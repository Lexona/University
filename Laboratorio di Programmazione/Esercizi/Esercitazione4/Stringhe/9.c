//verificare se una stringa è palindroma

#include <stdio.h>
#include <string.h>
#define MAX 20

int main () {
	char string[MAX];
	int i = 0, check = 0;

	printf("Inserisci una parola: ");
	scanf("%s", string);

	int dimensione = strlen(string);

	while (string[i] && check != 1) {
		if (string[i] != string[dimensione-1]) {
			check = 1;
		}

		i++;
		dimensione--;

	}

	if (check == 0){
		printf("Palindroma\n");
	} else {
		printf("Non palindroma\n");
	}

	return 0;
}
