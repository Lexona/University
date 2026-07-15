//data una stringa s, fornire una soluzione ricorsiva per la verifica che s sia palindroma

#include <stdio.h>
#include <string.h>
#define MAX 20

int check_palindroma (char start[], char end[]) {
	//caso base in cui c'è un solo elemento o uno ha superato l'altro
	if (start >= end) {
		return 0;
	}

	if (*start != *end) {
		return 1;
	}

	check_palindroma(start+1, end-1);
}

int main () {
	//dichiarazione delle variabili
	char str[MAX];
	int dimensione, palindroma;

	//inserimento della stringa
	printf("Scrivi una parola: ");
	do {
		scanf("%s", str);
	} while (strlen(str) > MAX);

	dimensione = strlen(str);

	palindroma = check_palindroma(str, str+dimensione-1);

	if (palindroma == 0)
		printf("Palidroma\n");
	else
		printf("No palindroma\n");

	return 0;
}
