//contare quanti vocali e consonanti sono presenti in una stringa

#include <stdio.h>
#include <string.h>
#define MAX 20

int main () {

	char string[MAX];
	int i = 0, vocali = 0, consonanti = 0;

	printf("Inserisci una parola: ");
	scanf("%s", string);

	while (string[i]) {
		if (string[i] == 'a' || string[i] == 'e' || string [i] == 'i' || string[i] == 'o' || string[i] == 'u') {
			vocali++;
		} else {
			consonanti++;
		}

		i++;
	}

	printf("Ci sono %d vocali e %d consonanti\n", vocali, consonanti);

	return 0;
}
