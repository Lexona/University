#define MAX 15

//struttura del Veicolo
struct Veicolo {
	char targa[11];
	float velocita;
	float limite;
};

//struttura del Report (array dinamico)
struct Report {
	struct Veicolo *deposito;
	int first_in;
};
