# Scrivere uno script BASH "visita.sh" che visita tutti i file della directory corrente. Per ogni file determina il suo tipo. Se il file leggibile è un file txt, doc o
# un sh o un c, visita.sh chiede all'utente se si vuole vedere il suo contenuto mostrando solo le ultime 3 righe, mentre se il file è una sottodirectory, visita.sh
# chiede se si vuole visitare anche la sottodirectory. Per ogni file incontrato, visita.sh chiede se lo si vuole rimuovere prima di passare a gestire il prossimo file
# nella directory corrente.

#!/bin/bash

# funzione di visita
visita_directory() {
    CARTELLA=$1
    pushd "$CARTELLA"
    for elem in *; do
        # controllo se il file è un file
        if [[ -f "$elem" && "$elem" != "visita.sh" && "$elem" =~ \.(txt|doc|sh|c)$ ]]; then

            echo "Hai trovato un file regolare, vuoi leggere le ultime 3 righe? (s/n)"
            read -r risposta_lettura

            # chiedo se vuole leggere il file
            if [[ $risposta_lettura == "s" ]]; then
                echo "Le ultime 3 righe del file sono:"
                tail -n 3 "$elem"
            elif [[ $risposta_lettura != "n" ]]; then
                echo "ERRORE: inserimento non valido."
                exit 1
            fi

            # chiedo se vuole eliminare il file
            echo "Vuoi eliminare questo file? (s/n)"
            read -r risposta_rimozione

            # chiedo se vuole leggere il file
            if [[ $risposta_rimozione == "s" ]]; then
                rm $elem
                echo "Elemento rimosso..."
            elif [[ $risposta_rimozione != "n" ]]; then
                echo "ERRORE: inserimento non valido."
                exit 1
            fi
        elif [[ -d "$elem" ]]; then
            echo "Hai trovato una directory, vuoi visitare anche la sottodirectory?"
            read -r risposta_visita

            if [[ $risposta_visita == "s" ]]; then
                visita_directory "$elem"
            elif [[ $risposta_visita != "n" ]]; then
                echo "ERRORE: inserimento non valido."
                exit 1
            fi
        fi
    done
    echo "Torno alla directory precedente..."
    popd
}

echo "Inizio programma..."
directory_attuale="."
visita_directory "$directory_attuale"