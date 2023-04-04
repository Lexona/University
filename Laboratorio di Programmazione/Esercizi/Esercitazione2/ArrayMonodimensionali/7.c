//dati due vettori di uguale lunghezza, effettuarne la somma elemento per elemento e memorizzazione in un terzo vettore.
//Esempio: dati A = 1,2,5,3,0 B = 2,4,1,2 allora RIS = 3,6,6,5

#include <stdio.h>

int main () {
	int A[] = {1,2,5,3,0};
	int B[] = {2,4,1,2};
	int RIS[4];

	for (int i = 0; i < 4; i++) {
		RIS[i] = A[i] + B[i];

		printf("%d\t", RIS[i]);
	}

	return 0;
}
