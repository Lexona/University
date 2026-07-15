#!/bin/bash

aggiungi_verifica() {
    echo "Inserisci giorno, mese, anno, nome studente e voto (es. 13 mag 2025 marta 30)"
    read -r giorno mese anno nome_studente voto

    # controllo i dati inseriti 
    if (( giorno <= 0 || giorno > 31 )) || \
    ! [[ "$mese" =~ ^(gen|feb|mar|apr|mag|giu|lug|ago|set|ott|nov|dic)$ ]] || \
    ! [[ "$anno" =~ ^[0-9]{4}$ ]] || ! [[ "$nome_studente" =~ ^.+$ ]] || \
    (( voto < 18 || voto > 30 )); then
        echo "Inserimento non valido."
        return
    fi

    echo "$giorno $mese $anno $nome_studente $voto" >> verifica.txt
}

conta() {
    FILE="verifica.txt"

    # controllo se esiste il file
    if [[ ! -e $(find . -name "$FILE") ]]; then
        echo "Non esiste ancora il file dei voti, crealo e poi torna qui."
        return
    fi

    echo "Inserisci il mese e lo studente:"
    read -r mese nome_studente

    # controllo i dati inseriti
    if ! [[ "$mese" =~ ^(gen|feb|mar|apr|mag|giu|lug|ago|set|ott|nov|dic)$ ]] || \
    ! grep -q "$nome_studente" "$FILE"; then
        echo "Dati inseriti non corretti."
        return
    fi

    # conto gli esami fatti
    esami_effettuati=$(awk -v nome_studente="$nome_studente" -v mese="$mese" 'nome_studente==$4 && mese==$2 {cont++} END {print cont}' "$FILE")
    echo "Lo studente ($nome_studente) nel mese ($mese) ha effettuato $esami_effettuati esami"
}

calcolo_media(){
    FILE="verifica.txt"

    echo "Inserisci lo studente:"
    read -r nome_studente
    if ! grep -q "$nome_studente" "$FILE"; then
        echo "Lo studente non e' presente nel file delle verifiche."
        return
    fi

    media=$(awk -v nome_studente="$nome_studente" '$4==nome_studente {somma+=$5; cont++} END {if (cont > 0) print somma/cont; else print 0}' "$FILE")
    echo "Lo studente ($nome_studente) ha una media di $media"
}

while true; do
    echo "----------------------------"
    echo "Scegli un'opzione:"
    echo "1 - Aggiungi verifica"
    echo "2 - Conta"
    echo "3 - Media"
    echo "Qualsiasi cosa per uscire."
    read -r scelta

    case "$scelta" in
        1) aggiungi_verifica;;
        2) conta ;;
        3) calcolo_media ;;
        *) exit 0
    esac
done




