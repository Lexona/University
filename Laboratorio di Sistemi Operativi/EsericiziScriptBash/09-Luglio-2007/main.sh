# Si realizzi uno script che elenchi il tipo di file regolari contenuti nella directory classificandoli tramite l'estensione ed elenchi
# per ogni estensione i gruppi che possiedono almeno un file con tale estensione e il numero di file da essi posseduti. Ad esempio:
# .tex: users 1 staff 2
# .mp3: users 1
# .pdf: staff 2

#!/bin/bash

# controlliamo che la cartella possegga file regolari
if ! [[ $(find . -type f ) ]]; then
    echo "La cartella corrente non contiene file regolari."
    exit 1
fi

# leggo ogni file
for elem in *; do
    # controllo se il file trovato è regolare
    if [[ -f "$elem" ]]; then
        # estraggo l'estensione del file
        estensione="${elem##*.}"

        # ottengo il gruppo del file
        gruppo=$(ls -l "$elem" | awk '{print $4}')

        # stampo il risultato
        echo "$estensione: $gruppo"
    fi
done | sort | uniq -c | awk '{print $2, $3, $1}'

