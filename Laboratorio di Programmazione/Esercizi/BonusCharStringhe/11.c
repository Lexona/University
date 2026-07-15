//data una stringa S ed un vettore di interi V, inserire in V il numero di occorrenze di ogni carattere di S esempio: S= [ p i p p o \0 ] allora V= [ 3 1 3 3 1 ]

#include <stdio.h>
#include <string.h>
#define MAX 20

int main () {

	char stringa[MAX];
	int v[MAX], cont;
	
	printf("Scrivi una parola: ");
	scanf("%s", stringa);
	
	int dim = strlen(stringa);
	
	for (int i = 0; i < dim; i++) {
		cont = 0;
		for (int j = 0; j < dim; j++) {
			if (stringa[i] == stringa[j]) {
				cont++;
			}
		}
		
		v[i] = cont;
		printf("%d ", v[i]);
	}

	return 0;
}
