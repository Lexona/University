//trasformazione stringa minuscola in maiuscola

#include <stdio.h>
#include <string.h>
#define MAX 20

int main () {

	char stringa[MAX];
	int i = 0;
	
	printf("Scrivi una parola: ");
	scanf("%s", stringa);
	
	while (stringa[i] != '\0') {
		stringa[i] = stringa[i] - 32;
		
		i++;
	}
	
	printf("Parola in maiuscolo: %s\n", stringa);
	
	//si dovrebbero aggiungere dei controlli ma mi soccio

	return 0;
}
