//Data una stringa s, verificare se la stringa è palindroma. Gli elementi di s potranno essere letti/scritti solo ed esclusivamente dal primo all'ultimo. Non possono essere utilizzate strutture di supporto diverse da Pile e/o Code.

#include <stdio.h>
#include <string.h>
#define MAX 20

//FUNZIONE DI INSERIMENTO NELLA PILA
void insert (char s[], char p[]);
//FUNZIONE DI CONTROLLO
void check_palindrome(char s[], char p[]);

int main () {

	char stringa[MAX], pila[MAX];
	
	do {
		printf("Scrivi una parola: ");
		scanf("%s", stringa);
		
		if (strlen(stringa) > MAX)
			printf("Valore non valido, riprovare.\n");
	
	} while (strlen(stringa) > MAX);
	
	insert(stringa, pila);
	check_palindrome(stringa, pila);
	
	return 0;
}

//FUNZIONE DI INSERIMENTO
void insert (char s[], char p[]) {
	 p[strlen(s)] = '\0';
	 
	 for (int i = 0; i < strlen(s); i++) {
	 	p[strlen(s)-1-i] = s[i];
	 }
	 
	 
}

//FUNZIONE DI CONTROLLO
void check_palindrome(char s[], char p[]) {
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == p[i]) {
			p[i] = '$';
		} else {
			printf("Parola non palindroma\n");
			return;
		}
	}
	
	printf("Parola palindroma\n");
}
