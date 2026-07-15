#include "functions.h"
#include <string.h>

//inserimento della stringa nella pila
void push(char s[], char p[], int dim) {
	for (int i = 0; i < dim; i++) {
		p[i] = s[dim - 1 - i];
	}
}

//controllo se la parola è palindroma
int check (char s[], char p[], int dim) {
	for (int i = 0; i < dim; i++) {
		if (p[i] != s[i])
			return 1;
	}

	return 0;
}

