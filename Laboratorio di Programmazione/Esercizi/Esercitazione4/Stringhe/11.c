//data una stringa S ed un vettore di interi V, inserire in V il numero di occorrenze di ogni carattere di S esempio: S= [ p i p p o \0 ]
//allora V= [ 3 1 3 3 1 ]

#include <stdio.h>
#include <string.h>
#define MAX 20

int main () {

	int vet[MAX], i = 0, cont = 0;
	char string[MAX];

	printf("Inserisci una parola: ");
	scanf("%s", string);

	int dimensione = strlen(string);

	for (int i = 0; i < dimensione; i++) {
		cont = 0;
		for (int j = 0; j < dimensione; j++) {
			if (string[i] == string[j]){
				cont ++;
			}
		}

		vet[i] = cont;
		printf("%d ", vet[i]);
	}

	return 0;
}
