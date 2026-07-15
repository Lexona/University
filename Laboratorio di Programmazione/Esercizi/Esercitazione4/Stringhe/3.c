//implementare funzione string compare senza utilizzare quella già presente (strcmp)

#include <stdio.h>
#include <string.h>
#define MAX 20

int string_compare(char s1[], char s2[]);

int main () {
	char string1[MAX], string2[MAX];

	printf("Scrivi la prima parola: ");
	scanf("%s", string1);
	printf("Scrivi la seconda parola: ");
	scanf("%s", string2);

	int risultato = string_compare(string1, string2);

	printf("Comparazione stringhe: %d", risultato);

	return 0;
}

int string_compare(char s1[], char s2[]){
	int i = 0, j = 0;

	while (s1[i] != '\0') {
		i++;
	}

	while (s2[j] != '\0') {
		j++;
	}

	if (i < j) {
		return -1 ;
	} else if (i == j) {
		return 0;
	} else {
		return 1;
	}
}
