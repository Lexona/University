//costruire un vettore che sia l'intersezione di 2 vettori dati (ossia mettere i soli elementi comuni tra i due vettori in un terzo vettore senza ripetizioni)

#include <stdio.h>

int main () {
    int A[] = {1,2,3,4,5};
    int B[] = {1,3,3,7,5};
    int RES[10], dim_res = 0, cont;

    for (int i = 0; i < 5; i++) {
        cont = 0;
        for (int j = 0; j < 5; j++) {
            if (A[i] == B[j]) {
                for (int k = 0; k < dim_res; k++) {
                    if (A[i] == RES[k]) {
                        cont = 1;
                        break;
                    }
                }

                if (!cont) {
                    RES[dim_res] = A[i];
                    dim_res++;
                }
            }
        }
    }

    //stampa
    for (int i = 0; i < dim_res; i++) {
        printf("%d\t", RES[i]);
    }

    return 0;
}
