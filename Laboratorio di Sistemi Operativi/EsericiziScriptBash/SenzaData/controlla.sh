# Scrivere uno script bash "controlla.sh" per controllare che le flag lette da input (non come parametri dello script) siano una combinazione
# delle lettere "a b c". Queste lettere possono comparire più di una volta, in ordine sparso. Lo script restituisce un errore se in input vengono
# passate lettere diverse. Lo script deve rimanere in loop fino a quando non viene ucciso con CTRL+C oppure premendo il tasto Q.

#!/bin/bash

controlla_input() {
    input="$1"

    if [[ "$input" =~ ^[abc]*$ ]]; then
        echo "Input valido ($input)"
    else
        echo "Input non valido."
    fi
}


while true; do 
    echo "Inserisci un combinazione di lettere (a, b, c) oppure Q per uscire."
    read -r input

    if [[ "$input" =~ ^[Qq]$ ]]; then
        echo "Uscita dallo script..."
        break
    fi

    controlla_input "$input"
done 

exit 0




