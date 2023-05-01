//implementare una funzione string_compare senza utilizzare quella già presente (strcmp)

#include <stdio.h>
#include <string.h>
#define MAX 20

void string_compare (char s1[], char s2[]);

int main () {

	char string1[MAX], string2[MAX];

	printf("Scrivi la prima parola: ");
	scanf("%s", string1);
	
	printf("Scrivi la seconda parola: ");
	scanf(" %s", string2);
	
	string_compare(string1, string2);
	
	return 0;
}

void string_compare (char s1[], char s2[]) {

	int dim1, dim2;
	
	dim1 = strlen(s1);
	dim2 = strlen(s2);
	
	if (dim1 == dim2) {
		printf("%d\n", 0);
	} else if (dim1 < dim2) {
		printf("%d\n", -1);
	} else {
		printf("%d\n", 1);
	}

}
