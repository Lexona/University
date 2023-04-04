//dato un vettore, stamparne un diagramma a barre fatto di * . esempio: vettore: [ 3 6 4] la stampa sarà:
// ***
// ******
// ****

#include <stdio.h>

int main () {

	int A[] = {3,6,4};
	char star = '*';

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j <= A[i]; j++) {
			printf("%c", star);
		}

		printf("\n");
	}

	return 0;
}
