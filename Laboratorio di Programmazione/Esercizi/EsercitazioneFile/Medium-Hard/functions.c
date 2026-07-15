#include "functions.h"

//inizializzazione dello stack
void init_stack(struct Elenco *e) {
	e -> first_in = 0;
}

//funzione di lettura degli elementi dal file
int load_next_student_from_file(FILE *f, struct Studente *s) {
	if (fscanf(f, "%s%s%s", s->matricola, s->nome, s->cognome) < 3)
		return 1; //se l'operazione non ha letto 3 elementi restituisco 1 che rappresenta lo stato di errore

	return 0;
}

//push degli elementi nella pila
int push (struct Elenco *e, struct Studente val) {
	//controllo se la pila è piena
	if (e -> first_in >= MAX)
		return 1;

	//se la pila non è piena
	e -> deposito[e -> first_in] = val;
	e -> first_in++;
	return 0;
}

//funzione di caricamento dei dati dal file
int load_students_from_file(struct Elenco *e, char nomeFile[]) {
	//apro il file in modalità lettura
	FILE *file = fopen(nomeFile, "r");
	//controllo se l'apertura ha avuto successo
	if (file == NULL)
		return 1;

	struct Studente s;
	int check = 0; //variabile di controllo del successo delle operazioni
	while (check == 0) {
		check = load_next_student_from_file(file, &s);

		if (check == 0) //se l'operazione di lettura dal file è andata a buon fine
			push(e, s); //faccio la push nella pila
	}

	fclose(file);
}

//funzione di pop dalla pila
int pop (struct Elenco *e, struct Studente *val) {
	//controllo se la pila è vuota
	if (e->first_in <= 0)
		return 1;

	//se la pila non è vuota
	*val = e->deposito[e->first_in - 1];
	e->first_in--;
	return 0;
}

//funzione di stampa
void print(struct Studente s) {
	printf("-----------------------\n");
	printf("Matricola: %s\n", s.matricola);
	printf("Nome: %s\n", s.nome);
	printf("Cognome: %s\n", s.cognome);
	printf("-----------------------\n");
}

//funzione di scrittura nel file
int write_student_on_file(FILE *f, struct Studente s) {
	printf("%s\n%s\n%s\n", s.matricola, s.nome, s.cognome); //stampo a video i dati del file

	fprintf(f, "%s\n%s\n%s\n", s.matricola, s.nome, s.cognome); //scrivo i dati nel file
	return 0;
}

//funzione intermedia per prendere i dati dall'elenco
int write_students_on_file(struct Elenco *e, char nomeFile[], char start_letter, char stop_letter) {
	//apro il file in modalità scrittura
	FILE *file = fopen(nomeFile, "w");
	//controllo se il file si sia aperto correttamente
	if (file == NULL)
		return 1;

	//dichiaro uno stack di apppoggio per le variabili che non rispettano la condizione
	struct Elenco appoggio;
	init_stack(&appoggio);

	struct Studente s;
	int check = 0;

	while (pop(e, &s) == 0) {
		//controllo se la condizione è rispettata
		if (s.cognome[0] >= start_letter && s.cognome[0] <= stop_letter)
			write_student_on_file(file, s);
		else
			push(&appoggio, s);
	}

	fclose(file);

	//rimetto i dati nello stack originale
	while (pop(&appoggio, &s) == 0) {
		push(e, s);
	}

	return 0;
}

















