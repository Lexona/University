//dichiarazione della lista
struct Partita {
	char campo[3][3];
	char vincitore;
	int punteggio;

	struct Partita *prossimo;
};
