//contare quanti caratteri maiuscoli sono presenti in una stringa

#include <stdio.h>
#include <string.h>
#define MAX 20

int main () {
	char stringa[MAX];
	int i = 0, cont = 0;
	
	printf("Scrivi una parola: ");
	scanf("%s", stringa);

	while (stringa[i] != '\0') {
		if (stringa[i] >= 65 && stringa[i] <= 90) {
			cont++;
		}
		
		i++;
	}
	
	printf("Caratteri maiuscoli: %d\n", cont);
	
	return 0;
}
