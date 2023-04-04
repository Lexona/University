//dato un vettore X , calcolare la somma S di ogni numero elevato alla rispettiva posizione. Esempio: X = [3 5 2 7] allora S=3^1+5^2+2^3+7^4

#include <stdio.h>
#include <math.h>

int main () {
	int X[] = {3,5,2,7};
	int somma = 0;

	for (int i = 0; i < 4; i++){
		somma += (int)pow(X[i], i+1);
	}

	//stampa del risultato
	printf("Somma: %d\n", somma);

	return 0;
}
