#include <stdio.h>
#include "functions.h"
#define MAX_NUM 30

int main () {
	struct Pila p;
	int numero;
	printf("Inserisci un numero decimale: ");
	do {
		scanf("%d", &numero);
	} while (numero < 0 || numero > MAX_NUM);

	init_stack(&p);
	push(&p, numero);
	pop(&p);

	return 0;
}
