//Dato un numero intero ≥ 0, fornire una funzione ricorsiva che ne restituisca la sua codifica binaria

#include <stdio.h>

int return_binary(int num) {
	//caso base
	if (num == 1 || num == 0)
		return num;

	//altri casi
	return 10*return_binary(num/2) + num%2;
}

int main () {
	//dichiarazione delle variabili
	int numero, codice;

	//inserimento del numero
	printf("Inserisci un numero: ");
	scanf("%d", &numero);

	//richiamo della funzione
	codice = return_binary(numero);

	printf("%d", codice);

	return 0;
}
