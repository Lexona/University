//dire in che posizione si trova il primo carattere maiuscolo all'iterno di una stringa

#include <stdio.h>
#include <string.h>
#define MAX 20

int main () {

	char stringa[MAX];
	int i = 0, pos = 0;
	
	printf("Scrivi una parola: ");
	scanf("%s", stringa);
	
	while (stringa[i] != '\0') {
		if ((stringa[i] >= 65 && stringa[i] <= 90) && pos == 0) {
			pos = i+1;
		}
		
		i++;
	}
	
	if (pos != 0) {
		printf("La prima lettera maiuscola sta nella posizione: %d\n", pos);
	} else {
		printf("Non ci sono lettere maiuscole\n");
	}
	

	return 0;
}
