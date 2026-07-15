//Data una stringa s ed un'altra stringa q, verificare se q è una sottostringa di s

#include <stdio.h>
#include <string.h>
#define MAX 20

int main () {

	char s[MAX], q[MAX];

	printf("Scrivi la prima parola: ");
	scanf("%s", s);

	printf("Inserisci la seconda parola: ");
	scanf(" %s", q);

	if (strstr(s, q)) {
		printf("q = sottostringa");
	} else {
		printf("q = NO sottostringa");
	}

	return 0;
}
