#define MAX 20

struct Post {
	char msg[257];
	int n_like;
};

struct Bacheca {
	struct Post *deposito;
	int first_in; //dove inserire
	int first_out; //dove leggere
	int n_occupati;
};
