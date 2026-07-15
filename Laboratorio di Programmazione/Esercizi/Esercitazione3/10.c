#include <stdio.h>
#define MAX 20

void func(int v[], int dim, int* v2[]);

int main(){
	int n;

	do{
		printf("Inserisci la dimensione del vettore: ");
		scanf("%d", &n);
	}while(n > MAX);

	int v[n];
	int* riassunto[3];

	for(int i = 0; i < n; i++){
		printf("Inserisci il %d° valore: ", i+1);
		scanf("%d", &v[i]);
	}

	func(v, n, riassunto);

	printf("Indirizzo della locazione del minimo: %p\n", riassunto[0]);
	printf("Indirizzo della locazione del massimo: %p\n", riassunto[1]);
	printf("Indirizzo della locazione del numero più frequente: %p\n", riassunto[2]);

	return 0;
}

void func(int v[], int dim, int* v2[]){
	int min = v[0], max = v[0], cont = 0, cont_max = 0, idx;

	for(int i = 1; i < dim; i++){
		if(v[i] < min){
			min = v[i];
			v2[0] = &v[i];
		}else if(v[i] >= max){
			max = v[i];
			v2[1] = &v[i];
			printf("%p\n", &v[i]);
		}
	}

	for(int i = 0; i < dim; i++){
		if(cont > cont_max){
			cont_max = cont;
			v2[2] = &v[idx];
		}

		for(int j = 0; j < dim; j++){
			if(v[i] == v[j]){
				cont++;
				idx = j;
			}
		}
	}

}
