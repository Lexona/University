//Data una stringa s ed un'altra stringa q, verificare se q è una sottostringa di s

#include <stdio.h>
#include <string.h>
#define MAX 20

int main () {

	char q[MAX], s[MAX];
	
	printf("Scrivi una parola: ");
	scanf("%s", s);
	
	printf("Scrivi un'altra parola: ");
	scanf(" %s", q);
	
	if (strstr(s, q)) {
		printf("Sottostringa\n");
	} else {
		printf("No sottostringa\n");
	}
	
	return 0;
}
