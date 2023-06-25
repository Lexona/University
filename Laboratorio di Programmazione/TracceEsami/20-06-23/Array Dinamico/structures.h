//struttura per i dati del Personaggio
struct Personaggio {
  char nome[33];
  int hp;
  int dp;
  int ap;
};

//struttura per l'array dinamico
struct Elenco {
  struct Personaggio *vettore;
  int dimensione;
};

