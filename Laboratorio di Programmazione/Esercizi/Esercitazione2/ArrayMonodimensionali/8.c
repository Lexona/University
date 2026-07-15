//dato un vettore, verificare se è ordinato in modo crescente.

#include <stdio.h>
#include <string.h>

int main () {
	int A[] = {1,3,5,-2,4,0,6};
	char res[3];

	for (int i = 0; i < 7; i++) {
		if (A[i] > A[i+1]) {
			strcpy(res, "No");
			break;
		} else {
			strcpy(res, "Si");
		}
	}

	printf("%s\n", res);

	return 0;
}
