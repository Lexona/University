//verificare se una stringa è palindroma

#include <stdio.h>
#include <string.h>
#define MAX 20

int main () {

	char stringa[MAX];
	int i = 0, check = 1;
	
	printf("Scrivi una parola: ");
	scanf("%s", stringa);
	
	int dim = strlen(stringa);
	
	while (stringa[i] != '\0') {
		if (stringa[i] != stringa[dim - 1]) {
			check = 0;
		}
		
		dim--;
		i++;
	}
	
	printf("Palindroma (1 si, 0 no): %d\n", check);

	return 0;
}
