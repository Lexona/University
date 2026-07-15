#!/bin/bash

# salvo il file passato per argomento
FILE=$1

cerca() {
    echo "-----------------------------------"
    echo "Inserisci una stringa da cercare all'interno del file:"
    read -r stringa

    if [[ $(grep "$stringa" "$FILE") ]]; then
        echo "Stringa trovata!"
    else
        echo "La stringa non è presente nel file."
    fi
}

aggiungi() {
    echo "-----------------------------------"
    echo "Inserisci il codice del prodotto:"
    read -r codice
    echo "Quanti ne vuoi?"
    read -r quantita

    # controllo gli inserimenti
    if ! [[ $(grep "$codice" "$FILE") ]] || (( quantita <= 0 )); then
        echo "Inserimento non valido."
        exit 1
    fi

    # se i dati sono corretti vado avanti
    echo "$codice $quantita" >> carrello.txt
}

# INIZIO SCRIPT
echo "Inizio script..."
cerca
aggiungi
echo "Fine script..."


