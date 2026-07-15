#define MAX 100

//struttura per il Veicolo
struct Veicolo {
	char targa[11];
	float velocita;
	int limite;
};

//struttura per il Report
struct Report {
	struct Veicolo deposito[MAX];
	int first_in;
};
