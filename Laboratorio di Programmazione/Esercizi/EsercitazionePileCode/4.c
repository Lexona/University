#include <stdio.h>

#define MAX 100

void decimal_to_binary(int a[], int n, int* dim);
void print_stack(int a[], int dim);

int main(){
	int binario[MAX], decimale, dimensione = 0;
	
	printf("Inserisci il numero decimale: ");
	scanf("%d", &decimale);
	
	decimal_to_binary(binario, decimale, &dimensione);	
	print_stack(binario, dimensione);

	return 0;
}

void decimal_to_binary(int a[], int n, int* dim){
	while(n != 0){
		a[*dim] = n%2;
		
		n /= 2;
		
		*dim += 1;
	}
}

void print_stack(int a[], int dim){
	for(int i = dim-1; i >= 0; i--){
		printf("%d", a[i]);
		a[i] = -1;
	}
	
	printf("\n");
}
