//contare quanti vocali e consonanti sono presenti in una stringa

#include <stdio.h>
#include <string.h>
#define MAX 20

int main () {

	char stringa[MAX];
	int i = 0, vocali = 0, consonanti = 0;
	
	printf("Scrivi una parola: ");
	scanf("%s", stringa);
	
	while (stringa[i] != '\0') {
		if (stringa[i] == 'a' || stringa[i] == 'A' || stringa[i] == 'e' || stringa[i] == 'E' || stringa[i] == 'i' || stringa[i] == 'I' || stringa[i] == 'o' || stringa[i] == 'O' || stringa[i] == 'u' || stringa[i] == 'U') {
			vocali++;
		} else {
			consonanti++;
		}
		i++;
	}
	
	printf("Ci sono %d vocali e %d consonanti\n", vocali, consonanti);

	return 0;
}
