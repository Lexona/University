#define MAX 50

struct Studente {
	char matricola[11];
	char nome[21];
	char cognome[21];
};

struct Elenco {
	struct Studente deposito[MAX];
	int first_in;
};

