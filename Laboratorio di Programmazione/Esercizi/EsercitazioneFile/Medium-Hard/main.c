#include "functions.h"
#include <stdio.h>

int main () {
	//dichiarazione delle variabili
	struct Studente s;
	struct Elenco e;
	int check = 0;

	//richiamo funzione di inizializzazione della pila
	init_stack(&e);
	//richiamo funzione di inserimento dati nella pila
	load_students_from_file(&e, "iscritti.txt");

	//richiamo funzione di scrittura dati nei file
	write_students_on_file(&e, "gruppo1.txt", 'A', 'G');
	write_students_on_file(&e, "gruppo2.txt", 'H', 'P');
	write_students_on_file(&e, "gruppo3.txt", 'Q', 'Z');

	return 0;
}
