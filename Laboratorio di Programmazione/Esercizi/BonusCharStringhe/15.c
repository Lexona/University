//Dato un array inizializzato con la stringa ciao\nmondo\n\0, eliminare eventuali caratteri \n contenuti, ottenendo la stringa finale ciao mondo (NB: verificare che la lunghezza della stringa sia esattamente 10).

#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "ciao\nmondo\n";
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == '\n') {
            // Sposto tutti i caratteri a destra del carattere \n di una posizione a sinistra
            if (i < len-1) {
                for (int j = i; j < len; j++) {
                    str[j] = str[j+1];
                }
                len--; // Aggiorno la lunghezza della stringa
                i--; // Ripeto il controllo per il carattere successivo
            }
        }
    }
    // Aggiungo il carattere terminatore \0 alla fine della stringa
    str[len] = '\0';
    printf("%s\n", str);
    printf("Lunghezza: %ld\n", strlen(str));
    return 0;
    
}
