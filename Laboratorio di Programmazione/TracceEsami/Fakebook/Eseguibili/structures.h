#define MAX 100

//dichiaro la struttura dati dei Post
struct Post {
	char msg[257];
	int n_like;
};

//dichiaro la struttura dati della Bacheca
struct Bacheca {
	struct Post **deposito;
	int first_in; //dove inserire
	int first_out; //locazione da cui leggere
	int n_occupati; //numero totale di elementi presenti nella bacheca
};
