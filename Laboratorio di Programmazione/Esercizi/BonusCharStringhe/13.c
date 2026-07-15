//Data una matrice contenente, in ogni riga, una stringa, copiare in un vettore la prima lettera presente in ogni riga dopo averla convertita in maiuscolo

#include <stdio.h>
#include <string.h>
#define MAX 20

int main () {

	char mat[MAX][MAX], vet[MAX];
	int n;
	
	printf("Quante parole vuoi scrivere? ");
	do {
		scanf("%d", &n);
		
		if (n < 0 || n > MAX)
			printf("Inserimento non valido, riprovare: ");
	} while (n < 0 || n > MAX);
	
	for (int i = 0; i < n; i++) {
		printf("Scrivi la parola %d: ", i+1);
		scanf("%s", mat[i]);
		
		vet[i] = mat[i][0] - 32;
	}
	
	//stampa vettore
	for (int i = 0; i < n; i++) {
		printf("%c ", vet[i]);
	}

	return 0;
}
