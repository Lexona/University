//verificare se una stringa è composta da soli caratteri maiuscoli

#include <stdio.h>
#include <string.h>
#define MAX 20

int main () {

	int check = 0, i = 0;
	char stringa[MAX];

	printf("Scrivi una parola: ");
	scanf("%s", stringa);
	
	while (stringa[i] != '\0') {
		if (stringa[i] >= 97 && stringa[i] <= 122) {
			check++;
		}
		
		i++;
	}
	
	if (check == 0){
		printf("Ci sono solo caratteri maiuscoli\n");
	} else {
		printf("Ci sono anche caratteri minuscoli\n");
	}

	return 0;
}
