//dato un vettore A ed un vettore B di lunghezza ≤ alla lunghezza di A, determinare se il vettore B è un sottovettore di A (ossia se esiste una sequenza di elementi
//in A uguale all'intera sequenza di elementi in B)

#include <stdio.h>
#include <stdbool.h>

int main() {
    int A[] = {1,2,3,4,5,6,7,8};
    int B[] = {3,4,5};
    bool found = false;

    for (int i = 0; i <= 8-3; i++) {
        found = true;
        for (int j = 0; j < 3; j++) {
            if (A[i+j] != B[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            printf("Il vettore B è un sottovettore di A.\n");
            return 0;
        }
    }

    printf("Il vettore B non è un sottovettore di A.\n");
    return 0;
}
