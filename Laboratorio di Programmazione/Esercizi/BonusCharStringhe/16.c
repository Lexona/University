//Verificare se una stringa venga alfabeticamente prima di un'altra (NB: attenzione minuscole/maiuscole)

#include <stdio.h>
#include <string.h>
#define MAX 20

int main () {

	char parola1[MAX], parola2[MAX];
	int i = 0, check = 0;
	
	printf("Scrivi una parola: ");
	scanf("%s", parola1);
	
	printf("Scrivi un'altra parola: ");
	scanf(" %s", parola2);
	
	while (parola1[i] != '\0' && check == 0) {
		if (parola1[i] > parola2[i]) {
			check++;
		}
		
		i++;
	}
	
	if (check == 0) {
		printf("Viene prima\n");
	} else {
		printf("Non viene prima\n");
	}

	return 0;
}
