//struttura Veicolo
struct Veicolo {
	char targa[11];
	float velocita;
	int limite;
};

//struttura Report
struct Report {
	struct Veicolo deposito;
	struct Report *prossimo;
};
