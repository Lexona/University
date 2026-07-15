//dato due vettori di numeri A e B, inserire in una variabile T il valore:
//1, se i due vettori sono uguali (es. A= [1 4 5] e B= [1 4 5])
//2, se sono uno il "reverse" dell'altro (es. A= [1 4 5] e B= [5 4 1])
//3, tutti gli altri casi.

#include <stdio.h>

int main () {
	int A[] = {1,2,5,3};
	int B[] = {4,8,6,7};
	int t = 3, j = 0, n = 3;

	//controllo che i vettori sono uguali
	for (int i = 0; i < 4; i++){
		if (A[i] == B[j]) {
			t = 1;
			j++;
		} else {
			break;
		}
	}

	//controllo che i vettori sono uno il reverse dell'altro
	if (t == 3) {
		for (int i = 0; i < 2; i++) {
			if (A[i] == B[n]) {
				t = 2;
				n--;
			}
		}
	}

	//stampa del risultato
	printf("%d\n", t);

	return 0;
}
