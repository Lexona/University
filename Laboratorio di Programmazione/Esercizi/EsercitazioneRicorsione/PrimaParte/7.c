//Dato un numero intero ≥ 0, fornire una funzione ricorsiva che ne stampi la sua codifica binaria

#include <stdio.h>

void print_binary(int numero) {
	//caso base
	if (numero <= 1) {
		printf("%d ", numero%2);
		return;
	}

	print_binary(numero/2);
	printf("%d ", numero%2);
}

int main () {
	//dichiarazione delle variabili
	int numero;

	//inserimento del numero
	printf("Inserisci un numero: ");
	scanf("%d", &numero);

	print_binary(numero);

	return 0;
}
